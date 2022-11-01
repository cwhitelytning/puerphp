<?php
/**
 * This file acts as an entry point for the server.
 * If you only need to use the index file, rename it in the virtual host settings.
 */

# Required for automatic loading of books:
require 'core/Core.php';
core\Core::run();