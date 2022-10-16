<?php namespace engine\includes;

include_once('logger/LoggerAwareInterface.inc');
include_once('logger/LoggerInterface.inc');
include_once('annex/Annex.inc');

include_once('PluginLogger.inc');
include_once('PluginPaths.inc');

use engine\includes\annex\Annex;
use engine\includes\logger\LoggerInterface;
use ReflectionClass;

/**
 * Class Plugin
 * @package engine\includes
 */
class Plugin extends Annex
{
  /**
   * Plugin continues to work.
   */
  const PLUGIN_CONTINUE = 0;

  /**
   * Plugin stops the operation and the plugins
   * following below in plugins.ini will not be called.
   */
  const PLUGIN_HANDLED = 1;

  /**
   * Contains the loader.
   * @var PluginLoader|null
   */
  private $owner;

  /**
   * Contains a logger.
   * @var LoggerInterface
   */
  private $logger;

  /**
   * Contains local paths.
   * @var PluginPaths
   */
  private $paths;

  /**
   * Plugin constructor.
   * @param PluginLoader|null $owner
   * @param LoggerInterface|null $logger
   */
  public function __construct(PluginLoader $owner = null, LoggerInterface $logger = null)
  {
    $this->paths = new PluginPaths();
    # Preset local paths:
    $this->paths->register('file', (new ReflectionClass($this))->getFileName());
    $this->paths->register('dir', dirname($this->paths->get('file')));
    $this->paths->register('logs', '%dir%', 'logs');
    $this->paths->register('configs', '%dir%', 'configs');
    $this->paths->register('data', '%dir%', 'data');

    $this->owner = $owner;
    $this->setLogger($logger);
  }

  /**
   * Returns the hash of the plugin.
   * @return string
   */
  public function getClassHash(): string
  {
    return spl_object_hash($this);
  }

  /**
   * Returns the preset paths of the plugin.
   * @return PluginPaths
   */
  public function getPaths(): PluginPaths
  {
    return $this->paths;
  }

  /**
   * Returns the owner.
   * @return PluginLoader|null
   */
  public function getOwner(): ?PluginLoader
  {
    return $this->owner;
  }

  /**
   * Allows you to conveniently record an error if the condition does not match the statement.
   * Returns the value of the condition.
   * @param bool $condition
   * @param string $error
   * @param array $args
   * @return bool
   */
  final protected function assert(bool $condition, string $error, array $args = []): bool
  {
    if (!$condition) $this->getLogger()->error($error, $args);
    return $condition;
  }

  /**
   * Returns the logger.
   * @return LoggerInterface
   */
  public function getLogger(): LoggerInterface
  {
    return $this->logger;
  }

  /**
   * Sets a logger instance on the object.
   * @param LoggerInterface|null $logger
   * @return void
   */
  public function setLogger(LoggerInterface $logger = null): void
  {
    $this->logger = $logger ?? new PluginLogger($this, $this->getPaths()->get('logs'));
  }

  /**
   * Initialization of the plugin.
   * @return void
   */
  protected function onPluginInit(): void
  {
  }

  /**
   * Calls when unloading the plugin.
   * @return void
   */
  protected function onPluginEnd(): void
  {
  }
}