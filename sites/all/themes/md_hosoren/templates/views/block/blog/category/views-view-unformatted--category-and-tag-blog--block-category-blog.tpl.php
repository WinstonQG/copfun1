<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<h3><?php print t('Categories'); ?></h3>
<ul>
	<li class="current"><a href="#" title=""><?php print t('All'); ?></a></li>
	<?php foreach ($rows as $id => $row):?>
	  <li>
      <?php print $row;?>
    </li>
	<?php endforeach; ?>
</ul>