<?php namespace modules\designer\src\xml;

use modules\designer\src\EntityInterface;

/**
 * Class XMLString represents an entity as a string (no tags).
 * @package modules\designer\src\xml
 */
class XMLString implements EntityInterface
{
  /**
   * XMLComment constructor.
   * @param string $value
   */
  public function __construct(public readonly string $value)
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
