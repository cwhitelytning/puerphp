<?php namespace lib\longhorn\designer\src\html;

use lib\longhorn\designer\src\xml\XMLEntity;

/**
 * Class HTMLEntities contains HTML tags that simplify the creation of XML entities.
 * @package lib\longhorn\designer\src\html
 */
final class HTMLEntities
{
  /**
   * Adds ann element represents introductory content, typically a group of introductory or navigational aids.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/header
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function header(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('header', $attributes, $value);
  }

  /**
   * Adds ann element is used to draw the reader's attention to the element's contents,
   * which are not otherwise granted special importance.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/b
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function b(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('b', $attributes, $value);
  }

  /**
   * Adds a generic container for flow content.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/div
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function div(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('div', $attributes, $value);
  }

  /**
   * Adds a line break in the text (carriage return).
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/br
   * @return XMLEntity
   */
  public static function br(): XMLEntity
  {
    return new XMLEntity('br');
  }

  /**
   * Adds ann area inside an image map that has predefined clickable areas.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/area
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function area(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('area', $attributes, $value);
  }

  /**
   * Adds ann element links a given piece of content with a machine-readable translation.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/data
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function data(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('data', $attributes, $value);
  }

  /**
   * Adds an element represents a specific period in time.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/time
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function time(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('time', $attributes, $value);
  }

  /**
   * Adds ann element indicates that the enclosed text is an extended quotation.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/blockquote
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function blockquote(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('blockquote', $attributes, $value);
  }

  /**
   * Adds ann element is an interactive element activated by a user with a mouse, keyboard, finger, voice command,
   * or other assistive technology.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/button
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function button(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('button', $attributes, $value);
  }

  /**
   * Adds ann element with either the canvas scripting API or the WebGL API to draw graphics and animations.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/canvas
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function canvas(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('canvas', $attributes, $value);
  }

  /**
   * Adds an element specifies the caption (or title) of a table.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/caption
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function caption(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('caption', $attributes, $value);
  }

  /**
   * Adds an element provides the description, definition,
   * or value for the preceding term (<dt>) in a description list (<dl>).
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/dd
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function dd(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('dd', $attributes, $value);
  }

  /**
   * Adds an element is used to describe a reference to a cited creative work, and must include the title of that work.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/cite
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function cite(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('cite', $attributes, $value);
  }

  /**
   * Adds an element defines a column within a table and is used for defining common semantics on all common cells.
   * It is generally found within a <colgroup> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/col
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function col(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('col', $attributes, $value);
  }

  /**
   * Adds an element defines a group of columns within a table.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/colgroup
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function colgroup(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('colgroup', $attributes, $value);
  }

  /**
   * Adds an element is used to indicate the term being defined within the context of a definition phrase or sentence.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/dfn
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function dfn(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('dfn', $attributes, $value);
  }

  /**
   * Adds an element marks text that has stress emphasis.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/em
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function em(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('em', $attributes, $value);
  }

  /**
   * Adds an element embeds external content at the specified point in the document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/embed
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function embed(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('embed', $attributes, $value);
  }

  /**
   * Adds an element represents self-contained content, potentially with an optional caption,
   * which is specified using the <figcaption> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/figcaption
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function figcaption(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('figcaption', $attributes, $value);
  }

  /**
   * Adds an element represents a caption or legend describing the rest of the contents of its parent <figure> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/figcaption
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function figure(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('figure', $attributes, $value);
  }

  /**
   * Adds an element represents a document section containing interactive controls for submitting information.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/form
   * @param array $attributes
   * @return XMLEntity
   */
  public static function form(array $attributes = []): XMLEntity
  {
    return new XMLEntity('form', $attributes);
  }

  /**
   * Adds an element represents a heading and related content.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/hgroup
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function hgroup(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('hgroup', $attributes, $value);
  }

  /**
   * Adds an element represents a thematic break between paragraph-level elements: for example,
   * a change of scene in a story, or a shift of topic within a section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/hr
   * @param array $attributes
   * @return XMLEntity
   */
  public static function hr(array $attributes = []): XMLEntity
  {
    return new XMLEntity('hr', $attributes);
  }

