<?php namespace engine\includes\plugin\logger;

include_once('AbstractLogger.inc');

/**
 * Class NullLogger
 * This Logger can be used to avoid conditional log calls.
 * Logging should always be optional, and if no logger is provided to your
 * setti creating a NullLogger instance to have something to throw logs at
 * is a good way to avoid littering your code with `if ($this->logger) { }`
 * blocks.
 * @package jengine\includes\plugin\logger
 */
final class NullLogger extends AbstractLogger
{
  /**
   * Logs with an arbitrary level.
   * @param int $level
   * @param string $message
   * @param array $context
   * @return void
   */
  public function log(int $level, string $message, array $context = []): void
  {
  }
}
