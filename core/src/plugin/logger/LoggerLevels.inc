<?php namespace core\src\plugin\logger;

use ReflectionClass;

/**
 * Class LoggerLevels
 * @package core\src\plugin\logger
 */
final class LoggerLevels {
  const EMERGENCY = 1 << 0;
  const ALERT     = 1 << 1;
  const CRITICAL  = 1 << 2;
  const ERROR     = 1 << 3;
  const WARNING   = 1 << 4;
  const NOTICE    = 1 << 5;
  const INFO      = 1 << 6;
  const DEBUG     = 1 << 7;

  /**
   * Returns a constant as a string from a number.
   * @param int $level
   * @return string
   */
  public static function toString(int $level): string
  {
    $reflection = new ReflectionClass(new LoggerLevels());
    $constants = $reflection->getConstants();
    return (string)array_search($level, $constants);
  }
}