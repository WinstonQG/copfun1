<?php

/**
 * @file field.tpl.php
 * Default template implementation to display the value of a field.
 *
 * This file is not used and is here as a starting point for customization only.
 * @see theme_field()
 *
 * Available variables:
 * - $items: An array of field values. Use render() to output them.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 *
 * Other variables:
 * - $element['#object']: The entity to which the field is attached.
 * - $element['#view_mode']: View mode, e.g. 'full', 'teaser'...
 * - $element['#field_name']: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_field()
 * @see theme_field()
 *
 * @ingroup themeable
 */
 //print render($items);
// dsm($element['#view_mode'])
?>
<?php if($element['#view_mode']=='node_modal_content'): ?>
		<div class="product-quickview-slider owl-carousel owl-carousel-inset">
			<?php foreach ($items as $delta => $item): ?>
				<div>
						<img src="<?php print image_style_url('product_modal_slider',$item['#item']['uri']); ?>" alt="<?php print render($item['#item']['alt']); ?>">
				</div>
			<?php endforeach; ?>
		</div>
		
<?php elseif($element['#view_mode']=='search_product'): ?>
		<div class="product-quickview-slider owl-carousel owl-carousel-inset">
			<?php foreach ($items as $delta => $item): ?>
				<div>
						<img src="<?php print image_style_url('lookbook',$item['#item']['uri']); ?>" alt="<?php print render($item['#item']['alt']); ?>">
				</div>
			<?php endforeach; ?>
		</div>

<?php elseif($element['#view_mode']=='line_item'): ?>
		<?php foreach ($items as $delta => $item): ?>
		   <?php print render($item); ?>
		<?php endforeach; ?>

<?php else: ?>
    
	<?php if(count($items) == 1):?>
		<div class="swiper-container product-slider-main">
      <div class="swiper-wrapper">
				<div class="easyzoom easyzoom--overlay">
					<a href="<?php print file_create_url($items[0]['#item']['uri']); ?>" title="<?php print render($items[0]['#item']['title']); ?>">
			        <img src="<?php print image_style_url('product_full',$items[0]['#item']['uri']); ?>" alt="<?php print render($items[0]['#item']['alt']); ?>">
			    </a>
				</div>
			</div>
		</div>
		<div class="swiper-container product-slider-thumbs">
	    <div class="swiper-wrapper">
	    </div>
	  </div>
	<?php else: ?>	
		<div class="swiper-container product-slider-main">
	      <div class="swiper-wrapper">
					<?php foreach ($items as $delta => $item): ?>
						<div class="swiper-slide">
	            <div class="easyzoom easyzoom--overlay">
								<a href="<?php print file_create_url($item['#item']['uri']); ?>" title="<?php print render($item['#item']['title']); ?>">
	                  <img src="<?php print  image_style_url('product_full',$item['#item']['uri']); ?>" alt="<?php print render($item['#item']['alt']); ?>">
	              </a>
							</div>
						</div>
					<?php endforeach; ?>
				</div>
				<?php if (0) : ?>
        <div class="swiper-button-prev"><i class="icon icon-left-open"></i></div>
        <div class="swiper-button-next"><i class="icon icon-right-open"></i></div>
      	<?php endif; ?>
		</div>
		<div class="swiper-container product-slider-thumbs">
	    <div class="swiper-wrapper">
	    	<?php foreach ($items as $delta => $item): ?>
	    		<div class="swiper-slide">
						<img src="<?php print image_style_url('product_slider_thumbnail',$item['#item']['uri']); ?>" alt="<?php print render($item['#item']['alt']); ?>">
					</div>
				<?php endforeach; ?>
			</div>
		</div>
	<?php endif; ?>
<?php endif; ?>