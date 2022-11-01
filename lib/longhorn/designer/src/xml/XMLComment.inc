<?php namespace longhorn\designer\src\xml;

/**
 * Class XMLComment represents an entity in the form of a comment.
 * @package longhorn\designer\src\xml
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
