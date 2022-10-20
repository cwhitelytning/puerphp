<?php namespace engine\includes;

/**
 * Class Paths
 * @package engine\includes
 */
final class Paths
{
  /**
   * Contains registered paths.
   * @var string[]
   */
  private array $paths = [];

  /**
   * Contains Boolean values for accessing variables.
   * @var bool[]
   */
  private array $access = [];

  /**
   * Paths constructor.
   */
  public function __construct()
  {
    $this->set('separator', DIRECTORY_SEPARATOR);
  }

  /**
   * Registers a new variable.
   * @param string $key
   * @param string $value
   * @param bool $readonly
   * @return bool
   */
  public function set(string $key, string $value, bool $readonly = true): bool
  {
    if ($result = !$this->isReadOnly($key)) {
      $this->paths[$key] = $this->format($value);
      $this->access[$key] = $readonly;
    }
    return $result;
  }

  /**
   * Checks whether a variable is read-only.
   * @param string $name
   * @return bool
   */
  public function isReadOnly(string $name): bool
  {
    return isset($this->access[$name]) && $this->access[$name];
  }

  /**
   * Replaces templates for variables in the line and reveals all transitions of the type /./, /../.
   * @param string $string
   * @return string
   */
  public function format(string $string): string
  {
    return self::getAbsolutePath($this->interpolate($string));
  }

  /**
   * Expands all transitions of type /./, /../ and returns a string.
   * @param string $path
   * @return string
   */
  public static function getAbsolutePath(string $path): string
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
   * @param string $path
   * @return string
   */
  public function interpolate(string $path): string
  {
    $replace = [];
    foreach ($this->paths as $key => $value) {
      $replace['{' . $key . '}'] = $value;
    }
    return strtr($path, $replace);
  }

  /**
   * Returns the value of a variable.
   * @param string $key
   * @return string|null
   */
  public function get(string $key): ?string
  {
    return $this->exists($key) ? $this->paths[$key] : null;
  }

  /**
   * Checks whether a variable has been registered.
   * @param string $key
   * @return bool
   */
  public function exists(string $key): bool
  {
    return isset($this->paths[$key]);
  }
}
