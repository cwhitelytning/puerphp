<?php namespace engine\includes;

include_once('logger/LoggerAwareInterface.inc');
include_once('logger/NullLogger.inc');
include_once('ModuleInfo.inc');
include_once('Environ.inc');

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
   * @var Environ
   */
  private Environ $environ;

  /**
   * Module constructor.
   * @param ModuleLoader|null $loader
   * @param LoggerInterface|null $logger
   */
  final public function __construct(?ModuleLoader $loader, ?LoggerInterface $logger = null)
  {
    $this->environ = new Environ();
    # Path to the file of the current module.
    $this->environ->set('file', $this->getInfo()->getFilename());
    # Directory where the current module is located.
    $this->environ->set('dir', '{file}', '..');
    # Root directory is everything above the directory in which it is located.
    $this->environ->set('root', '{dir}', '..');
    # Directory of configuration files.
    $this->environ->set('configs', '{dir}', 'configs');

    $this->setLoader($loader);
    $this->setLogger($logger);
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
   * Returns registered paths.
   * @return Environ
   */
  final protected function getEnviron(): Environ
  {
    return $this->environ;
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
