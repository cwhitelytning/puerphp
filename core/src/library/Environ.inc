<?php namespace core\src\library;

/**
 * Class EnvironFile used to store the module's environment variables.
 * @package core\src\library
 */
final class Environ
{
  /**
   * Contains variables.
   * @var array
   */
  private array $vars = [];

  /**
   * Loads the environment paths from a xml file and returns it.
   * @param string $filename
   * @param int $count limiting the number of processed paths.
   * @return array
   */
  public function getPathsFromFile(string $filename, int $count = 0): array
  {
    $paths = [];
    if ($environs = @simplexml_load_file($filename)) {
      foreach ($environs as $environ) {
        $name = (string)$environ['name'];
        $paths[$name] = self::getAbsolutePath($this->format((string)$environ['value']));

        if ($count && $count == count($paths)) break;
      }
    }
    return $paths;
  }

  /**
   * Adds several variables from the array.
   * @param array $values
   * @return $this
   */
  public function append(array $values): Environ
  {
    foreach ($values as $key => $value) {
      $this->set($key, is_array($value) ? self::collect(...$value) : $value);
    }
    return $this;
  }

  /**
   * Sets the new value of the variable.
   * @param string $key
   * @param string ...$chunks
   * @return bool
   */
  public function set(string $key, string ...$chunks): bool
  {
    if ($result = !$this->has($key)) {
      $this->vars[$key] = self::getAbsolutePath($this->format(...$chunks));
    }
    return $result;
  }

  /**
   * Checks if the variable with the specified key.
   * @param string $key
   * @return bool
   */
  public function has(string $key): bool
  {
    return isset($this->vars[$key]);
  }

  /**
   * Expands all transitions of type /./, /../ and returns a string.
   * @param string $filename
   * @return string
   */
  public static function getAbsolutePath(string $filename): string
  {
    $filename = self::replaceSeparator($filename, '/');
    $chunks = explode('/', $filename);

    $strings = [];
    foreach ($chunks as $chunk) {
      if ($chunk == '..') {
        array_pop($strings);
      } elseif ($chunk != '.') {
        $strings[] = $chunk;
      }
    }
    return self::collect(...$strings);
  }

  /**
   * Replaces the directory separator.
   * @param string $filename
   * @param string $separator
   * @return string
   */
  public static function replaceSeparator(string $filename, string $separator = DIRECTORY_SEPARATOR): string
  {
    return str_replace(['\\', '/'], $separator, $filename);
  }

  /**
   * Collects an array of strings into a string,
   * concatenating them with the directory separator of the current operating system where the script is being executed.
   * @param string ...$chunks
   * @return string
   */
  public static function collect(string ...$chunks): string
  {
    return implode(DIRECTORY_SEPARATOR, $chunks);
  }

  /**
   * Replaces templates for variables in the line and returns the string.
   * @param string ...$strings
   * @return string
   */
  public function format(string ...$strings): string
  {
    $replace = [];
    foreach ($this->vars as $key => $value) {
      $replace['{' . $key . '}'] = $value;
    }
    return strtr(self::collect(...$strings), $replace);
  }

  /**
   * Returns the value of a variable.
   * @param string $key
   * @return string|null
   */
  public function get(string $key): ?string
  {
    return $this->has($key) ? $this->vars[$key] : null;
  }
}
