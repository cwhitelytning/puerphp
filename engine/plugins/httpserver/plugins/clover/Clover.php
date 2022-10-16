<?php namespace engine\plugins\httpserver\plugins\clover;

use engine\includes\library\ConfigFile;
use engine\includes\Plugin;
use engine\plugins\httpserver\HTTPServer;
use engine\plugins\httpserver\includes\http\ResponseInterface;
use engine\plugins\httpserver\includes\http\Status;
use engine\plugins\httpserver\packages\designer\html\HTMLContent;

/**
 * Class Clover
 * @description Content Management System
 * @author Clay Whitelytning
 * @version 1.0.0
 * @package engine\plugins\httpserver\plugins\clover
 */
final class Clover extends Plugin
{
  /**
   * @var ConfigFile
   */
  private $settings;

  /**
   * @var array
   */
  private $sql;

  /**
   * @var array
   */
  private $users;

  /**
   * @return ConfigFile
   */
  protected function getSQLConfigFile(): ConfigFile
  {
    $file = new ConfigFile($this->getPaths()->collect('%configs%', 'sql.cfg'));
    $file->register('sql_host', '127.0.0.1');
    $file->register('sql_user', '');
    $file->register('sql_pass', '');
    $file->register('sql_db', '');
    $file->register('sql_table', '');
    $file->register('sql_type', 'mysql');
    $file->register('sql_charset', 'utf8');
    $file->executeOrCreate($this->getClassInfo()->getShortInfo());
    return $file;
  }

  /**
   * @return ConfigFile
   */
  protected function getSettingsConfigFile(): ConfigFile
  {
    $file = new ConfigFile($this->getPaths()->collect('%configs%', 'main.cfg'));
    $file->register('use_sql', 0, [
      'Where to load the list of users from'
      , '2 - loads the list of users from sql, if there is no connection with the database, load from a users.cfg file'
      , '1 - loads the list of users only from sql'
      , '0 - loads the list of users only from users.cfg']);
    $file->register('auth_url', '/clover', [
      'Url from which you will log in to the control panel'
    ]);

    $file->executeOrCreate($this->getClassInfo()->getShortInfo());
    return $file;
  }

  /**
   * @param ResponseInterface $response
   * @param string $url
   * @return int
   */
  protected function onLoginPage(ResponseInterface $response, string $url): int
  {
    $html = new HTMLContent();
    $head = $html->getHead();
    $head->title('Clover');
    $head->meta(['name' => 'viewport', 'content' => 'width=device-width, initial-scale=1.0']);
    $head->link(['rel' => 'stylesheet', 'href' => 'public/clover/styles/login.css']);
    $head->link(['rel' => 'shortcut icon', 'href' => 'public/clover/icon.svg', 'type' => 'image/svg+xml']);

    $body = $html->getBody();
    $popup = $body->div(null, ['class' => 'popup']);
    $popup->img(['src' => 'public/clover/icon.svg', 'alt' => 'icon']);
    $popup->h1('Clover');
    $popup->h5('Sign in to your account');

    $form = $popup->form(['action' => "$url", 'method' => 'post', 'autocomplete' => 'on']);
    $form->label()->input(['class' => 'email', 'name' => 'email', 'type' => 'text', 'placeholder' => 'email', 'required' => null]);
    $form->label()->input(['class' => 'password', 'name' => 'password', 'type' => 'password', 'placeholder' => 'password', 'required' => null]);
    $form->button('Login', ['class' => 'blue-button']);

    $response->getContent()->set('html', $html);
    $response->getStatus()->setCode(Status::HTTP_OK);
    return self::PLUGIN_HANDLED;
  }

  /**
   * @param ResponseInterface $response
   * @return int
   */
  public function onRequest(ResponseInterface $response): int
  {
    if ($owner = $this->getOwner()) {
      if ($owner instanceof HTTPServer) {
        return $this->onLoginPage($response, $owner->getRequestUrl());
      }
    }
    return self::PLUGIN_CONTINUE;
  }

  protected function onPluginInit(): void
  {
    $this->settings = $this->getSettingsConfigFile();
    if ($owner = $this->getOwner()) {
      if ($owner instanceof HTTPServer) {
        $owner->getListeners()->set($this, $this->settings->get('auth_url'));
      }
    }
  }
}