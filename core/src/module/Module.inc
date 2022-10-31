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
      'MODULE_FILE' => (new ReflectionClass($this))->getFileName(),
      # Directory where the current module is located.
      'MODULE_DIR' => ['{MODULE_FILE}', '..'],
      # Directory of configuration files.
      'CONFIGS_DIR' => ['{MODULE_DIR}', 'configs']
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

    if ($attributes = $reflection->getAttributes(ModuleInfo::class)) {
      $arguments = $attributes[0]->getArguments();
      $arguments['name'] = $reflection->getShortName();
    }
    return $arguments;
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
