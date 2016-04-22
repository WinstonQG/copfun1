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
  /* Sort criterion: Content: Weight Featured (field_weight_featured) */
  $handler->display->display_options['sorts']['field_weight_featured_value']['id'] = 'field_weight_featured_value';
  $handler->display->display_options['sorts']['field_weight_featured_value']['table'] = 'field_data_field_weight_featured';
  $handler->display->display_options['sorts']['field_weight_featured_value']['field'] = 'field_weight_featured_value';
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
  $handler->display->display_options['title'] = 'New';
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
  $handler->display->display_options['menu']['title'] = 'New (front)';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Reorder Products';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Hot */
  $handler = $view->new_display('page', 'Hot', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Hot';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Weight Hot (field_weight_hot) */
  $handler->display->display_options['sorts']['field_weight_hot_value']['id'] = 'field_weight_hot_value';
  $handler->display->display_options['sorts']['field_weight_hot_value']['table'] = 'field_data_field_weight_hot';
  $handler->display->display_options['sorts']['field_weight_hot_value']['field'] = 'field_weight_hot_value';
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
  $handler->display->display_options['menu']['title'] = 'Hot (front)';
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

  /* Display: Accessories */
  $handler = $view->new_display('page', 'Accessories', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Accessories';
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
  /* Field: Content: Weight Accessories Selector */
  $handler->display->display_options['fields']['field_weight_accessories_selector']['id'] = 'field_weight_accessories_selector';
  $handler->display->display_options['fields']['field_weight_accessories_selector']['table'] = 'field_data_field_weight_accessories';
  $handler->display->display_options['fields']['field_weight_accessories_selector']['field'] = 'field_weight_accessories_selector';
  $handler->display->display_options['fields']['field_weight_accessories_selector']['label'] = '';
  $handler->display->display_options['fields']['field_weight_accessories_selector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_weight_accessories_selector']['weight_range'] = '100';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Weight Accessories (field_weight_accessories) */
  $handler->display->display_options['sorts']['field_weight_accessories_value']['id'] = 'field_weight_accessories_value';
  $handler->display->display_options['sorts']['field_weight_accessories_value']['table'] = 'field_data_field_weight_accessories';
  $handler->display->display_options['sorts']['field_weight_accessories_value']['field'] = 'field_weight_accessories_value';
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
    130 => '130',
    129 => '129',
    134 => '134',
    127 => '127',
    131 => '131',
    128 => '128',
    136 => '136',
    133 => '133',
    166 => '166',
    132 => '132',
    126 => '126',
    135 => '135',
    137 => '137',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'accessories';
  /* Filter criterion: Content: Product Store (field_product_store:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'admin/fck/sorting/accessories';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Accessories';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Jersey */
  $handler = $view->new_display('page', 'Jersey', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Jersey Players';
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
  /* Field: Content: Weight Jersey Selector */
  $handler->display->display_options['fields']['field_weight_jersey_selector']['id'] = 'field_weight_jersey_selector';
  $handler->display->display_options['fields']['field_weight_jersey_selector']['table'] = 'field_data_field_weight_jersey';
  $handler->display->display_options['fields']['field_weight_jersey_selector']['field'] = 'field_weight_jersey_selector';
  $handler->display->display_options['fields']['field_weight_jersey_selector']['label'] = '';
  $handler->display->display_options['fields']['field_weight_jersey_selector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_weight_jersey_selector']['weight_range'] = '100';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Weight Jersey (field_weight_jersey) */
  $handler->display->display_options['sorts']['field_weight_jersey_value']['id'] = 'field_weight_jersey_value';
  $handler->display->display_options['sorts']['field_weight_jersey_value']['table'] = 'field_data_field_weight_jersey';
  $handler->display->display_options['sorts']['field_weight_jersey_value']['field'] = 'field_weight_jersey_value';
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
    159 => '159',
    160 => '160',
    161 => '161',
    162 => '162',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'player_jerseys';
  /* Filter criterion: Content: Product Store (field_product_store:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'admin/fck/sorting/jersey';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Jersey Players';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Match Kits */
  $handler = $view->new_display('page', 'Match Kits', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Match Kits';
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
  /* Field: Content: Weight Match Kits Selector */
  $handler->display->display_options['fields']['field_weight_match_kits_selector']['id'] = 'field_weight_match_kits_selector';
  $handler->display->display_options['fields']['field_weight_match_kits_selector']['table'] = 'field_data_field_weight_match_kits';
  $handler->display->display_options['fields']['field_weight_match_kits_selector']['field'] = 'field_weight_match_kits_selector';
  $handler->display->display_options['fields']['field_weight_match_kits_selector']['label'] = '';
  $handler->display->display_options['fields']['field_weight_match_kits_selector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_weight_match_kits_selector']['weight_range'] = '100';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Weight Match Kits (field_weight_match_kits) */
  $handler->display->display_options['sorts']['field_weight_match_kits_value']['id'] = 'field_weight_match_kits_value';
  $handler->display->display_options['sorts']['field_weight_match_kits_value']['table'] = 'field_data_field_weight_match_kits';
  $handler->display->display_options['sorts']['field_weight_match_kits_value']['field'] = 'field_weight_match_kits_value';
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
    145 => '145',
    144 => '144',
    147 => '147',
    146 => '146',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'match_kits';
  /* Filter criterion: Content: Product Store (field_product_store:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'admin/fck/sorting/match-kits';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Match Kits';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Gifts */
  $handler = $view->new_display('page', 'Gifts', 'page_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Gifts';
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
  /* Field: Content: Weight Gifts Selector */
  $handler->display->display_options['fields']['field_weight_gifts_selector']['id'] = 'field_weight_gifts_selector';
  $handler->display->display_options['fields']['field_weight_gifts_selector']['table'] = 'field_data_field_weight_gifts';
  $handler->display->display_options['fields']['field_weight_gifts_selector']['field'] = 'field_weight_gifts_selector';
  $handler->display->display_options['fields']['field_weight_gifts_selector']['label'] = '';
  $handler->display->display_options['fields']['field_weight_gifts_selector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_weight_gifts_selector']['weight_range'] = '100';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Weight Gifts (field_weight_gifts) */
  $handler->display->display_options['sorts']['field_weight_gifts_value']['id'] = 'field_weight_gifts_value';
  $handler->display->display_options['sorts']['field_weight_gifts_value']['table'] = 'field_data_field_weight_gifts';
  $handler->display->display_options['sorts']['field_weight_gifts_value']['field'] = 'field_weight_gifts_value';
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
    152 => '152',
    151 => '151',
    153 => '153',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'gifts';
  /* Filter criterion: Content: Product Store (field_product_store:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'admin/fck/sorting/gifts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Gifts';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Baby */
  $handler = $view->new_display('page', 'Baby', 'page_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Baby';
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
  /* Field: Content: Weight Baby Selector */
  $handler->display->display_options['fields']['field_weight_baby_selector']['id'] = 'field_weight_baby_selector';
  $handler->display->display_options['fields']['field_weight_baby_selector']['table'] = 'field_data_field_weight_baby';
  $handler->display->display_options['fields']['field_weight_baby_selector']['field'] = 'field_weight_baby_selector';
  $handler->display->display_options['fields']['field_weight_baby_selector']['label'] = '';
  $handler->display->display_options['fields']['field_weight_baby_selector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_weight_baby_selector']['weight_range'] = '100';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Weight Baby (field_weight_baby) */
  $handler->display->display_options['sorts']['field_weight_baby_value']['id'] = 'field_weight_baby_value';
  $handler->display->display_options['sorts']['field_weight_baby_value']['table'] = 'field_data_field_weight_baby';
  $handler->display->display_options['sorts']['field_weight_baby_value']['field'] = 'field_weight_baby_value';
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
    149 => '149',
    148 => '148',
    150 => '150',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'baby';
  /* Filter criterion: Content: Product Store (field_product_store:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'admin/fck/sorting/baby';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Baby';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Sale */
  $handler = $view->new_display('page', 'Sale', 'page_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sale';
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
  /* Field: Content: Weight Sale Selector */
  $handler->display->display_options['fields']['field_weight_sale_selector']['id'] = 'field_weight_sale_selector';
  $handler->display->display_options['fields']['field_weight_sale_selector']['table'] = 'field_data_field_weight_sale';
  $handler->display->display_options['fields']['field_weight_sale_selector']['field'] = 'field_weight_sale_selector';
  $handler->display->display_options['fields']['field_weight_sale_selector']['label'] = '';
  $handler->display->display_options['fields']['field_weight_sale_selector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_weight_sale_selector']['weight_range'] = '100';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Weight Sale (field_weight_sale) */
  $handler->display->display_options['sorts']['field_weight_sale_value']['id'] = 'field_weight_sale_value';
  $handler->display->display_options['sorts']['field_weight_sale_value']['table'] = 'field_data_field_weight_sale';
  $handler->display->display_options['sorts']['field_weight_sale_value']['field'] = 'field_weight_sale_value';
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
    163 => '163',
    164 => '164',
    165 => '165',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'sale';
  /* Filter criterion: Content: Product Store (field_product_store:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'admin/fck/sorting/sale';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Sale';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Featured */
  $handler = $view->new_display('page', 'Featured', 'page_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Featured';
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
  /* Field: Content: Weight Featured Selector */
  $handler->display->display_options['fields']['field_weight_featured_selector']['id'] = 'field_weight_featured_selector';
  $handler->display->display_options['fields']['field_weight_featured_selector']['table'] = 'field_data_field_weight_featured';
  $handler->display->display_options['fields']['field_weight_featured_selector']['field'] = 'field_weight_featured_selector';
  $handler->display->display_options['fields']['field_weight_featured_selector']['label'] = '';
  $handler->display->display_options['fields']['field_weight_featured_selector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_weight_featured_selector']['weight_range'] = '100';
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
    'featured' => 'featured',
  );
  /* Filter criterion: Content: Product Store (field_product_store:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_product_store';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'admin/fck/sorting/featured';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Featured (front)';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['fck_sorting'] = $view;

  return $export;
}
