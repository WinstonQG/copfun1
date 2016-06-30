<?php
/**
 * @file
 * md_product.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function md_product_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_lookbook';
  $strongarm->value = '0';
  $export['comment_anonymous_lookbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_shop_product';
  $strongarm->value = '1';
  $export['comment_anonymous_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_lookbook';
  $strongarm->value = 1;
  $export['comment_default_mode_lookbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_shop_product';
  $strongarm->value = 1;
  $export['comment_default_mode_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_lookbook';
  $strongarm->value = '50';
  $export['comment_default_per_page_lookbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_shop_product';
  $strongarm->value = '50';
  $export['comment_default_per_page_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_lookbook';
  $strongarm->value = 1;
  $export['comment_form_location_lookbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_shop_product';
  $strongarm->value = 1;
  $export['comment_form_location_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_lookbook';
  $strongarm->value = '1';
  $export['comment_lookbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_lookbook';
  $strongarm->value = '1';
  $export['comment_preview_lookbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_shop_product';
  $strongarm->value = '0';
  $export['comment_preview_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_shop_product';
  $strongarm->value = '2';
  $export['comment_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_lookbook';
  $strongarm->value = 1;
  $export['comment_subject_field_lookbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_shop_product';
  $strongarm->value = 1;
  $export['comment_subject_field_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_commerce_product__jersey_print';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'line_item' => array(
        'custom_settings' => TRUE,
      ),
      'node_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'attribute_view' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'commerce_line_item_display' => array(
        'custom_settings' => FALSE,
      ),
      'commerce_line_item_token' => array(
        'custom_settings' => FALSE,
      ),
      'node_full' => array(
        'custom_settings' => FALSE,
      ),
      'node_rss' => array(
        'custom_settings' => FALSE,
      ),
      'node_search_index' => array(
        'custom_settings' => FALSE,
      ),
      'node_search_result' => array(
        'custom_settings' => FALSE,
      ),
      'node_modal_content' => array(
        'custom_settings' => TRUE,
      ),
      'node_email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'node_email_html' => array(
        'custom_settings' => FALSE,
      ),
      'node_email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'node_token' => array(
        'custom_settings' => FALSE,
      ),
      'commerce_discount_offer_token' => array(
        'custom_settings' => FALSE,
      ),
      'node_modal_product_detail' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'sku' => array(
          'default' => array(
            'weight' => '-10',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'node_modal_content' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'node_modal_product_detail' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'line_item' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'title' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'node_modal_content' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'node_modal_product_detail' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'line_item' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'status' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'node_modal_content' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'node_modal_product_detail' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'line_item' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'flag_wishlist_product' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'node_modal_content' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'node_modal_product_detail' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'line_item' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_commerce_product__jersey_print'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_commerce_product__product';
  $strongarm->value = array(
    'view_modes' => array(
      'line_item' => array(
        'custom_settings' => TRUE,
      ),
      'node_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'node_modal_content' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'commerce_line_item_display' => array(
        'custom_settings' => FALSE,
      ),
      'commerce_line_item_diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'commerce_line_item_token' => array(
        'custom_settings' => FALSE,
      ),
      'node_full' => array(
        'custom_settings' => FALSE,
      ),
      'node_rss' => array(
        'custom_settings' => FALSE,
      ),
      'node_search_index' => array(
        'custom_settings' => FALSE,
      ),
      'node_search_result' => array(
        'custom_settings' => FALSE,
      ),
      'node_diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'node_token' => array(
        'custom_settings' => FALSE,
      ),
      'attribute_view' => array(
        'custom_settings' => FALSE,
      ),
      'node_email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'node_email_html' => array(
        'custom_settings' => FALSE,
      ),
      'node_email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'commerce_discount_offer_token' => array(
        'custom_settings' => FALSE,
      ),
      'node_modal_product_detail' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'sku' => array(
          'weight' => '0',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'status' => array(
          'weight' => '12',
        ),
      ),
      'display' => array(
        'sku' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'node_modal_content' => array(
            'weight' => '-10',
            'visible' => TRUE,
          ),
          'line_item' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'node_teaser' => array(
            'weight' => '-10',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'node_modal_product_detail' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'title' => array(
          'default' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
          'node_modal_content' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'line_item' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'node_teaser' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'node_modal_product_detail' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
        ),
        'status' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'node_modal_content' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'line_item' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'node_teaser' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'node_modal_product_detail' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'flag_wishlist_product' => array(
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'line_item' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'node_modal_product_detail' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_commerce_product__product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__shop_product';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'modal_content' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'modal_product_detail' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'flag' => array(
          'weight' => '18',
        ),
        'title' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'product:sku' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-10',
            'visible' => FALSE,
          ),
          'modal_product_detail' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'product:title' => array(
          'default' => array(
            'weight' => '47',
            'visible' => FALSE,
          ),
          'modal_content' => array(
            'weight' => '33',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'modal_product_detail' => array(
            'weight' => '47',
            'visible' => FALSE,
          ),
        ),
        'product:status' => array(
          'default' => array(
            'weight' => '48',
            'visible' => FALSE,
          ),
          'modal_content' => array(
            'weight' => '43',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'modal_product_detail' => array(
            'weight' => '48',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_price' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'product:field_color' => array(
          'default' => array(
            'weight' => '46',
            'visible' => FALSE,
          ),
          'modal_content' => array(
            'weight' => '44',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'modal_product_detail' => array(
            'weight' => '46',
            'visible' => FALSE,
          ),
        ),
        'product:field_price_old' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'product:field_product_images' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
        'product:field_size' => array(
          'default' => array(
            'weight' => '45',
            'visible' => FALSE,
          ),
          'modal_content' => array(
            'weight' => '41',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'modal_product_detail' => array(
            'weight' => '45',
            'visible' => FALSE,
          ),
        ),
        'flag_wishlist' => array(
          'default' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
        ),
        'sharethis' => array(
          'default' => array(
            'weight' => '15',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '46',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'modal_product_detail' => array(
            'weight' => '15',
            'visible' => TRUE,
          ),
        ),
        'flippy_pager' => array(
          'modal_content' => array(
            'weight' => '42',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
        ),
        'product:field_outwear_adult_size' => array(
          'default' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
        ),
        'product:field_outwear_children_size' => array(
          'default' => array(
            'weight' => '9',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '9',
            'visible' => TRUE,
          ),
        ),
        'product:field_outwear_baby_size' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'product:commerce_stock' => array(
          'default' => array(
            'weight' => '21',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '14',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '21',
            'visible' => TRUE,
          ),
        ),
        'product:field_foot_size' => array(
          'modal_content' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'product:field_text_preview_image' => array(
          'default' => array(
            'weight' => '16',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '9',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '16',
            'visible' => TRUE,
          ),
        ),
        'product:field_jersey_print' => array(
          'default' => array(
            'weight' => '23',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '16',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '23',
            'visible' => TRUE,
          ),
        ),
        'product:field_autograph_preview_image' => array(
          'default' => array(
            'weight' => '19',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '15',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '19',
            'visible' => TRUE,
          ),
        ),
        'product:field_badge_preview_image' => array(
          'default' => array(
            'weight' => '17',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '17',
            'visible' => TRUE,
          ),
        ),
        'product:flag_wishlist_product' => array(
          'default' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'modal_content' => array(
            'weight' => '13',
            'visible' => TRUE,
          ),
          'modal_product_detail' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_shop_product';
  $strongarm->value = 1;
  $export['i18n_node_extended_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_shop_product';
  $strongarm->value = array();
  $export['i18n_node_options_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_shop_product';
  $strongarm->value = '0';
  $export['language_content_type_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_lookbook';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_lookbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_shop_product';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_lookbook';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_lookbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_shop_product';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeblock_comment_link_shop_product';
  $strongarm->value = '0';
  $export['nodeblock_comment_link_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeblock_node_link_shop_product';
  $strongarm->value = '0';
  $export['nodeblock_node_link_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeblock_node_overrides_shop_product';
  $strongarm->value = array(
    0 => 'nodeblock',
  );
  $export['nodeblock_node_overrides_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeblock_node_override_block_available_shop_product';
  $strongarm->value = 'disabled';
  $export['nodeblock_node_override_block_available_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeblock_node_override_block_title_field_shop_product';
  $strongarm->value = 'nodeblock';
  $export['nodeblock_node_override_block_title_field_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeblock_shop_product';
  $strongarm->value = '1';
  $export['nodeblock_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeblock_view_mode_shop_product';
  $strongarm->value = 'modal_content';
  $export['nodeblock_view_mode_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_lookbook';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_lookbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_shop_product';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_lookbook';
  $strongarm->value = '1';
  $export['node_preview_lookbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_shop_product';
  $strongarm->value = '1';
  $export['node_preview_shop_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_lookbook';
  $strongarm->value = 0;
  $export['node_submitted_lookbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_shop_product';
  $strongarm->value = 1;
  $export['node_submitted_shop_product'] = $strongarm;

  return $export;
}
