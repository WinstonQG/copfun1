<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<?php if (!empty($title)): ?>
  <h1><?php print $title; ?></h1>
<?php endif; ?>
<div class="row grid">
    <?php foreach ($rows as $id => $row): ?>
<?php $class_filter = ' ' ; ?>
      <?php foreach ($view->result[$id]->field_field_portfolio_categories as $value): ?>  
    <?php $class_filter .= ' ' . 'type-'.strtr($value['rendered']['#markup'], ' ', '-'); ?>
  <?php endforeach; ?>
    <div class="grid-item <?php print $class_filter; ?> col-md-4 col-sm-4 col-xs-12">
      <?php print $row; ?>
    </div>            
    <?php endforeach; ?>
</div>
