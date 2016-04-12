<?php

/**
 * Implements hook_rules_action_info().
 */
function fck_custom_rules_action_info() {
  return array(
    'commerce_pricing_attributes_calculate_fck_fields' => array(
      'label' => t('Calculate FCK Jersey-Print textfields as attributes'),
      'parameter' => array(
        'commerce_line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('Line Item'),
          'wrapped' => TRUE,
        ),
      ),
      'provides' => array(
        'fck_textfields_sum' => array(
          'type' => 'decimal',
          'label' => t('FCK Textfields Sum'),
        ),
      ),
      'group' => t('Commerce Line Item'),
    ),
  );
}

/**
 * Rule action callback.
 */
function commerce_pricing_attributes_calculate_fck_fields($line_item_wrapper){
  $fck_textfields_sum = 0;  
  // Load the default currency code.
  $default_currency_code = commerce_default_currency();
  $fck_number = '';
  // Set the convert to currency.
  $covert_to_currency = $line_item_wrapper
    ->commerce_unit_price
    ->currency_code
    ->value();  

  $attributes = array();
  $commerce_product_fields = field_info_instances('commerce_product', $line_item_wrapper->commerce_product->type->value());
  foreach ($commerce_product_fields as $field_name => $field_instance) {
    
    $field = field_info_field($field_name);    
    
    if($field['type'] == 'commerce_pricing_attributes'){
      $attributes[$field_name] = $line_item_wrapper->commerce_product->{$field_name}->value();
    }
  } 

  if(!empty($attributes)) {
    $fck_number = '';
    $fck_label = '';
    $line_item = $line_item_wrapper->value();
    if(isset($line_item->data['commerce_option_list'])){
      $data = $line_item->data['commerce_option_list'];
      if (isset($data[0]->field_text_number['und'][0])) {
        $fck_number = $data[0]->field_text_number['und'][0]['value']; 
      }
      if (isset($data[0]->field_text_label['und'][0])) {
        $fck_label = $data[0]->field_text_label['und'][0]['value'];
      }
    } elseif (isset($line_item->commerce_pricing_attributes)) {
      $data = unserialize($line_item->commerce_pricing_attributes);
      $fck_number = $data['jersey_print']['field_text_number'];
      $fck_label = $data['jersey_print']['field_text_label'];
    }
    
    $symbol_label = strlen($fck_label)  * variable_get('fck_label_coef', 2000);
    $symbol_number = strlen($fck_number)  * variable_get('fck_text_coef', 3500);
    
    $fck_textfields_sum = $symbol_label + $symbol_number;
  }
  return array('fck_textfields_sum' => $fck_textfields_sum);  
}
