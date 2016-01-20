<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<div class="section-post-media">
	<?php foreach ($row->field_field_media_blog as $keyC => $valueC):?>
	  	<?php if($row->field_field_media_blog[$keyC]['rendered']['#bundle'] == 'image'):?>
		  	<a href="#" title="">
		        <img src="<?php print image_style_url('news_blog_image_style',$row->field_field_media_blog[$keyC]['rendered']['#file']->uri)?>" alt="">
			</a>
		<?php endif?>

		<?php if($row->field_field_media_blog[$keyC]['rendered']['#bundle'] == 'video' || $row->field_field_media_blog[$keyC]['rendered']['#bundle'] == 'audio'):?>
			<?php print $field->original_value; ?>
			<?php endif?>
	<?php endforeach;?>
</div>