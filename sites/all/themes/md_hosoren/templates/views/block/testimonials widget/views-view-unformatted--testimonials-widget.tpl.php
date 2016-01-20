<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="section-header center">
  <?php if (!empty($title)): ?>
  <h2><?php print $title; ?></h2>
<?php endif; ?>
</div>
<div class="section-customers">
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
            <div class="customers-carousel owl-carousel" id="customers-carousel">
                <?php foreach ($rows as $id => $row): ?>
                  <div<?php if ($classes_array[$id]) {
                    print ' class="' . $classes_array[$id] . '"';
                  } ?>>
                  <?php print $row; ?>
                  </div>
                <?php endforeach; ?>
            </div>
        </div>
    </div></div>