<?php namespace plugins\server\src;

/**
 * Class Methods
 * @package plugins\server\src
 */
final class Methods {
  /**
   * The HTTP GET method requests a representation of the specified resource.
   * Requests using GET should only be used to request data (they shouldn't include data).
   */
  const HTTP_GET_METHOD = 'GET';

  /**
   * The HTTP HEAD method requests the headers that would be returned
   * if the HEAD request's URL was instead requested with the HTTP GET method.
   */
  const HTTP_HEAD_METHOD = 'HEAD';

  /**
   * The HTTP POST method sends data to the server.
   * The type of the body of the request is indicated by the Content-Type header.
   */
  const HTTP_POST_METHOD = 'POST';

  /**
   * The PUT method replaces all current representations of the target resource with the request payload.
   */
  const HTTP_PUT_METHOD = 'PUT';

  /**
   * The HTTP DELETE request method deletes the specified resource.
   */
  const HTTP_DELETE_METHOD = 'DELETE';

  /**
   * The HTTP CONNECT method starts two-way communications with the requested resource.
   * It can be used to open a tunnel.
   */
  const HTTP_CONNECT_METHOD = 'CONNECT';

  /**
   * The HTTP OPTIONS method requests permitted communication options for a given URL or server.
   * A client can specify a URL with this method, or an asterisk (*) to refer to the entire server.
   */
  const HTTP_OPTIONS_METHOD = 'OPTIONS';

  /**
   * The HTTP TRACE method performs a message loop-back test along the path to the target resource,
   * providing a useful debugging mechanism.
   */
  const HTTP_TRACE_METHOD = 'TRACE';

  /**
   * The HTTP PATCH request method applies partial modifications to a resource.
   */
  const HTTP_PATCH_METHOD = 'PATCH';
}