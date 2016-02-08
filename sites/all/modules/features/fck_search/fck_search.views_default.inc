<?php
/**
 * @file
 * fck_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function fck_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'fck_search_pages';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_shop_product';
  $view->human_name = 'FCK Search pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Clothing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Contextual filter: Clothing: Term ID (indexed) */
  $handler->display->display_options['arguments']['field_clothing_tid']['id'] = 'field_clothing_tid';
  $handler->display->display_options['arguments']['field_clothing_tid']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['arguments']['field_clothing_tid']['field'] = 'field_clothing_tid';
  $handler->display->display_options['arguments']['field_clothing_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clothing_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clothing_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_clothing_tid']['not'] = 0;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'shop_product' => 'shop_product',
  );
  /* Filter criterion: Baby » Vocabulary: Machine name (indexed) */
  $handler->display->display_options['filters']['field_baby_vocabulary_machine_name']['id'] = 'field_baby_vocabulary_machine_name';
  $handler->display->display_options['filters']['field_baby_vocabulary_machine_name']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['filters']['field_baby_vocabulary_machine_name']['field'] = 'field_baby_vocabulary_machine_name';
  $handler->display->display_options['filters']['field_baby_vocabulary_machine_name']['value'] = 'baby';

  /* Display: Clothing */
  $handler = $view->new_display('page', 'Clothing', 'clothing_page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'shop_product' => 'shop_product',
  );
  /* Filter criterion: Clothing » Vocabulary: Machine name (indexed) */
  $handler->display->display_options['filters']['field_clothing_vocabulary_machine_name']['id'] = 'field_clothing_vocabulary_machine_name';
  $handler->display->display_options['filters']['field_clothing_vocabulary_machine_name']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['filters']['field_clothing_vocabulary_machine_name']['field'] = 'field_clothing_vocabulary_machine_name';
  $handler->display->display_options['filters']['field_clothing_vocabulary_machine_name']['value'] = 'clothing';
  $handler->display->display_options['path'] = 'categories/clothing/%';

  /* Display: Accessories */
  $handler = $view->new_display('page', 'Accessories', 'accessories_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Accessories';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Accessories: Term ID (indexed) */
  $handler->display->display_options['arguments']['field_accessories_tid']['id'] = 'field_accessories_tid';
  $handler->display->display_options['arguments']['field_accessories_tid']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['arguments']['field_accessories_tid']['field'] = 'field_accessories_tid';
  $handler->display->display_options['arguments']['field_accessories_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_accessories_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_accessories_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_accessories_tid']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'shop_product' => 'shop_product',
  );
  /* Filter criterion: Accessories » Vocabulary: Machine name (indexed) */
  $handler->display->display_options['filters']['field_accessories_vocabulary_machine_name']['id'] = 'field_accessories_vocabulary_machine_name';
  $handler->display->display_options['filters']['field_accessories_vocabulary_machine_name']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['filters']['field_accessories_vocabulary_machine_name']['field'] = 'field_accessories_vocabulary_machine_name';
  $handler->display->display_options['filters']['field_accessories_vocabulary_machine_name']['value'] = 'accessories';
  $handler->display->display_options['path'] = 'categories/accessories/%';

  /* Display: Match Kits */
  $handler = $view->new_display('page', 'Match Kits', 'match_kits_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Match Kits';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Match Kits: Term ID (indexed) */
  $handler->display->display_options['arguments']['field_match_kits_tid']['id'] = 'field_match_kits_tid';
  $handler->display->display_options['arguments']['field_match_kits_tid']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['arguments']['field_match_kits_tid']['field'] = 'field_match_kits_tid';
  $handler->display->display_options['arguments']['field_match_kits_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_match_kits_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_match_kits_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_match_kits_tid']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'shop_product' => 'shop_product',
  );
  /* Filter criterion: Match Kits » Vocabulary: Machine name (indexed) */
  $handler->display->display_options['filters']['field_match_kits_vocabulary_machine_name']['id'] = 'field_match_kits_vocabulary_machine_name';
  $handler->display->display_options['filters']['field_match_kits_vocabulary_machine_name']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['filters']['field_match_kits_vocabulary_machine_name']['field'] = 'field_match_kits_vocabulary_machine_name';
  $handler->display->display_options['filters']['field_match_kits_vocabulary_machine_name']['value'] = 'match_kits';
  $handler->display->display_options['path'] = 'categories/match-kits/%';

  /* Display: Baby */
  $handler = $view->new_display('page', 'Baby', 'baby_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Baby';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Baby: Term ID (indexed) */
  $handler->display->display_options['arguments']['field_baby_tid']['id'] = 'field_baby_tid';
  $handler->display->display_options['arguments']['field_baby_tid']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['arguments']['field_baby_tid']['field'] = 'field_baby_tid';
  $handler->display->display_options['arguments']['field_baby_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_baby_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_baby_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_baby_tid']['not'] = 0;
  $handler->display->display_options['path'] = 'categories/baby/%';

  /* Display: Gifts */
  $handler = $view->new_display('page', 'Gifts', 'gifts_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Gifts';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Gifts: Term ID (indexed) */
  $handler->display->display_options['arguments']['field_gifts_tid']['id'] = 'field_gifts_tid';
  $handler->display->display_options['arguments']['field_gifts_tid']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['arguments']['field_gifts_tid']['field'] = 'field_gifts_tid';
  $handler->display->display_options['arguments']['field_gifts_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_gifts_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_gifts_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_gifts_tid']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'shop_product' => 'shop_product',
  );
  /* Filter criterion: Gifts » Vocabulary: Machine name (indexed) */
  $handler->display->display_options['filters']['field_gifts_vocabulary_machine_name']['id'] = 'field_gifts_vocabulary_machine_name';
  $handler->display->display_options['filters']['field_gifts_vocabulary_machine_name']['table'] = 'search_api_index_shop_product';
  $handler->display->display_options['filters']['field_gifts_vocabulary_machine_name']['field'] = 'field_gifts_vocabulary_machine_name';
  $handler->display->display_options['filters']['field_gifts_vocabulary_machine_name']['value'] = 'gifts';
  $handler->display->display_options['path'] = 'categories/gifts/%';
  $translatables['fck_search_pages'] = array(
    t('Master'),
    t('Clothing'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Node ID'),
    t('.'),
    t(','),
    t('All'),
    t('Accessories'),
    t('Match Kits'),
    t('Baby'),
    t('Gifts'),
  );
  $export['fck_search_pages'] = $view;

  return $export;
}
