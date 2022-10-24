<?php namespace engine\includes\loader;

use engine\includes\factory\ModuleFactory;
use engine\includes\loader\exceptions\ClassNotFoundException;
use engine\includes\loader\exceptions\IncludeException;
use engine\includes\loader\exceptions\InvalidClassException;
use engine\includes\module\Module;

include_once('exceptions/ClassNotFoundException.inc');
include_once('exceptions/InvalidClassException.inc');

/**
 * Class ModuleLoader a universal class loader that allows you to load classes from anywhere.
 * @package engine\includes\loader
 */
class ModuleLoader extends ModuleFactory
{
  /**
   * Specifies the main class of the module from which all other modules should be inherited.
   * It is necessary to check the module being added.
   */
  const MODULE_CLASSNAME = Module::class;

  /**
   * Includes the file and imports the class into the list of all modules.
   * @param string $filename
   * @param string $namespace
   * @return Module|null
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  protected function loadClass(string $filename, string $namespace): ?Module
  {
    if (@include_once($filename)) {
      $classname = pathinfo($filename, PATHINFO_FILENAME);
      return $this->import("$namespace\\$classname\\$classname");
    } else
      throw new IncludeException($filename);
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
   * Checks whether the class is valid for the loader.
   * @param string $classname
   * @return bool
   */
  private function isValidClass(string $classname): bool
  {
    $parents = class_parents($classname);
    return isset($parents[static::MODULE_CLASSNAME]);
  }
}
