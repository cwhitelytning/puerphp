<?php namespace engine\includes\module;

/**
 * Class Environ used to store the module's environment variables.
 * @package engine\includes\module
 */
final class Environ
{
  /**
   * Contains variables.
   * @var string[]
   */
  private array $variables = [];

  /**
   * Environ constructor.
   * @param array $variables
   */
  public function __construct(array $variables = [])
  {
    $this->append($variables);
  }

  /**
   * Adds multiple variables from the array.
   * @param array $variables
   * @return void
   */
  public function append(array $variables): void
  {
    foreach ($variables as $key => $value) {
      if (is_array($value)) {
        $this->set($key, ...$value);
      } elseif (is_string($value)) {
        $this->set($key, $value);
      }
    }
  }

  /**
   * Registers a new variable.
   * @param string $key
   * @param string ...$values
   * @return bool
   */
  public function set(string $key, string ...$values): bool
  {
    if ($result = is_null($this->variables[$key])) {
      $this->variables[$key] = self::absolute($this->format(...$values));
    }
    return $result;
  }

  /**
   * Expands all transitions of type /./, /../ and returns a string.
   * @param string $path
   * @return string
   */
  public static function absolute(string $path): string
  {
    if ((($position = strpos($path, '\\')) !== false) || (($position = strpos($path, '/')) !== false)) {
      $separator = $path[$position];
      $strings = explode($separator, $path);

      $levels = [];
      foreach ($strings as $string) {
        if ($string == '..') {
          array_pop($levels);
        } elseif ($string != '.') {
          $levels[] = $string;
        }
      }
      return implode($separator, $levels);
    }
    return $path;
  }

  /**
   * Replaces templates for variables in the line and returns the string.
   * @param string ...$values
   * @return string
   */
  public function format(string ...$values): string
  {
    $replace = [];
    foreach ($this->variables as $key => $value) {
      $replace['{' . $key . '}'] = $value;
    }
    return strtr($this->collect(...$values), $replace);
  }

  /**
   * Collects an array of strings into a string,
   * concatenating them with the directory separator of the current operating system where the script is being executed.
   * @param string ...$strings
   * @return string
   */
  public function collect(string ...$strings): string
  {
    return implode(DIRECTORY_SEPARATOR, $strings);
  }

  /**
   * Returns the value of a variable.
   * @param string $key
   * @return string|null
   */
  public function get(string $key): ?string
  {
    return $this->exists($key) ? $this->variables[$key] : null;
  }

  /**
   * Checks whether a variable has been registered.
   * @param string $key
   * @return bool
   */
  public function exists(string $key): bool
  {
    return isset($this->variables[$key]);
  }
}
