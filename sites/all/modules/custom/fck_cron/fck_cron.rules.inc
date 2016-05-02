<?php

/**
 * Implements hook_rules_action_info().
 */
function fck_cron_rules_action_info() {	
	$actions = array();

	$actions['fck_cron_rules_new_product_update'] = array(
		'label' => t('Drop New option for products after expiration date (30 days)'),	
		'group' => t('FCK'),
		'callbacks' => array(
		  'execute' => 'fck_cron_rules_new_product_update',
		),		
	);	
		
	return $actions;
}

/**
 * Rules action: Drop New option for products after expiration date (30 days)
 */
function fck_cron_rules_new_product_update() {	
	fck_cron_new_product_update();
}