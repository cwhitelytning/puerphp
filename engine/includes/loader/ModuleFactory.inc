<?php namespace engine\includes\loader;

include_once('exceptions/ClassNotFoundException.inc');
include_once('exceptions/InvalidClassException.inc');

use Countable;
use engine\includes\loader\exceptions\ClassNotFoundException;
use engine\includes\loader\exceptions\InvalidClassException;
use engine\includes\module\Module;

/**
 * Class ModuleFactory stores all added modules.
 * Do not change the visibility of functions, this will disrupt the logic of protected storage.
 * @package engine\includes\loader
 */
class ModuleFactory extends Module implements Countable
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
   * Returns the number of modules.
   * @return int
   */
  final public function count(): int
  {
    return count($this->modules);
  }

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
   * Creates a new instance of the class and adds it to the list of modules.
   * @param string $classpath
   * @return Module|null
   * @throws ClassNotFoundException
   * @throws InvalidClassException
   */
  final protected function import(string $classpath): ?Module
  {
    if ($this->search($classpath)) {
      # An already loaded class will be ignored.
      return null;
    } elseif (class_exists($classpath)) {
      if ($this->isValidClass($classpath)) {
        return $this->add(new $classpath($this));
      } else
        throw new InvalidClassException($classpath);

    } else
      throw new ClassNotFoundException($classpath);
  }

  /**
   * Searches for a class from a list of all loaded modules, comparing their paths.
   * If the class is successfully found returns the module.
   * @param string $classname
   * @return Module|null
   */
  final public function search(string $classname): ?Module
  {
    return $this->fetch(function (Module $module) use (&$classname) {
      return $module->getInfo()->getClassname() == $classname;
    });
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
   * Checks whether the class is valid for the loader.
   * @param string $classname
   * @return bool
   */
  private function isValidClass(string $classname): bool
  {
    $parents = class_parents($classname);
    return isset($parents[static::MODULE_CLASSNAME]);
  }

  /**
   * Adds a module to the list of all modules.
   * Returns null if the specified class name is already in the list.
   * @param Module $module
   * @return Module
   */
  private function add(Module $module): Module
  {
    $name = $module->getInfo()->getName();
    return $this->modules[$name] = $module;
  }
}
