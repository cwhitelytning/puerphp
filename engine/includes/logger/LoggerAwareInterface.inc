<?php namespace engine\includes\logger;

/**
 * Interface LoggerAwareInterface
 * @package engine\includes\logger
 */
interface LoggerAwareInterface
{
  /**
   * Sets a logger instance on the object.
   * @param LoggerInterface $logger
   * @return void
   */
  public function setLogger(LoggerInterface $logger): void;
}
