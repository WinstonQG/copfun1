<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>

    <?php print $row; ?>
  
<?php endforeach; ?>