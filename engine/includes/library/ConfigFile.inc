<?php namespace engine\includes\library;

include_once('SettingFile.php');

/**
 * Class ConfigFile allows you to extract variables and their values from the configuration file.
 * @package engine\includes\library
 */
final class ConfigFile extends SettingFile
{
  /**
   * Used to store configuration values.
   * These values are constant and change only from the file.
   * @var array
   */
  private $vars = [];

  /**
   * Contains a description of the configuration variable.
   * @var array
   */
  private $descriptions = [];

  /**
   * Returns the value of a configuration variable.
   * @param string $key
   * @return integer|string|double
   */
  public function get(string $key)
  {
    return $this->vars[$key];
  }

  /**
   * Executes or creates a file (if it does not exist)
   * @param array $info
   */
  public function executeOrCreate(array $info): void
  {
    if (!$this->create($info)) $this->execute();
  }

  /**
   * Automatically creates a configuration file (if not exists)
   * based on registered variables and added description.
   * @param array $info used in the header of the file
   * @return bool if the file exists or an error occurred when creating the file returns false.
   */
  public function create(array $info): bool
  {
    $filename = $this->getFilename();
    if (!file_exists($filename)) {
      @mkdir(dirname($filename), 0644, true);

      # Even if the file could not be created (there are no write permissions),
      # the plugin must solve this error on its own.
      if ($file = @fopen($filename, 'a+')) {
        $name = $info['name'] ?? 'unknown';
        $author = $info['author'] ?? 'unknown';
        $version = $info['version'] ?? 'unknown';

        fwrite($file, "; This file was automatically generated\n"
          ."; Configuration variables for plugin \"$name\" by \"$author\" (version \"$version\")\n\n"
        );

        foreach ($this->vars as $key => $value) {
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
   * Registers a new value.
   * @param string $key
   * @param integer|double|string $value
   * @param array $description
   * @return bool
   */
  public function register(string $key, $value, array $description = []): bool
  {
    if ($result = in_array(gettype($value), ['integer', 'double', 'string'])) {
      $this->vars[$key] = $value;
      $this->descriptions[$key] = $description;
    }
    return $result;
  }

  /**
   * Reads the configuration and enters the values in the registered keys.
   */
  public function execute(): void
  {
    if ($vars = $this->parseFile($this->getFilename())) {
      foreach ($vars as $key => $value) {
        # Only if the key was registered earlier.
        if (isset($this->vars[$key])) {
          # When reading the configuration, everything is a string,
          # registration sets the type of value by which the expected type is determined.
          switch (gettype($this->vars[$key])) {
            case 'string':
              $this->vars[$key] = $value;
              break;
            case 'integer':
              $this->vars[$key] = (int)$value;
              break;
            case 'double':
              $this->vars[$key] = (double)$value;
              break;
          }
          # If the value does not match the expected value,
          # it is a configuration error that will not be recorded in the log.
          # Since the plugin registering this value has already set the default value.
        }
      }
    }
  }
}
