<?php namespace core\src\library;

use Attribute;

/**
 * Class ModuleInfo provides information about the module.
 * @package core\src\library
 */
#[Attribute(Attribute::TARGET_CLASS)]
final class LibraryInfo
{
  public function __construct(public string $author, public string $version, public string $description)
  {
  }
}