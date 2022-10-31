<?php namespace modules\designer\src\xml;

use modules\designer\src\Node;

/**
 * Class XMLEntity underlying XML entity that is used to create the elements of a document.
 * @package modules\designer\src\xml
 */
class XMLEntity extends Node
{
  /**
   * XMLEntity constructor.
   * @param string $name
   * @param array $attrs
   * @param string|null $value
   * @param int $options
   */
  public function __construct(private string $name, private array $attrs = [],
                              private ?string $value = null, private int $options = 0)
  {
  }

  /**
   * Returns a string.
   * @return string
   */
  final public function __toString(): string
  {
    $pattern = ['<', $this->name, self::attrsAsString($this->attrs), '>', $this->value, parent::__toString()];

    if ($pattern[4] || $pattern[5] || $this->options & LIBXML_NOEMPTYTAG) {
      $pattern[] = "</$this->name>";
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
  private static function attrsAsString(array $attributes): string
  {
    $collected = '';
    foreach ($attributes as $key => $value) {
      if (is_array($value)) {
        self::attrsAsString($value);
      } elseif (is_null($value)) {
        $collected .= " $key";
      } else {
        $collected .= " $key=\"$value\"";
      }
    }
    return $collected;
  }
}
