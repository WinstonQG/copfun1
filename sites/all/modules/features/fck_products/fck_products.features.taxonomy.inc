<?php
/**
 * @file
 * fck_products.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function fck_products_taxonomy_default_vocabularies() {
  return array(
    'outerwear_size_adult' => array(
      'name' => 'Outerwear - Size - Adult',
      'machine_name' => 'outerwear_size_adult',
      'description' => 'Outerwear - Size - Adult',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -10,
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
    'outerwear_size_baby' => array(
      'name' => 'Outwear - Size - Baby',
      'machine_name' => 'outerwear_size_baby',
      'description' => 'Outerwear - Size - Baby',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -8,
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
    'outerwear_size_children' => array(
      'name' => 'Outerwear - Size - Children',
      'machine_name' => 'outerwear_size_children',
      'description' => 'Outerwear - Size - Children',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
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
