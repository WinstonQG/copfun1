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

$node = entity_load_single('node', $output);
$wrapper = entity_metadata_wrapper('node', $node);
// price
$commerce_price_data = $wrapper
	->field_product_store[0]
	->commerce_price
	->value();
$commerce_price = commerce_currency_format(
	$commerce_price_data['amount'], 
	$commerce_price_data['currency_code']
);
// image
$first_image = $wrapper->field_product_store[0]->field_product_images[0]->value();
if (isset($first_image['uri'])) {
	$url = image_style_url('product_list_small', $first_image['uri']);	
}

?>

<div class="whishlist-item">
	<div class="product-image">
		<?php print l(theme('image', array('path' => $url)), 'node/'.$output, array('html' => TRUE)); ?>
	</div>
	<div class="product-body">
		<div class="whishlist-name">
			<h3><?php print l($node->title, 'node/'.$node->nid); ?></h3>
		</div>
		<div class="whishlist-price">
			<span>Price:</span>
			<strong><?php print $commerce_price; ?></strong>
		</div>
	</div>
</div>
