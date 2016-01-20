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
$date_format = date('d-M',$row->node_created);
$date_month = explode('-', $date_format);
?>
<article class="post">
	<?php print $fields['field_media_blog']->content;?>
    
    <div class="entry-summary">
        <div class="entry-datetime">
            <a href="#" title="">
                <span class="entry-day"><?php print $date_month[0];?></span>
                <span class="entry-month">/<?php print $date_month[1];?></span>
            </a>
        </div>
        <!-- /.entry-datetime -->

        <div class="entry-title">
            <h2><?php print $fields['title']->content;?></h2>
        </div>
        <!-- /.entry-title -->

        <div class="entry-excerpt">
            <?php print $fields['body']->content;?>
        </div>
        <!-- /.entry-excerpt -->

        <div class="entry-meta">
            <span><?php print t('Posted by')?></span>
            <strong class="entry-author"><?php print $author_name;?> </strong>
            <span>-</span>
            <span class="entry-category"><?php print $fields['field_category_blog']->content?>  </span>
            <span>-</span>
            <span class="entry-comment-count"><a href="#" title=""><?php print $fields['comment_count']->content . ' ' . t('Comments')?></a></span>
        </div>
        <!-- /.entry-meta -->
    </div>
    <!-- /.entry-summary -->
</article>