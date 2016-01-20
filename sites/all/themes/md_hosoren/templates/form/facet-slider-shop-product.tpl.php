<?php
	unset($form['range-from']['#theme_wrappers']);
	unset($form['range-to']['#theme_wrappers']);

	$form['submit']['#value'] = "FILTER";
	$form['submit']['#attributes'] = array('class' => array('submit-filter'));

?>



<?php print drupal_render($form['range-min']) ?>
<?php print drupal_render($form['range-max']) ?>

<?php print drupal_render($form['range-slider']) ?>
<div class="slider_value center small gray">
	<span><?php print t('Start from') ?></span>
	<span id="amount" class="dark bold"><?php print drupal_render($form['range-from']) ?></span>
	<span><?php print t('to') ?></span>
	<span class="dark bold"><?php print drupal_render($form['range-to']) ?></span>
</div>

<div style="display: none">
	<?php print $form['range-min']['#value']; ?>
	<?php print $form['range-max']['#value']; ?>
  <?php print drupal_render($form['submit']) ?>
  <?php print drupal_render_children($form); ?>
</div>
