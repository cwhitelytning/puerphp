<?php namespace lib\longhorn\designer\src;

use Countable;

/**
 * Class Node can contain nested nodes.
 * @package lib\longhorn\designer\src
 */
class Node implements EntityInterface, Countable
{
  /**
   * Contains nested entities.
   * @var EntityInterface[]
   */
  private array $entities = [];

  /**
   * Adds one entity to the end of the array.
   * @param EntityInterface $entity
   * @return EntityInterface
   */
  final public function append(EntityInterface $entity): EntityInterface
  {
    return $this->entities[] = $entity;
  }

  /**
   * Returns a string.
   * @return string
   */
  public function __toString(): string
  {
    $strings = [];
    foreach ($this->entities as $entity) {
      $strings[] = (string)$entity;
    }
    return implode($strings);
  }

  /**
   * Returns the number of nested entities.
   * @return int
   */
  final public function count(): int
  {
    return count($this->entities);
  }
}
