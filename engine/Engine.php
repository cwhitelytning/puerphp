<?php namespace engine;

include_once('includes/PluginLoader.inc');

use engine\includes\PluginLoader;
use engine\includes\Plugin;

/**
 * Class Engine
 * @package engine
 * @description Engine plugin loader
 * @author Clay Whitelytning
 * @version 1.0.9
 */
final class Engine extends PluginLoader
{
  /**
   * Creates a new instance of the engine and simulates life cycle work.
   * @param array $args
   */
  public static function run(array $args = [])
  {
    $engine = new Engine();
    # -----------------------------------------------------------------------------------------------------------------
    $engine->getLogger()->info('-------- Log file opened --------');
    $engine->onPluginInit();
    # -----------------------------------------------------------------------------------------------------------------
    $engine->getLoader()->fetch(function (Plugin $plugin) use (&$engine, &$args) {
      if (method_exists($plugin, 'onPluginMain')) {
        $plugin->onPluginMain(...$args);
      }
      return self::PLUGIN_CONTINUE;
    });
    # -----------------------------------------------------------------------------------------------------------------
    $engine->onPluginEnd();
    $engine->getLogger()->info('-------- Log file closed --------');
    # -----------------------------------------------------------------------------------------------------------------
    $engine = null;
  }
}
