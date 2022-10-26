<?php namespace engine;

include_once('includes/module/Module.inc');
include_once('includes/loader/ModuleLoader.inc');
include_once('includes/plugin/Plugin.inc');
include_once('includes/file/VariableFile.inc');

use engine\includes\file\ConfigFile;
use engine\includes\loader\exceptions\ClassNotFoundException;
use engine\includes\loader\exceptions\IncludeException;
use engine\includes\loader\exceptions\InvalidClassException;
use engine\includes\loader\ModuleLoader;
use engine\includes\module\Module;
use engine\includes\module\ModuleInfo;

#[
  ModuleInfo(
    name: 'Engine',
    author: 'Clay Whitelytning',
    version: '1.1.2',
    description: 'Module Loader'
  )
]
final class Engine extends ModuleLoader
{
  /**
   * Loads and initializes modules from modules.file.
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  private function onModuleInit(): void
  {
    if ($names = ConfigFile::parseFile($this->getEnviron()->format('{configs}', 'modules.conf'))) {
      # Loading all local modules.
      foreach ($names as $name) $this->loadClassFile($name);
      # Initialization of all modules after loading.
      $this->fetch(function (Module $module) {
        if (method_exists($module, 'onModuleInit')) {
          $module->onModuleInit();
        }
      });
    }
  }

  /**
   * Creates a new instance of the engine and simulates life cycle work.
   * @return void
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  public static function run(): void
  {
    $engine = new Engine(null);
    $engine->onModuleInit();
    # ----------------------------------------------------------------------------------------------------------------
    $engine->onModuleEnd();
    $engine = null;
  }

  /**
   * Notification of all loaded modules about their unloading.
   * @return void
   */
  private function onModuleEnd(): void
  {
    $this->fetch(function (Module $module) {
      if (method_exists($module, 'onModuleEnd')) {
        $module->onModuleEnd();
      }
    });
  }
}
