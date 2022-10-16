<?php namespace engine\plugins\httpserver;

include_once('includes/http/Headers.inc');
include_once('includes/http/Content.inc');
include_once('includes/http/Status.inc');
include_once('includes/http/Response.inc');

include_once('includes/designer/xml/XMLTag.inc');
include_once('includes/designer/html/HTMLTag.inc');
include_once('includes/designer/html/HTMLContent.inc');

include_once('includes/Listeners.inc');

use engine\includes\Plugin;
use engine\includes\PluginLoader;

use engine\plugins\httpserver\includes\http\Content;
use engine\plugins\httpserver\includes\http\Headers;
use engine\plugins\httpserver\includes\http\Response;
use engine\plugins\httpserver\includes\http\ResponseInterface;
use engine\plugins\httpserver\includes\http\Status;
use engine\plugins\httpserver\includes\Listeners;

/**
 * Class HTTPServer
 * @description Simple configurable server
 * @package engine\plugins\httpserver
 * @author Clay Whitelytning
 * @version 1.0.9
 */
final class HTTPServer extends PluginLoader
{
  /**
   * Contains registered pages.
   * @var Listeners
   */
  private $listeners;

  public function onPluginMain(): void
  {
    $uri = $_SERVER['REQUEST_URI'];
    $this->getLogger()->info('IP address "%0" requested the page (uri "%1")', [$_SERVER['REMOTE_ADDR'], $uri]);

    $url = $this->getRequestUrl();
    $response = new Response(new Status(Status::HTTP_NOT_FOUND), new Headers(), new Content());

    # We are looking for the requested page from the listener.
    $this->getLoader()->fetch(function(Plugin $plugin) use (&$response, &$url) {
      if ($this->listeners->contain($plugin->getClassInfo()->getName(), $url)) {
        if (method_exists($plugin, 'onRequest')) {
          return $plugin->onRequest($response);
        }
      }
      return self::PLUGIN_CONTINUE;
    });
    $this->sendResponse($response);
  }

  /**
   * Returns the requested URL path.
   * @return string
   */
  public function getRequestUrl(): string
  {
    return parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);
  }

  /**
   * Sends a response to a client request.
   * @param ResponseInterface $response
   * @return void
   */
  private function sendResponse(ResponseInterface $response): void
  {
    if ($this->assert(!headers_sent(), 'Headers have already been sent')) {
      $status = $response->getStatus();
      header(self::getProtocol() . ' ' . $status);

      if ($headers = $response->getHeaders()) {
        header_remove(); # remove all headers
        foreach ($headers->toStrings() as $string) header($string);
      }

      echo $response->getContent();
      $this->getLogger()->info('Response sent IP address "%0" (status "%1")', [$_SERVER['REMOTE_ADDR'], $status]);
    }
  }

  /**
   * Returns name and revision of the information protocol via which the page was requested.
   * @return string
   */
  static public function getProtocol(): string
  {
    return $_SERVER['SERVER_PROTOCOL'] ?? 'HTTP/1.0';
  }

  /**
   * Returns a Listeners class.
   * @return Listeners
   */
  public function getListeners(): Listeners
  {
    return $this->listeners;
  }

  /**
   * Initialization of the plugin.
   * @return void
   */
  protected function onPluginInit(): void
  {
    $this->listeners = new Listeners();
    parent::onPluginInit();
  }
}
