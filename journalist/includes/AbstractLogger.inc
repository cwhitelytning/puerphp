<?php namespace journalist\includes;

use engine\includes\logger\LoggerInterface;
use engine\includes\logger\LoggerLevels;
use engine\includes\Module;

/**
 * Class AbstractLogger
 * @package journalist\includes
 */
class AbstractLogger extends Module implements LoggerInterface
{
  /**
   * @inheritDoc
   * @param string $message
   * @param array $context
   */
  function emergency(string $message, array $context = [])
  {
    $this->log(LoggerLevels::EMERGENCY, $message, $context);
  }

  /**
   * @inheritDoc
   * @param string $message
   * @param array $context
   */
  function alert(string $message, array $context = [])
  {
    $this->log(LoggerLevels::ALERT, $message, $context);
  }

  /**
   * @inheritDoc
   * @param string $message
   * @param array $context
   */
  function critical(string $message, array $context = [])
  {
    $this->log(LoggerLevels::CRITICAL, $message, $context);
  }

  /**
   * @inheritDoc
   * @param string $message
   * @param array $context
   */
  function error(string $message, array $context = [])
  {
    $this->log(LoggerLevels::ERROR, $message, $context);
  }

  /**
   * @inheritDoc
   * @param string $message
   * @param array $context
   */
  function warning(string $message, array $context = [])
  {
    $this->log(LoggerLevels::WARNING, $message, $context);
  }

  /**
   * @inheritDoc
   * @param string $message
   * @param array $context
   */
  function notice(string $message, array $context = [])
  {
    $this->log(LoggerLevels::NOTICE, $message, $context);
  }

  /**
   * @inheritDoc
   * @param string $message
   * @param array $context
   */
  function info(string $message, array $context = [])
  {
    $this->log(LoggerLevels::INFO, $message, $context);
  }

  /**
   * @inheritDoc
   * @param string $message
   * @param array $context
   */
  function debug(string $message, array $context = [])
  {
    $this->log(LoggerLevels::DEBUG, $message, $context);
  }
}
