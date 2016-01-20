<?php
/**
 * File: md-awemenu-item.tpl.php
 * Author: MegaDrupal
 * Website: http://megadrupal.com/
 */
?>
<li class="<?php print implode(' ', $classes_array);?>">
	<a href="<?php print $item_url;?>" class="<?php print implode(' ', $item_link_classes);?>"><?php print $item_link_content;?></a>
	<?php if (!empty($submenu_render)):?>
	<ul class="<?php print implode(' ', $submenu_classes);?>"<?php print $submenu_attributes;?>>
		<?php print drupal_render($submenu_render);?>
	</ul>
	<?php endif;?>
</li>