<?php namespace core\src\plugin;

include_once('logger/LoggerInterface.inc');
include_once('logger/LoggerLevels.inc');
include_once('logger/AbstractLogger.inc');
include_once('logger/NullLogger.inc');

use core\src\library\Library;
use core\src\plugin\logger\LoggerInterface;
use core\src\plugin\logger\NullLogger;

/**
 * Class Plugin
 * @package core\src\plugin
 */
class Plugin extends Library
{
  /**
   * Contains logger.
   * @var Library
   */
  private Library $logger;

  /**
   * Plugin initializing.
   */
  public function initialization()
  {
    $this->logger = $this->findLogger() ?? new NullLogger(null);
  }

  /**
   * Searches for a module implementing the Logger Interface.
   * If successful, returns the first found module.
   * @return Library|null
   */
  private function findLogger(): ?Library
  {
    if ($loader = $this->getLoader()) {
      return $loader->each(function (Library $library) {
        $implements = class_implements($library);
        return isset($implements[LoggerInterface::class]);
      });
    }
    return null;
  }

  /**
   * Returns the logger.
   * @return Library
   */
  final protected function getLogger(): Library
  {
    return $this->logger;
  }
}
