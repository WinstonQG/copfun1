<?php

/**
 * Implements hook_rules_action_info().
 */
function commerce_stock_filter_rules_action_info() {	
	$actions = array();

	$actions['commerce_stock_filter_publish_product_display'] = array(
		'label' => t('Publish a product display by product variation'),
		'parameter' => array(
		  'commerce_product' => array(
		    'type' => 'commerce_product',
		    'label' => t('Product'),
		  ),
		),
		'group' => t('Commerce Stock'),
		'callbacks' => array(
		  'execute' => 'commerce_stock_filter_rules_publish_product_display',
		),		
	);

	$actions['commerce_stock_filter_unpublish_product_display'] = array(
		'label' => t('Unpublish a product display if all product variantons have stock = 0'),
		'parameter' => array(
		  'commerce_product' => array(
		    'type' => 'commerce_product',
		    'label' => t('Product'),
		  ),
		),
		'group' => t('Commerce Stock'),
		'callbacks' => array(
		  'execute' => 'commerce_stock_filter_rules_unpublish_product_display',
		),		
	);
		
	return $actions;
}

/**
 * Rules action: Publish a product display by product variation
 */
function commerce_stock_filter_rules_publish_product_display($product) {	
	// don't launch on node add/edit forms 
	// (supposed product display forms)
	$a0 = arg(0); 
	$a2 = arg(2);
	if ($a0 == 'node' && ($a2 == 'add' || $a2 == 'edit')) {
		return;
	}
	// get product display id by product variation id
	$nid = csf_get_referencing_node_id($product);	
	$product_display = entity_load_single('node', $nid);	
	// publish product display
	dsm('pub');
	$product_display = node_load($nid);	
	$product_display->csf_ignore = TRUE;
	$product_display->status = TRUE;	
	node_save($product_display);		
}  

/**
 * Rules action: Unpublish a product display if all product variantons have stock = 0
 */
function commerce_stock_filter_rules_unpublish_product_display($product) {	
	// don't launch on node add/edit forms 
	// (supposed product display forms)
	$a0 = arg(0); 
	$a2 = arg(2);
	if ($a0 == 'node' && ($a2 == 'add' || $a2 == 'edit')) {
		return;
	}
	// get product display id by product variation id
	$nid = csf_get_referencing_node_id($product);	
	$product_display = entity_load_single('node', $nid);
	$wrapper = entity_metadata_wrapper('node', $product_display);
	// calculate a stock of all product variantions
	$total_stock = 0;
	foreach ($wrapper->field_product_store as $product) {
		$total_stock += $product->commerce_stock->value();
	}
	dsm('unbub'. $total_stock);
	// if total stock = 0 - unpublish product display		
	if (!$total_stock) {
		$product_display = node_load($nid);	
		$product_display->csf_ignore = TRUE;
		$product_display->status = FALSE;	
		node_save($product_display);
	}
} 