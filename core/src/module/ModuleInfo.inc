<?php namespace core\src\module;

use Attribute;

/**
 * Class ModuleInfo provides information about the module.
 * @package core\src\module
 */
#[Attribute(Attribute::TARGET_CLASS)]
final class ModuleInfo
{
  public function __construct(public string $author, public string $version, public string $description)
  {
  }
}