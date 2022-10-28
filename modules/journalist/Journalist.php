<?php namespace modules\journalist;

use core\src\module\ModuleInfo;
use core\src\plugin\logger\AbstractLogger;

#[
  ModuleInfo
  (
    name: 'Journalist',
    author: 'Clay Whitelytning',
    version: '1.1.3',
    description: 'File Logger'
  )
]
final class Journalist extends AbstractLogger
{
  /**
   * Contains level names and a boolean value.
   * @var array
   */
  private array $levels;

  /**
   * Initializing the module.
   */
  public function onModuleInit(): void
  {
    $env = $this->getEnviron();
    if ($levels = @simplexml_load_file($env->format('{configs}', 'levels.xml'))) {
      foreach ($levels as $level) {
        $key = strtoupper((string)$level['name']);
        $this->levels[$key] = filter_var((string)$level['enabled'], FILTER_VALIDATE_BOOLEAN);
      }
    }
  }

  /**
   * Writes a new message to the log.
   * @param string $level
   * @param string $message
   * @param array $context
   */
  protected function log(string $level, string $message, array $context = [])
  {
    if ($this->levels[$level]) {
      $components[] = $level;
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
