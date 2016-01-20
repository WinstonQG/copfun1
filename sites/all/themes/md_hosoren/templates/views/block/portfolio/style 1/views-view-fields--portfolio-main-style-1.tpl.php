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
global $base_url;
$media ='';
if ($fields['field_display_media_type']->content == 'Gallery'){
  if ( $row->field_field_multimedia[0]['rendered']['#bundle'] == 'video'){
    $media = '<div class="awe-media-portfolio">' . $fields['field_multimedia']->content . '</div>';
  } else {
    $media = '<div class="awe-media-image">'.$fields['field_multimedia']->content .'</div>';
  }
} else{
  $media = '<div class="entry-carousel owl-carousel">'.$fields['field_multimedia_1']->content .'</div>';
}
?>
                        <div class="awe-media margin-bottom-30">
                            <div class="awe-media-header">
                                    <?php print $media;?>
                                <!-- /.awe-media-image -->

                                <div class="awe-media-hover">
                                    <a href="<?php print $fields['path']->content;?>" class="profolio-content-text">
                                        <h2 class="upper"><?php print $fields['title']->content;?></h2>
                                        <p><?php print $fields['field_portfolio_categories']->content;?></p>

                                        <span class="icon-next">
                                    <i class="icon fontello icon-right-open" aria-hidden="true"></i>
                                </span>
                                    </a>
                                </div>
                                <!-- /.awe-media-hover -->

                            </div>
                            <!-- /.awe-media-header -->
                        </div>
                        <!-- /.awe-media -->
