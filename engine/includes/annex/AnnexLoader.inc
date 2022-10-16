<?php namespace engine\includes\annex;

include_once('exceptions/ClassNotFoundException.inc');
include_once('exceptions/InvalidClassException.inc');
include_once('exceptions/FileIncludeException.inc');
include_once('AnnexFactory.inc');

use engine\includes\annex\exceptions\ClassNotFoundException;
use engine\includes\annex\exceptions\FileIncludeException;
use engine\includes\annex\exceptions\InvalidClassException;

/**
 * Class AnnexLoader provides the ability to load Annex objects from the directory.
 * @package engine\includes\annex
 */
final class AnnexLoader extends AnnexFactory
{
  /**
   * Used to search for a class when including a file.
   * @var string
   */
  private $namespace;

  /**
   * Used to load Annexes from the path.
   * @var string
   */
  private $directory;

  /**
   * Used when checking the included class.
   * If the class does not match the one specified during loading, an exception will be thrown.
   * @var string
   */
  private $classpath;

  /**
   * AnnexLoader constructor.
   * @param string $namespace
   * @param string $classpath
   */
  function __construct(string $namespace, string $classpath = Annex::class)
  {
    $this->namespace = $namespace;
    $this->classpath = $classpath;
    $this->directory = str_replace('\\', DIRECTORY_SEPARATOR, $namespace);
  }

  /**
   * Loads one or more Annexes from the directory passed in the constructor.
   * @param string $name
   * @param mixed ...$args
   * @return AnnexInterface
   * @throws ClassNotFoundException
   * @throws FileIncludeException
   * @throws InvalidClassException
   */
  function load(string $name, ...$args): AnnexInterface
  {
    $directory = $this->directory . DIRECTORY_SEPARATOR . strtolower($name);
    $filename = $directory . DIRECTORY_SEPARATOR . "$name.php";
    if (include_once($filename)) {
      $classpath = "$this->namespace\\$name\\$name";
      if (class_exists($classpath)) {
        if ($this->checkClass($classpath)) {
          return $this->add(new $classpath(...$args));
        } else
          throw new InvalidClassException($classpath);

      } else
        throw new ClassNotFoundException($classpath);

    } else
      throw new FileIncludeException($filename);
  }

  /**
   * Checks the class parents.
   * @param string $classpath
   * @return bool
   */
  function checkClass(string $classpath): bool
  {
    $parents = class_parents($classpath);
    return isset($parents[$this->classpath]);
  }

  /**
   * Returns the classpath.
   * @return string
   */
  function getClassPath(): string
  {
    return $this->classpath;
  }
}
