<?php namespace engine\includes\file;

/**
 * Class EnvironFile used to store the module's environment variables.
 * @package engine\includes\file
 */
final class EnvironFile extends ConfigFile
{
  /**
   * Contains variables.
   * @var array
   */
  private array $vars = [];

  /**
   * Loads variables from a file and returns a new instance.
   * @param string $filename
   * @return EnvironFile
   */
  public static function loadFromFile(string $filename): EnvironFile
  {
    return (new EnvironFile($filename))->append(self::parseFile($filename));
  }

  /**
   * Adds several variables from the array.
   * @param array $values
   * @return $this
   */
  public function append(array $values): EnvironFile
  {
    foreach ($values as $key => $value) {
      $this->set($key, is_array($value) ? self::collect(...$value) : $value);
    }
    return $this;
  }

  /**
   * Sets the new value of the variable.
   * @param string $key
   * @param string ...$strings
   * @return bool
   */
  public function set(string $key, string ...$strings): bool
  {
    if ($result = !$this->has($key)) {
      $this->vars[$key] = self::getAbsolutePath($this->format(...$strings));
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
    $filename = str_replace(['\\', '/'], '/', $filename);
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
