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

$line_item = entity_load_single('commerce_line_item', $output);
$wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);


$title = $wrapper->commerce_product->title->value();
$commerce_price_data = $wrapper->commerce_total->value();
$price = commerce_currency_format(
	$commerce_price_data['amount'], 
	$commerce_price_data['currency_code']
);
$qty = (int)$wrapper->quantity->value();
$first_image = $wrapper->commerce_product->field_product_images[0]->value();
if (isset($first_image['uri'])) {
	$image_url = image_style_url('product_list_small', $first_image['uri']);	
}

$dislay_path = $row->field_commerce_display_path[0]['raw']['value'];

?>

<div class="cart-item">
	<div class="product-image">
		<?php print l(theme('image', array('path' => $image_url)), $dislay_path, array('html' => TRUE)); ?>
	</div>
	<div class="product-body">
		<div class="product-name">
			<h3><?php print l($title, $dislay_path); ?></h3>
		</div>
		<div class="cart-price">
			<span><?php print t('Price') ?>:</span>
			<strong><?php print $price; ?></strong>
		</div>
		<div class="cart-quantity">
			<span><?php print t('Quantity') ?>:</span>
			<strong><?php print $qty; ?></strong>
		</div>
	</div>
</div>
