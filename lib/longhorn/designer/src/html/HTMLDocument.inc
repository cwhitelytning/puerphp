<?php namespace lib\longhorn\designer\src\html;

use lib\longhorn\designer\src\dom\DOMDocument;
use lib\longhorn\designer\src\EntityInterface;
use lib\longhorn\designer\src\xml\XMLEntity;

/**
 * Class HTMLDocument
 * @package lib\longhorn\designer\src\html
 */
class HTMLDocument extends DOMDocument
{
  /**
   * Contains the document root.
   * @var XMLEntity
   */
  private EntityInterface $root;

  /**
   * Contains the head of the document.
   * @var XMLEntity
   */
  private EntityInterface $head;

  /**
   * Contains the body of the document.
   * @var XMLEntity
   */
  private EntityInterface $body;

  /**
   * HTMLDocument constructor.
   * @param string $lang
   */
  public function __construct(string $lang)
  {
    parent::__construct('html');

    $this->root = $this->append(new XMLEntity('html', ['lang' => $lang], options: LIBXML_NOEMPTYTAG));
    $this->head = $this->root->append(new XMLEntity('head', options: LIBXML_NOEMPTYTAG));
    $this->body = $this->root->append(new XMLEntity('body', options: LIBXML_NOEMPTYTAG));
  }

  /**
   * Returns the head of the document.
   * @return XMLEntity
   */
  public function getHead(): XMLEntity
  {
    return $this->head;
  }

  /**
   * Returns the body of the document.
   * @return XMLEntity
   */
  public function getBody(): XMLEntity
  {
    return $this->body;
  }
}
