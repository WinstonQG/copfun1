<?php
/**
 * @file
 * md_portfolio.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function md_portfolio_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'lasted_portfolios';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Portfolio : Lasted Block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'LASTED PORTFOLIOS';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_multimedia']['id'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['table'] = 'field_data_field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['field'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['label'] = '';
  $handler->display->display_options['fields']['field_multimedia']['element_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_multimedia']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_multimedia']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_multimedia']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_multimedia']['separator'] = '';
  /* Field: Content: Portfolio Categories */
  $handler->display->display_options['fields']['field_portfolio_categories']['id'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['table'] = 'field_data_field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['field'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['label'] = '';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_type'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_portfolio_categories']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_portfolio_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_portfolio_categories']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_portfolio_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['separator'] = '/';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_type'] = '0';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'portfolio' => 'portfolio',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['lasted_portfolios'] = $view;

  $view = new view();
  $view->name = 'portfolio_category_filter';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Portfolio Category Filter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Portfolio Category Filter';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'portfolio_categories' => 'portfolio_categories',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['portfolio_category_filter'] = $view;

  $view = new view();
  $view->name = 'portfolio_main_style_1';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Portfolio Main Style 1';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'portfolio_category_filter:default';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_multimedia']['id'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['table'] = 'field_data_field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['field'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['label'] = '';
  $handler->display->display_options['fields']['field_multimedia']['element_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_multimedia']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_multimedia']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_multimedia']['delta_offset'] = '0';
  /* Field: Content: Portfolio Categories */
  $handler->display->display_options['fields']['field_portfolio_categories']['id'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['table'] = 'field_data_field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['field'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['label'] = '';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_type'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_portfolio_categories']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_portfolio_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_portfolio_categories']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_portfolio_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['separator'] = '/';
  /* Field: Content: Display media type */
  $handler->display->display_options['fields']['field_display_media_type']['id'] = 'field_display_media_type';
  $handler->display->display_options['fields']['field_display_media_type']['table'] = 'field_data_field_display_media_type';
  $handler->display->display_options['fields']['field_display_media_type']['field'] = 'field_display_media_type';
  $handler->display->display_options['fields']['field_display_media_type']['label'] = '';
  $handler->display->display_options['fields']['field_display_media_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_display_media_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_media_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_display_media_type']['element_default_classes'] = FALSE;
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_multimedia_1']['id'] = 'field_multimedia_1';
  $handler->display->display_options['fields']['field_multimedia_1']['table'] = 'field_data_field_multimedia';
  $handler->display->display_options['fields']['field_multimedia_1']['field'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia_1']['label'] = '';
  $handler->display->display_options['fields']['field_multimedia_1']['element_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_multimedia_1']['settings'] = array(
    'file_view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_multimedia_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_multimedia_1']['separator'] = ' ';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_type'] = '0';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'portfolio' => 'portfolio',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'portfolio_main_style_1');
  $export['portfolio_main_style_1'] = $view;

  $view = new view();
  $view->name = 'portfolio_main_style_2';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Portfolio Main Style 2';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'portfolio_category_filter:default';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_multimedia']['id'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['table'] = 'field_data_field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['field'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['label'] = '';
  $handler->display->display_options['fields']['field_multimedia']['element_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_multimedia']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_multimedia']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_multimedia']['delta_offset'] = '0';
  /* Field: Content: Portfolio Categories */
  $handler->display->display_options['fields']['field_portfolio_categories']['id'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['table'] = 'field_data_field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['field'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['label'] = '';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_type'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_portfolio_categories']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_portfolio_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_portfolio_categories']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_portfolio_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['separator'] = '/';
  /* Field: Content: Display media type */
  $handler->display->display_options['fields']['field_display_media_type']['id'] = 'field_display_media_type';
  $handler->display->display_options['fields']['field_display_media_type']['table'] = 'field_data_field_display_media_type';
  $handler->display->display_options['fields']['field_display_media_type']['field'] = 'field_display_media_type';
  $handler->display->display_options['fields']['field_display_media_type']['label'] = '';
  $handler->display->display_options['fields']['field_display_media_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_display_media_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_media_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_display_media_type']['element_default_classes'] = FALSE;
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_multimedia_1']['id'] = 'field_multimedia_1';
  $handler->display->display_options['fields']['field_multimedia_1']['table'] = 'field_data_field_multimedia';
  $handler->display->display_options['fields']['field_multimedia_1']['field'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia_1']['label'] = '';
  $handler->display->display_options['fields']['field_multimedia_1']['element_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_multimedia_1']['settings'] = array(
    'file_view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_multimedia_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_multimedia_1']['separator'] = ' ';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_type'] = '0';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'portfolio' => 'portfolio',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['portfolio_main_style_2'] = $view;

  $view = new view();
  $view->name = 'portfolio_main_style_4';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Portfolio Main Style Masonry';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'portfolio_category_filter:default';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_multimedia']['id'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['table'] = 'field_data_field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['field'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['label'] = '';
  $handler->display->display_options['fields']['field_multimedia']['element_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_multimedia']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_multimedia']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_multimedia']['delta_offset'] = '0';
  /* Field: Content: Portfolio Categories */
  $handler->display->display_options['fields']['field_portfolio_categories']['id'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['table'] = 'field_data_field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['field'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['label'] = '';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_type'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_portfolio_categories']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_portfolio_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_portfolio_categories']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_portfolio_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['separator'] = '/';
  /* Field: Content: Display media type */
  $handler->display->display_options['fields']['field_display_media_type']['id'] = 'field_display_media_type';
  $handler->display->display_options['fields']['field_display_media_type']['table'] = 'field_data_field_display_media_type';
  $handler->display->display_options['fields']['field_display_media_type']['field'] = 'field_display_media_type';
  $handler->display->display_options['fields']['field_display_media_type']['label'] = '';
  $handler->display->display_options['fields']['field_display_media_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_display_media_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_media_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_display_media_type']['element_default_classes'] = FALSE;
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_multimedia_1']['id'] = 'field_multimedia_1';
  $handler->display->display_options['fields']['field_multimedia_1']['table'] = 'field_data_field_multimedia';
  $handler->display->display_options['fields']['field_multimedia_1']['field'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia_1']['label'] = '';
  $handler->display->display_options['fields']['field_multimedia_1']['element_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_multimedia_1']['settings'] = array(
    'file_view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_multimedia_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_multimedia_1']['separator'] = ' ';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_type'] = '0';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'portfolio' => 'portfolio',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['portfolio_main_style_4'] = $view;

  $view = new view();
  $view->name = 'portfolio_main_style_grid';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Portfolio Main Style Grid';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'portfolio_category_filter:default';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_multimedia']['id'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['table'] = 'field_data_field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['field'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['label'] = '';
  $handler->display->display_options['fields']['field_multimedia']['element_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_multimedia']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_multimedia']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_multimedia']['delta_offset'] = '0';
  /* Field: Content: Portfolio Categories */
  $handler->display->display_options['fields']['field_portfolio_categories']['id'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['table'] = 'field_data_field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['field'] = 'field_portfolio_categories';
  $handler->display->display_options['fields']['field_portfolio_categories']['label'] = '';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_type'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_portfolio_categories']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_portfolio_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_portfolio_categories']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_portfolio_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_portfolio_categories']['separator'] = '/';
  /* Field: Content: Display media type */
  $handler->display->display_options['fields']['field_display_media_type']['id'] = 'field_display_media_type';
  $handler->display->display_options['fields']['field_display_media_type']['table'] = 'field_data_field_display_media_type';
  $handler->display->display_options['fields']['field_display_media_type']['field'] = 'field_display_media_type';
  $handler->display->display_options['fields']['field_display_media_type']['label'] = '';
  $handler->display->display_options['fields']['field_display_media_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_display_media_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_media_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_display_media_type']['element_default_classes'] = FALSE;
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_multimedia_1']['id'] = 'field_multimedia_1';
  $handler->display->display_options['fields']['field_multimedia_1']['table'] = 'field_data_field_multimedia';
  $handler->display->display_options['fields']['field_multimedia_1']['field'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia_1']['label'] = '';
  $handler->display->display_options['fields']['field_multimedia_1']['element_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_multimedia_1']['settings'] = array(
    'file_view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_multimedia_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_multimedia_1']['separator'] = ' ';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_type'] = '0';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'portfolio' => 'portfolio',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['portfolio_main_style_grid'] = $view;

  return $export;
}
