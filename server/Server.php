<?php namespace server;

include_once('includes/Status.inc');
include_once('includes/Headers.inc');
include_once('includes/Methods.inc');
include_once('includes/Content.inc');
include_once('includes/Response.inc');

use engine\includes\module\Module;
use server\includes\Content;
use server\includes\Headers;
use server\includes\Response;
use server\includes\Status;

/**
 * Class Server
 * @description Simple non-configurable server
 * @author Clay Whitelytning
 * @version 1.1.1
 * @package server
 */
class Server extends Module
{
  /**
   * Contains a response generated by other modules.
   * @var Response
   */
  private Response $response;

  /**
   * Server initialization.
   * @return void
   */
  public function onModuleInit(): void
  {
    $this->response = new Response(new Status(Status::HTTP_NOT_FOUND), new Headers(), new Content());
  }

  /**
   * Unloading the server.
   * @return void
   */
  public function onModuleEnd(): void
  {
    http_response_code($this->response->getStatus()->getCode());
    if ($headers = $this->response->getHeaders()->toStrings()) {
      foreach ($headers as $header) header($header);
    }
    echo $this->response->getContent();
  }
}