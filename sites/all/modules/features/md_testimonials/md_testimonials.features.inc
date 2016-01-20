<?php
/**
 * @file
 * md_testimonials.features.inc
 */

/**
 * Implements hook_views_api().
 */
function md_testimonials_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function md_testimonials_image_default_styles() {
  $styles = array();

  // Exported image style: customer_avatar.
  $styles['customer_avatar'] = array(
    'label' => 'Customer Avatar ( 62x62)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 62,
          'height' => 62,
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
function md_testimonials_node_info() {
  $items = array(
    'testimonials' => array(
      'name' => t('Testimonials'),
      'base' => 'node_content',
      'description' => t('Content type Testimonial'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
