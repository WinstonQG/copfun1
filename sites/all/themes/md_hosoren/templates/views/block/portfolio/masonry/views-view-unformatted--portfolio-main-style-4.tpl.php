<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class='grid row'>
<?php if (!empty($title)): ?>
  <h1><?php print $title; ?></h1>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <?php $class_filter = ' '; ?>
  <?php foreach ($view->result[$id]->field_field_portfolio_categories as $value): ?>  
    <?php $class_filter .= ' ' . 'type-' . strtr($value['rendered']['#markup'], ' ', '-'); ?>
  <?php endforeach; ?>
  <div class="grid-item <?php print $class_filter; ?> col-md-3 col-sm-3 col-xs-12">
      <?php print $row; ?>
  </div>  
<?php endforeach; ?>
</div>
