<?php namespace engine\plugins\httpserver\includes\http;

include_once('ResponseInterface.inc');

/**
 * Class Response
 * @package engine\plugins\httpserver\includes\http
 */
final class Response implements ResponseInterface {
  /**
   * Contains headers.
   * @var HeadersInterface
   */
  protected $headers;
  /**
   * Contains code and description.
   * @var StatusInterface
   */
  protected $status;
  /**
   * Contains the content to send the response.
   * @var ContentInterface
   */
  private $content;

  /**
   * Response constructor.
   * @param Status $status
   */
  public function __construct(StatusInterface $status, HeadersInterface $headers, ContentInterface $content)
  {
    $this->status = $status;
    $this->headers = $headers;
    $this->content = $content;
  }

  /**
   * Returns the headers.
   * @return HeadersInterface
   */
  public function getHeaders(): HeadersInterface
  {
    return $this->headers;
  }

  /**
   * Returns a status.
   * @return StatusInterface
   */
  public function getStatus(): StatusInterface
  {
    return $this->status;
  }

  /**
   * Returns a list of strings to send content in the response.
   * @return ContentInterface
   */
  public function getContent(): ContentInterface
  {
    return $this->content;
  }
}
