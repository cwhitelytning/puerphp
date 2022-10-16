<?php namespace engine\includes;

/**
 * Class PluginPaths
 * @package engine\includes
 */
final class PluginPaths
{
  /**
   * Contains the path to the main plugin file.
   * @var array
   */
  private $paths = [];

  /**
   * Registers a new path.
   * @param string $name
   * @param string ...$paths
   * @return string|null returns the collected path or if the path has already been registered returns null.
   */
  public function register(string $name, string ...$paths): ?string
  {
    return $this->contain($name) ? null : $this->paths[$name] = $this->collect(...$paths);
  }

  /**
   * Checks whether the specified path exists by its name.
   * @param string $name
   * @return bool
   */
  public function contain(string $name): bool
  {
    return isset($this->paths[$name]);
  }

  /**
   * Returns a string substituting already registered paths.
   * @param string ...$paths
   * @return string
   */
  public function collect(string ...$paths): string
  {
    # Allows you to substitute for already existing variable names.
    foreach ($this->paths as $name => $path) {
      if (($key = array_search("%$name%", $paths)) !== false) {
        $paths[$key] = $path;
      }
    }
    return implode(DIRECTORY_SEPARATOR, $paths);
  }

  /**
   * Returns the path by name.
   * @param string $name
   * @return string|null
   */
  public function get(string $name): ?string
  {
    return $this->contain($name) ? $this->paths[$name] : null;
  }
}
