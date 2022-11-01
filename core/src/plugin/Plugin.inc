<?php namespace core\src\plugin;

include_once('logger/LoggerInterface.inc');
include_once('logger/LoggerLevels.inc');
include_once('logger/AbstractLogger.inc');
include_once('logger/NullLogger.inc');

use core\src\book\Book;
use core\src\plugin\logger\LoggerInterface;
use core\src\plugin\logger\NullLogger;

/**
 * Class Plugin
 * @package core\src\plugin
 */
class Plugin extends Book
{
  /**
   * Contains logger.
   * @var Book
   */
  private Book $logger;

  /**
   * Plugin initializing.
   */
  public function initialization()
  {
    $this->logger = $this->findLogger() ?? new NullLogger(null);
  }

  /**
   * Searches for a book implementing the Logger Interface.
   * If successful, returns the first found book.
   * @return Book|null
   */
  private function findLogger(): ?Book
  {
    if ($loader = $this->getLoader()) {
      return $loader->each(function (Book $book) {
        $implements = class_implements($book);
        return isset($implements[LoggerInterface::class]);
      });
    }
    return null;
  }

  /**
   * Returns the logger.
   * @return Book
   */
  final protected function getLogger(): Book
  {
    return $this->logger;
  }
}
