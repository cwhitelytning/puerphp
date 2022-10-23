<?php namespace journalist\includes;

use engine\includes\Module;

include_once('LoggerInterface.inc');
include_once('LoggerLevels.inc');

/**
 * Class AbstractLogger combines sending a message into one function.
 * @package journalist\includes
 */
abstract class AbstractLogger extends Module implements LoggerInterface
{
  /**
   * Writes a message to the log with the emergency level.
   * @param string $message
   * @param array $context
   */
  final public function emergency(string $message, array $context = []): void
  {
    $this->log(LoggerLevels::EMERGENCY, $message, $context);
  }

  /**
   * Writes a message to the log with the alert level.
   * @param string $message
   * @param array $context
   */
  final public function alert(string $message, array $context = []): void
  {
    $this->log(LoggerLevels::ALERT, $message, $context);
  }

  /**
   * Writes a message to the log with the critical level.
   * @param string $message
   * @param array $context
   */
  final public function critical(string $message, array $context = []): void
  {
    $this->log(LoggerLevels::CRITICAL, $message, $context);
  }

  /**
   * Writes a message to the log with the error level.
   * @param string $message
   * @param array $context
   */
  final function error(string $message, array $context = []): void
  {
    $this->log(LoggerLevels::ERROR, $message, $context);
  }

  /**
   * @param string $message
   * @param array $context
   */
  final public function warning(string $message, array $context = []): void
  {
    $this->log(LoggerLevels::WARNING, $message, $context);
  }

  /**
   * Writes a message to the log with the notice level.
   * @param string $message
   * @param array $context
   */
  final public function notice(string $message, array $context = []): void
  {
    $this->log(LoggerLevels::NOTICE, $message, $context);
  }

  /**
   * Writes a message to the log with the info level.
   * @param string $message
   * @param array $context
   */
  final public function info(string $message, array $context = []): void
  {
    $this->log(LoggerLevels::INFO, $message, $context);
  }

  /**
   * Writes a message to the log with the debug level.
   * @param string $message
   * @param array $context
   */
  final function debug(string $message, array $context = []): void
  {
    $this->log(LoggerLevels::DEBUG, $message, $context);
  }
}