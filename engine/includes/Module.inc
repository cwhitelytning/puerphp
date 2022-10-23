<?php namespace engine\includes;

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
class Module
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
   */
  final public function __construct(?ModuleLoader $loader)
  {
    $this->environ = new Environ([
      # Path to the file of the current module.
      'file' => $this->getInfo()->getFilename(),
      # Directory where the current module is located.
      'dir' => ['{file}', '..'],
      # Root directory is everything above the directory in which it is located.
      'root' => ['{dir}', '..'],
      # Directory of configuration files.
      'configs' => ['{dir}', 'configs']
    ]);

    $this->setLoader($loader);
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
  final protected function getLoader(): ?ModuleLoader
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
}
