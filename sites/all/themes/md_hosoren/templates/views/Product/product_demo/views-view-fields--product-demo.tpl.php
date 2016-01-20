<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php if(isset($fields['view']->content)):?>
	<div class="col-md-3 col-sm-4">
<?php endif;?>
		<div class="awe-media home-cate-media">
			<div class="awe-media-header">
				<div class="awe-media-image">
					<?php print $fields['field_image']->content; ?>
				</div>
				<div class="awe-media-overlay overlay-dark-50 fullpage">
					<div class="content">
						<div class="fp-table text-left">
								<div class="fp-table-cell">
										<h2 class="upper"><?php print $fields['name']->content; ?></h2>
										<div class="margin-bottom-50"><?php print $fields['description']->content; ?></div>
										<a href="<?php print $fields['tid']->content; ?>" class="btn btn-sm btn-outline btn-white">View All</a>
								</div>
						</div>
				</div>
			</div>
			</div>
		</div>
<?php if(isset($fields['view']->content)):?>
	</div>
	<div class="col-md-9 col-sm-8">
		<?php print $fields['view']->content; ?>
	</div>
<?php endif;?>