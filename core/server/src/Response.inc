<?php namespace core\server\src;

/**
 * Class Response
 * @package core\server\src
 */
final class Response {
  /**
   * Contains headers.
   * @var Headers
   */
  protected Headers $headers;

  /**
   * Contains code and description.
   * @var Status
   */
  protected Status $status;

  /**
   * Contains the content to send the response.
   * @var Content
   */
  private Content $content;

  /**
   * Response constructor.
   * @param Status $status
   * @param Headers $headers
   * @param Content $content
   */
  public function __construct(Status $status, Headers $headers, Content $content)
  {
    $this->status = $status;
    $this->headers = $headers;
    $this->content = $content;
  }

  /**
   * Returns the headers.
   * @return Headers
   */
  public function getHeaders(): Headers
  {
    return $this->headers;
  }

  /**
   * Returns a status.
   * @return Status
   */
  public function getStatus(): Status
  {
    return $this->status;
  }

  /**
   * Returns a list of strings to send content in the response.
   * @return Content
   */
  public function getContent(): Content
  {
    return $this->content;
  }
}
