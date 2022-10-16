<?php namespace engine\includes\annex;

include_once('ClassInfo.inc');

/**
 * Class Annex
 * @package engine\includes\annex
 */
class Annex
{
  /**
   * Returns information about class.
   * @return ClassInfo
   */
  public function getClassInfo(): ClassInfo
  {
    return new ClassInfo($this);
  }
}
