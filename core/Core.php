<?php namespace core;

include_once('src/library/Library.inc');
include_once('src/loader/LibraryLoader.inc');
include_once('src/plugin/Plugin.inc');

use core\src\library\Library;
use core\src\library\LibraryInfo;
use core\src\loader\exceptions\ClassNotFoundException;
use core\src\loader\exceptions\IncludeException;
use core\src\loader\exceptions\InvalidClassException;
use core\src\loader\LibraryLoader;
use core\src\plugin\Plugin;

#[LibraryInfo('Clay Whitelytning', '1.1.3', 'Master Library Loader')]
final class Core extends LibraryLoader
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
    $engine->initialization();
    $engine->main();
    $engine->finalization();
    $engine = null;
  }

  /**
   * Loads and initializes libraries.
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  private function initialization(): void
  {
    $env = $this->getEnviron();
    # It is expected after adding to see two additional variables ROOT_DIR and LIBS_DIR.
    # * ROOT_DIR - must be extracted from the path where the core is located.
    # * LIBS_DIR - must be in the root directory.
    $env->append($env->getPathsFromFile($env->format('{CONFIGS_DIR}', 'envs.xml'), 2));

    if ($libs = @simplexml_load_file($env->format('{CONFIGS_DIR}', 'libs.xml'))) {
      foreach ($libs as $lib) {
        $group = (string)$lib['group'];
        $directory = $env::collect($env->get('LIBS_DIR'), $group);
        if ($library = $this->loadClassFile($directory, (string)$lib['id'], "libs\\$group")) {
          # Called when the class is loaded and created.
          if (method_exists($library, 'create')) { $library->create(); }
        }
      }
    }

    $this->each(function (Library $library) {
      # Called after all libraries have been created.
      if (method_exists($library, 'initialization')) { $library->initialization(); }
    });
  }

  /**
   * Calls the main function of plugins.
   * @return void
   */
  private function main(): void
  {
    $this->each(function (Library $plugin) {
      if (method_exists($plugin, 'main')) { $plugin->main(); }
    }, Plugin::class);
  }

  /**
   * Notification of all loaded modules about their unloading.
   * @return void
   */
  private function finalization(): void
  {
    $this->each(function (Library $library) {
      if (method_exists($library, 'finalization')) {
        $library->finalization();
      }
    });
  }
}
