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

$jersey_print_output = '';
// check if current product is Jersey print
if (isset($wrapper->commerce_product->field_jersey_print)) {	
	// get jersey print values from line item 
	$jersey_print_values = unserialize($wrapper->commerce_pricing_attributes->value());
	if (!empty($jersey_print_values)) {	
		$jersey_print_values = $jersey_print_values['jersey_print'];
	}
	// get jersey print common data (info about Price per attribute to show)
	$jersey_print_data = $wrapper->commerce_product->field_jersey_print->value()['set_details'];	

	$jersey_print_output = theme('fck_jp_attributes', array('jersey_print_values' => $jersey_print_values, 'jersey_print_data' => $jersey_print_data));	
}

?>

<?php print $output; ?>
<?php print $jersey_print_output; ?>
