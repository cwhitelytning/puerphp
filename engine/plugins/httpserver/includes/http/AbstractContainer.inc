<?php namespace engine\plugins\httpserver\includes\http;

use Countable;

/**
 * Class AbstractContainer
 * @package engine\plugins\httpserver\includes\http
 */
abstract class AbstractContainer implements Countable
{
  /**
   * Contains view string properties "key" and "value"
   * @var array
   */
  protected $properties = [];

  /**
   * Container constructor.
   * @param array $properties
   */
  public function __construct(array $properties = [])
  {
    $this->add($properties);
  }

  /**
   * Allows you to add multiple properties at once.
   * @param array $array
   */
  final public function add(array $array): void
  {
    foreach ($array as $key => $value) {
      if (is_string($key) && is_string($value)) {
        $this->set($key, $value);
      }
    }
  }

  /**
   * Sets or replaces a property.
   * @param string $key
   * @param string $value
   */
  public function set(string $key, string $value): void
  {
    $this->properties[$key] = $value;
  }

  /**
   * Checks if the property array is empty.
   * @return bool
   */
  final public function isEmpty(): bool
  {
    return empty($this->properties);
  }

  /**
   * Erases all properties.
   */
  final public function clear(): void
  {
    $this->properties = [];
  }

  /**
   * Removes the specified property from the properties array.
   * @param string $key
   */
  final public function delete(string $key): void
  {
    unset($this->properties[$key]);
  }

  /**
   * Returns the key value.
   * @param string $key
   * @return string|null
   */
  public function get(string $key): ?string
  {
    return $this->hasKey($key) ? $this->properties[$key] : null;
  }

  /**
   * Checks if the specified key is in the property set.
   * @param string $key
   * @return bool
   */
  final public function hasKey(string $key): bool
  {
    return isset($this->properties[$key]);
  }

  /**
   * Checks if a value exists in an array.
   * @param mixed $value
   * @return bool
   */
  final public function hasValue($value): bool
  {
    return in_array($value, $this->properties);
  }

  /**
   * Returns the number of properties.
   * @return int
   */
  final public function count(): int
  {
    return count($this->properties);
  }
}
