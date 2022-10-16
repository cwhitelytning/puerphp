<?php namespace engine\plugins\server\includes;

include_once('ContentInterface.inc');

/**
 * Class Content
 * @package engine\plugins\server\includes
 */
class Content implements ContentInterface
{
  /**
   * Contains an array of ContentInterface.
   * @var ContentInterface[]
   */
  private $contents = [];

  /**
   * Sets or replaces the ContentInterface.
   * @param string $name
   * @param ContentInterface $content
   */
  function set(string $name, ContentInterface $content): void
  {
    $this->contents[$name] = $content;
  }

  /**
   * Checks if a ContentInterface exists.
   * @param string $name
   * @return bool
   */
  function exists(string $name): bool
  {
    return isset($this->contents[$name]);
  }

  /**
   * Returns ContentInterface.
   * @param string $name
   * @return ContentInterface
   */
  function get(string $name): ContentInterface
  {
    return $this->contents[$name];
  }

  /**
   * Returns a string.
   * @return string
   */
  function __toString(): string
  {
    return implode('', $this->contents);
  }
}