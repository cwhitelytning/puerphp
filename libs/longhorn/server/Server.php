<?php namespace libs\longhorn\server;

include_once('src/Status.inc');
include_once('src/Headers.inc');
include_once('src/Methods.inc');
include_once('src/Content.inc');
include_once('src/Response.inc');

use core\src\library\Library;
use core\src\library\LibraryInfo;
use libs\longhorn\server\src\Content;
use libs\longhorn\server\src\Headers;
use libs\longhorn\server\src\Response;
use libs\longhorn\server\src\Status;

#[LibraryInfo('Clay Whitelytning', '1.1.3', 'Simple non-configurable server')]
class Server extends Library
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
  public function initialization(): void
  {
    $this->response = new Response(new Status(Status::HTTP_NOT_FOUND), new Headers(), new Content());
  }

  /**
   * Unloading the server.
   * @return void
   */
  public function finalization(): void
  {
    http_response_code($this->response->getStatus()->getCode());
    if ($headers = $this->response->getHeaders()->toStrings()) {
      foreach ($headers as $header) header($header);
    }
    echo $this->response->getContent();
  }
}