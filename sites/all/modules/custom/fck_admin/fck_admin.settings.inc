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

  return system_settings_form($form);
}
