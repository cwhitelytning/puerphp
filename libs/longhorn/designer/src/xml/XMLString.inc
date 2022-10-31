<?php namespace libs\longhorn\designer\src\xml;

use libs\longhorn\designer\src\EntityInterface;

/**
 * Class XMLString represents an entity as a string (no tags).
 * @package libs\longhorn\designer\src\xml
 */
class XMLString implements EntityInterface
{
  /**
   * XMLComment constructor.
   * @param string $value
   */
  public function __construct(private string $value)
  {
  }

  /**
   * Returns a string.
   * @return string
   */
  public function __toString(): string
  {
    return $this->value;
  }
}
