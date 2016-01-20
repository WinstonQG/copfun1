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
$date_format = date('d-F',$row->node_created);
$date_month = explode('-', $date_format);
?>
<div class="section-post">
    <?php if(isset($fields['field_media_blog'])):?>
        <?php print $fields['field_media_blog']->content;?>
    <?php endif;?>

    <div class="section-post-body">
        <div class="section-post-time">
            <span><?php print $date_month[0]?></span>  <small><?php print $date_month[1]?></small>
        </div>

        <h4 class="section-post-title">
        <a href="<?php print $fields['path']->content?>" title="<?php print $row->node_title;?>"><?php print $row->node_title;?></a>
        </h4>
				<div class="section-post-excerpt">
        	<?php print $fields['body']->content?>
      	</div>

        <a href="<?php print $fields['path']->content?>" title="" class="read-more"><?php print t('Read more')?></a>
    </div>
</div>