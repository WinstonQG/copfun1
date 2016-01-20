<?php
/**
 * @file
 * md_view_index.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function md_view_index_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function md_view_index_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