  /**
   * Adds an element is described in the HTML specification as a semantic alternative to <ul>,
   * but treated by browsers (and exposed through the accessibility tree) as no different than <ul>.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/menu
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function menu(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('menu', $attributes, $value);
  }

  /**
   * Adds an element represents an ordered list of items — typically rendered as a numbered list.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ol
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function ol(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('ol', $attributes, $value);
  }

  /**
   * Adds an element represents preformatted text which is to be presented exactly as written in the HTML file.
   * The text is typically rendered using a non-proportional, or monospaced, font.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/pre
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function pre(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('pre', $attributes, $value);
  }

  /**
   * Adds an element represents a range of text that is set off from the normal text for some reason,
   * such as idiomatic text, technical terms, taxonomic designations, among others.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/i
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function i(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('i', $attributes, $value);
  }

  /**
   * Adds an element represents a nested browsing context, embedding another HTML page into the current one.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/iframe
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function iframe(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('iframe', $attributes, $value);
  }

  /**
   * Adds an element embeds an image into the document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/img
   * @param array $attributes
   * @return XMLEntity
   */
  public static function img(array $attributes = []): XMLEntity
  {
    return new XMLEntity('img', $attributes);
  }

  /**
   * Adds an element is used to create interactive controls for web-based forms in order to accept data from the user;
   * a wide variety of types of input data and control widgets are available, depending on the device and user agent.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/input
   * @param array $attributes
   * @return XMLEntity
   */
  public static function input(array $attributes = []): XMLEntity
  {
    return new XMLEntity('input', $attributes);
  }

