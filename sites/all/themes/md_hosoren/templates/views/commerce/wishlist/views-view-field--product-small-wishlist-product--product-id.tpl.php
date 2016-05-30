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

global $user;
$uid = $user->uid;

$product_id = $row->product_id;
$product_nid = fck_get_node_id($product_id);
$jersey_print = fck_jp_get_wishlist_data($product_id, $uid, TRUE);
$price = '';
$jersey_print_output = '';
if (!empty($jersey_print)) {	
	//
	$product = commerce_product_load($product_id);
	$jersey_print_data = $product->field_jersey_print['und'][0]['set_details'];
	$jersey_print_values = $jersey_print;
	$jersey_print_output = theme('fck_jp_attributes', array('jersey_print_values' => $jersey_print_values, 'jersey_print_data' => $jersey_print_data,
		'show_price' => FALSE));

	$jersey_print_price = fck_jp_get_wishlist_data($product_id, $uid);
	$price = fck_jp_get_wishlist_price($product_id, $uid, $jersey_print_price);	

	$autograph = $jersey_print['field_autograph'];
	$badge = $jersey_print['field_superliga_badge'];
	$player = is_object($jersey_print['field_players']) ? $jersey_print['field_players']->tid : 0;
	$label = $jersey_print['field_text_label'];
	$number = $jersey_print['field_text_number'];

	$url = fck_generate_product_url($product_nid, $product_id, $autograph, $badge, $player, $label, $number);
} else {
	$url = fck_generate_product_url($product_nid);
}

$product = entity_load_single('commerce_product', $product_id);
$wrapper = entity_metadata_wrapper('commerce_product', $product);
// price
// 
if (empty($price)) {
	$commerce_price_data = $wrapper	
		->commerce_price
		->value();
	$price = commerce_currency_format(
		$commerce_price_data['amount'], 
		$commerce_price_data['currency_code']
	);
}
// image
$first_image = $wrapper->field_product_images[0]->value();
$image_url = '';
if (isset($first_image['uri'])) {
	$image_url = image_style_url('product_list_small', $first_image['uri']);	
}

?>

<div class="whishlist-item">
	<div class="product-image">
		<?php print l(theme('image', array('path' => $image_url)), $url, array('html' => TRUE)); ?>
	</div>
	<div class="product-body">
		<div class="whishlist-name">
			<h3><?php print l($product->title, $url); ?></h3>
			<?php print $jersey_print_output; ?>
		</div>
		<div class="whishlist-price">
			<span><?php print t('Price') ?>:</span>
			<strong><?php print $price; ?></strong>
		</div>
	</div>
</div>
