<?php namespace engine\plugins\httpserver\includes\http;

/**
 * Interface StatusInterface
 * @package engine\plugins\httpserver\includes\http
 */
interface StatusInterface
{
  /**
   * Returns the status code.
   * @return int
   */
  function getCode(): int;

  /**
   * Sets a new status code.
   * @param int $code
   * @return void
   */
  function setCode(int $code);

  /**
   * Returns a description of the status code.
   * @return string
   */
  function getDescription(): string;

  /**
   * Returns a string.
   * @return string
   */
  function __toString(): string;
}
