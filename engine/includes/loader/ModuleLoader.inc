<?php namespace engine\includes\loader;

use engine\includes\loader\exceptions\ClassNotFoundException;
use engine\includes\loader\exceptions\IncludeException;
use engine\includes\loader\exceptions\InvalidClassException;
use engine\includes\module\Module;
use ReflectionClass;

include_once('exceptions/ClassNotFoundException.inc');
include_once('exceptions/InvalidClassException.inc');

/**
 * Class ModuleLoader a universal class loader that allows you to load classes from anywhere.
 * @package engine\includes\loader
 */
class ModuleLoader extends Module
{
  /**
   * Specifies to the loader the base class from which all loaded classes should be inherited.
   * If a class does not contain a base class in the class hierarchy, the loaded class is considered invalid.
   *
   * <b>It is not recommended to use another class that does not extend from the module class,
   * this will cause incorrect behavior of the loader.</b>
   */
  const MODULE_CLASS = Module::class;

  /**
   * Contains modules.
   * @var Module[]
   */
  private array $modules = [];

  /**
   * Returns the module.
   * @param string $name
   * @return Module|null
   */
  final public function get(string $name): ?Module
  {
    return $this->has($name) ? $this->modules[$name] : null;
  }

  /**
   * Checks if the specified module class is present in the loader.
   * @param string $name
   * @return bool
   */
  final public function has(string $name): bool
  {
    return isset($this->modules[$name]);
  }

  /**
   * Extracts each Module and passes it to the callback function.
   * Iteration is stopped using the returned positive value.
   * If the iteration was stopped ahead of time,
   * it returns the current extracted module.
   * @param callable $callable
   * @return Module|null
   */
  final public function fetch(callable $callable): ?Module
  {
    foreach ($this->modules as $module) {
      if ($callable($module)) return $module;
    }
    return null;
  }

  /**
   * Loads a class from a namespace that must match the directory structure in which the file is located.
   * @param string $filename
   * @return Module|null
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  protected function loadClassFile(string $filename): ?Module
  {
    $namespace = (new ReflectionClass($this))->getNamespaceName();
    $filename = $this->getEnviron()->format('{dir}', strtolower($filename), "$filename.php");
    return $this->loadClassFileFrom($filename, $namespace);
  }

  /**
   * Loads a class from a file including a file and importing a class from a namespace.
   * Class name is taken from the file name.
   * @param string $filename
   * @param string $namespace
   * @return Module|null
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  private function loadClassFileFrom(string $filename, string $namespace): ?Module
  {
    if (@include_once($filename)) {
      $name = pathinfo($filename, PATHINFO_FILENAME);
      return $this->importClass("$namespace\\$name\\$name");
    } else
      throw new IncludeException($filename);
  }

  /**
   * Imports a class from the path specified to it,
   * creates a new instance and adds it to the list.
   * @param string $class
   * @return Module|null
   * @throws ClassNotFoundException
   * @throws InvalidClassException
   */
  private function importClass(string $class): ?Module
  {
    if (class_exists($class)) {
      if ($this->isValidClass($class)) {
        return $this->add(new $class($this));
      } else
        throw new InvalidClassException($class);

    } else
      throw new ClassNotFoundException($class);
  }

  /**
   * Checks whether the class is valid for the loader.
   * @param string $class
   * @return bool
   */
  private function isValidClass(string $class): bool
  {
    $parents = class_parents($class);
    return isset($parents[static::MODULE_CLASS]);
  }

  /**
   * Adds a module to the list of all modules.
   * @param Module $module
   * @return Module
   */
  private function add(Module $module): Module
  {
    $name = (new ReflectionClass($module))->getShortName();
    return $this->modules[$name] = $module;
  }
}
