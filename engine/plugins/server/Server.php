<?php namespace engine\plugins\server;

include_once('includes/Headers.inc');
include_once('includes/Methods.inc');
include_once('includes/Content.inc');
include_once('includes/Status.inc');
include_once('includes/Response.inc');

use engine\includes\Plugin;
use engine\includes\PluginLoader;
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
    http_response_code($this->response->getStatus()->getCode());
    if ($headers = $this->response->getHeaders()->toStrings()) {
      foreach ($headers as $header) header($header);
    }
    echo $this->response->getContent();
  }
}