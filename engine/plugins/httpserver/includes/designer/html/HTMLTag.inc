<?php namespace engine\plugins\httpserver\packages\designer\html;

use engine\plugins\httpserver\packages\designer\xml\XMLTag;

/**
 * Class HtmlTag
 * @package engine\plugins\httpserver\packages\designer\html
 */
class HTMLTag extends XMLTag
{
  /**
   * Adds a element represents introductory content, typically a group of introductory or navigational aids.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/header
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function header(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('header', $value, $attributes);
  }

  /**
   * Adds a element is used to draw the reader's attention to the element's contents,
   * which are not otherwise granted special importance.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/b
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function b(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('b', $value, $attributes);
  }

  /**
   * Adds a generic container for flow content.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/div
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function div(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('div', $value, $attributes);
  }

  /**
   * Adds a line break in the text (carriage return).
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/br
   * @return $this
   */
  public function br(): HTMLTag
  {
    return $this->addTag('br');
  }

  /**
   * Adds a area inside an image map that has predefined clickable areas.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/area
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function area(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('area', $value, $attributes);
  }

  /**
   * Adds a element links a given piece of content with a machine-readable translation.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/data
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function data(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('data', $value, $attributes);
  }

  /**
   * Adds a element represents a specific period in time.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/time
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function time(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('time', $value, $attributes);
  }

  /**
   * Adds a element indicates that the enclosed text is an extended quotation.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/blockquote
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function blockquote(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('blockquote', $value, $attributes);
  }

  /**
   * Adds a element is an interactive element activated by a user with a mouse, keyboard, finger, voice command,
   * or other assistive technology.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/button
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function button(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('button', $value, $attributes);
  }

  /**
   * Adds a element with either the canvas scripting API or the WebGL API to draw graphics and animations.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/canvas
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function canvas(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('canvas', $value, $attributes);
  }

  /**
   * Adds a element specifies the caption (or title) of a table.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/caption
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function caption(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('caption', $value, $attributes);
  }

  /**
   * Adds a element provides the description, definition,
   * or value for the preceding term (<dt>) in a description list (<dl>).
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/dd
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function dd(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('dd', $value, $attributes);
  }

  /**
   * Adds a element is used to describe a reference to a cited creative work, and must include the title of that work.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/cite
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function cite(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('cite', $value, $attributes);
  }

  /**
   * Adds a element defines a column within a table and is used for defining common semantics on all common cells.
   * It is generally found within a <colgroup> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/col
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function col(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('col', $value, $attributes);
  }

  /**
   * Adds a element defines a group of columns within a table.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/colgroup
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function colgroup(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('colgroup', $value, $attributes);
  }

  /**
   * Adds a element is used to indicate the term being defined within the context of a definition phrase or sentence.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/dfn
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function dfn(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('dfn', $value, $attributes);
  }

  /**
   * Adds a element marks text that has stress emphasis.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/em
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function em(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('em', $value, $attributes);
  }

  /**
   * Adds a element embeds external content at the specified point in the document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/embed
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function embed(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('embed', $value, $attributes);
  }

  /**
   * Adds a element represents self-contained content, potentially with an optional caption,
   * which is specified using the <figcaption> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/figcaption
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function figcaption(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('figcaption', $value, $attributes);
  }

  /**
   * Adds a element represents a caption or legend describing the rest of the contents of its parent <figure> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/figcaption
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function figure(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('figure', $value, $attributes);
  }

  /**
   * Adds a element represents a document section containing interactive controls for submitting information.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/form
   * @param array $attributes
   * @return $this
   */
  public function form(array $attributes = []): HTMLTag
  {
    return $this->addTag('form', null, $attributes);
  }

  /**
   * Adds a element represents a heading and related content.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/hgroup
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function hgroup(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('hgroup', $value, $attributes);
  }

  /**
   * Adds a element represents a thematic break between paragraph-level elements: for example,
   * a change of scene in a story, or a shift of topic within a section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/hr
   * @param array $attributes
   * @return $this
   */
  public function hr(array $attributes = []): HTMLTag
  {
    return $this->addTag('hr', null, $attributes);
  }

