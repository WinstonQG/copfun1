<?php
/**
 * @file
 * fck_admin_pages.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function fck_admin_pages_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'fck_sorting';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FCK Sorting';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'New Products';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Product Store */
  $handler->display->display_options['fields']['field_product_store']['id'] = 'field_product_store';
  $handler->display->display_options['fields']['field_product_store']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['fields']['field_product_store']['field'] = 'field_product_store';
  $handler->display->display_options['fields']['field_product_store']['label'] = '';
  $handler->display->display_options['fields']['field_product_store']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_store']['type'] = 'commerce_product_reference_rendered_product';
  $handler->display->display_options['fields']['field_product_store']['settings'] = array(
    'view_mode' => 'full',
    'page' => 1,
  );
  $handler->display->display_options['fields']['field_product_store']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_product_store']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Weight Hot Selector */
  $handler->display->display_options['fields']['field_weight_hot_selector']['id'] = 'field_weight_hot_selector';
  $handler->display->display_options['fields']['field_weight_hot_selector']['table'] = 'field_data_field_weight_hot';
  $handler->display->display_options['fields']['field_weight_hot_selector']['field'] = 'field_weight_hot_selector';
  $handler->display->display_options['fields']['field_weight_hot_selector']['label'] = '';
  $handler->display->display_options['fields']['field_weight_hot_selector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_weight_hot_selector']['weight_range'] = '20';
  /* Field: Content: All taxonomy terms (translated) */
  $handler->display->display_options['fields']['term_node_tid_i18n']['id'] = 'term_node_tid_i18n';
  $handler->display->display_options['fields']['term_node_tid_i18n']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_i18n']['field'] = 'term_node_tid_i18n';
  $handler->display->display_options['fields']['term_node_tid_i18n']['label'] = 'Categories';
  $handler->display->display_options['fields']['term_node_tid_i18n']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid_i18n']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_i18n']['vocabularies'] = array(
    'outerwear_size_adult' => 0,
    'outerwear_size_children' => 0,
    'outerwear_size_baby' => 0,
    'player_jerseys' => 0,
    'match_kits' => 0,
    'accessories' => 0,
    'clothing' => 0,
    'sale' => 0,
    'baby' => 0,
    'categories_blog' => 0,
    'gifts' => 0,
    'news' => 0,
    'portfolio_categories' => 0,
    'product_brand' => 0,
    'product_category' => 0,
    'product_lookbook' => 0,
    'product_store_color' => 0,
    'product_store_size' => 0,
    'product_trending' => 0,
    'newsletter' => 0,
    'tags' => 0,
    'tags_blog' => 0,
    'foot_size' => 0,
    'jersey_print_players' => 0,
  );
  /* Field: Content: Weight Clothing */
  $handler->display->display_options['fields']['field_weight_clothing']['id'] = 'field_weight_clothing';
  $handler->display->display_options['fields']['field_weight_clothing']['table'] = 'field_data_field_weight_clothing';
  $handler->display->display_options['fields']['field_weight_clothing']['field'] = 'field_weight_clothing';
  /* Sort criterion: Content: Weight Hot (field_weight_hot) */
  $handler->display->display_options['sorts']['field_weight_hot_value']['id'] = 'field_weight_hot_value';
  $handler->display->display_options['sorts']['field_weight_hot_value']['table'] = 'field_data_field_weight_hot';
  $handler->display->display_options['sorts']['field_weight_hot_value']['field'] = 'field_weight_hot_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'shop_product' => 'shop_product',
  );
  /* Filter criterion: Content: Product Store (field_product_store:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';

  /* Display: New */
  $handler = $view->new_display('page', 'New', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'New Products';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Product Store */
  $handler->display->display_options['fields']['field_product_store']['id'] = 'field_product_store';
  $handler->display->display_options['fields']['field_product_store']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['fields']['field_product_store']['field'] = 'field_product_store';
  $handler->display->display_options['fields']['field_product_store']['label'] = '';
  $handler->display->display_options['fields']['field_product_store']['type'] = 'commerce_product_reference_rendered_product';
  $handler->display->display_options['fields']['field_product_store']['settings'] = array(
    'view_mode' => 'full',
    'page' => 1,
  );
  $handler->display->display_options['fields']['field_product_store']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_product_store']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Weight New Selector */
  $handler->display->display_options['fields']['field_weight_new_selector']['id'] = 'field_weight_new_selector';
  $handler->display->display_options['fields']['field_weight_new_selector']['table'] = 'field_data_field_weight_new';
  $handler->display->display_options['fields']['field_weight_new_selector']['field'] = 'field_weight_new_selector';
  $handler->display->display_options['fields']['field_weight_new_selector']['label'] = '';
  $handler->display->display_options['fields']['field_weight_new_selector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_weight_new_selector']['weight_range'] = '20';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Weight New (field_weight_new) */
  $handler->display->display_options['sorts']['field_weight_new_value']['id'] = 'field_weight_new_value';
  $handler->display->display_options['sorts']['field_weight_new_value']['table'] = 'field_data_field_weight_new';
  $handler->display->display_options['sorts']['field_weight_new_value']['field'] = 'field_weight_new_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'shop_product' => 'shop_product',
  );
  /* Filter criterion: Content: Group (field_group) */
  $handler->display->display_options['filters']['field_group_value']['id'] = 'field_group_value';
  $handler->display->display_options['filters']['field_group_value']['table'] = 'field_data_field_group';
  $handler->display->display_options['filters']['field_group_value']['field'] = 'field_group_value';
  $handler->display->display_options['filters']['field_group_value']['value'] = array(
    'new' => 'new',
  );
  /* Filter criterion: Content: Product Store (field_product_store:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'admin/fck/sorting/new-products';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'New products';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Reorder Products';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Hot */
  $handler = $view->new_display('page', 'Hot', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Hot Products';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Product Store */
  $handler->display->display_options['fields']['field_product_store']['id'] = 'field_product_store';
  $handler->display->display_options['fields']['field_product_store']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['fields']['field_product_store']['field'] = 'field_product_store';
  $handler->display->display_options['fields']['field_product_store']['label'] = '';
  $handler->display->display_options['fields']['field_product_store']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_store']['type'] = 'commerce_product_reference_rendered_product';
  $handler->display->display_options['fields']['field_product_store']['settings'] = array(
    'view_mode' => 'full',
    'page' => 1,
  );
  $handler->display->display_options['fields']['field_product_store']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_product_store']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Weight Hot Selector */
  $handler->display->display_options['fields']['field_weight_hot_selector']['id'] = 'field_weight_hot_selector';
  $handler->display->display_options['fields']['field_weight_hot_selector']['table'] = 'field_data_field_weight_hot';
  $handler->display->display_options['fields']['field_weight_hot_selector']['field'] = 'field_weight_hot_selector';
  $handler->display->display_options['fields']['field_weight_hot_selector']['label'] = '';
  $handler->display->display_options['fields']['field_weight_hot_selector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_weight_hot_selector']['weight_range'] = '20';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'shop_product' => 'shop_product',
  );
  /* Filter criterion: Content: Group (field_group) */
  $handler->display->display_options['filters']['field_group_value']['id'] = 'field_group_value';
  $handler->display->display_options['filters']['field_group_value']['table'] = 'field_data_field_group';
  $handler->display->display_options['filters']['field_group_value']['field'] = 'field_group_value';
  $handler->display->display_options['filters']['field_group_value']['value'] = array(
    'hot' => 'hot',
  );
  /* Filter criterion: Content: Product Store (field_product_store:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'admin/fck/sorting/hot-products';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Hot Products';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Clothing */
  $handler = $view->new_display('page', 'Clothing', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Clothing';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Product Store */
  $handler->display->display_options['fields']['field_product_store']['id'] = 'field_product_store';
  $handler->display->display_options['fields']['field_product_store']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['fields']['field_product_store']['field'] = 'field_product_store';
  $handler->display->display_options['fields']['field_product_store']['label'] = '';
  $handler->display->display_options['fields']['field_product_store']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_store']['type'] = 'commerce_product_reference_rendered_product';
  $handler->display->display_options['fields']['field_product_store']['settings'] = array(
    'view_mode' => 'full',
    'page' => 1,
  );
  $handler->display->display_options['fields']['field_product_store']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_product_store']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Weight Clothing Selector */
  $handler->display->display_options['fields']['field_weight_clothing_selector']['id'] = 'field_weight_clothing_selector';
  $handler->display->display_options['fields']['field_weight_clothing_selector']['table'] = 'field_data_field_weight_clothing';
  $handler->display->display_options['fields']['field_weight_clothing_selector']['field'] = 'field_weight_clothing_selector';
  $handler->display->display_options['fields']['field_weight_clothing_selector']['label'] = '';
  $handler->display->display_options['fields']['field_weight_clothing_selector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_weight_clothing_selector']['weight_range'] = '100';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Weight Clothing (field_weight_clothing) */
  $handler->display->display_options['sorts']['field_weight_clothing_value']['id'] = 'field_weight_clothing_value';
  $handler->display->display_options['sorts']['field_weight_clothing_value']['table'] = 'field_data_field_weight_clothing';
  $handler->display->display_options['sorts']['field_weight_clothing_value']['field'] = 'field_weight_clothing_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'shop_product' => 'shop_product',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    139 => '139',
    140 => '140',
    141 => '141',
    138 => '138',
    143 => '143',
    142 => '142',
    168 => '168',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'clothing';
  /* Filter criterion: Content: Product Store (field_product_store:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'admin/fck/sorting/clothing';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Clothing';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['fck_sorting'] = $view;

  return $export;
}
