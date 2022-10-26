<?php
/**
 * This file acts as an entry point for the server.
 * If you only need to use the index file, rename it in the virtual host settings.
 */

# Plugins are a separate part of the core:
require 'core/Core.php';

# Required for automatic loading of plugins:
core\Core::run();