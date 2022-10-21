<?php namespace engine\includes;

/**
 * Class Environ used to store the module's environment variables.
 * @package engine\includes
 */
final class Environ
{
  /**
   * Contains variables.
   * @var string[]
   */
  private array $variables = [];

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
    return strtr(implode(DIRECTORY_SEPARATOR, $values), $replace);
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
