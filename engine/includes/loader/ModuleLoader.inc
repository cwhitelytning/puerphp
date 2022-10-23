<?php namespace engine\includes\loader;

use engine\includes\loader\exceptions\ClassNotFoundException;
use engine\includes\loader\exceptions\IncludeException;
use engine\includes\loader\exceptions\InvalidClassException;
use engine\includes\Module;

include_once('ModuleFactory.inc');

/**
 * Class ModuleLoader a universal class loader that allows you to load classes from anywhere.
 * @package engine\includes\loader
 */
class ModuleLoader extends ModuleFactory
{
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
}
