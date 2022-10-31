<?php namespace libs\longhorn\server\src;

use Stringable;

/**
 * Class Content
 * @package libs\longhorn\server\src
 */
class Content implements Stringable
{
  /**
   * Contains an array of ContentInterface.
   * @var Stringable[]
   */
  private array $contents = [];

  /**
   * Sets or replaces the ContentInterface.
   * @param string $name
   * @param Stringable $content
   */
  function set(string $name, Stringable $content): void
  {
    $this->contents[$name] = $content;
  }

  /**
   * Checks if a ContainInterface with the given name exists.
   * @param string $name
   * @return bool
   */
  function has(string $name): bool
  {
    return isset($this->contents[$name]);
  }

  /**
   * Returns ContentInterface.
   * @param string $name
   * @return Stringable
   */
  function get(string $name): Stringable
  {
    return $this->contents[$name];
  }

  /**
   * Returns a string.
   * @return string
   */
  function __toString(): string
  {
    return implode($this->contents);
  }
}