<?php namespace core;

include_once('src/module/Module.inc');
include_once('src/loader/ModuleLoader.inc');
include_once('src/plugin/Plugin.inc');

use core\src\module\Module;
use core\src\module\ModuleInfo;
use core\src\loader\exceptions\ClassNotFoundException;
use core\src\loader\exceptions\IncludeException;
use core\src\loader\exceptions\InvalidClassException;
use core\src\loader\ModuleLoader;

#[
  ModuleInfo
  (
    name: 'Core',
    author: 'Clay Whitelytning',
    version: '1.1.3',
    description: 'Module Loader'
  )
]
final class Core extends ModuleLoader
{
  /**
   * Creates a new instance of the core and simulates life cycle work.
   * @return void
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  public static function run(): void
  {
    $engine = new Core(null);
    $engine->onModuleInit();
    # ----------------------------------------------------------------------------------------------------------------
    $engine->onModuleEnd();
    $engine = null;
  }

  /**
   * Loads and initializes modules from modules.file.
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  private function onModuleInit(): void
  {
    $env = $this->getEnviron();
    $env->append([
      # Above this module is the root directory.
      'root' => ['{dir}', '..'],
      # Directory for modules.
      'modules' => ['{root}', 'modules'],
      # Directory for plugins.
      'plugins' => ['{root}', 'plugins']
    ]);

    if ($modules = @simplexml_load_file($env->format('{configs}', 'modules.xml'))) {
      foreach ($modules as $module) {
        $this->loadClassFile($env->get('modules'), (string)$module['id'], 'modules');
      }
    }

    if ($plugins = @simplexml_load_file($env->format('{configs}', 'plugins.xml'))) {
      foreach ($plugins as $plugin) {
        $this->loadClassFile($env->get('plugins'), (string)$plugin['id'], 'plugins');
      }
    }

    $this->fetch(function (Module $module) {
      if (method_exists($module, 'onModuleInit')) {
        $module->onModuleInit();
      }
    });
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
