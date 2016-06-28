<?php

function fck_admin_settings_form($form, &$form_state) {  
  $categories = fck_get_categories();
  $form['categories'] = array(
    '#type' => 'fieldset',
    '#title' => t('Categories'),
    //'#tree' => TRUE,
  );  
  
  foreach ($categories as $category_id => $category) {    
    $category_banner_varname = fck_get_category_banner_varname($category_id);
    $banner = variable_get($category_banner_varname, '');    
    $form['categories'][$category_banner_varname] = array(       
      '#type' => 'managed_file',
      '#name' => $category_banner_varname,
      '#title' => $category["en_value"].' banner image',          
      '#upload_location' => 'public://',
      '#default_value' => variable_get($category_banner_varname, ''),  
    );
    
    $category_desc_varname = fck_get_category_desc_varname($category_id);
    $form['categories'][$category_desc_varname] = array(
      '#type' => 'textfield',
      '#title' => $category["en_value"].' short description (below image)',
      '#default_value' => variable_get($category_desc_varname, ''),
    );
  }
  
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

  $form['invoices'] = array(
    '#type' => 'fieldset',
    '#title' => t('Invoices'),    
  );
  $form['invoices']['fck_invoice_redirect_page'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('fck_invoice_redirect_page', 'home'),
    '#title' => t('Continue shopping page'),    
  );
  $form['invoices']['fck_invoice_delivery_range'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('fck_invoice_delivery_range', '1-3 days'),
    '#title' => t('Delivery range'),    
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
  $form['cart_checkout'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cart/Checkout'),
  );
  $form['cart_checkout']['fck_free_shipping_rate'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('fck_free_shipping_rate', 790.00),
    '#title' => t('Free shipping rate'),
    '#description' => '<strong>Note: </strong>1kr. = 1, 20kr.=20',
  );
  
  $form['#submit'][] = 'fck_admin_settings_form_submit';

  return system_settings_form($form);
}

function fck_admin_settings_form_submit($form, &$form_state) {  
  $categories = fck_get_categories();
  foreach ($categories as $category_id => $category) {    
    $category_banner_varname = fck_get_category_banner_varname($category_id);
    $banner_fid = $form_state['values'][$category_banner_varname];
    if ($banner_fid) {      
      $file = file_load($banner_fid);
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      file_usage_add($file, 'fck_admin', 'fck_admin', $banner_fid);
    }
  }  
}