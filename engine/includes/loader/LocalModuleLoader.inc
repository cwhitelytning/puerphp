<?php namespace engine\includes\loader;

use engine\includes\loader\exceptions\ClassNotFoundException;
use engine\includes\loader\exceptions\IncludeException;
use engine\includes\loader\exceptions\InvalidClassException;
use engine\includes\module\Module;

include_once('exceptions/IncludeException.inc');
include_once('ModuleLoader.inc');

/**
 * Class LocalModuleLoader designed for loading modules from the file system.
 * @package engine\includes\loader
 */
class LocalModuleLoader extends ModuleLoader
{
  /**
   * Notification of all modules about their loading.
   * @return void
   */
  protected function onModuleInit(): void
  {
    $this->fetch(function (Module $module) {
      if (method_exists($module, 'onModuleInit')) {
        $module->onModuleInit();
      }
    });
  }

  /**
   * Loads the module from the file system.
   * @param string $directory in which to search for modules.
   * @param string $namespace in which the class will be searched.
   * @param string $classname that is located in both the directory and the namespace.
   * @return Module|null
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  protected function loadFile(string $directory, string $namespace, string $classname): ?Module
  {
    $filename = $this->getEnviron()->collect($directory, strtolower($classname), "$classname.php");
    return $this->loadClass($filename, $namespace);
  }

  /**
   * Notification of all modules about their unloading.
   * @return void
   */
  protected function onModuleEnd(): void
  {
    $this->fetch(function (Module $module) {
      if (method_exists($module, 'onModuleEnd')) {
        $module->onModuleEnd();
      }
    });
  }
}