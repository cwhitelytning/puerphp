<?php namespace core\src\plugin\logger;

use ReflectionClass;

/**
 * Class LoggerLevels
 * @package core\src\plugin\logger
 */
final class LoggerLevels {
  const EMERGENCY = 'EMERGENCY';
  const ALERT     = 'ALERT';
  const CRITICAL  = 'CRITICAL';
  const ERROR     = 'ERROR';
  const WARNING   = 'WARNING';
  const NOTICE    = 'NOTICE';
  const INFO      = 'INFO';
  const DEBUG     = 'DEBUG';
}