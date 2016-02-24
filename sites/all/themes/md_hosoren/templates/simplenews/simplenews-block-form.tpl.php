<?php
	unset($form['mail']['#theme_wrappers']);
	$form['submit']['#value'] = t('Subscribe Email');
	$form['mail']['#atrributes']['placeholder'] = t('Enter your email address');
  $form['#atrributes']['class'][] = 'subscible-form';
  $form['mail']['#title'] = t('Enter your email address');
  $form['#prefix'] = '<div class="subscible-form">';
  $form['#suffix'] = '</div>';
  
?>

<?php if (user_is_logged_in()): ?>
	<?php print drupal_render($form['submit']); ?>
	<?php print drupal_render_children($form); ?>
<?php else: ?>
	<div class="form-group">
		<?php print drupal_render($form['mail']); ?>
	</div><div class="form-submit">
		<?php print drupal_render($form['submit']); ?></div>
		<?php print drupal_render_children($form); ?>
<?php endif;?>