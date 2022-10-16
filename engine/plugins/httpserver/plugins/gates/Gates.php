<?php namespace engine\plugins\httpserver\plugins\gates;

use engine\includes\library\ConfigFile;
use engine\includes\Plugin;
use engine\plugins\httpserver\HTTPServer;
use engine\plugins\httpserver\includes\http\ResponseInterface;
use engine\plugins\httpserver\includes\http\Status;

/**
 * Class Gates
 * @description IP Filter
 * @author Clay Whitelytning
 * @version 1.0.7
 */
final class Gates extends Plugin
{
  /**
   * @var array
   */
  private $access = [];

  /**
   * Called when a page is requested.
   * @param ResponseInterface $response
   * @return int
   */
  public function onRequest(ResponseInterface $response): int
  {
    $mode = array_key_first($this->access);
    if ($this->assert($mode == 'allow' || $mode == 'deny', 'Invalid mode (mode "%0")', [$mode])) {
      $exists = false;
      $address = $_SERVER['REMOTE_ADDR'];

      foreach ($this->access[$mode] as $value) {
        if ($exists = strpos($address, $value) === 0) break;
      }

      if (($exists && $mode == 'deny') || (!$exists && $mode == 'allow')) {
        $this->getLogger()->info('IP address "%0" is denied', [$address]);
        $response->getStatus()->setCode(Status::HTTP_FORBIDDEN);
      } else {
        $this->getLogger()->info('IP address "%0" is allowed', [$address]);
      }
    }
    return self::PLUGIN_CONTINUE;
  }

  /**
   * Plugin initialization.
   * @return void
   */
  public function onPluginInit(): void
  {
    $this->access = ConfigFile::parseFile($this->getPaths()->collect('%configs%', 'access.cfg'));
    if ($this->assert((bool)$this->access, 'No selected mode, please check access.cfg file')) {
      if ($owner = $this->getOwner()) {
        if ($owner instanceof HTTPServer) {
          $owner->getListeners()->set($this, '*');
        }
      }
    }
  }
}