  /**
   * Adds a element is described in the HTML specification as a semantic alternative to <ul>,
   * but treated by browsers (and exposed through the accessibility tree) as no different than <ul>.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/menu
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function menu(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('menu', $value, $attributes);
  }

  /**
   * Adds a element represents an ordered list of items — typically rendered as a numbered list.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ol
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function ol(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('ol', $value, $attributes);
  }

  /**
   * Adds a element represents preformatted text which is to be presented exactly as written in the HTML file.
   * The text is typically rendered using a non-proportional, or monospaced, font.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/pre
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function pre(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('pre', $value, $attributes);
  }

  /**
   * Adds a element represents a range of text that is set off from the normal text for some reason,
   * such as idiomatic text, technical terms, taxonomical designations, among others.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/i
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function i(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('i', $value, $attributes);
  }

  /**
   * Adds a element represents a nested browsing context, embedding another HTML page into the current one.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/iframe
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function iframe(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('iframe', $value, $attributes);
  }

  /**
   * Adds a element embeds an image into the document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/img
   * @param array $attributes
   * @return $this
   */
  public function img(array $attributes = []): HTMLTag
  {
    return $this->addTag('img', null, $attributes);
  }

  /**
   * Adds a element is used to create interactive controls for web-based forms in order to accept data from the user;
   * a wide variety of types of input data and control widgets are available, depending on the device and user agent.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/input
   * @param array $attributes
   * @return $this
   */
  public function input(array $attributes = []): HTMLTag
  {
    return $this->addTag('input', null, $attributes);
  }