  /**
   * Adds an element represents a caption for an item in a user interface.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/label
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function label(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('label', $attributes, $value);
  }

  /**
   * Adds an element represents a caption for the content of its parent <fieldset>.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/legend
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function legend(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('legend', $attributes, $value);
  }

  /**
   * Adds an element represents either a scalar value within a known range or a fractional.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/meter
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function meter(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('meter', $attributes, $value);
  }

  /**
   * Adds an element creates a grouping of options within a <select> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/optgroup
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function optgroup(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('optgroup', $attributes, $value);
  }

  /**
   * Adds an element is used to define an item contained in a <select>, an <optgroup>, or a <datalist> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/option
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function option(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('option', $attributes, $value);
  }

  /**
   * Adds an element is a container element into which a site or app can inject the results of a calculation or the outcome of a user action.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/output
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function output(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('output', $attributes, $value);
  }

  /**
   * Adds an element displays an indicator showing the completion progress of a task,
   * typically displayed as a progress bar.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/progress
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function progress(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('progress', $attributes, $value);
  }

  /**
   * Adds an element represents a control that provides a menu of options.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/progress
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function select(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('select', $attributes, $value);
  }

  /**
   * Adds an element represents a multi-line plain-text editing control,
   * useful when you want to allow users to enter a sizeable amount of free-form text,
   * for example a comment on a review or feedback form.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/textarea
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function textarea(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('textarea', $attributes, $value);
  }

  /**
   * Adds an element represents a range of text that has been added to a document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ins
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function ins(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('ins', $attributes, $value);
  }

  /**
   * Adds an element represents a range of text that has been deleted from a document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ins
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function del(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('del', $attributes, $value);
  }

  /**
   * Adds an element is used to group several controls as well as labels (<label>) within a web form.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/fieldset
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function fieldset(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('fieldset', $attributes, $value);
  }

  /**
   * Adds an element represents tabular data — that is,
   * information presented in a two-dimensional table comprised of rows and columns of cells containing data.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/table
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function table(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('table', $attributes, $value);
  }

  /**
   * Adds an element defines a set of rows defining the head of the columns of the table.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/thead
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function thead(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('thead', $attributes, $value);
  }

  /**
   * Adds an element encapsulates a set of table rows (<tr> elements),
   * indicating that they comprise the body of the table (<table>).
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/tbody
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function tbody(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('tbody', $attributes, $value);
  }

  /**
   * Adds an area inside an image map that has predefined clickable areas.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/area
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function audio(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('audio', $attributes, $value);
  }

  /**
   * Adds an element represents a portion of a document whose content is only indirectly related to the document's main content.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/aside
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function aside(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('aside', $attributes, $value);
  }

  /**
   * Adds a self-contained composition in a document, page, application, or site,
   * which is intended to be independently distributable or reusable (e.g., in syndication).
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/article
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function article(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('article', $attributes, $value);
  }

  /**
   * Adds an image map.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/map
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function map(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('map', $attributes, $value);
  }

  /**
   * Adds an element—part of the Web Components technology suite—is a placeholder inside a web component
   * that you can fill with your own markup, which lets you create separate DOM trees and present them together.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/slot
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function slot(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('slot', $attributes, $value);
  }

  /**
   * Adds an element represents side-comments and small print, like copyright and legal text,
   * independent of its styled presentation.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/small
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function small(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('small', $attributes, $value);
  }

  /**
   * Adds an element is a generic inline container for phrasing content, which does not inherently represent anything.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/small
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function span(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('span', $attributes, $value);
  }

  /**
   * Adds an element indicates that its contents have strong importance, seriousness, or urgency.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/strong
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function strong(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('strong', $attributes, $value);
  }

  /**
   * Adds an element specifies inline text which should be displayed as subscript for solely typographical reasons.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/sub
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function sub(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('sub', $attributes, $value);
  }

  /**
   * Adds an element specifies a summary, caption, or legend for a <details> element's disclosure box.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/summary
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function summary(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('summary', $attributes, $value);
  }

  /**
   * Adds an element creates a disclosure widget in which information is visible only when the widget is toggled into an "open" state.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/details
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function details(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('details', $attributes, $value);
  }

  /**
   * Adds an element specifies inline text which is to be displayed as superscript for solely typographical reasons.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/sup
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function sup(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('sup', $attributes, $value);
  }

  /**
   * Adds an element represents the name of a variable in a mathematical expression or a programming context.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/var
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function var(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('var', $attributes, $value);
  }

  /**
   * Adds an element defines a cell of a table that contains data.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/td
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function td(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('td', $attributes, $value);
  }

  /**
   * Adds an element is a mechanism for holding HTML that is not to be rendered immediately when a page
   * is loaded but may be instantiated subsequently during runtime using JavaScript.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/template
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function template(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('template', $attributes, $value);
  }

  /**
   * Adds an element defines a row of cells in a table.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/tr
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function tr(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('tr', $attributes, $value);
  }

  /**
   * Adds an element defines a set of rows summarizing the columns of the table.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/tfoot
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function tfoot(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('tfoot', $attributes, $value);
  }

  /**
   * Adds an element defines a cell as header of a group of table cells.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/th
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function th(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('th', $attributes, $value);
  }

  /**
   * Adds the header of the first section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/h1
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function h1(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('h1', $attributes, $value);
  }

  /**
   * Adds the header of the second section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/h2
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function h2(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('h2', $attributes, $value);
  }

  /**
   * Adds the header of the third section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/h3
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function h3(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('h3', $attributes, $value);
  }

  /**
   * Adds the header of the fourth section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/h4
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function h4(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('h4', $attributes, $value);
  }

  /**
   * Adds the header of the fifth section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/h5
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function h5(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('h5', $attributes, $value);
  }

  /**
   * Adds the header of the sixth section.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/h6
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function h6(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('h6', $attributes, $value);
  }

  /**
   * Adds an paragraph.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/p
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function p(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('p', $attributes, $value);
  }

  /**
   * Adds an unordered list of items.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ul
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function ul(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('ul', $attributes, $value);
  }

  /**
   * Adds an element represents a span of inline text which should be rendered in a way that indicates that it has a non-textual annotation.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ul
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function u(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('u', $attributes, $value);
  }

  /**
   * Adds an element represents a word break opportunity—a position within text where the browser may optionally break a line,
   * though its line-breaking rules would not otherwise create a break at that location.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ul
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function wbr(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('wbr', $attributes, $value);
  }

  /**
   * Adds an element represents a span of inline text denoting textual user input from a keyboard, voice input,
   * or any other text entry device.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/kbd
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function kbd(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('kbd', $attributes, $value);
  }

  /**
   * Adds an element displays its contents styled in a fashion intended to indicate that the text is a short fragment of computer code.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/code
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function code(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('code', $attributes, $value);
  }

  /**
   * Adds an item in a list.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/li
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function li(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('li', $attributes, $value);
  }

  /**
   * Adds an element tells the browser's bidirectional algorithm to treat the text it contains in isolation from its surrounding text.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/bdi
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function bdi(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('bdi', $attributes, $value);
  }

  /**
   * Adds an element overrides the current directionality of text, so that the text within is rendered in a different direction.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/bdo
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function bdo(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('bdo', $attributes, $value);
  }

  /**
   * Adds a hyperlink to web pages, files, email addresses, locations in the same page, or anything else a URL can address.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/a
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function a(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('a', $attributes, $value);
  }

  /**
   * Adds an abbreviation or acronym.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/abbr
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function abbr(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('abbr', $attributes, $value);
  }

  /**
   * Adds an element represents a section of a page whose purpose is to provide navigation links,
   * either within the current document or to other documents.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/nav
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function nav(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('nav', $attributes, $value);
  }

  /**
   * Adds an element represents an external resource, which can be treated as an image,
   * a nested browsing context, or a resource to be handled by a plugin.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/object
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function object(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('object', $attributes, $value);
  }

  /**
   * Adds an element is used as a child of the media elements, <audio> and <video>.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/source
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function source(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('source', $attributes, $value);
  }

  /**
   * Adds an element specifies multiple media resources for the <picture>, the <audio> element, or the <video> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/track
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function track(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('track', $attributes, $value);
  }

  /**
   * Adds an element embeds a media player which supports video playback into the document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/video
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function video(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('video', $attributes, $value);
  }

  /**
   * Adds an element indicates that the enclosed text is a short inline quotation.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/q
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function q(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('q', $attributes, $value);
  }

  /**
   * Adds an element is used to provide fall-back parentheses for browsers that do not support display of ruby
   * annotations using the <ruby> element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/q
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function rp(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('rp', $attributes, $value);
  }

  /**
   * Adds ann element specifies the ruby text component of a ruby annotation, which is used to provide pronunciation,
   * translation, or transliteration information for East Asian typography.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/rt
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function rt(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('rt', $attributes, $value);
  }

  /**
   * Adds an element renders text with a strikethrough, or a line through it.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/s
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function s(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('s', $attributes, $value);
  }

  /**
   * Adds ann element is used to enclose inline text which represents sample (or quoted) output from a computer program.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/samp
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function samp(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('samp', $attributes, $value);
  }

  /**
   * Adds ann element represents a generic standalone section of a document,
   * which doesn't have a more specific semantic element to represent it.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/section
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function section(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('section', $attributes, $value);
  }

  /**
   * Adds an element represents small annotations that are rendered above, below, or next to base text,
   * usually used for showing the pronunciation of East Asian characters.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/ruby
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function ruby(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('ruby', $attributes, $value);
  }

  /**
   * Adds an element contains zero or more <source> elements and one <img> element to offer alternative versions
   * of an image for different display/device scenarios.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/picture
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function picture(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('picture', $attributes, $value);
  }

  /**
   * Adds an element defines a section of HTML to be inserted if a script type on the page
   * is unsupported or if scripting is currently turned off in the browser.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/noscript
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function noscript(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('noscript', $attributes, $value);
  }

  /**
   * Adds an element indicates that the enclosed HTML provides contact information for a person or people, or for an organization.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/address
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function address(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('address', $attributes, $value);
  }

  /**
   * Adds an element represents a footer for its nearest ancestor sectioning content or sectioning root element.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/footer
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function footer(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('footer', $attributes, $value);
  }

  /**
   * Adds ann element is used to embed executable code or data;
   * this is typically used to embed or refer to JavaScript code.
   * @link https://developer.mozilla.org/ru/docs/Web/HTML/Element/script
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function script(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('script', $attributes, $value);
  }

  /**
   * Adds an element contains style information for a document, or part of a document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/style
   * @param string|null $value
   * @return XMLEntity
   */
  public static function style(?string $value = null): XMLEntity
  {
    return new XMLEntity('style', ['type' => 'text/css'], $value);
  }

