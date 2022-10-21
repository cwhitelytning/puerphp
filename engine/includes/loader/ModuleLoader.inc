<?php namespace engine\includes\loader;

include_once('exceptions/ClassNotFoundException.inc');
include_once('exceptions/InvalidClassException.inc');

use Countable;
use engine\includes\loader\exceptions\ClassNotFoundException;
use engine\includes\loader\exceptions\InvalidClassException;
use engine\includes\logger\LoggerInterface;
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
   * Searches for the module by name and returns it (if found).
   * @param string $name
   * @return Module|null
   */
  final public function get(string $name): ?Module
  {
    return $this->fetch(function (Module $module) use (&$name) {
      return $module->getInfo()->getName() == $name;
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
   * Sets a new logger or by default.
   * @param LoggerInterface|null $logger
   */
  final public function setLogger(LoggerInterface $logger = null): void
  {
    parent::setLogger($logger);
    $this->fetch(function (Module $module) {
      $module->setLogger($this->getLogger());
    });
  }

  /**
   * Creates a new instance of the class and adds it to the list of modules.
   * @param string $classpath
   * @param mixed ...$args
   * @throws ClassNotFoundException
   * @throws InvalidClassException
   */
  final protected function add(string $classpath, ...$args)
  {
    if (class_exists($classpath)) {
      if ($this->isValidClass($classpath)) {
        # It is better not to use a string identifier,
        # the class name should be unique but it may match.
        $this->modules[] = new $classpath($this, $this->getLogger(), ...$args);
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
  final private function isValidClass(string $classpath): bool
  {
    $parents = class_parents($classpath);
    return isset($parents[static::MODULE_CLASSPATH]);
  }
}
