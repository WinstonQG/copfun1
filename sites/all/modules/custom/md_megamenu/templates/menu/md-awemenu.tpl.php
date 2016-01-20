<?php
/**
 * File: md-awemenu.tpl.php
 * Author: MegaDrupal
 * Website: http://megadrupal.com/
 */
?>
<div id="md-megamenu-<?php print $menu->mid;?>" class="<?php print implode(' ', $classes_array);?>">
	<div class="awemenu-container"<?php if (!$menu->settings['general']['dmg_fullwidth']) print ' style="width: '. $menu->settings['general']['dmg_customwidth'] .'px;"';?>>
		<?php if ($logo):?>
		<div class="awemenu-logo">
			<a href="<?php print url('<front>');?>" title="<?php print t('Home');?>" rel="home">
				<img src="<?php print $logo;?>" alt="<?php print t('Home');?>">
			</a>
		</div>
		<?php endif;?>
		<ul class="awemenu">
			<?php print drupal_render($menu_items);?>
		</ul>
	</div>
</div>