<?php

/**
 * @file
 * Hooks provided by the Commerce Billy PDF module.
 */

/**
 * Defines a custom PDF template.
 *
 * @return array
 *   An array of PDF template info arrays keyed by the 'name' string. PDF
 *   template info arrays are associative arrays containing the following keys:
 *   - name: string containing the machine-name of the PDF template; should
 *     only include lowercase letters, numbers, -, and _. Must differ from
 *     'default'.
 *   - title: the translatable name of the PDF template, used in the
 *     administrative interface.
 */
function hook_commerce_billy_pdf_templates() {
  $templates = array();

  $templates['my_template'] = array(
    'name' => 'my_template',
    'title' => t('My template'),
  );

  return $templates;
}

/**
 * Specifies the PDF template name to be used for a given order.
 *
 * @param object $order
 *   The order the PDF invoice should be generated for.
 *
 * @return string
 *   The PDF template name string defined in
 *   hook_commerce_billy_pdf_templates().
 */
function hook_commerce_billy_pdf_get_order_template($order) {
  $template_name = 'default';

  $line_item_id_0 = $order->commerce_line_items['und'][0]['line_item_id'];
  $line_item_0 = commerce_line_item_load($line_item_id_0);
  if ($line_item_0->type == 'my_line_item_type') {
    // We checked for the type of the order's first line item.
    $template_name = 'my_template';
  }

  return $template_name;
}
