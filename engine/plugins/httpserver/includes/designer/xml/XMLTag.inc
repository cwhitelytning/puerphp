<?php namespace engine\plugins\httpserver\packages\designer\xml;

use Countable;
use engine\plugins\httpserver\includes\http\ContentInterface;

/**
 * Class XmlTag
 * @package engine\plugins\httpserver\packages\designer\xml
 */
class XMLTag implements ContentInterface, Countable
{
  /**
   * Contains tag attributes.
   * @var array
   */
  private $attributes;

  /**
   * Contains the tag name.
   * @var string
   */
  private $name;

  /**
   * Contains child tags.
   * @var XMLTag[]
   */
  private $tags = [];

  /**
   * Contains the owner of the tag.
   * @var XMLTag|null
   */
  private $parent;

  /**
   * @var string|null
   */
  private $value;

  /**
   * XmlTag constructor.
   * @param string $name
   * @param string|null $value
   * @param array $attributes
   * @param XMLTag|null $parent
   */
  public function __construct(string $name, ?string $value = null, array $attributes = [], XMLTag $parent = null)
  {
    $this->name = $name;
    $this->value = $value;
    $this->parent = $parent;
    $this->setAttributes($attributes);
  }

  /**
   * Returns the tag name.
   * @return string
   */
  public function getName(): string
  {
    return $this->name;
  }

  /**
   * Returns namespace from tags.
   * @param bool $recursive
   * @return array
   */
  public function getNamespace(bool $recursive = false): array
  {
    $namespace[] = $this->name;
    if ($recursive && $parent = $this->getParent()) {
      $namespace[] .= $parent->getNamespace();
    }
    return $namespace;
  }

  /**
   * Returns the parent of the tag.
   * @return XMLTag|null
   */
  public function getParent(): ?XMLTag
  {
    return $this->parent;
  }

  /**
   * Adds a raw value that, when converted to a string, will only extract its value (no tags).
   * @param string $value
   * @return $this
   */
  public function addRaw(string $value): XMLTag
  {
    $this->addTag('@raw', $value);
    return $this;
  }

  /**
   * Creates a new tag and adds it to the list of child tags.
   * @param string $name
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function addTag(string $name, ?string $value = null, array $attributes = []): XMLTag
  {
    return $this->addChild(new $this($name, $value, $attributes, $this));
  }

  /**
   * Adds an existing child tag.
   * @param XMLTag $tag
   * @return $this
   */
  public function addChild(XMLTag $tag): XMLTag
  {
    return $this->tags[] = $tag;
  }

  /**
   * Returns a string.
   * @return string
   */
  public function __toString(): string
  {
    return self::buildString($this);
  }

  /**
   * Collects all attributes and child tags into a string.
   * @param XMLTag $object
   * @param string $eol
   * @return string
   */
  public static function buildString(XMLTag $object, string $eol = PHP_EOL): string
  {
    $attrs = self::buildAttributes($object->attributes);
    $pattern = ['<', $object->name, $attrs, '>', $eol];
    $nested = [];

    if ($tags = &$object->tags) {
      foreach ($tags as $tag) {
        $nested[] = self::buildString($tag, $eol);
      }
    }

    if ($nested || $object->value) {
      $pattern[] = implode($nested);

      if (is_string($object->value)) {
        $pattern[] = $object->value;
        $pattern[] = $eol;
      }

      $pattern[] = "</$object->name>";
      $pattern[] = $eol;
    } else {
      $pattern[3] = '/>';
    }

    return implode($pattern);
  }

  /**
   * Collects all attributes into a string.
   * @param array $attributes
   * @return string
   */
  public static function buildAttributes(array $attributes): string
  {
    $collected = '';
    foreach ($attributes as $key => $value) {
      if (is_array($value)) {
        self::buildAttributes($value);
      } elseif (is_null($value)) {
        $collected .= " $key";
      } else {
        $collected .= " $key=\"$value\"";
      }
    }
    return $collected;
  }

  /**
   * Returns an array of tag attributes.
   * @return array
   */
  public function getAttributes(): array
  {
    return $this->attributes;
  }

  /**
   * Sets and changes the attributes of a tag.
   * @param array $attributes
   */
  public function setAttributes(array $attributes)
  {
    $this->attributes = $attributes;
  }

  /**
   * Returns child elements.
   * @return XMLTag[]
   */
  public function getTags(): array
  {
    return $this->tags;
  }

  /**
   * Returns the value of a tag.
   * @return string|null
   */
  public function getValue(): ?string
  {
    return $this->value;
  }

  /**
   * Returns the number of child tags.
   * @return int
   */
  public function count(): int
  {
    return count($this->tags);
  }
}
