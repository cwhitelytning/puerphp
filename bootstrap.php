<?php
/**
 * This file acts as an entry point for the server.
 * If you only need to use the index file, rename it in the virtual host settings.
 */

# Plugins are a separate part of the engine:
require 'engine/Engine.php';

# Required for automatic loading of plugins:
engine\Engine::run();