<?php namespace engine\includes\library;

use Countable;

include_once('SettingFile.php');

/**
 * Class DictionaryFile
 * @package engine\includes\library
 */
final class DictionaryFile extends SettingFile implements Countable
{
  /**
   * Contains the number of language keys and their values.
   * @var string[]
   */
  private $languages;

  /**
   * DictionaryFile constructor.
   * @param string $filename
   */
  public function __construct(string $filename)
  {
    parent::__construct($filename);
    $this->languages = self::parseFile($filename);
  }

  /**
   * Returns the value of the language key.
   * @param string $language
   * @param $key
   * @return string|null
   */
  public function get(string $language, $key): ?string
  {
    return $this->hasLanguageKey($language, $key) ? $this->languages[$language][$key] : null;
  }

  /**
   * Checks if the language key exists.
   * @param string $language
   * @param string $key
   * @return bool
   */
  public function hasLanguageKey(string $language, string $key): bool
  {
    return $this->hasLanguageCode($language) && isset($this->languages[$language][$key]);
  }

  /**
   * Checks whether the specified one exists in the list.
   * @param string $language
   * @return bool
   */
  public function hasLanguageCode(string $language): bool
  {
    return isset($this->languages[$language]);
  }

  /**
   * Returns the number of languages.
   * @return int
   */
  public function count(): int
  {
    return count($this->languages);
  }
}
