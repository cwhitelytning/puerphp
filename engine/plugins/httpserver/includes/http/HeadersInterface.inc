<?php namespace engine\plugins\httpserver\includes\http;

/**
 * Interface HeadersInterface
 * @package engine\plugins\httpserver\includes\http
 */
interface HeadersInterface
{
  /**
   * Returns strings.
   * @return String[]
   */
  function toStrings(): array;
}
