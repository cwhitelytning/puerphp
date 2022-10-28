<?php namespace core\src\module;

include_once('ModuleInfo.inc');
include_once('Environ.inc');

use core\src\loader\ModuleLoader;
use ReflectionClass;

/**
 * Class Module
 * @package core\src\module
 */
class Module
{
  /**
   * Contains the loader in which this module is located.
   * @var ModuleLoader|null
   */
  private ?ModuleLoader $loader;

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
    $this->environ = new Environ();
    $this->environ->append([
      # Path to the file of the current module.
      'file' => (new ReflectionClass($this))->getFileName(),
      # Directory where the current module is located.
      'dir' => ['{file}', '..'],
      # Directory of configuration files.
      'configs' => ['{dir}', 'configs']
    ]);

    $this->setLoader($loader);
  }

  /**
   * Returns information about the class by parsing annotations to it.
   * @return array
   */
  final protected function getInfo(): array
  {
    $attributes = (new ReflectionClass($this))->getAttributes(ModuleInfo::class);
    return $attributes ? $attributes[0]->getArguments() : [];
  }

  /**
   * Sets the loader in which this module is located.
   * Do not use this function.
   * @param ModuleLoader|null $loader
   */
  private function setLoader(?ModuleLoader $loader): void
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
   * Returns the module's environment variables.
   * @return Environ
   */
  final protected function getEnviron(): Environ
  {
    return $this->environ;
  }
}
