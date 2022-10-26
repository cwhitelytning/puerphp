<?php namespace core\src\file;

/**
 * Class ConfigFile it is a base class that is a function of parsing special files.
 * Such files can be a list, a configuration file in the form of a key and a parameter value, as well as sections.
 * @package core\src\file
 */
class ConfigFile
{
  /**
   * Contains the path to the file.
   * @var string|null
   */
  private ?string $filename;

  /**
   * ConfigFile constructor.
   * @param string|null $filename
   */
  public function __construct(?string $filename = null)
  {
    $this->filename = $filename;
  }

  /**
   * Parses the contents of the configuration file and returns an array.
   * @param string $filename
   * @return array|false
   */
  final public static function parseFile(string $filename): array|false
  {
    # If the file was opened, but there is no data, this is not an error.
    # If the file could not be opened, it means that it does not exist or there is no read access.
    $content = @file_get_contents($filename);
    return is_string($content) ? self::parse(explode("\n", $content)) : false;
  }

  /**
   * Returns parsed strings.
   * @param array $strings
   * @return array
   */
  final public static function parse(array $strings): array
  {
    $data = [];
    $section = &$data;

    foreach ($strings as $string) {
      # Removing comments from the line:
      if ((($position = strpos($string, ';')) !== false) || (($position = strpos($string, '#')) !== false)) {
        $string = substr($string, 0, $position);
      }

      # Removing all special characters:
      if ($string = trim($string)) {
        # If this is a key and value, we split it:
        if (($position = strpos($string, ' ')) || ($position = strpos($string, '='))) {
          $key = substr($string, 0, $position);
          $value = trim(substr($string, $position), " \t\n\r\0\x0B\"");

          $section[$key] = $value;
        } elseif ($string[0] == '[' && $string[-1] == ']') {
          $key = substr($string, 1, -1);

          $section = &$data; # returns on main section
          $section[$key] = []; # creates a new section
          $section = &$section[$key]; # sets a section
        } else
          $section[] = $string;
      }
    }
    return $data;
  }

  /**
   * Returns the path to the file.
   * If the class is used for storage returns null.
   * @return string|null
   */
  final public function getFilename(): ?string
  {
    return $this->filename;
  }
}
