<?php namespace engine\includes\module;

use Attribute;

/**
 * Class ModuleInfo provides information about the module.
 * @package engine\includes\module
 */
#[Attribute(Attribute::TARGET_CLASS)]
final class ModuleInfo
{
  public function __construct(public string $name, public string $author, public string $version, public string $description)
  {
  }
}