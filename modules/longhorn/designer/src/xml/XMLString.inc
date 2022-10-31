<?php namespace modules\longhorn\designer\src\xml;

use modules\longhorn\designer\src\EntityInterface;

/**
 * Class XMLString represents an entity as a string (no tags).
 * @package modules\longhorn\designer\src\xml
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
