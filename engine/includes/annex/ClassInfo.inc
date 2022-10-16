<?php namespace engine\includes\annex;

use ReflectionClass;

/**
 * Class ClassInfo contains information about the class by parsing annotations to it.
 * @package engine\includes\annex
 */
final class ClassInfo
{
  /**
   * Contains the name of the class.
   * @var string
   */
  private $name;

  /**
   * Contains class annotations.
   * @var array
   */
  private $annotations;

  /**
   * Returns all annotations on a class.
   * @param object $object
   */
  public function __construct(object $object)
  {
    $class = new ReflectionClass($object);
    $this->name = $class->getShortName();
    $this->annotations = self::parseAnnotations($class->getDocComment());
  }

  /**
   * Parses the document to a method or to a class and returns a list of annotations.
   * @param string $comments
   * @return array
   */
  static protected function parseAnnotations(string $comments): array
  {
    $tag = 0;
    $collection = [];

    while ($tag = strpos($comments, '@', $tag)) {
      if ($separator = strpos($comments, ' ', $tag)) {
        $key = mb_substr($comments, ++$tag, $separator - $tag);
        if ($key = trim($key)) {
          $value = '';
          if ($end = strpos($comments, '*', $separator)) {
            $value = mb_substr($comments, ++$separator, $end - $separator);
          }
          $collection[$key][] = trim($value);
        }
      }
    }

    return $collection;
  }

  /**
   * Returns the license type.
   * @return string|null
   */
  public function getLicense(): ?string
  {
    return $this->getAnnotation('license');
  }

  /**
   * Returns the annotation value as a string.
   * @param string $key
   * @return string|null
   */
  private function getAnnotation(string $key): ?string
  {
    return isset($this->annotations[$key]) ? implode(', ', $this->annotations[$key]) : null;
  }

  /**
   * Returns a link to the source.
   * @return string|null
   */
  public function getLink(): ?string
  {
    return $this->getAnnotation('link');
  }

  /**
   * Returns the path to the package in which the given class is located.
   * @return string|null
   */
  public function getPackage(): ?string
  {
    return $this->getAnnotation('package');
  }

  /**
   * Returns a version or a date.
   * @return string|null
   */
  public function getSince(): ?string
  {
    return $this->getAnnotation('since');
  }

  /**
   * Returns the copyright.
   * @return string|null
   */
  public function getCopyright(): ?string
  {
    return $this->getAnnotation('copyright');
  }

  /**
   * Returns the description of the package.
   * @return string|null
   */
  public function getDescription(): ?string
  {
    return $this->getAnnotation('description');
  }

  /**
   * Returns the package version.
   * @return string|null
   */
  public function getVersion(): ?string
  {
    return $this->getAnnotation('version');
  }

  /**
   * Returns the author of the package.
   * @return string|null
   */
  public function getAuthor(): ?string
  {
    return $this->getAnnotation('author');
  }

  /**
   * Returns the class name.
   * @return string
   */
  public function getName(): string
  {
    return $this->name;
  }

  /**
   * Returns the name, author, version, and description of the plugin.
   * @return array
   */
  public function getShortInfo(): array
  {
    return [
      'name' => $this->getName(),
      'author' => $this->getAuthor(),
      'version' => $this->getVersion(),
      'description' => $this->getDescription()
    ];
  }
}