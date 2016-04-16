
<?php print drupal_render($form['attributes']); ?>

<div class="e-group clearfix">
	<h4 class="pull-left"><?php print t('Remember original FCK pressure on the shirt!'); ?></h4>
	<?php print $preview_text_button; ?>	
</div>

<h5><?php print t('F.C. Kopengahens squad'); ?></h5>
<?php print drupal_render($form['field_jersey_print'][0]['field_players']); ?>
<div class='e-players-value e-attribute-price-preview'></div>

<h5><?php print t('Own name and number'); ?></h5>
<div class="clearfix">	
		<div class="e-text-label-field pull-left">
			<?php print drupal_render($form['field_jersey_print'][0]['field_text_label']); ?>
			<div class='e-text-label-value e-attribute-price-preview'></div>
		</div>
		<div class="e-text-number-field pull-left">
			<?php print drupal_render($form['field_jersey_print'][0]['field_text_number']); ?>
			<div class='e-text-number-value e-attribute-price-preview'></div>
		</div>	
</div>

<div class="e-group clearfix">
	<h4 class="pull-left"><?php print t('Add Superliga sleeve brand!'); ?></h4>
	<?php print $preview_badge_button; ?>
</div>
<?php print drupal_render($form['field_jersey_print'][0]['field_superliga_badge']); ?>
<div class='e-badge-value e-attribute-price-preview'></div>

<div class="e-group clearfix">
	<h4 class="pull-left"><?php print t('Add autographs from FCK squad!'); ?></h4>
	<?php print $preview_autograph_button; ?>
</div>
<?php print drupal_render($form['field_jersey_print'][0]['field_autograph']); ?>
<div class='e-autograph-value e-attribute-price-preview'></div>

<?php print drupal_render_children($form); ?>