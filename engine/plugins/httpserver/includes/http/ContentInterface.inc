<?php namespace engine\plugins\httpserver\includes\http;

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
