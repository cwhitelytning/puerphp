<?php namespace engine\plugins\httpserver\includes;

use engine\includes\logger\LoggerInterface;
use engine\includes\Plugin;

/**
 * Class Listeners
 * @package engine\plugins\httpserver\includes
 */
final class Listeners
{
  /**
   * Contains listened pages.
   * @var array
   */
  private $listeners = [];

  /**
   * Sets a new listener and the pages being listened to or replaces it.
   * @param Plugin $plugin
   * @param string ...$urls
   */
  public function set(Plugin $plugin, string ...$urls)
  {
    foreach ($urls as $url)
      $plugin->getLogger()->debug('Listening url (url "%0")', [$url]);

    $name = $plugin->getClassInfo()->getName();
    $this->listeners[$name] = $urls;
  }

  /**
   * Checks whether the listener contains the specified url.
   * @param string $listener
   * @param string $url
   * @return bool
   */
  public function contain(string $listener, string $url): bool
  {
    return $this->exists($listener) && (in_array($url, $this->listeners[$listener])
        || (isset($this->listeners[$listener][0]) && $this->listeners[$listener][0] == '*'));
  }

  /**
   * Checks whether the specified listener name exists in the list of all listeners.
   * @param string $listener
   * @return bool
   */
  public function exists(string $listener): bool
  {
    return isset($this->listeners[$listener]);
  }
}
