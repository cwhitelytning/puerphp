<?php namespace engine\includes\annex;

include_once('AnnexInterface.inc');
include_once('ClassInfo.inc');

/**
 * Class Annex
 * @package engine\includes\annex
 */
class Annex implements AnnexInterface
{
  /**
   * Returns information about class.
   * @return ClassInfo
   */
  function getClassInfo(): ClassInfo
  {
    return new ClassInfo($this);
  }
}
