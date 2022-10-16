<?php namespace engine\plugins\server;

include_once('includes/Headers.inc');
include_once('includes/Methods.inc');
include_once('includes/Content.inc');
include_once('includes/Status.inc');
include_once('includes/Response.inc');

use engine\includes\Plugin;
use engine\plugins\server\includes\Content;
use engine\plugins\server\includes\Headers;
use engine\plugins\server\includes\Response;
use engine\plugins\server\includes\Status;

/**
 * Class Server
 * @description Simple non-configurable server
 * @author Clay Whitelytning
 * @version 1.0.9
 * @package engine\plugins\server
 */
class Server extends Plugin
{
  /**
   * Contains the response.
   * @var Response
   */
  protected $response;

  /**
   * Returns a response.
   * @return Response
   */
  public function getResponse(): Response
  {
    return $this->response;
  }

  /**
   * Initialization of the plugin.
   */
  protected function onPluginInit(): void
  {
    $this->response = new Response(new Status(Status::HTTP_NOT_FOUND), new Headers(), new Content());
  }

  /**
   * Sends a response to a client request.
   */
  protected function onPluginEnd(): void
  {
    # Global array may not be available if it is located under the console interface.
    if (isset($_SERVER['REQUEST_URI'], $_SERVER['REMOTE_ADDR'], $_SERVER['REMOTE_PORT'], $_SERVER['REQUEST_METHOD'])) {
      $this->getLogger()->debug('Sending a response to a request ("%REMOTE_ADDR:%REMOTE_PORT", "%REQUEST_METHOD", "%REQUEST_URI")', $_SERVER);
    }

    http_response_code($status = $this->response->getStatus()->getCode());
    if ($headers = $this->response->getHeaders()->toStrings()) {
      foreach ($headers as $header) header($header);
    }
    echo $this->response->getContent();
    $this->getLogger()->debug('Response has been sent (status "%0")', [$status]);
  }
}