<?php namespace longhorn\designer\src\xml;

use longhorn\designer\src\Node;

/**
 * Class XMLDocument
 * @package longhorn\designer\src\xml
 */
class XMLDocument extends Node
{
  /**
   * XMLDocument constructor.
   * @param string $version
   * @param string $encoding
   */
  public function __construct(private string $version, private string $encoding)
  {
  }

  /**
   * Returns a string.
   * @return string
   */
  public function __toString(): string
  {
    return "<?xml version=\"$this->version\" encoding=\"$this->encoding\" ?>" . parent::__toString();
  }
}
