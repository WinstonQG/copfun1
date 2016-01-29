<?php
/**
 * @file
 * md_product.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function md_product_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'product_sidebar_link';
  $context->description = '';
  $context->tag = 'Product';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'product_grid:page' => 'product_grid:page',
        'product_list:page' => 'product_list:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-product_sidebar_category-block' => array(
          'module' => 'views',
          'delta' => 'product_sidebar_category-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-product_sidebar_brands-block' => array(
          'module' => 'views',
          'delta' => 'product_sidebar_brands-block',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-product_sidebar_size-block' => array(
          'module' => 'views',
          'delta' => 'product_sidebar_size-block',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-product_sidebar_color-block' => array(
          'module' => 'views',
          'delta' => 'product_sidebar_color-block',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'md_commerce_filter-commerce_filter_price' => array(
          'module' => 'md_commerce_filter',
          'delta' => 'commerce_filter_price',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Product');
  $export['product_sidebar_link'] = $context;

  return $export;
}
