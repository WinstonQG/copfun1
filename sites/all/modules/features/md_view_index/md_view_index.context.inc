<?php
/**
 * @file
 * md_view_index.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function md_view_index_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'product_sidebar_filter';
  $context->description = '';
  $context->tag = 'Product';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'product_filter_api:page' => 'product_filter_api:page',
        'product_filter_api:page_1' => 'product_filter_api:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-aUBynzWqsqN8DntU0P5K5r1LC2f06Mgx' => array(
          'module' => 'facetapi',
          'delta' => 'aUBynzWqsqN8DntU0P5K5r1LC2f06Mgx',
          'region' => 'sidebar_first',
          'weight' => '-38',
        ),
        'facetapi-3wqzo3sMeDJzgFCrXCl5S9jvzNrlqa2v' => array(
          'module' => 'facetapi',
          'delta' => '3wqzo3sMeDJzgFCrXCl5S9jvzNrlqa2v',
          'region' => 'sidebar_first',
          'weight' => '-37',
        ),
        'facetapi-1O6An3MfU0abdB81wY4NtF3kVB9LCFhy' => array(
          'module' => 'facetapi',
          'delta' => '1O6An3MfU0abdB81wY4NtF3kVB9LCFhy',
          'region' => 'sidebar_first',
          'weight' => '-36',
        ),
        'facetapi-nLaP86V4l07HBEzcULZLSjFpLJAMcruw' => array(
          'module' => 'facetapi',
          'delta' => 'nLaP86V4l07HBEzcULZLSjFpLJAMcruw',
          'region' => 'sidebar_first',
          'weight' => '-35',
        ),
        'facetapi-nmlI6RuATuqr1ct1Dmt6xTgerTplufmU' => array(
          'module' => 'facetapi',
          'delta' => 'nmlI6RuATuqr1ct1Dmt6xTgerTplufmU',
          'region' => 'sidebar_first',
          'weight' => '-34',
        ),
        'facetapi-90MVbspVIqbs41n5g13AqMIy5kLf1eND' => array(
          'module' => 'facetapi',
          'delta' => '90MVbspVIqbs41n5g13AqMIy5kLf1eND',
          'region' => 'sidebar_first',
          'weight' => '-33',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Product');
  $export['product_sidebar_filter'] = $context;

  return $export;
}
