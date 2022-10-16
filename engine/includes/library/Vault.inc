<?php namespace engine\includes\library;

use Countable;

/**
 * Class Vault allows you to store a key and a time-stamped value.
 * It represents a miniature encrypted storage (openssl encryption and decryption functions are used).
 * Attention! It is not recommended to use it for storing important information.
 *            Storage is used to "quickly read and write" with easy protection against changes.
 * @package engine\includes\library
 */
final class Vault implements Countable
{
  /**
   * Encryption method used.
   */
  const AES_METHOD = 'AES-192-CBC';

  /**
   * Contains the path to the file.
   * @var string
   */
  private $filename;

  /**
   * Contains a secure key.
   * @var string
   */
  private $key;

  /**
   * Used when reading an already existing storage (if the passed key is invalid).
   * @var bool
   */
  private $invalidKey = false;

  /**
   * Contains read or write data.
   * @var array
   */
  private $data = [];

  /**
   * Vault constructor.
   * @param string $filename
   * @param string|null $key
   * @param bool $overwrite does not read the file (if it exists) thereby overwriting the old data.
   */
  public function __construct(string $filename, ?string $key = null, bool $overwrite = false)
  {
    $this->filename = $filename;
    $this->key = $key ?? openssl_random_pseudo_bytes(40);

    if ($overwrite) {
      unlink($this->filename);
    } elseif ($file = fopen($this->filename, 'rb')) {
      while($raw = fgets($file)) {
        if ($decrypted = @openssl_decrypt($raw, self::AES_METHOD, bin2hex($this->key))) {
          $decoded = base64_decode($decrypted);
          $chunks = explode('|', $decoded, 3);
          if (isset($chunks[1], $chunks[2])) {
            $this->data[$chunks[0]] = ['value' => $chunks[1], 'timestamp' => $chunks[2]];
          }
        } else {
          $this->invalidKey = true;
          break;
        }
      }
      fclose($file);
    }
  }

  /**
   * Checks whether the passed key is invalid to the storage file.
   * @return bool
   */
  public function isInvalidKey(): bool
  {
    return $this->invalidKey;
  }

  /**
   * Adds or replaces an existing value with a timestamp update.
   * @param string $key
   * @param $value
   */
  public function set(string $key, $value)
  {
    $this->update($key, $value);
    $this->touch($key);
  }

  /**
   * Updates only the value without updating the timestamp.
   * @param string $key
   * @param $value
   */
  public function update(string $key, $value)
  {
    $this->data[$key]['value'] = $value;
  }

  /**
   * Updates only the timestamp
   * @param string $key
   * @param int|null $timestamp if null uses the time now.
   */
  public function touch(string $key, ?int $timestamp = null)
  {
    $this->data[$key]['timestamp'] = $timestamp ?? time();
  }

  /**
   * Deletes the value and timestamp by key.
   * @param string $key
   */
  public function remove(string $key)
  {
    unset($this->data[$key]);
  }

  /**
   * Vault destructor.
   */
  public function __destruct()
  {
    if ($this->data) {
      @mkdir(dirname($this->filename), 0644, true);
      $hex = bin2hex($this->key);
      if ($file = fopen($this->filename, 'wb+')) {
        foreach ($this->data as $key => $item) {
          $string = base64_encode($key . '|' . $item['value'] . '|' .$item['timestamp']);
          # We need to generate a permanent key to the file so does not initialize the vector.
          # Will issue a warning: Using an empty Initialization Vector (iv) is potentially insecure and not recommended in...
          fwrite($file, @openssl_encrypt($string, self::AES_METHOD, $hex) . PHP_EOL);
        }
      }
      fclose($file);
    }
  }

  /**
   * Returns the number of keys.
   * @return int
   */
  public function count(): int
  {
    return count($this->data);
  }
}
