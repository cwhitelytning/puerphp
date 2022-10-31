<?php namespace core\src\library;

include_once('LibraryInfo.inc');
include_once('Environ.inc');

use core\src\loader\LibraryLoader;
use ReflectionClass;

/**
 * Class Library
 * @package core\src\library
 */
class Library
{
  /**
   * Contains the loader in which this library is located.
   * @var LibraryLoader|null
   */
  private ?LibraryLoader $loader;

  /**
   * Contains registered paths.
   * @var Environ
   */
  private Environ $environ;

  /**
   * Module constructor.
   * @param LibraryLoader|null $loader
   */
  final public function __construct(?LibraryLoader $loader)
  {
    $this->environ = (new Environ())->append([
      # Path to the file of the current module.
      'LIBRARY_FILE' => (new ReflectionClass($this))->getFileName(),
      # Directory where the current module is located.
      'LIBRARY_DIR' => ['{LIBRARY_FILE}', '..'],
      # Directory of configuration files.
      'CONFIGS_DIR' => ['{LIBRARY_DIR}', 'configs']
    ]);

    $this->setLoader($loader);
  }

  /**
   * Returns information about the class by parsing annotations to it.
   * @return array
   */
  final protected function getInfo(): array
  {
    $arguments = [];
    $reflection = new ReflectionClass($this);

    if ($attributes = $reflection->getAttributes(LibraryInfo::class)) {
      $arguments = $attributes[0]->getArguments();
      $arguments['name'] = $reflection->getShortName();
    }
    return $arguments;
  }

  /**
   * Sets the loader in which this module is located.
   * Do not use this function.
   * @param LibraryLoader|null $loader
   */
  private function setLoader(?LibraryLoader $loader): void
  {
    $this->loader = $loader;
  }

  /**
   * Returns the loader in which this module is located.
   * @return LibraryLoader|null
   */
  final protected function getLoader(): ?LibraryLoader
  {
    return $this->loader;
  }

  /**
   * Returns the module's environment variables.
   * @return Environ
   */
  final protected function getEnviron(): Environ
  {
    return $this->environ;
  }
}
