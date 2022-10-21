<?php namespace engine\includes;

include_once('logger/LoggerAwareInterface.inc');
include_once('logger/NullLogger.inc');
include_once('ModuleInfo.inc');
include_once('Paths.inc');

use engine\includes\loader\ModuleLoader;
use engine\includes\logger\LoggerAwareInterface;
use engine\includes\logger\LoggerInterface;
use engine\includes\logger\NullLogger;

/**
 * Class Module
 * @package engine\includes
 */
class Module implements LoggerAwareInterface
{
  /**
   * Contains the loader in which this module is located.
   * @var ModuleLoader|null
   */
  private ?ModuleLoader $loader;

  /**
   * Contains a logger.
   * @var LoggerInterface
   */
  private LoggerInterface $logger;

  /**
   * Contains registered paths.
   * @var Paths
   */
  private Paths $paths;

  /**
   * Module constructor.
   * @param ModuleLoader|null $loader
   * @param LoggerInterface|null $logger
   */
  final public function __construct(?ModuleLoader $loader, ?LoggerInterface $logger = null)
  {
    $this->paths = new Paths();
    # Path to the file of the current module.
    $this->paths->set('file', $this->getInfo()->getFilename());
    # Directory where the current module is located.
    $this->paths->set('dir', '{file}', '..');
    # Root directory is everything above the directory in which it is located.
    $this->paths->set('root', '{dir}', '..');
    # Directory of configuration files.
    $this->paths->set('configs', '{dir}', 'configs');

    $this->setLoader($loader);
    $this->setLogger($logger);
  }

  /**
   * Sets the loader in which this module is located.
   * Do not use this function.
   * @param ModuleLoader|null $loader
   */
  final private function setLoader(?ModuleLoader $loader): void
  {
    $this->loader = $loader;
  }

  /**
   * Returns the loader in which this module is located.
   * @return ModuleLoader|null
   */
  final public function getLoader(): ?ModuleLoader
  {
    return $this->loader;
  }

  /**
   * Returns information about the class by parsing annotations to it.
   * @return ModuleInfo
   */
  final protected function getInfo(): ModuleInfo
  {
    return new ModuleInfo($this);
  }

  /**
   * Returns registered paths.
   * @return Paths
   */
  final protected function getPaths(): Paths
  {
    return $this->paths;
  }

  /**
   * Returns logger.
   * @return LoggerInterface
   */
  final protected function getLogger(): LoggerInterface
  {
    return $this->logger;
  }

  /**
   * Sets a new logger or by default.
   * @param LoggerInterface|null $logger
   */
  public function setLogger(LoggerInterface $logger = null): void
  {
    $this->logger = $logger ?? new NullLogger();
  }
}
