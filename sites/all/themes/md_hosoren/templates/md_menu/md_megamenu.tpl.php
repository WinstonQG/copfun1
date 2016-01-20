<?php
/**
 * File: md-awemenu.tpl.php
 * Author: MegaDrupal
 * Website: http://megadrupal.com/
 */
$count_item = count($variables['menu_items']);
$half = $count_item/2;
?>
<div id="md-megamenu-<?php print $menu->mid;?>" class="<?php print implode(' ', $classes_array);?>">

			<?php if(theme_get_setting('header_type')=='3' && !empty($variables['logo'])): ?>
				<div class="awemenu-container">
					<div class="awe-logo">
						<a href="<?php print url('<front>');?>" title="<?php print t('Home');?>" rel="home">
							<img src="<?php print $logo;?>" alt="<?php print t('Home');?>">
						</a>
					</div>
					<ul class="awemenu">
					<?php foreach ($menu_items as $id => $value): ?>
						<?php if($id<$half): ?>
			        <?php print drupal_render($value); ?>
			      <?php endif;?>
			    <?php endforeach; ?>			
					<li class="awemenu-item menu-logo">
						<a href="<?php print url('<front>');?>" title="<?php print t('Home');?>" rel="home">
							<img src="<?php print $logo;?>" alt="<?php print t('Home');?>">
						</a>
					</li>
			    <?php foreach ($menu_items as $id => $value): ?>
						<?php if($id>=$half): ?>
			        <?php print drupal_render($value); ?>
			      <?php endif;?>
			    <?php endforeach; ?>
			  </ul>
			</div>

			<?php else: ?>
				<?php if ($logo):?>
					<div class="awemenu-container">
						<div class="awe-logo">
							<a href="<?php print url('<front>');?>" title="<?php print t('Home');?>" rel="home">
								<img src="<?php print $logo;?>" alt="<?php print t('Home');?>">
							</a>
						</div>
						<ul class="awemenu">
							<?php print drupal_render($menu_items); ?>
						</ul>
					</div>
				<?php else: ?>
					<div class="awemenu-container">
						<ul class="awemenu">
							<?php print drupal_render($menu_items);?>
						</ul>		
					</div>
				<?php endif;?>
			<?php endif;?>
			
</div>
