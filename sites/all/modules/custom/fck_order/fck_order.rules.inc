<?php

/**
 * Implements hook_rules_condition_info().
 */
function fck_order_rules_condition_info() {
  $inline_conditions = inline_conditions_get_info();
  $conditions = array();

  if (module_exists('commerce_order')) {
    $conditions['commerce_order_nosh_compare_order_amount'] = array(
      'label' => t('Order amount comparison (without shipping)'),
      'parameter' => array(
        'commerce_order' => array(
          'type' => 'commerce_order',
          'label' => t('Order'),
          'description' => t('The order.'),
          'wrapped' => TRUE,
        ),
        'operator' => array(
          'type' => 'text',
          'label' => t('Operator'),
          'description' => t('The operator used with the order amount value below.'),
          'default value' => '>=',
          'options list' => '_commerce_discount_operator_options',
        ),
        'total' => array(
          'type' => 'commerce_price',
          'label' => t('Order amount (without shipping)'),
          'default value' => '',
          'description' => t('The value to compare against the passed order amount.'),
        ),
      ),
      'module' => 'fck_order',
      'group' => t('Commerce Order'),
      'callbacks' => array(
        'execute' => 'commerce_order_nosh_compare_order_amount',
      ),
    );
  }

  return $conditions;
}

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
 * Build callback for commerce_order_compare_order_amount.
 *
 * @param EntityDrupalWrapper $wrapper
 *   The wrapped entity given by the rule.
 * @param string $operator
 *   The comparison operator.
 * @param array $total
 *   A commerce_price type array.
 *
 * @return bool
 *   return true if condition is valid. false otherwise.
 */
function commerce_order_nosh_compare_order_amount(EntityDrupalWrapper $wrapper, $operator, $total) {
  $total_order = 0;

  // Ensure the discount currency code is the same than the order.
  if ($wrapper->commerce_order_total->currency_code->value() != $total['currency_code']) {
    return FALSE;
  }
  
  // Get given total order amount.
  foreach ($wrapper->commerce_line_items as $line_item_wrapper) {
    if ($line_item_wrapper->getBundle() != 'shipping') {
      // Convert the line item's total to the order's currency for totalling.
      $component_total = commerce_price_component_total($line_item_wrapper->commerce_total->value());      

      // Add the totals.
      $total_order += commerce_currency_convert(
        $component_total['amount'],
        $component_total['currency_code'],
        $total['currency_code']
      );
    }
  }

  switch ($operator) {
    case '<':
      return $total_order < $total['amount'];

    case '==':
      return $total_order == $total['amount'];

    case '>':
      return $total_order > $total['amount'];

    default:
      return FALSE;
  }
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