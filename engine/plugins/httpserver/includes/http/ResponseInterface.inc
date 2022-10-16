<?php namespace engine\plugins\httpserver\includes\http;

include_once('StatusInterface.inc');
include_once('HeadersInterface.inc');
include_once('ContentInterface.inc');

/**
 * Interface ResponseInterface
 * @package engine\plugins\httpserver\includes\http
 */
interface ResponseInterface
{
  /**
   * Returns a list of headers.
   * @return HeadersInterface|null
   */
  function getHeaders(): HeadersInterface;
  /**
   * Returns the status.
   * @return StatusInterface
   */
  function getStatus(): StatusInterface;
  /**
   * Returns content.
   * @return ContentInterface|null
   */
  function getContent(): ContentInterface;
}