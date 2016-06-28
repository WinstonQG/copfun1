<?php

/**
 * Implements hook_rules_action_info().
 */
function fck_order_rules_action_info() {
  return array(
    'fck_order_shipping_refresh' => array(
      'label' => t('FCK order shipping refresh'),
      'parameter' => array(
        'commerce_order' => array(
          'type' => 'commerce_order',
          'label' => t('Order'),          
        ),
      ),
      'group' => t('FCK'),
      'callbacks' => array(
        'execute' => 'fck_order_shipping_refresh',
      ),
    ),
  );
}

/**
 * Rules action: recalculate order shipping. 
 * Uses:
 * - Update existing Line item (change qty and click Update cart button);
 * - Add/Remove product to/from cart
 * The reason of using:
 * If cart total > 799kr. the "post danmark" shipping rate should be = 0, and
 * during above updates the shipping is not recalculated by default.
 */
function fck_order_shipping_refresh($order) {
  $shipping = fck_get_order_shipping($order);  
  fck_add_order_shipping($order, $shipping);
}