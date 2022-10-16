<?php namespace engine\includes\annex;

/**
 * Interface AnnexInterface
 * @package engine\includes\annex
 */
interface AnnexInterface
{
  /**
   * Returns information about class.
   * @return ClassInfo
   */
  function getClassInfo(): ClassInfo;
}
