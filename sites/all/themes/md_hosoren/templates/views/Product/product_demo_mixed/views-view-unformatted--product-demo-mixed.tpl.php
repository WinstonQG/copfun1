<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="cate4-wrapper">
	<?php foreach ($rows as $id => $row): ?>
		<div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
			<div class="content">
					<h2>
							<small><?php print render($view->result[$id]->field_field_sub_description[0]['rendered']); ?></small>
							<span><?php print render($view->result[$id]->taxonomy_term_data_name); ?></span>
					</h2>

					<p class="lead"><?php print render($view->result[$id]->taxonomy_term_data_description); ?></p>

					<?php print l('View All Category', 'taxonomy/term/' . $view->result[$id]->tid, array('html' => 'true', 'attributes' => array('class' =>  array('btn', 'btn-lg','btn-dark','btn-outline')))); ?>

					<div class="small-image">
							<?php print render($view->result[$id]->field_field_thumbnail_picture[0]['rendered']); ?>
					</div>
			</div>
			<div class="large-image">
					<?php print render($view->result[$id]->field_field_image[0]['rendered']); ?>
			</div>
		</div>
	<?php endforeach; ?>
</div>