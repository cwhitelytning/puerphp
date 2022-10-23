<?php namespace engine;

include_once('includes/Module.inc');
include_once('includes/loader/FileLoader.inc');
include_once('includes/setti/ConfigFile.inc');

use engine\includes\setti\SettiFile;
use engine\includes\loader\exceptions\ClassNotFoundException;
use engine\includes\loader\exceptions\FileIncludeException;
use engine\includes\loader\exceptions\InvalidClassException;
use engine\includes\loader\FileLoader;
use engine\includes\Module;

/**
 * Class Engine
 * @package engine
 * @description Engine module loader
 * @author Clay Whitelytning
 * @version 1.1.0
 */
final class Engine extends FileLoader
{
  /**
   * Creates a new instance of the engine and simulates life cycle work.
   * @return void
   * @throws ClassNotFoundException
   * @throws FileIncludeException
   * @throws InvalidClassException
   */
  public static function run(): void
  {
    $engine = new Engine(null);
    $engine->multiple('' /* global namespace */,
      SettiFile::parseFile($engine->getEnviron()->format('{configs}', 'modules.setti'))
    );

    # Initialization of modules.
    # ---------------------------------------------------------------------------------------------------------------
    $engine->fetch(function (Module $module) {
      if (method_exists($module, 'onModuleInit')) $module->onModuleInit();
    });

    # De-initialization of modules.
    # ---------------------------------------------------------------------------------------------------------------
    $engine->fetch(function (Module $module) {
      if (method_exists($module, 'onModuleEnd')) $module->onModuleEnd();
    });
    # ---------------------------------------------------------------------------------------------------------------
    $engine = null;
  }
}
