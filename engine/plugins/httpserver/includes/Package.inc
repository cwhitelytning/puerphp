<?php namespace engine\plugins\httpserver\includes;

use engine\includes\annex\Annex;

/**
 * Class Package includes files before declaring the class, the constructor and destructor are locked.
 * @package engine\plugins\httpserver\includes
 */
class Package extends Annex
{
  /**
   * Package constructor.
   */
  final function __construct() {}

  /**
   * Package destructor.
   */
  final function __destruct() {}
}
