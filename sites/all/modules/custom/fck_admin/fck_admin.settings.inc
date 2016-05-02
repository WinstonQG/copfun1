<?php

function fck_admin_settings_form($form, &$form_state) {
  $form['jerseyprint'] = array(
    '#type' => 'fieldset',
    '#title' => t('Jersey Print'),
  );
  $form['jerseyprint']['fck_price_per_letter'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('fck_price_per_letter', 2000),
    '#title' => t('Price per letter'),
    '#description' => '<strong>Note: </strong>1kr. = 100, 20kr.=2000',
  );
  $form['jerseyprint']['fck_price_per_digit'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('fck_price_per_digit', 3500),
    '#title' => t('Price per number'),
    '#description' => '<strong>Note: </strong>1kr. = 100, 20kr.=2000',
  );

  $form['shop_product'] = array(
    '#type' => 'fieldset',
    '#title' => t('Shop Product'),
  );
  $form['shop_product']['fck_new_product_expiration'] = array(
    '#type' => 'select',
    '#default_value' => variable_get('fck_new_product_expiration', 120),
    '#title' => t('New Product Expiration'), 
    '#options' => array(
      60 => '1 minute',
      120 => '2 minutes',
      3600 => '1 hour',
      86400 => '1 day',
      604800 => '1 week',
      2592000 => '30 days',
    ),
  );

  return system_settings_form($form);
}
