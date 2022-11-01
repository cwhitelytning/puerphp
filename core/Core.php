<?php namespace core;

include_once('src/book/Book.inc');
include_once('src/loader/BookLoader.inc');
include_once('src/plugin/Plugin.inc');

use core\src\book\Book;
use core\src\book\BookInfo;
use core\src\loader\exceptions\ClassNotFoundException;
use core\src\loader\exceptions\IncludeException;
use core\src\loader\exceptions\InvalidClassException;
use core\src\loader\BookLoader;
use core\src\plugin\Plugin;

#[BookInfo('Clay Whitelytning', '1.1.3', 'Master Book Loader')]
final class Core extends BookLoader
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
   * Loads and initializes books.
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  private function initialization(): void
  {
    $env = $this->getEnviron();
    # It is expected after adding to see two additional variables ROOT_DIR and LIB_DIR.
    # * ROOT_DIR - directory can be used by books.
    # * LIB_DIR - directory from which books are loaded.
    $env->append($env->getPathsFromFile($env->format('{CONFIGS_DIR}', 'envs.xml'), 2));

    if ($libs = @simplexml_load_file($env->format('{CONFIGS_DIR}', 'books.xml'))) {
      foreach ($libs as $lib) {
        $group = (string)$lib['group'];
        $directory = $env::collect($env->get('LIB_DIR'), $group);
        $this->loadClassFile($directory, (string)$lib['id'], "lib\\$group");
      }
    }

    $this->each(function (Book $book) {
      # Called after all books have been created.
      if (method_exists($book, 'initialization')) { $book->initialization(); }
    });
  }

  /**
   * Calls the main function of plugins.
   * @return void
   */
  private function main(): void
  {
    $this->each(function (Book $plugin) {
      if (method_exists($plugin, 'main')) { $plugin->main(); }
    }, Plugin::class);
  }

  /**
   * Notification of all loaded books about their unloading.
   * @return void
   */
  private function finalization(): void
  {
    $this->each(function (Book $book) {
      if (method_exists($book, 'finalization')) {
        $book->finalization();
      }
    });
  }
}
