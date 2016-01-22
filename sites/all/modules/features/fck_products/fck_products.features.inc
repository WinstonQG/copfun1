<?php
/**
 * @file
 * fck_products.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function fck_products_commerce_product_default_types() {
  $items = array(
    'outwear_adult_custom' => array(
      'type' => 'outwear_adult_custom',
      'name' => 'Outwear Adult Custom',
      'description' => 'Outwear Adult Custom',
      'help' => '',
      'revision' => 1,
    ),
    'outwear_adult_regular' => array(
      'type' => 'outwear_adult_regular',
      'name' => 'Outwear Adult Regular',
      'description' => 'Outwear Adult Regular, attribute - Size',
      'help' => '',
      'revision' => 0,
    ),
    'outwear_baby_regular' => array(
      'type' => 'outwear_baby_regular',
      'name' => 'Outwear Baby Regular',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'outwear_children_custom' => array(
      'type' => 'outwear_children_custom',
      'name' => 'Outwear Children Custom',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'outwear_children_regular' => array(
      'type' => 'outwear_children_regular',
      'name' => 'Outwear Children Regular',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'simple_product' => array(
      'type' => 'simple_product',
      'name' => 'Simple product',
      'description' => 'Supposed to have special attributes like Size, Superliga etc',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}
