<?php
/**
 * @file
 * md_portfolio.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function md_portfolio_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'portfolio_single';
  $context->description = '';
  $context->tag = 'Portfolio';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'portfolio' => 'portfolio',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-lasted_portfolios-block' => array(
          'module' => 'views',
          'delta' => 'lasted_portfolios-block',
          'region' => 'bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Portfolio');
  $export['portfolio_single'] = $context;

  return $export;
}
