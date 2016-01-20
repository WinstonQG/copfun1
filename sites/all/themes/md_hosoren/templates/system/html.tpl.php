<?php

/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */
?><!DOCTYPE html>
<html>
<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php if (isset($ios_144) && $ios_144 != NULL) : ?>
    <link rel="apple-touch-icon-precomposed" sizes="144x144"
          href="<?php print $ios_144; ?>"><?php endif; ?>
  <?php if (isset($ios_114) && $ios_114 != NULL) : ?>
    <link rel="apple-touch-icon-precomposed" sizes="114x114"
          href="<?php print $ios_114; ?>"><?php endif; ?>
  <?php if (isset($ios_72) && $ios_72 != NULL)  : ?>
    <link rel="apple-touch-icon-precomposed" sizes="72x72"
          href="<?php print $ios_72; ?>"><?php endif; ?>
  <?php if (isset($ios_57) && $ios_57 != NULL)  : ?>
    <link rel="apple-touch-icon-precomposed" sizes="57x57"
          href="<?php print $ios_57; ?>"><?php endif; ?>
  <meta name="msapplication-tap-highlight" content="no"/>
  <meta name="viewport" content="user-scalable=0, width=device-width, initial-scale=1, minimum-scale=1.0, maximum-scale=1.0, minimal-ui"/>
  <meta name="format-detection" content="telephone=no">
  <link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Montserrat:400,700">
  <link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Roboto:300,400,700,400italic,700italic&amp;subset=latin,vietnamese">
  <?php
    print $styles;
    print $scripts;
    global $base_url;
  ?>
  <?php 
      if (isset($header_code)): print $header_code; endif;
  ?>
  <style type="text/css">
    <?php if (isset($googlewebfonts)): print $googlewebfonts; endif; ?>
    <?php if (isset($theme_setting_css)): print $theme_setting_css; endif; ?>
    <?php
    // custom typography
    if (isset($typography)): print $typography; endif;
    ?>
    <?php if (isset($custom_css)): print $custom_css; endif; ?>
  </style>
</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php print $preload; ?>
  
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
  <?php if (isset($footer_code)): print $footer_code; endif; ?>
</body>
</html>
