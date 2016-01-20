<?php

unset($form['author']['name']['#theme_wrappers']);
unset($form['author']['mail']['#theme_wrappers']);
unset($form['author']['homepage']['#theme_wrappers']);
unset($form['comment_body']['und'][0]['value']['#theme_wrappers']);
unset($form['subject']['#theme_wrappers']);
unset($form['actions']['#theme_wrappers']);

$form['actions']['submit']['#value'] = t("Submit Comment");
?>

<div class="row">
	<?php if (!isset($form['author']['_author'])) : ?>
		<div class="col-md-6">
				<div class="form-group">
				    <?php print drupal_render($form['author']['name']); ?>
				</div>
		</div>
		<div class="col-md-6">
				<div class="form-group">
					 	<?php print drupal_render($form['author']['mail']); ?>
				</div>
		</div>
	<?php endif;?>
</div>

<div class="form-group">
    <?php print drupal_render($form['author']['homepage']); ?>
</div>

<div class="form-group">
    <?php print drupal_render($form['subject']) ?>
</div>

<div class="form-group">
    <?php print drupal_render($form['comment_body']['und'][0]['value']); ?>
</div>

<div class="form-submit">
    <?php print drupal_render($form['actions']) ?>
</div>

<div style="display: none">
  <?php print drupal_render_children($form); ?>
</div>

