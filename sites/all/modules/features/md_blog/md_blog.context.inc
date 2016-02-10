<?php
/**
 * @file
 * md_blog.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function md_blog_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_category';
  $context->description = '';
  $context->tag = 'Blog';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'categories_blog' => 'categories_blog',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-92def435f0b0d1b72564095625a69af5' => array(
          'module' => 'views',
          'delta' => '92def435f0b0d1b72564095625a69af5',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-8d28d618fba1caa61820627572b661c9' => array(
          'module' => 'views',
          'delta' => '8d28d618fba1caa61820627572b661c9',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-blog_sidebar-block_recent_post' => array(
          'module' => 'views',
          'delta' => 'blog_sidebar-block_recent_post',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-5052afdc81fe2c9b483ba5702b1abb01' => array(
          'module' => 'views',
          'delta' => '5052afdc81fe2c9b483ba5702b1abb01',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'md_block_custom-mls_social_blog' => array(
          'module' => 'md_block_custom',
          'delta' => 'mls_social_blog',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  $export['blog_category'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_classic';
  $context->description = '';
  $context->tag = 'Blog';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'blog_classic' => 'blog_classic',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-92def435f0b0d1b72564095625a69af5' => array(
          'module' => 'views',
          'delta' => '92def435f0b0d1b72564095625a69af5',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-8d28d618fba1caa61820627572b661c9' => array(
          'module' => 'views',
          'delta' => '8d28d618fba1caa61820627572b661c9',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-blog_sidebar-block_recent_post' => array(
          'module' => 'views',
          'delta' => 'blog_sidebar-block_recent_post',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-5052afdc81fe2c9b483ba5702b1abb01' => array(
          'module' => 'views',
          'delta' => '5052afdc81fe2c9b483ba5702b1abb01',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'md_block_custom-mls_social_blog' => array(
          'module' => 'md_block_custom',
          'delta' => 'mls_social_blog',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  $export['blog_classic'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_list';
  $context->description = '';
  $context->tag = 'Blog';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'blog_list' => 'blog_list',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-92def435f0b0d1b72564095625a69af5' => array(
          'module' => 'views',
          'delta' => '92def435f0b0d1b72564095625a69af5',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-8d28d618fba1caa61820627572b661c9' => array(
          'module' => 'views',
          'delta' => '8d28d618fba1caa61820627572b661c9',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-blog_sidebar-block_recent_post' => array(
          'module' => 'views',
          'delta' => 'blog_sidebar-block_recent_post',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-5052afdc81fe2c9b483ba5702b1abb01' => array(
          'module' => 'views',
          'delta' => '5052afdc81fe2c9b483ba5702b1abb01',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'md_block_custom-mls_social_blog' => array(
          'module' => 'md_block_custom',
          'delta' => 'mls_social_blog',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  $export['blog_list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_single';
  $context->description = '';
  $context->tag = 'Blog';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-92def435f0b0d1b72564095625a69af5' => array(
          'module' => 'views',
          'delta' => '92def435f0b0d1b72564095625a69af5',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-8d28d618fba1caa61820627572b661c9' => array(
          'module' => 'views',
          'delta' => '8d28d618fba1caa61820627572b661c9',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-blog_sidebar-block_recent_post' => array(
          'module' => 'views',
          'delta' => 'blog_sidebar-block_recent_post',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-5052afdc81fe2c9b483ba5702b1abb01' => array(
          'module' => 'views',
          'delta' => '5052afdc81fe2c9b483ba5702b1abb01',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'md_block_custom-mls_social_blog' => array(
          'module' => 'md_block_custom',
          'delta' => 'mls_social_blog',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  $export['blog_single'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_tags';
  $context->description = '';
  $context->tag = 'Blog';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'tags_blog' => 'tags_blog',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-92def435f0b0d1b72564095625a69af5' => array(
          'module' => 'views',
          'delta' => '92def435f0b0d1b72564095625a69af5',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-8d28d618fba1caa61820627572b661c9' => array(
          'module' => 'views',
          'delta' => '8d28d618fba1caa61820627572b661c9',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-blog_sidebar-block_recent_post' => array(
          'module' => 'views',
          'delta' => 'blog_sidebar-block_recent_post',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-5052afdc81fe2c9b483ba5702b1abb01' => array(
          'module' => 'views',
          'delta' => '5052afdc81fe2c9b483ba5702b1abb01',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'md_block_custom-mls_social_blog' => array(
          'module' => 'md_block_custom',
          'delta' => 'mls_social_blog',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  $export['blog_tags'] = $context;

  return $export;
}
