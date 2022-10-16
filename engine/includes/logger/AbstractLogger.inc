<?php namespace engine\includes;

include_once('LoggerInterface.inc');
include_once('LoggerLevels.inc');

use engine\includes\logger\LoggerInterface;
use engine\includes\logger\LoggerLevels;

/**
 * Class AbstractLogger combines sending a message into one function.
 * @package engine\includes
 */
abstract class AbstractLogger implements LoggerInterface
{
  /**
   * Writes a message to the log with the emergency level.
   * @param string $message
   * @param array $args
   */
  final public function emergency(string $message, array $args = []): void
  {
    $this->log(LoggerLevels::EMERGENCY, $message, $args);
  }

  /**
   * Writes a message to the log with the alert level.
   * @param string $message
   * @param array $args
   */
  final public function alert(string $message, array $args = []): void
  {
    $this->log(LoggerLevels::ALERT, $message, $args);
  }

  /**
   * Writes a message to the log with the critical level.
   * @param string $message
   * @param array $args
   */
  final public function critical(string $message, array $args = []): void
  {
    $this->log(LoggerLevels::CRITICAL, $message, $args);
  }

  /**
   * Writes a message to the log with the error level.
   * @param string $message
   * @param array $args
   */
  final function error(string $message, array $args = []): void
  {
    $this->log(LoggerLevels::ERROR, $message, $args);
  }

  /**
   * @param string $message
   * @param array $args
   */
  final public function warning(string $message, array $args = []): void
  {
    $this->log(LoggerLevels::WARNING, $message, $args);
  }

  /**
   * Writes a message to the log with the notice level.
   * @param string $message
   * @param array $args
   */
  final public function notice(string $message, array $args = []): void
  {
    $this->log(LoggerLevels::NOTICE, $message, $args);
  }

  /**
   * Writes a message to the log with the info level.
   * @param string $message
   * @param array $args
   */
  final public function info(string $message, array $args = []): void
  {
    $this->log(LoggerLevels::INFO, $message, $args);
  }

  /**
   * Writes a message to the log with the debug level.
   * @param string $message
   * @param array $args
   */
  final function debug(string $message, array $args = []): void
  {
    $this->log(LoggerLevels::DEBUG, $message, $args);
  }
}