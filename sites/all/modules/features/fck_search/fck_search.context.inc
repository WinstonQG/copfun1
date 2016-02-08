<?php
/**
 * @file
 * fck_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function fck_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'fck_search_pages';
  $context->description = 'FCK Search Pages';
  $context->tag = 'search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'fck_search_pages' => 'fck_search_pages',
        'fck_search_pages:accessories_page' => 'fck_search_pages:accessories_page',
        'fck_search_pages:baby_page' => 'fck_search_pages:baby_page',
        'fck_search_pages:clothing_page' => 'fck_search_pages:clothing_page',
        'fck_search_pages:gifts_page' => 'fck_search_pages:gifts_page',
        'fck_search_pages:match_kits_page' => 'fck_search_pages:match_kits_page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-33L3mhnHNq4HsiS41vF0saLTvQ1oLAfQ' => array(
          'module' => 'facetapi',
          'delta' => '33L3mhnHNq4HsiS41vF0saLTvQ1oLAfQ',
          'region' => 'sidebar_first',
          'weight' => '-54',
        ),
        'facetapi-8HfmZJaQgeaPRtYmzOxKwQs0ZDV03IZj' => array(
          'module' => 'facetapi',
          'delta' => '8HfmZJaQgeaPRtYmzOxKwQs0ZDV03IZj',
          'region' => 'sidebar_first',
          'weight' => '-53',
        ),
        'facetapi-HfZiWbSokDqvBAqAk3A1JoFoCNsASU1u' => array(
          'module' => 'facetapi',
          'delta' => 'HfZiWbSokDqvBAqAk3A1JoFoCNsASU1u',
          'region' => 'sidebar_first',
          'weight' => '-52',
        ),
        'facetapi-poGwIUG4Pvn7JyZlYbLpeiXDZ0tY16PR' => array(
          'module' => 'facetapi',
          'delta' => 'poGwIUG4Pvn7JyZlYbLpeiXDZ0tY16PR',
          'region' => 'sidebar_first',
          'weight' => '-51',
        ),
        'facetapi-HlZ1mun6zDgwjOhcSAmJDoBEedFWaL8u' => array(
          'module' => 'facetapi',
          'delta' => 'HlZ1mun6zDgwjOhcSAmJDoBEedFWaL8u',
          'region' => 'sidebar_first',
          'weight' => '-50',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('FCK Search Pages');
  t('search');
  $export['fck_search_pages'] = $context;

  return $export;
}
