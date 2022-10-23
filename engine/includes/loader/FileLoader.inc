<?php namespace engine\includes\loader;

use engine\includes\loader\exceptions\ClassNotFoundException;
use engine\includes\loader\exceptions\IncludeException;
use engine\includes\loader\exceptions\InvalidClassException;
use engine\includes\loader\exceptions\LoaderException;

include_once('exceptions/IncludeException.inc');
include_once('ModuleLoader.inc');

/**
 * Class FileLoader designed for loading modules from the file system.
 * @package engine\includes\loader
 */
class FileLoader extends ModuleLoader
{
  /**
   * Loads one or more modules from the file system.
   * @param string $namespace
   * @param array $classnames
   * @param array $args
   * @return void
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  final protected function multiple(string $namespace, array $classnames, array $args = [])
  {
    foreach ($classnames as $classname) {
      $this->load($namespace, $classname, $args);
    }
  }

  /**
   * Loads the module from the file system.
   * @param string $namespace
   * @param string $classname
   * @param array $args
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  final protected function load(string $namespace, string $classname, array $args = [])
  {
    $filename = $this->getEnviron()->format('{root}', strtolower($classname), "$classname.php");
    if (@include_once($filename)) {
      $this->add("$namespace\\$classname\\$classname", ...$args);
    } else
      throw new IncludeException($filename);
  }
}