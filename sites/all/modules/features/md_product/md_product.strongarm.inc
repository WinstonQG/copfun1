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
    ),
    'extra_fields' => array(
      'form' => array(
        'flag' => array(
          'weight' => '17',
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
            'weight' => '-10',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-10',
            'visible' => FALSE,
          ),
        ),
        'product:title' => array(
          'default' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'modal_content' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
        ),
        'product:status' => array(
          'default' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
          'modal_content' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_price' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'product:field_color' => array(
          'default' => array(
            'weight' => '16',
            'visible' => FALSE,
          ),
          'modal_content' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
        'product:field_price_old' => array(
          'default' => array(
            'weight' => '3',
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
        ),
        'product:field_product_images' => array(
          'default' => array(
            'weight' => '4',
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
        ),
        'product:field_size' => array(
          'default' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'modal_content' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'flag_wishlist' => array(
          'default' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'sharethis' => array(
          'default' => array(
            'weight' => '9',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
        'flippy_pager' => array(
          'modal_content' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
        'product:commerce_stock' => array(
          'default' => array(
            'weight' => '42',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '42',
            'visible' => TRUE,
          ),
        ),
        'product:field_outwear_adult_size' => array(
          'default' => array(
            'weight' => '37',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '37',
            'visible' => TRUE,
          ),
        ),
        'product:field_outwear_children_size' => array(
          'default' => array(
            'weight' => '39',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '39',
            'visible' => TRUE,
          ),
        ),
        'product:field_outwear_baby_size' => array(
          'default' => array(
            'weight' => '41',
            'visible' => TRUE,
          ),
          'modal_content' => array(
            'weight' => '41',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__shop_product'] = $strongarm;

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
