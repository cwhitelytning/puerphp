<?php namespace core\src\loader;

include_once('exceptions/LoaderException.inc');
include_once('exceptions/IncludeException.inc');
include_once('exceptions/InvalidClassException.inc');
include_once('exceptions/ClassNotFoundException.inc');

use core\src\book\Book;
use core\src\loader\exceptions\ClassNotFoundException;
use core\src\loader\exceptions\IncludeException;
use core\src\loader\exceptions\InvalidClassException;

/**
 * Class BookLoader a universal class loader that allows you to load classes from anywhere.
 * @package core\src\loader
 */
class BookLoader extends Book
{
  /**
   * Specifies to the loader the base class from which all loaded classes should be inherited.
   * If a class does not contain a base class in the class hierarchy, the loaded class is considered invalid.
   *
   * <b>It is not recommended to use another class that does not extend from the book class,
   * this will cause incorrect behavior of the loader.</b>
   */
  const BOOK_CLASS = Book::class;

  /**
   * Contains libraries.
   * @var Book[]
   */
  private array $books = [];

  /**
   * Returns the book.
   * @param int $index
   * @return Book|null
   */
  final public function get(int $index): ?Book
  {
    return $this->books[$index];
  }

  /**
   * Checks if the specified book class is present in the loader.
   * @param int $index
   * @return bool
   */
  final public function has(int $index): bool
  {
    return isset($this->books[$index]);
  }

  /**
   * Extracts each Book and passes it to the callback function.
   * Iteration is stopped using the returned positive value.
   * If the iteration was stopped ahead of time,
   * it returns the current extracted book.
   * @param callable $callable
   * @param string $class filter libraries
   * @return Book|null
   */
  final public function each(callable $callable, string $class = self::BOOK_CLASS): ?Book
  {
    foreach ($this->books as $book) {
      if ($book instanceof $class) {
        if ($callable($book)) return $book;
      }
    }
    return null;
  }

  /**
   * Loads a class from a namespace that must match the directory structure in which the file is located.
   * @param string $directory in which the libraries are located
   * @param string $filename Classname -> filename (no extension) -> directory name.
   * @param string $namespace in which the class to load will be searched for.
   * @return Book|null
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  final protected function loadClassFile(string $directory, string $filename, string $namespace): ?Book
  {
    $filename = $this->getEnviron()::collect($directory, strtolower($filename), "$filename.php");
    return $this->loadClassFileFrom($filename, $namespace);
  }

  /**
   * Loads a class from a file including a file and importing a class from a namespace.
   * Class name is taken from the file name.
   * @param string $filename
   * @param string $namespace
   * @return Book|null
   * @throws ClassNotFoundException
   * @throws IncludeException
   * @throws InvalidClassException
   */
  private function loadClassFileFrom(string $filename, string $namespace): ?Book
  {
    if (@include_once($filename)) {
      $name = pathinfo($filename, PATHINFO_FILENAME);
      return $this->importClass("$namespace\\$name\\$name");
    } else
      throw new IncludeException($filename);
  }

  /**
   * Imports a class from the path specified to it,
   * creates a new instance and adds it to the list.
   * @param string $class
   * @return Book|null
   * @throws ClassNotFoundException
   * @throws InvalidClassException
   */
  private function importClass(string $class): ?Book
  {
    if (class_exists($class)) {
      if ($this->isValidClass($class)) {
        return $this->add(new $class($this));
      } else
        throw new InvalidClassException($class);

    } else
      throw new ClassNotFoundException($class);
  }

  /**
   * Checks whether the class is valid for the loader.
   * @param string $class
   * @return bool
   */
  private function isValidClass(string $class): bool
  {
    $parents = class_parents($class);
    return isset($parents[static::BOOK_CLASS]);
  }

  /**
   * Adds a book to the list.
   * @param Book $book
   * @return Book
   */
  private function add(Book $book): Book
  {
    return $this->books[] = $book;
  }
}
