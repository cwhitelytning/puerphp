<?php namespace core\src\book;

include_once('BookInfo.inc');
include_once('Environ.inc');

use core\src\loader\BookLoader;
use ReflectionClass;

/**
 * Class Book
 * @package core\src\book
 */
class Book
{
  /**
   * Contains the loader in which this book is located.
   * @var BookLoader|null
   */
  private ?BookLoader $loader;

  /**
   * Contains registered paths.
   * @var Environ
   */
  private Environ $environ;

  /**
   * Book constructor.
   * @param BookLoader|null $loader
   */
  final public function __construct(?BookLoader $loader)
  {
    $this->environ = (new Environ())->append([
      # Path to the file of the current book.
      'BOOK_FILE' => (new ReflectionClass($this))->getFileName(),
      # Directory where the current book is located.
      'BOOK_DIR' => ['{BOOK_FILE}', '..'],
      # Directory of configuration files.
      'CONFIGS_DIR' => ['{BOOK_DIR}', 'configs']
    ]);

    $this->setLoader($loader);
  }

  /**
   * Returns information about the class by parsing annotations to it.
   * @return array
   */
  final protected function getInfo(): array
  {
    $arguments = [];
    $reflection = new ReflectionClass($this);

    if ($attributes = $reflection->getAttributes(BookInfo::class)) {
      $arguments = $attributes[0]->getArguments();
      $arguments['name'] = $reflection->getShortName();
    }
    return $arguments;
  }

  /**
   * Sets the loader in which this book is located.
   * Do not use this function.
   * @param BookLoader|null $loader
   */
  private function setLoader(?BookLoader $loader): void
  {
    $this->loader = $loader;
  }

  /**
   * Returns the loader in which this book is located.
   * @return BookLoader|null
   */
  final protected function getLoader(): ?BookLoader
  {
    return $this->loader;
  }

  /**
   * Returns the book's environment variables.
   * @return Environ
   */
  final protected function getEnviron(): Environ
  {
    return $this->environ;
  }
}
