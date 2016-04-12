<?php
/**
 * @file
 * fck_jersey_print.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function fck_jersey_print_commerce_product_default_types() {
  $items = array(
    'jersey_print' => array(
      'type' => 'jersey_print',
      'name' => 'Jersey print',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}
