<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<ul class="awe-nav">
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>

    <li><a href="#" data-filter="*" id="all" class="current"><?php print t('Show all');?></a></li>
    <?php foreach ($rows as $id => $row): ?>
    <li><a href="#" data-filter=".type-<?php print strtr($view->result[$id]->taxonomy_term_data_name,' ','-'); ?>"><?php print $view->result[$id]->taxonomy_term_data_name; ?></a> </li>  
    <?php endforeach; ?>
</ul>