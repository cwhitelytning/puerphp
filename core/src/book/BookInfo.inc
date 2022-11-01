<?php namespace core\src\book;

use Attribute;

/**
 * Class BookInfo contains information about the book (author, version, description).
 * @package core\src\book
 */
#[Attribute(Attribute::TARGET_CLASS)]
final class BookInfo
{
  public function __construct(public string $author, public string $version, public string $description)
  {
  }
}