<?php namespace engine;

include_once('includes/Module.inc');
include_once('includes/setti/ConfigFile.inc');
include_once('includes/loader/LocalModuleLoader.inc');

use engine\includes\loader\LocalModuleLoader;
use engine\includes\setti\SettiFile;
use engine\includes\loader\exceptions\ClassNotFoundException;
use engine\includes\loader\exceptions\IncludeException;
use engine\includes\loader\exceptions\InvalidClassException;

/**
 * Class Engine
 * @package engine
 * @description Engine module loader
 * @author Clay Whitelytning
 * @version 1.1.0
 */
final class Engine extends LocalModuleLoader
{
  /**
   * Loads and initializes modules from modules.setti.
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  protected function onModuleInit(): void
  {
    if ($filenames = SettiFile::parseFile($this->getEnviron()->format('{configs}', 'modules.setti'))) {
      foreach ($filenames as $filename) {
        $this->loadFile($this->getEnviron()->get('root'), '' /* global namespace */, $filename);
      }
      parent::onModuleInit();
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
}
