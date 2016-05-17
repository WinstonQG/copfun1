<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */

$lid = $row->commerce_line_item_field_data_commerce_line_items_line_item_;
$type = $row->field_data_commerce_total_commerce_line_item_entity_type;

$line_item = entity_load_single($type, $lid);
$wrapper = entity_metadata_wrapper($type, $line_item);
$title = $wrapper->commerce_product->title->value();

$jersey_print_values = unserialize($wrapper->commerce_pricing_attributes->value());
if (!empty($jersey_print_values)) {	
	$jersey_print_values = $jersey_print_values['jersey_print'];
}

$jersey_print_output = '';
$jersey_print_prices = array();
if (isset($wrapper->commerce_product->field_jersey_print)) {	
	$jersey_print_data = $wrapper->commerce_product->field_jersey_print->value()['set_details'];
	//dsm($jersey_print_values);
	//dsm($jersey_print_data);

	$jersey_print_output = theme('fck_jp_attributes', array('jersey_print_values' => $jersey_print_values, 'jersey_print_data' => $jersey_print_data));

	/*
	if ($jersey_print_values['field_superliga_badge']) {
		// superliga badge option
		$option = $jersey_print_data['field_superliga_badge']['options'][1];
		$price = commerce_currency_format($option['price'], $option['currency_code']);
		$jersey_print_prices['field_superliga_badge'] = $jersey_print_values['field_superliga_badge'] ? $price : '';
	}

	if ($jersey_print_values['field_autograph']) {
		// autograph option
		$option = $jersey_print_data['field_autograph']['options'][1];
		$price = commerce_currency_format($option['price'], $option['currency_code']);
		$jersey_print_prices['field_autograph'] = $jersey_print_values['field_autograph'] ? $price : '';
	}

	if (!is_null($jersey_print_values['field_players'])) {
		// players option
		$option = $jersey_print_data['field_players']['options'][$jersey_print_values['field_players']->tid];
		$price = commerce_currency_format($option['price'], $option['currency_code']);	
		$jersey_print_prices['field_players'] = $jersey_print_values['field_players'] ? $price : '';
	}
	// Label text option
	$text_label = $jersey_print_values['field_text_label'];
	if (!empty($text_label)) {		
		$jersey_print_prices['field_text_label'] = fck_custom_get_custom_price($text_label, 'label');
	}
	// Number text option
	$text_number = $jersey_print_values['field_text_number'];
	if (!empty($text_number)) {			
		$jersey_print_prices['field_text_number'] = fck_custom_get_custom_price($text_number, 'number');
	}*/
}

?>

<?php print $output; ?>
<?php print $jersey_print_output; ?>