  /**
   * Adds a element represents a caption for an item in a user interface.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/label
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function label(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('label', $value, $attributes);
  }

  /**
   * Adds a element represents a caption for the content of its parent <fieldset>.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/legend
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function legend(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('legend', $value, $attributes);
  }

  /**
   * Adds a element represents either a scalar value within a known range or a fractional.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/meter
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function meter(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('meter', $value, $attributes);
  }

  /**
   * Adds a element creates a grouping of options within a <select> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/optgroup
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function optgroup(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('optgroup', $value, $attributes);
  }

  /**
   * Adds a element is used to define an item contained in a <select>, an <optgroup>, or a <datalist> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/option
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function option(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('option', $value, $attributes);
  }

  /**
   * Adds a element is a container element into which a site or app can inject the results of a calculation or the outcome of a user action.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/output
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function output(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('output', $value, $attributes);
  }

  /**
   * Adds a element displays an indicator showing the completion progress of a task,
   * typically displayed as a progress bar.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/progress
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function progress(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('progress', $value, $attributes);
  }

  /**
   * Adds a element represents a control that provides a menu of options.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/progress
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function select(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('select', $value, $attributes);
  }

  /**
   * Adds a element represents a multi-line plain-text editing control,
   * useful when you want to allow users to enter a sizeable amount of free-form text,
   * for example a comment on a review or feedback form.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/textarea
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function textarea(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('textarea', $value, $attributes);
  }

  /**
   * Adds a element represents a range of text that has been added to a document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ins
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function ins(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('ins', $value, $attributes);
  }

  /**
   * Adds a element represents a range of text that has been deleted from a document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ins
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function del(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('del', $value, $attributes);
  }

  /**
   * Adds a element is used to group several controls as well as labels (<label>) within a web form.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/fieldset
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function fieldset(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('fieldset', $value, $attributes);
  }

  /**
   * Adds a element represents tabular data — that is,
   * information presented in a two-dimensional table comprised of rows and columns of cells containing data.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/table
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function table(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('table', $value, $attributes);
  }

  /**
   * Adds a element defines a set of rows defining the head of the columns of the table.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/thead
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function thead(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('thead', $value, $attributes);
  }

  /**
   * Adds a element encapsulates a set of table rows (<tr> elements),
   * indicating that they comprise the body of the table (<table>).
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/tbody
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function tbody(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('tbody', $value, $attributes);
  }

  /**
   * Adds a area inside an image map that has predefined clickable areas.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/area
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function audio(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('audio', $value, $attributes);
  }

  /**
   * Adds a element represents a portion of a document whose content is only indirectly related to the document's main content.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/aside
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function aside(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('aside', $value, $attributes);
  }

  /**
   * Adds a self-contained composition in a document, page, application, or site,
   * which is intended to be independently distributable or reusable (e.g., in syndication).
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/article
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function article(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('article', $value, $attributes);
  }

  /**
   * Adds a image map.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/map
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function map(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('map', $value, $attributes);
  }

  /**
   * Adds a element—part of the Web Components technology suite—is a placeholder inside a web component
   * that you can fill with your own markup, which lets you create separate DOM trees and present them together.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/slot
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function slot(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('slot', $value, $attributes);
  }

  /**
   * Adds a element represents side-comments and small print, like copyright and legal text,
   * independent of its styled presentation.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/small
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function small(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('small', $value, $attributes);
  }

  /**
   * Adds a element is a generic inline container for phrasing content, which does not inherently represent anything.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/small
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function span(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('span', $value, $attributes);
  }

  /**
   * Adds a element indicates that its contents have strong importance, seriousness, or urgency.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/strong
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function strong(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('strong', $value, $attributes);
  }

  /**
   * Adds a element specifies inline text which should be displayed as subscript for solely typographical reasons.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/sub
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function sub(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('sub', $value, $attributes);
  }

  /**
   * Adds a element specifies a summary, caption, or legend for a <details> element's disclosure box.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/summary
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function summary(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('summary', $value, $attributes);
  }

  /**
   * Adds a element creates a disclosure widget in which information is visible only when the widget is toggled into an "open" state.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/details
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function details(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('details', $value, $attributes);
  }

  /**
   * Adds a element specifies inline text which is to be displayed as superscript for solely typographical reasons.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/sup
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function sup(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('sup', $value, $attributes);
  }

  /**
   * Adds a element represents the name of a variable in a mathematical expression or a programming context.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/var
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function var(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('var', $value, $attributes);
  }

  /**
   * Adds a element defines a cell of a table that contains data.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/td
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function td(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('td', $value, $attributes);
  }

  /**
   * Adds a element is a mechanism for holding HTML that is not to be rendered immediately when a page
   * is loaded but may be instantiated subsequently during runtime using JavaScript.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/template
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function template(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('template', $value, $attributes);
  }

  /**
   * Adds a element defines a row of cells in a table.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/tr
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function tr(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('tr', $value, $attributes);
  }

  /**
   * Adds a element defines a set of rows summarizing the columns of the table.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/tfoot
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function tfoot(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('tfoot', $value, $attributes);
  }

  /**
   * Adds a element defines a cell as header of a group of table cells.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/th
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function th(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('th', $value, $attributes);
  }

  /**
   * Adds the header of the first section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/h1
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function h1(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('h1', $value, $attributes);
  }

  /**
   * Adds the header of the second section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/h2
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function h2(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('h2', $value, $attributes);
  }

  /**
   * Adds the header of the third section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/h3
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function h3(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('h3', $value, $attributes);
  }

  /**
   * Adds the header of the fourth section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/h4
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function h4(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('h4', $value, $attributes);
  }

  /**
   * Adds the header of the fifth section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/h5
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function h5(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('h5', $value, $attributes);
  }

  /**
   * Adds the header of the sixth section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/h6
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function h6(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('h6', $value, $attributes);
  }

  /**
   * Adds a paragraph.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/p
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function p(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('p', $value, $attributes);
  }

  /**
   * Adds a unordered list of items.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ul
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function ul(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('ul', $value, $attributes);
  }

  /**
   * Adds a element represents a span of inline text which should be rendered in a way that indicates that it has a non-textual annotation.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ul
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function u(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('u', $value, $attributes);
  }

  /**
   * Adds a element represents a word break opportunity—a position within text where the browser may optionally break a line,
   * though its line-breaking rules would not otherwise create a break at that location.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ul
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function wbr(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('wbr', $value, $attributes);
  }

  /**
   * Adds a element represents a span of inline text denoting textual user input from a keyboard, voice input,
   * or any other text entry device.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/kbd
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function kbd(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('kbd', $value, $attributes);
  }

  /**
   * Adds a element displays its contents styled in a fashion intended to indicate that the text is a short fragment of computer code.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/code
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function code(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('code', $value, $attributes);
  }

  /**
   * Adds a item in a list.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/li
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function li(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('li', $value, $attributes);
  }

  /**
   * Adds a element tells the browser's bidirectional algorithm to treat the text it contains in isolation from its surrounding text.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/bdi
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function bdi(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('bdi', $value, $attributes);
  }

  /**
   * Adds a element overrides the current directionality of text, so that the text within is rendered in a different direction.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/bdo
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function bdo(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('bdo', $value, $attributes);
  }

  /**
   * Added a hyperlink to web pages, files, email addresses, locations in the same page, or anything else a URL can address.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/a
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function a(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('a', $value, $attributes);
  }

  /**
   * Added a abbreviation or acronym.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/abbr
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function abbr(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('abbr', $value, $attributes);
  }

  /**
   * Added a element represents a section of a page whose purpose is to provide navigation links,
   * either within the current document or to other documents.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/nav
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function nav(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('nav', $value, $attributes);
  }

  /**
   * Added a element represents an external resource, which can be treated as an image,
   * a nested browsing context, or a resource to be handled by a plugin.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/object
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function object(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('object', $value, $attributes);
  }

  /**
   * Added a element is used as a child of the media elements, <audio> and <video>.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/source
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function source(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('source', $value, $attributes);
  }

  /**
   * Added a element specifies multiple media resources for the <picture>, the <audio> element, or the <video> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/track
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function track(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('track', $value, $attributes);
  }

  /**
   * Added a element embeds a media player which supports video playback into the document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/video
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function video(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('video', $value, $attributes);
  }

  /**
   * Added a element indicates that the enclosed text is a short inline quotation.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/q
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function q(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('q', $value, $attributes);
  }

  /**
   * Added a element is used to provide fall-back parentheses for browsers that do not support display of ruby
   * annotations using the <ruby> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/q
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function rp(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('rp', $value, $attributes);
  }

  /**
   * Added a element specifies the ruby text component of a ruby annotation, which is used to provide pronunciation,
   * translation, or transliteration information for East Asian typography.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/rt
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function rt(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('rt', $value, $attributes);
  }

  /**
   * Added a element renders text with a strikethrough, or a line through it.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/s
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function s(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('s', $value, $attributes);
  }

  /**
   * Added a element is used to enclose inline text which represents sample (or quoted) output from a computer program.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/samp
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function samp(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('samp', $value, $attributes);
  }

  /**
   * Added a element represents a generic standalone section of a document,
   * which doesn't have a more specific semantic element to represent it.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/section
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function section(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('section', $value, $attributes);
  }

  /**
   * Added a element represents small annotations that are rendered above, below, or next to base text,
   * usually used for showing the pronunciation of East Asian characters.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ruby
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function ruby(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('ruby', $value, $attributes);
  }

  /**
   * Added a element contains zero or more <source> elements and one <img> element to offer alternative versions
   * of an image for different display/device scenarios.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/picture
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function picture(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('picture', $value, $attributes);
  }

  /**
   * Added a element defines a section of HTML to be inserted if a script type on the page
   * is unsupported or if scripting is currently turned off in the browser.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/noscript
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function noscript(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('noscript', $value, $attributes);
  }

  /**
   * Adds a element indicates that the enclosed HTML provides contact information for a person or people, or for an organization.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/address
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function address(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('address', $value, $attributes);
  }

  /**
   * Adds a element represents a footer for its nearest ancestor sectioning content or sectioning root element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/footer
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function footer(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('footer', $value, $attributes);
  }

  /**
   * Adds a element is used to embed executable code or data;
   * this is typically used to embed or refer to JavaScript code.
   * @link https://developer.mozilla.org/ru/docs/Web/HTML/Element/script
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function script(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('script', $value, $attributes);
  }

  /**
   * Adds a element contains style information for a document, or part of a document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/style
   * @param string|null $value
   * @return $this
   */
  public function style(?string $value = null): HTMLTag
  {
    return $this->addTag('style', $value, ['type' => 'text/css']);
  }

