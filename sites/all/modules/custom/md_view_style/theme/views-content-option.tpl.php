<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if ($class_wrapper && $layout_number): ?>
	<div class="<?php print $class_wrapper; ?>" data-items="<?php print $layout_number; ?>">
<?php elseif ($class_wrapper): ?>
	<div class="<?php print $class_wrapper; ?>">
<?php endif; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php if ($class_content): ?><div class="<?php print $class_content; ?>"><?php endif; ?>
	
    <?php foreach ($rows as $id => $row): ?>
				<?php if ($classes_array[$id]): ?><div class="<?php print $classes_array[$id]; ?>"><?php endif; ?>
					<?php print $row; ?>
				<?php if ($classes_array[$id]): ?></div><?php endif; ?>
    <?php endforeach; ?>
		
  <?php if ($class_content): ?></div><?php endif; ?>
<?php if ($class_wrapper): ?></div><?php endif; ?>