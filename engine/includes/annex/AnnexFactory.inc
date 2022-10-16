<?php namespace engine\includes\annex;

include_once('Annex.inc');

/**
 * Class AnnexFactory provides the ability to add Annex objects.
 * @package engine\includes\annex
 */
class AnnexFactory extends Annex
{
  /**
   * Contains a list of all the added Annexes.
   * @var AnnexInterface[]
   */
  private $annexes = [];

  /**
   * Extracts each Annex and passes it to the callback function.
   * Stopping the iteration is performed using the return value true.
   * @param callable $callable
   */
  function fetch(callable $callable)
  {
    foreach ($this->annexes as $annex) {
      if ($callable($annex)) break;
    }
  }

  /**
   * Adds a new Annex object to the list.
   * @param AnnexInterface $annex
   * @return AnnexInterface
   */
  function add(AnnexInterface $annex): AnnexInterface
  {
    $name = $annex->getClassInfo()->getName();
    return $this->annexes[$name] = $annex;
  }

  /**
   * Unloads the Annex from the list.
   * @param string $name
   */
  function unload(string $name)
  {
    $this->annexes[$name] = null;
    unset($this->annexes[$name]);
  }
}
