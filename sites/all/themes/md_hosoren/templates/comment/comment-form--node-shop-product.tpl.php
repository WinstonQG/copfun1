<?php
hide($form['author']);
hide($form['author']['homepage']);
hide($form['comment_body']);

unset($form['author']['name']['#theme_wrappers']);
unset($form['author']['mail']['#theme_wrappers']);
unset($form['author']['homepage']['#theme_wrappers']);
unset($form['subject']['#theme_wrappers']);
unset($form['comment_body']['und'][0]['value']['#theme_wrappers']);

$form['actions']['submit']['#value'] = t("Submit Review");
?>

	<div class="row">
		<?php if (!isset($form['author']['_author'])) : ?>
			<div class="col-sm-6">
				<div class="form-group">
	            	<label for="reply-name">Name <sup>*</sup></label>
				    <?php print drupal_render($form['author']['name']); ?>
				</div>
			  </div>
			<div class="col-sm-6">
				<div class="form-group">
					<label for="reply-email">Email <sup>*</sup></label>
			    	<?php print drupal_render($form['author']['mail']); ?>
			    </div>
			  </div>
		<?php endif; ?>
	</div>
	<div class="form-group">
    <label for="reply-title">Title <sup>*</sup></label>
	  <?php print drupal_render($form['subject']); ?>
  </div>
	<div class="form-group">
    <label for="reply-text">Your review <sup>*</sup></label>
	  <?php print drupal_render($form['comment_body']['und'][0]['value']); ?>
	</div>
	<div class="form-submit clearfix">
		<div class="pull-left">
			<?php print drupal_render($form['field_your_rating']); ?>
		</div>  	
		<div class="pull-right">
		  <?php print drupal_render($form['actions']) ?>
		</div> 
	</div> 

<div style="display: none">
  <?php print drupal_render_children($form); ?>
</div>
