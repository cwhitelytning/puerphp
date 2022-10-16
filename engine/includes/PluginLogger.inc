<?php namespace engine\includes;

include_once('logger/AbstractLogger.inc');
use engine\includes\logger\LoggerLevels;

/**
 * Class Logger
 * @package engine\includes
 */
final class PluginLogger extends AbstractLogger
{
  /**
   * Contains a plugin.
   * @var Plugin
   */
  private $plugin;

  /**
   * Used to write logs.
   * @var string
   */
  private $directory;

  /**
   * Logger constructor.
   * @param Plugin $plugin
   * @param string $directory
   */
  function __construct(Plugin $plugin, string $directory)
  {
    $this->plugin = $plugin;
    $this->directory = $directory;
  }

  /**
   * Returns the directory set for logging.
   * @return string
   */
  public function getDirectory(): string
  {
    return $this->directory;
  }

  /**
   * Writes a new message to the log.
   * @param int $level
   * @param string $message
   * @param array $args
   */
  protected function log(int $level, string $message, array $args = [])
  {
    # The journal is maintained only by the loader, plugins only send him a message.
    $message = '[' . $this->plugin->getClassInfo()->getName() . '] ' . $message;
    if ($loader = $this->plugin->getOwner()) {
      $loader->getLogger()->log($level, $message, $args);
    } else {
      $components[] = LoggerLevels::toString($level);
      $components[] = str_repeat(' ', 10 - strlen($components[0]));
      $components[] = $message;
      $this->logMessage('L' . date('Ymd'), implode(' ', $components), $args);
    }
  }

  /**
   * Logs a message to the specified file (include a timestamp with the message).
   * @param string $filename
   * @param string $message
   * @param array $args
   */
  protected function logMessage(string $filename, string $message, array $args = [])
  {
    @mkdir($this->directory, 0644, true);

    $filepath = $this->directory . DIRECTORY_SEPARATOR . "$filename.log";
    $timestamp = date('Y/m/d - H:i:s');

    foreach ($args as $key => $value) { $message = str_replace("%$key", $value, $message); }
    @file_put_contents($filepath, "$timestamp\t$message\n", FILE_APPEND);
  }
}
