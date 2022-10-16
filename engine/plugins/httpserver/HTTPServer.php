<?php namespace engine\plugins\httpserver;

include_once('includes/http/Headers.inc');
include_once('includes/http/Content.inc');
include_once('includes/http/Status.inc');
include_once('includes/http/Response.inc');

include_once('includes/Listeners.inc');
include_once('includes/Package.inc');

use engine\includes\annex\AnnexLoader;
use engine\includes\Plugin;
use engine\includes\PluginLoader;

use engine\includes\library\ConfigFile;
use engine\plugins\httpserver\includes\http\Content;
use engine\plugins\httpserver\includes\http\Headers;
use engine\plugins\httpserver\includes\http\Response;
use engine\plugins\httpserver\includes\http\ResponseInterface;
use engine\plugins\httpserver\includes\http\Status;
use engine\plugins\httpserver\includes\Listeners;
use engine\plugins\httpserver\includes\Package;

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
   * Contains a package loader.
   * @var AnnexLoader
   */
  private $packages;

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
  static function getProtocol(): string
  {
    return $_SERVER['SERVER_PROTOCOL'] ?? 'HTTP/1.0';
  }

  /**
   * @return Listeners
   */
  public function getListeners(): Listeners
  {
    return $this->listeners;
  }

  /**
   * Returns the package loader.
   * @return AnnexLoader
   */
  protected function getPackages(): AnnexLoader
  {
    return $this->packages;
  }

  /**
   * Initialization of the plugin.
   * @return void
   */
  protected function onPluginInit(): void
  {
    $this->listeners = new Listeners();
    $this->loadPackages();
    parent::onPluginInit();
  }

  /**
   * Loads packages.
   */
  protected function loadPackages()
  {
    $this->getPaths()->register('packages', '%dir%', 'packages');
    $this->packages = new AnnexLoader($this->getClassInfo()->getPackage() . '\packages', Package::class);
    # ----------------------------------------------------------------------------------------------------------------
    $filename = $this->getPaths()->collect('%configs%', 'packages.ini');
    $this->getLogger()->debug('Begin reading packages list (filepath "%0")', [$filename]);

    $count = $this->multiple(ConfigFile::parseFile($filename), $this->packages);
    $this->getLogger()->debug("Finished reading packages list (loaded $count packages)");
  }
}
