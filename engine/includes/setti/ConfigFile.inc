<?php namespace engine\includes\setti;

include_once('SettiFile.inc');
use engine\includes\module\ModuleInfo;

/**
 * Class ConfigFile allows you to extract variables and their values from the configuration file.
 * @package engine\includes\setti
 */
final class ConfigFile extends SettiFile
{
  /**
   * Used to store configuration values.
   * These values are constant and change only from the file.
   * @var array
   */
  private array $values = [];

  /**
   * Contains a description of the configuration variable.
   * @var array
   */
  private array $descriptions = [];

  /**
   * Selects one or more keys and returns their values.
   * @param string ...$keys
   * @return array
   */
  public function select(string ...$keys): array
  {
    $values = [];
    foreach ($keys as $key) $values[] = $this->get($key);
    return $values;
  }

  /**
   * Returns the value of a configuration variable.
   * @param string $key
   * @return integer|string|double
   */
  public function get(string $key)
  {
    return $this->values[$key];
  }

  /**
   * Generates a file (if it does not exist)
   * or executes it by applying the values from the configuration to the registered variables.
   * @param ModuleInfo $info
   */
  public function generateOrExecute(ModuleInfo $info): void
  {
    if (!$this->generate($info)) $this->execute();
  }

  /**
   * Automatically creates a configuration file (if not exists)
   * based on registered variables and added description.
   * @param ModuleInfo $info used in the header of the file
   * @return bool if the file exists or an error occurred when creating the file returns false.
   */
  public function generate(ModuleInfo $info): bool
  {
    $filename = $this->getFilename();
    if (!file_exists($filename)) {
      @mkdir(dirname($filename), 0644, true);

      # Even if the file could not be created (there are no write permissions),
      # the plugin must solve this error on its own.
      if ($file = @fopen($filename, 'a+')) {
        $name = $info->getName();
        $author = $info->getAuthor() ?? 'unknown';
        $version = $info->getVersion() ?? 'unknown';

        fwrite($file, "; This file was automatically generated\n"
          ."; Configuration variables for plugin \"$name\" by \"$author\" (version \"$version\")\n\n"
        );

        foreach ($this->values as $key => $value) {
          if ($strings = $this->descriptions[$key]) {
            $description = implode("\n; ", $strings);
            fwrite($file, "; $description\n; -\n");
          }

          $value = is_string($value) ? "\"$value\"" : $value;
          fwrite($file, "; Default: $value\n");
          fwrite($file, "$key $value\n\n");
        }

        return fclose($file);
      }
    }
    return false;
  }

  /**
   * Reads the configuration
   * and applies the values from the configuration to the registered variables.
   */
  public function execute(): void
  {
    if ($vars = self::parseFile($this->getFilename())) {
      foreach ($vars as $key => $value) {
        # Only if the key was registered earlier.
        if (isset($this->values[$key])) {
          # When reading the configuration, everything is a string,
          # registration sets the type of value by which the expected type is determined.
          switch (gettype($this->values[$key])) {
            case 'string':
              $this->values[$key] = $value;
              break;
            case 'integer':
              $this->values[$key] = (int)$value;
              break;
            case 'double':
              $this->values[$key] = (double)$value;
              break;
          }
          # If the value does not match the expected value,
          # it is a configuration error that will not be recorded in the log.
          # Since the plugin registering this value has already set the default value.
        }
      }
    }
  }

  /**
   * Registers a new configuration variable.
   * @param string $key
   * @param integer|double|string $value
   * @param string ...$description
   * @return bool
   */
  public function set(string $key, $value, string ...$description): bool
  {
    if ($result = in_array(gettype($value), ['integer', 'double', 'string'])) {
      $this->values[$key] = $value;
      $this->descriptions[$key] = $description;
    }
    return $result;
  }
}
