<?php namespace engine\includes\factory;

use Countable;
use engine\includes\module\Module;

/**
 * Class ModuleFactory stores all added modules.
 * @package engine\includes\factory
 */
class ModuleFactory extends Module implements Countable
{
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
   * Adds a module to the list of all modules.
   * @param Module $module
   * @return Module
   */
  final protected function add(Module $module): Module
  {
    $name = $module->getInfo()->getName();
    return $this->modules[$name] = $module;
  }
}
