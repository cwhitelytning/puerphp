<?php namespace core\src\plugin;

include_once('logger/LoggerInterface.inc');
include_once('logger/LoggerLevels.inc');
include_once('logger/AbstractLogger.inc');
include_once('logger/NullLogger.inc');

use core\src\book\Book;
use core\src\loader\BookLoader;
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
   * @var LoggerInterface
   */
  private LoggerInterface $logger;

  /**
   * Plugin constructor.
   * @param BookLoader|null $loader
   */
  final public function __construct(?BookLoader $loader)
  {
    parent::__construct($loader);
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
        return $book instanceof LoggerInterface;
      });
    }
    return null;
  }

  /**
   * Returns the logger.
   * @return LoggerInterface
   */
  final protected function getLogger(): LoggerInterface
  {
    return $this->logger;
  }
}
