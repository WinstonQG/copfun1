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
$uid = arg(1);
if (empty($uid)) {
	global $user;
	$uid = $user->uid;
}
$product_id = $row->product_id;
$product_nid = fck_get_node_id($row->product_id);
$jersey_print = fck_jp_get_wishlist_data($product_id, $uid, TRUE);

$autograph = $jersey_print['field_autograph'];
$badge = $jersey_print['field_superliga_badge'];
$player = is_object($jersey_print['field_players']) ? $jersey_print['field_players']->tid : 0;
$label = $jersey_print['field_text_label'];
$number = $jersey_print['field_text_number'];

$url = fck_generate_product_url($product_nid, $product_id, $autograph, $badge, $player, $label, $number);
?>

<?php print l($output, $url, array('html' => TRUE)); ?>
