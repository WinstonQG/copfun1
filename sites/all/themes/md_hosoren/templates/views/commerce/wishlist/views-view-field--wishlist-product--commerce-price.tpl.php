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
/*$node = entity_load_single('node', $output);
$wrapper = entity_metadata_wrapper('node', $node);
$commerce_price_data = $wrapper
	->field_product_store[0]
	->commerce_price
	->value();
$commerce_price = commerce_currency_format(
	$commerce_price_data['amount'], 
	$commerce_price_data['currency_code']
);*/

$uid = arg(1);
if (empty($uid)) {
	global $user;
	$uid = $user->uid;
}
$product_id = $row->product_id;
$jersey_print = fck_jp_get_wishlist_data($product_id, $uid);
$price = !empty($jersey_print) ? fck_jp_get_wishlist_price($product_id, $uid, $jersey_print) : $output;
?>
<?php print $price; ?>

