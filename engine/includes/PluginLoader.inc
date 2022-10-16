<?php namespace engine\includes;

use engine\includes\annex\AnnexLoader;
use engine\includes\annex\exceptions\AnnexException;
use engine\includes\library\ConfigFile;

include_once('annex/AnnexLoader.inc');
include_once('library/ConfigFile.inc');
include_once('Plugin.inc');

/**
 * Class PluginLoader
 * @package engine\includes
 */
class PluginLoader extends Plugin
{
  /**
   * Contains the Annex loader.
   * @var AnnexLoader
   */
  private $loader;

  /**
   * Initialization of the plugin.
   */
  protected function onPluginInit(): void
  {
    $this->getPaths()->register('plugins', '%dir%', 'plugins');
    $this->loader = new AnnexLoader($this->getClassInfo()->getPackage() . '\plugins', Plugin::class);
    # ----------------------------------------------------------------------------------------------------------------
    $filename = $this->getPaths()->collect('%configs%', 'plugins.ini');
    $this->getLogger()->debug('Begin reading plugins list (filepath "%0")', [$filename]);

    $count = $this->multiple(ConfigFile::parseFile($filename), $this->loader, [$this]);
    $this->getLogger()->debug("Finished reading plugins list (loaded $count plugins)");
    # ----------------------------------------------------------------------------------------------------------------
    $this->loader->fetch(function (Plugin $plugin) { $plugin->onPluginInit(); return self::PLUGIN_CONTINUE; });
  }

  /**
   * Loads multiple Annexes from the list.
   * @param array $names
   * @param AnnexLoader $loader
   * @param array $args
   * @return int number of loaded Annexes
   */
  final protected function multiple(array $names, AnnexLoader $loader, array $args = []): int
  {
    $count = count($names);
    $classname = pathinfo($loader->getClasspath(), PATHINFO_FILENAME);

    foreach ($names as $name) {
      $this->getLogger()->debug("$classname loading (name \"$name\")");
      try {
        $annex = $loader->load($name, ...$args);
        $this->getLogger()->info("$classname loaded: %name - %description (version \"%version\") by %author",
          $annex->getClassInfo()->getShortInfo()
        );
      } catch (AnnexException $exception) {
        $count--;
        $this->getLogger()->error($exception);
      }
    }
    return $count;
  }

  /**
   * Returns the Annex loader.
   * @return AnnexLoader
   */
  final protected function getLoader(): AnnexLoader
  {
    return $this->loader;
  }

  /**
   * Unloading all loaded plugins.
   * @return void
   */
  protected function onPluginEnd(): void
  {
    $this->loader->fetch(function (Plugin $plugin) {
      $name = $plugin->getClassInfo()->getName();

      $plugin->onPluginEnd();
      $this->loader->unload($name);

      $this->getLogger()->debug('Plugin unloaded (plugin "%0")', [$name]);
      return self::PLUGIN_CONTINUE;
    });
  }
}
