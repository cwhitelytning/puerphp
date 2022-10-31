<?php namespace modules\designer\src\xml;

use modules\designer\src\EntityInterface;

/**
 * Class XMLComment represents an entity in the form of a comment.
 * @package modules\designer\src\xml
 */
final class XMLComment extends XMLString
{
  /**
   * Returns a string.
   * @return string
   */
  public function __toString(): string
  {
    return '<!-- ' . parent::__toString() . ' -->';
  }
}
