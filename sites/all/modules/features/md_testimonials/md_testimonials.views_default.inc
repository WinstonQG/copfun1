<?php
/**
 * @file
 * md_testimonials.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function md_testimonials_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'testimonials';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Testimonials';
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
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['manual_load'] = 1;
  $handler->display->display_options['pager']['options']['text'] = 'View More';
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Customer Avatar */
  $handler->display->display_options['fields']['field_customer_avatar']['id'] = 'field_customer_avatar';
  $handler->display->display_options['fields']['field_customer_avatar']['table'] = 'field_data_field_customer_avatar';
  $handler->display->display_options['fields']['field_customer_avatar']['field'] = 'field_customer_avatar';
  $handler->display->display_options['fields']['field_customer_avatar']['label'] = '';
  $handler->display->display_options['fields']['field_customer_avatar']['element_type'] = '0';
  $handler->display->display_options['fields']['field_customer_avatar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_customer_avatar']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_customer_avatar']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_customer_avatar']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_customer_avatar']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_customer_avatar']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Customer Testimonial */
  $handler->display->display_options['fields']['field_customer_testimonial']['id'] = 'field_customer_testimonial';
  $handler->display->display_options['fields']['field_customer_testimonial']['table'] = 'field_data_field_customer_testimonial';
  $handler->display->display_options['fields']['field_customer_testimonial']['field'] = 'field_customer_testimonial';
  $handler->display->display_options['fields']['field_customer_testimonial']['label'] = '';
  $handler->display->display_options['fields']['field_customer_testimonial']['element_type'] = '0';
  $handler->display->display_options['fields']['field_customer_testimonial']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_customer_testimonial']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_customer_testimonial']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_customer_testimonial']['type'] = 'text_plain';
  /* Field: Content: Customer Website */
  $handler->display->display_options['fields']['field_customer_website']['id'] = 'field_customer_website';
  $handler->display->display_options['fields']['field_customer_website']['table'] = 'field_data_field_customer_website';
  $handler->display->display_options['fields']['field_customer_website']['field'] = 'field_customer_website';
  $handler->display->display_options['fields']['field_customer_website']['label'] = '';
  $handler->display->display_options['fields']['field_customer_website']['element_type'] = '0';
  $handler->display->display_options['fields']['field_customer_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_customer_website']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_customer_website']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_customer_website']['click_sort_column'] = 'url';
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
    'testimonials' => 'testimonials',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['testimonials'] = $view;

  $view = new view();
  $view->name = 'testimonials_widget';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Testimonials Widget';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Customer Testimonial */
  $handler->display->display_options['fields']['field_customer_testimonial']['id'] = 'field_customer_testimonial';
  $handler->display->display_options['fields']['field_customer_testimonial']['table'] = 'field_data_field_customer_testimonial';
  $handler->display->display_options['fields']['field_customer_testimonial']['field'] = 'field_customer_testimonial';
  $handler->display->display_options['fields']['field_customer_testimonial']['label'] = '';
  $handler->display->display_options['fields']['field_customer_testimonial']['element_type'] = '0';
  $handler->display->display_options['fields']['field_customer_testimonial']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_customer_testimonial']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_customer_testimonial']['element_default_classes'] = FALSE;
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
    'testimonials' => 'testimonials',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['testimonials_widget'] = $view;

  return $export;
}
