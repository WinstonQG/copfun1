<?php
/**
 * @file
 * md_product.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function md_product_taxonomy_default_vocabularies() {
  return array(
    'player_jerseys' => array(
      'name' => 'Player Jerseys',
      'machine_name' => 'player_jerseys',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -1,
      'language' => 'und',
      'i18n_mode' => 1,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'sale' => array(
      'name' => 'Sale',
      'machine_name' => 'sale',
      'description' => 'Sale',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
