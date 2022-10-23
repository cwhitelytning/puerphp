<?php namespace engine\includes\loader;

include_once('exceptions/ClassNotFoundException.inc');
include_once('exceptions/InvalidClassException.inc');

use Countable;
use engine\includes\loader\exceptions\ClassNotFoundException;
use engine\includes\loader\exceptions\InvalidClassException;
use engine\includes\Module;

/**
 * Class ModuleFactory stores all added modules.
 * Do not change the visibility of functions, this will disrupt the logic of protected storage.
 * @package engine\includes\loader
 */
class ModuleLoader extends Module implements Countable
{
  /**
   * Specifies the main class of the module from which all other modules should be inherited.
   * It is necessary to check the module being added.
   */
  const MODULE_CLASSPATH = Module::class;

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
   * Creates a new instance of the class and adds it to the list of modules.
   * @param string $classpath
   * @param mixed ...$args
   * @return Module|null
   * @throws ClassNotFoundException
   * @throws InvalidClassException
   */
  final protected function import(string $classpath, ...$args): ?Module
  {
    if (class_exists($classpath)) {
      if ($this->isValidClass($classpath)) {
        # It is better not to use a string identifier,
        # the class name should be unique, but it may match.
        return $this->add(new $classpath($this, ...$args));
      } else
        throw new InvalidClassException($classpath);

    } else
      throw new ClassNotFoundException($classpath);
  }

  /**
   * Checks whether the class is valid for the loader.
   * @param string $classpath
   * @return bool
   */
  private function isValidClass(string $classpath): bool
  {
    $parents = class_parents($classpath);
    return isset($parents[static::MODULE_CLASSPATH]);
  }

  /**
   * Adds a module to the list of all modules.
   * Returns null if the specified class name is already in the list.
   * @param Module $module
   * @return Module|null
   */
  private function add(Module $module): ?Module
  {
    $name = $module->getInfo()->getName();
    return $this->has($name) ? null : $this->modules[$name] = $module;
  }
}
