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
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
			<h2><?php print render($view->result[$id]->node_title); ?></h2>
			<div class="heading">
				<div class="image">
					<img src="<?php print image_style_url('lookbook',$view->result[$id]->field_field_image[0]['raw']['uri']); ?>" alt="lookbook">
				</div>
			</div>
			<div class="content">
				<div class="small-image">
					<img src="<?php print image_style_url('lookbook_thumbnail',$view->result[$id]->field_field_thumbnail[0]['raw']['uri']); ?>" alt="lookbook">
				</div>
				<div class="content-body">
						<h3><?php print render($view->result[$id]->field_field_subtitle[0]['raw']['value']); ?></h3>
						<p><?php print render($view->result[$id]->field_body[0]['raw']['value']); ?></p>
						<a href="<?php print render($view->result[$id]->field_field_product_lookbook[0]['rendered']['#href']); ?>" class="btn btn-lg btn-dark"><span><?php print t('VIEW LOOKBOOK') ?></span><i class="fa fa-chevron-right margin-left-5"></i></a>
				</div>
				<span class="line"></span>
			</div>	
  </div>
<?php endforeach; ?>