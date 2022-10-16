<?php namespace engine\plugins\server\includes;

/**
 * Interface ContentInterface
 * @package engine\plugins\httpserver\includes\http
 */
interface ContentInterface
{
  /**
   * Returns a string.
   * @return string
   */
  function __toString(): string;
}
