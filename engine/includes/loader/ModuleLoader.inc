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
   * Specifies the main class of the module from which all other modules should be inherited.
   * It is necessary to check the module being added.
   */
  const MODULE_CLASSNAME = Module::class;

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
   * Loads a class from a file including a file and importing a class from a namespace.
   * Class name is taken from the file name.
   * @param string $filename
   * @param string $namespace
   * @return Module|null
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  protected function loadClassFileFrom(string $filename, string $namespace): ?Module
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
  final protected function importClass(string $class): ?Module
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
    return isset($parents[static::MODULE_CLASSNAME]);
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
