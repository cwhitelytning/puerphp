<?php namespace engine\plugins\httpserver\packages\designer\html;

use engine\plugins\httpserver\includes\http\ContentInterface;

/**
 * Class HtmlContent
 * @package engine\plugins\httpserver\packages\designer\html
 */
final class HTMLContent implements ContentInterface
{
  /**
   * @var HTMLTag
   */
  private $head;

  /**
   * @var HTMLTag
   */
  private $body;

  /**
   * @var HTMLTag
   */
  private $root;

  /**
   * Document constructor.
   * @param array $attributes
   */
  public function __construct(array $attributes = [])
  {
    $this->root = new HTMLTag('html', null, $attributes);
    $this->head = $this->root->addChild(new HTMLTag('head'));
    $this->body = $this->root->addChild(new HTMLTag('body'));
  }

  /**
   * Returns head.
   * @return HTMLTag
   */
  public function getHead(): HTMLTag
  {
    return $this->head;
  }

  /**
   * Returns body.
   * @return HTMLTag
   */
  public function getBody(): HTMLTag
  {
    return $this->body;
  }

  /**
   * Returns a string.
   * @return string
   */
  public function __toString(): string
  {
    return '<!DOCTYPE html>' . PHP_EOL . $this->root;
  }
}
