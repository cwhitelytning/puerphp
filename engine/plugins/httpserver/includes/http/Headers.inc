<?php namespace engine\plugins\httpserver\includes\http;

include_once('AbstractContainer.inc');
include_once('HeadersInterface.inc');

/**
 * Class Headers
 * @package engine\plugins\httpserver\includes\http
 */
final class Headers extends AbstractContainer implements HeadersInterface
{
  const ACCEPT = 'Accept';
  const ACCEPT_CHARSET = 'Accept-Charset';
  const ACCEPT_ENCODING = 'Accept-Encoding';
  const ACCEPT_LANGUAGE = 'Accept-Language';
  const ACCEPT_PATCH = 'Accept-Patch';
  const ACCEPT_RANGES = 'Accept-Ranges';
  const ACCESS_CONTROL_ALLOW_CREDENTIALS = 'Access-Control-Allow-Credentials';
  const ACCESS_CONTROL_ALLOW_HEADERS = 'Access-Control-Allow-Headers';
  const ACCESS_CONTROL_ALLOW_METHODS = 'Access-Control-Allow-Methods';
  const ACCESS_CONTROL_ALLOW_ORIGIN = 'Access-Control-Allow-Origin';
  const ACCESS_CONTROL_EXPOSE_HEADERS = 'Access-Control-Expose-Headers';
  const ACCESS_CONTROL_MAX_AGE = 'Access-Control-Max-Age';
  const ACCESS_CONTROL_REQUEST_HEADERS = 'Access-Control-Request-Headers';
  const ACCESS_CONTROL_REQUEST_METHOD = 'Access-Control-Request-Method';
  const AGE = 'Age';
  const ALLOW = 'Allow';
  const AUTHORIZATION = 'Authorization';
  const CACHE_CONTROL = 'Cache-Control';
  const CONNECTION = 'Connection';
  const CONTENT_DISPOSITION = 'Content-Disposition';
  const CONTENT_ENCODING = 'Content-Encoding';
  const CONTENT_LANGUAGE = 'Content-Language';
  const CONTENT_LENGTH = 'Content-Length';
  const CONTENT_LOCATION = 'Content-Location';
  const CONTENT_RANGE = 'Content-Range';
  const CONTENT_TYPE = 'Content-Type';
  const COOKIE = 'Cookie';
  const DATE = 'Date';
  const ETAG = 'ETag';
  const EXPECT = 'Expect';
  const EXPIRES = 'Expires';
  const FROM = 'From';
  const HOST = 'Host';
  const IF_MATCH = 'If-Match';
  const IF_MODIFIED_SINCE = 'If-Modified-Since';
  const IF_NONE_MATCH = 'If-None-Match';
  const IF_RANGE = 'If-Range';
  const IF_UNMODIFIED_SINCE = 'If-Unmodified-Since';
  const LAST_MODIFIED = 'Last-Modified';
  const LINK = 'Link';
  const LOCATION = 'Location';
  const MAX_FORWARDS = 'Max-Forwards';
  const ORIGIN = 'Origin';
  const PRAGMA = 'Pragma';
  const PROXY_AUTHENTICATE = 'Proxy-Authenticate';
  const PROXY_AUTHORIZATION = 'Proxy-Authorization';
  const RANGE = 'Range';
  const REFERER = 'Referer';
  const RETRY_AFTER = 'Retry-After';
  const SERVER = 'Server';
  const SET_COOKIE = 'Set-Cookie';
  const SET_COOKIE2 = 'Set-Cookie2';
  const TE = 'Te';
  const TRAILER = 'Trailer';
  const TRANSFER_ENCODING = 'Transfer-Encoding';
  const UPGRADE = 'Upgrade';
  const USER_AGENT = 'User-Agent';
  const VARY = 'Vary';
  const VIA = 'Via';
  const WARNING = 'Warning';
  const WWW_AUTHENTICATE = 'WWW-Authenticate';

  /**
   * Used when combining a name and a value.
   */
  const PROPERTY_DELIMITER = ':';

  /**
   * Used when collecting all properties in a string.
   */
  const STRING_DELIMITER = "\r\n";

  /**
   * Returns a string.
   * @return string
   */
  public function __toString(): string
  {
    return implode(self::STRING_DELIMITER, $this->toStrings());
  }

  /**
   * Returns an array of strings.
   * @return array
   */
  public function toStrings(): array
  {
    $strings = [];
    foreach ($this->properties as $key => $value) {
      $strings[] = $key . self::PROPERTY_DELIMITER . $value;
    }
    return $strings;
  }

  /**
   * Sets or replaces a value.
   * @param string $key
   * @param string $value
   */
  public function set(string $key, string $value): void
  {
    $key = ucwords(trim($key), '-');
    $this->properties[$key] = $value;
  }
}
