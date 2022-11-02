<?php namespace core;

include_once('src/book/Book.inc');
include_once('src/loader/BookLoader.inc');
include_once('src/plugin/Plugin.inc');

use core\src\book\Book;
use core\src\loader\BookLoader;
use core\src\loader\exceptions\LoaderException;
use core\src\plugin\Plugin;

/**
 * Class Core
 * @package core
 */
final class Core extends BookLoader
{
  /**
   * Creates a new instance of the core and simulates life cycle work.
   * @return void
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
   */
  private function initialization(): void
  {
    $env = $this->getEnviron();
    # It is expected after adding to see two additional variables ROOT_DIR and LIB_DIR.
    # * ROOT_DIR - directory can be used by books.
    # * LIB_DIR - directory from which books are loaded.
    $env->append($env->getPathsFromFile($env->format('{CONF_DIR}', 'paths.xml'), 2));

    if ($libs = @simplexml_load_file($env->format('{CONF_DIR}', 'books.xml'))) {
      foreach ($libs as $lib) {
        try {
          $id = (string)$lib['id']; # Classpath is its unique identifier.
          $filename = $env->format('{LIB_DIR}', "$id.php"); # Classpath must be the same as the filepath.

          $this->loadClassFile($filename, $id);
        } catch (LoaderException $exception) {
          trigger_error($exception, E_USER_WARNING);
        }
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