  /**
   * @link https://developer.mozilla.org/ru/docs/Web/HTML/Element/title
   * @param string $value
   * @return $this
   */
  public function title(string $value): HTMLTag
  {
    return $this->addTag('title', $value);
  }

  /**
   * Adds a element represents metadata that cannot be represented by other HTML meta-related elements,
   * like <base>, <link>, <script>, <style> or <title>.
   * @link https://developer.mozilla.org/ru/docs/Web/HTML/Element/meta
   * @param array $attributes
   * @return $this
   */
  public function meta(array $attributes): HTMLTag
  {
    return $this->addTag('meta', null, $attributes);
  }

  /**
   * Adds a element specifies the base URL to use for all relative URLs in a document.
   * There can be only one <base> element in a document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/base
   * @param string|null $value
   * @param array $attributes
   * @return $this
   */
  public function base(?string $value = null, array $attributes = []): HTMLTag
  {
    return $this->addTag('base', $value, $attributes);
  }

  /**
   * Adds a element specifies relationships between the current document and an external resource.
   * @link https://developer.mozilla.org/ru/docs/Web/HTML/Element/link
   * @param array $attributes
   * @return $this
   */
  public function link(array $attributes): HTMLTag
  {
    return $this->addTag('link', null, $attributes);
  }
}
