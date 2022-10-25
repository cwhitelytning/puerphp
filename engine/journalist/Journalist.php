<?php namespace engine\journalist;

use engine\includes\plugin\logger\AbstractLogger;
use engine\includes\plugin\logger\LoggerLevels;
use engine\includes\setti\ConfigFile;

/**
 * Class Journalist
 * @author Clay Whitelytning
 * @version 1.1.1
 * @description File Logger
 * @package engine\journalist
 */
final class Journalist extends AbstractLogger
{
  /**
   * Contains logging levels from the configuration file.
   * @var ConfigFile
   */
  private ConfigFile $levels;

  /**
   * Initializing the module.
   */
  public function onModuleInit(): void
  {
    $this->levels = $this->getLevelsConfig();
  }

  /**
   * Returns the configuration of the level.cfg file.
   * @return ConfigFile
   */
  protected function getLevelsConfig(): ConfigFile
  {
    $config = new ConfigFile($this->getEnviron()->format('{configs}', 'levels.setti'));

    $config->set('emergency', 1);
    $config->set('alert', 1);
    $config->set('critical', 1);
    $config->set('error', 1);
    $config->set('warning', 1);
    $config->set('notice', 0);
    $config->set('info', 0);
    $config->set('debug', 0);
    $config->generateOrExecute($this->getInfo());

    return $config;
  }

  /**
   * Writes a new message to the log.
   * @param int $level
   * @param string $message
   * @param array $context
   */
  protected function log(int $level, string $message, array $context = [])
  {
    $components[] = LoggerLevels::toString($level);
    if ($this->levels->get(strtolower($components[0]))) {
      # We add spaces to align the levels of different lengths.
      $components[] = str_repeat(' ', 10 - strlen($components[0]));
      $components[] = $message;

      $filename = $this->getEnviron()->format('{dir}', 'logs', 'L' . date('Ymd'));
      $this->logMessage($filename, implode("\t", $components), $context);
    }
  }

  /**
   * Logs a message to the specified file (include a timestamp with the message).
   * @param string $filename
   * @param string $message
   * @param array $context
   */
  protected function logMessage(string $filename, string $message, array $context = [])
  {
    @mkdir(dirname($filename), 0644, true);

    $timestamp = date('Y/m/d - H:i:s:');
    $message = $this->interpolate($message, $context);
    @file_put_contents("$filename.log", "$timestamp\t$message\n", FILE_APPEND);
  }

  /**
   * Interpolates context values into the message placeholders.
   * @param string $message
   * @param array $context
   * @return string
   */
  function interpolate(string $message, array $context = []): string
  {
    # build a replacement array with braces around the context keys
    $replace = [];
    foreach ($context as $key => $val) {
      # check that the value can be cast to string
      if (!is_array($val) && (!is_object($val) || method_exists($val, '__toString'))) {
        $replace['{' . $key . '}'] = $val;
      }
    }

    # interpolate replacement values into the message and return
    return strtr($message, $replace);
  }
}