  /**
   * @link https://developer.mozilla.org/ru/docs/Web/HTML/Element/title
   * @param string $value
   * @return XMLEntity
   */
  public static function title(string $value): XMLEntity
  {
    return new XMLEntity('title', [], $value);
  }

  /**
   * Adds an element represents metadata that cannot be represented by other HTML meta-related elements,
   * like <base>, <link>, <script>, <style> or <title>.
   * @link https://developer.mozilla.org/ru/docs/Web/HTML/Element/meta
   * @param array $attributes
   * @return XMLEntity
   */
  public static function meta(array $attributes): XMLEntity
  {
    return new XMLEntity('meta', $attributes);
  }

  /**
   * Adds an element specifies the base URL to use for all relative URLs in a document.
   * There can be only one <base> element in a document.
   * @link https://developer.mozilla.org/en-US/docs/Web/HTML/Element/base
   * @param string|null $value
   * @param array $attributes
   * @return XMLEntity
   */
  public static function base(array $attributes = [], ?string $value = null): XMLEntity
  {
    return new XMLEntity('base', $attributes, $value);
  }

  /**
   * Adds an element specifies relationships between the current document and an external resource.
   * @link https://developer.mozilla.org/ru/docs/Web/HTML/Element/link
   * @param array $attributes
   * @return XMLEntity
   */
  public static function link(array $attributes): XMLEntity
  {
    return new XMLEntity('link', $attributes);
  }
}