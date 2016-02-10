<?php
/**
 * @file
 * md_portfolio.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function md_portfolio_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function md_portfolio_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function md_portfolio_image_default_styles() {
  $styles = array();

  // Exported image style: portfolio_grid.
  $styles['portfolio_grid'] = array(
    'label' => 'Portfolio Grid (261x263)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 261,
          'height' => 263,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: portfolio_style_2.
  $styles['portfolio_style_2'] = array(
    'label' => 'Portfolio Style 2 (355x360)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 355,
          'height' => 360,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function md_portfolio_node_info() {
  $items = array(
    'portfolio' => array(
      'name' => t('Portfolio'),
      'base' => 'node_content',
      'description' => t('Portfolio content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
