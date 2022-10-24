<?php namespace engine\includes\plugin;

include_once('logger/LoggerInterface.inc');
include_once('logger/LoggerLevels.inc');
include_once('logger/AbstractLogger.inc');
include_once('logger/NullLogger.inc');

use engine\includes\module\Module;
use engine\includes\plugin\logger\LoggerInterface;
use engine\includes\plugin\logger\NullLogger;

class Plugin extends Module
{
  /**
   * @var Module
   */
  private Module $logger;

  /**
   * Plugin initializing.
   */
  public function onModuleInit()
  {
    $this->logger = $this->findLogger() ?? new NullLogger(null);
  }

  /**
   * Searches for a module implementing the Logger Interface.
   * If successful, returns the first found module.
   * @return Module|null
   */
  private function findLogger(): ?Module
  {
    if ($loader = $this->getLoader()) {
      return $loader->fetch(function (Module $module) {
        $implements = class_implements($module);
        return isset($implements[LoggerInterface::class]);
      });
    }
    return null;
  }

  /**
   * Returns the logger.
   * @return Module
   */
  final protected function getLogger(): Module
  {
    return $this->logger;
  }
}
