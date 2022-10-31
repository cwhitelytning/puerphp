<?php namespace modules\designer;

include_once('src/EntityInterface.inc');
include_once('src/Node.inc');

include_once('src/xml/XMLEntity.inc');
include_once('src/xml/XMLString.inc');
include_once('src/xml/XMLComment.inc');
include_once('src/xml/XMLDocument.inc');
include_once('src/dom/DOMDocument.inc');
include_once('src/html/HTMLDocument.inc');

use core\src\module\Module;
use core\src\module\ModuleInfo;

#[
  ModuleInfo
  (
    author: 'Clay Whitelytning',
    version: '1.1.3',
    description: 'Dynamic page creation using XML and HTML markup'
  )
]
final class Designer extends Module
{
}
