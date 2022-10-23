<?php namespace journalist\includes;

/**
 * Interface LoggerAwareInterface
 * @package journalist\includes
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
