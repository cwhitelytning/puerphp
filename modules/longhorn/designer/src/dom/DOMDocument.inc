<?php namespace modules\longhorn\designer\src\dom;

use modules\longhorn\designer\src\Node;

/**
 * Class DOMDocument
 * @package modules\longhorn\designer\src\dom
 */
class DOMDocument extends Node
{
  /**
   * DOMDocument constructor.
   * @param string $doctype
   */
  public function __construct(private string $doctype)
  {
  }

  /**
   * Returns a string.
   * @return string
   */
  final public function __toString(): string
  {
    return "<!DOCTYPE $this->doctype>" . parent::__toString();
  }
}
