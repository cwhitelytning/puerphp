<?php
/**
 * This file acts as an entry point for the server.
 * If you only need to use the index file, rename it in the virtual host settings.
 */

ini_set('display_errors', '1');
ini_set('display_startup_errors', '1');
error_reporting(E_ALL);

# Plugins are a separate part of the engine:
require 'engine/Engine.php';

# Required for automatic loading of plugins:
engine\Engine::run(isset($argv) ? array_slice($argv, 1) : []);