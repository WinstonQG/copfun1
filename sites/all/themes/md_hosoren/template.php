<?php

include_once './' . drupal_get_path('theme', 'md_hosoren') . '/theme_setting/front/html.preprocess.inc';
include_once './' . drupal_get_path('theme', 'md_hosoren') . '/theme_setting/front/page.preprocess.inc';
include_once './' . drupal_get_path('theme', 'md_hosoren') . '/theme_setting/front/function.theme.inc';

function md_hosoren_facetapi_title($variables) {
  return t('@title', array('@title' => drupal_strtolower($variables['title'])));
}

function md_hosoren_facetapi_count($variables) {
  $count = (int) $variables['count'];
  $one_item = t('pc.');
  $more_items = t('pcs.');
  //pcs.   
  $output = format_plural($count, '1 ' . $one_item, '@count ' . $more_items);
  return '<span class="facet-count">(' . $output . ')</span>';
}

/**
 * Implements hook_js_alter()
 * Add/ Remove JS
 */
function md_hosoren_js_alter(&$js) {
  unset($js[drupal_get_path('module', 'views_infinite_scroll') . '/js/jquery.autopager-1.0.0.js']);
  unset($js[drupal_get_path('module', 'views_infinite_scroll') . '/js/views_infinite_scroll.js']);
	unset($js[drupal_get_path('module', 'awecontent') . '/js/awecontent/lib/owl.carousel/owl.carousel.js']);
}

function md_hosoren_preprocess_views_view(&$vars) {
  
  $view = $vars['view'];
  $path_theme = drupal_get_path('theme', 'md_hosoren');
  if ($view->query->pager->plugin_name == 'infinite_scroll') {
    drupal_add_js("{$path_theme}/js/libs/scroll_load/jquery.autopager-1.0.0.js", array('weight' => 6));
    drupal_add_js("{$path_theme}/js/libs/scroll_load/views_infinite_scroll.js", array('weight' => 7));
  }
  /*if ($view->name == 'lasted_portfolios' || $view->name == 'product_slider') {
    drupal_add_css("{$path_theme}/css/libs/owl.carousel/owl.carousel.css", array('weight' => 7));
    drupal_add_css("{$path_theme}/css/libs/owl.carousel/owl.theme.css", array('weight' => 7));
    drupal_add_css("{$path_theme}/css/libs/owl.carousel/owl.transitions.css", array('weight' => 7));
    drupal_add_js(drupal_get_path('module', 'awecontent') .'/js/awecontent/lib/owl.carousel/owl.carousel.js');
  }*/
}

function md_hosoren_field(&$vars) {
  $output = '';
  // PORTFOLIO FIELD
  if ($vars['element']['#field_name'] == 'field_portfolio_date' || $vars['element']['#field_name'] == 'field_portfolio_client') {
    // Render the label, if it's not hidden.
    if (!$vars ['label_hidden']) {
      $output .= '<span class="name">' . $vars ['label'] . ':&nbsp;</span>';
    }
    // Render the items.
    foreach ($vars ['items'] as $delta => $item) {
      $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
      $output .= '<span class="value">' . drupal_render($item) . '</span>';
    }
    // Render the top-level DIV.
    $output = '<li><div class="' . $vars ['classes'] . '"' . $vars ['attributes'] . '>' . $output . '</div></li>';
    return $output;
  }
  elseif ($vars['element']['#field_name'] == 'field_project_description') {
    // Render the label, if it's not hidden.
    if (!$vars ['label_hidden']) {
      $output .= '<h2 class="portfolio-title">' . $vars ['label'] . '</h2>';
    }
    // Render the items.
    foreach ($vars ['items'] as $delta => $item) {
      $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
      $output .= '<div class="portfolio-desc"><p>' . drupal_render($item) . '</p></div>';
    }
    // Render the top-level DIV.
    $output = '<div class="' . $vars ['classes'] . '"' . $vars ['attributes'] . '>' . $output . '</div>';
    return $output;
  }
  else {
    // DEFAUTL FIELD
    // Render the label, if it's not hidden.
    if (!$vars ['label_hidden']) {
      $output .= '<div class="field-label"' . $vars ['title_attributes'] . '>' . $vars ['label'] . ':&nbsp;</div>';
    }

    // Render the items.
    $output .= '<div class="field-items"' . $vars ['content_attributes'] . '>';
    foreach ($vars ['items'] as $delta => $item) {
      $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
      $output .= '<div class="' . $classes . '"' . $vars ['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
    }
    $output .= '</div>';

    // Render the top-level DIV.
    $output = '<div class="' . $vars ['classes'] . '"' . $vars ['attributes'] . '>' . $output . '</div>';

    return $output;
  }
}

/**
 * Implement hook_preprocess_node()
 */
function md_hosoren_preprocess_node(&$vars) {

  global $base_url;
  $node = $vars['node'];
  $content_type = $vars['type'];

  // Content type Product
  if ($content_type === 'shop_product') {

    //field categories
    $categories_content = '';
    $field_categories = field_get_items('node', $node, 'field_product_category');    
    if (isset($field_categories) && !empty($field_categories)) {
      foreach ($field_categories as $key => $categories_item) {
        if (isset($categories_item['taxonomy_term'])) {
          $categories_content .= l($categories_item['taxonomy_term']->name, 'taxonomy/term/' . $categories_item['taxonomy_term']->tid);
        }
      }
    }
    $vars['categories_list'] = $categories_content;
  }
  if ($content_type === 'portfolio') {
    $user_path_portfolio = theme_get_setting('portfolio_main_url');
    if (($user_path_portfolio != NULL) || $user_path_portfolio != "") {
      $vars['portfolio_path'] = $base_url . '/' . $user_path_portfolio;
    }
    else {
      $vars['portfolio_path'] = NULL;
    }
  }
}

function md_hosoren_node_recent_content($vars) {
//  if ($vars['node']->type == 'testimonials') {
    $node = $vars['node'];
    $output = '<ul><li><h3 class="node-title">';
    $output .= l($node->title, 'node/' . $node->nid);
    $output .= theme('mark', array('type' => node_mark($node->nid, $node->changed)));
    $output .= '</h3></li>';
    $output .= '</ul>';
    return $output;
//  }
}
