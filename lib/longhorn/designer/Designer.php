<?php namespace lib\longhorn\designer;

include_once('src/EntityInterface.inc');
include_once('src/Node.inc');

include_once('src/xml/XMLEntity.inc');
include_once('src/xml/XMLString.inc');
include_once('src/xml/XMLComment.inc');
include_once('src/xml/XMLDocument.inc');
include_once('src/dom/DOMDocument.inc');
include_once('src/html/HTMLDocument.inc');

use core\src\book\Book;
use core\src\book\BookInfo;

#[BookInfo('Clay Whitelytning', '1.1.3', 'Dynamic page creation using XML and HTML markup')]
final class Designer extends Book
{
}
