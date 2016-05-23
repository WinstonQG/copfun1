<?php
/**
 * @file
 * md_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function md_blog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "taxonomy_display" && $api == "taxonomy_display") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function md_blog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function md_blog_image_default_styles() {
  $styles = array();

  // Exported image style: blog_preview_thumbs.
  $styles['blog_preview_thumbs'] = array(
    'label' => 'Blog Preview Thumbs',
    'effects' => array(
      18 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 340,
          'height' => 340,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: news_blog_image_style.
  $styles['news_blog_image_style'] = array(
    'label' => 'News Blog Image Style (270X207)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 270,
          'height' => 207,
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
function md_blog_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
