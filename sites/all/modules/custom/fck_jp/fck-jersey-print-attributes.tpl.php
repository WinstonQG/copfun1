<div class="fck-cart-attributes">
	<?php if ($jersey_print_values && $jersey_print_values['field_superliga_badge']) : ?>
		<div class="fck-attribute">
			<span class="jp-label"><?php print t('Superliga badge'); ?>:</span>
			<span class="jp-value">Ja</span>
			<?php if ($show_price) : ?>
			<span class="jp-price"> +<?php print $jersey_print_prices['field_superliga_badge']; ?></span>
			<?php endif; ?>
		</div>
	<?php endif; ?>
	<?php if ($jersey_print_values && $jersey_print_values['field_autograph']) : ?>
		<div class="fck-attribute">
			<span class="jp-label"><?php print t('Autograph'); ?>:</span>
			<span class="jp-value">Ja</span>
			<?php if ($show_price) : ?>
			<span class="jp-price"> +<?php print $jersey_print_prices['field_autograph']; ?></span>
			<?php endif; ?>
		</div>
	<?php endif; ?>
	<?php if ($jersey_print_values && !empty($jersey_print_values['field_text_label'])) : ?>
		<div class="fck-attribute">
			<span class="jp-label"><?php print t('Text Label'); ?>:</span>
			<span class="jp-value"><?php print $jersey_print_values['field_text_label']; ?></span>
			<?php if ($show_price) : ?>
			<span class="jp-price"> +<?php print $jersey_print_prices['field_text_label']; ?></span>
			<?php endif; ?>
		</div>
	<?php endif; ?>
	<?php if ($jersey_print_values && !empty($jersey_print_values['field_text_number'])) : ?>
		<div class="fck-attribute">
			<span class="jp-label"><?php print t('Text Number'); ?>:</span>
			<span class="jp-value"><?php print $jersey_print_values['field_text_number']; ?></span>
			<?php if ($show_price) : ?>
			<span class="jp-price"> +<?php print $jersey_print_prices['field_text_number']; ?></span>
			<?php endif; ?>
		</div>
	<?php endif; ?>
	<?php if ($jersey_print_values && is_object($jersey_print_values['field_players'])) : ?>
		<div class="fck-attribute">
			<span class="jp-label"><?php print t('Player'); ?>:</span>
			<span class="jp-value">"<?php print $jersey_print_values['field_players']->name; ?>"</span>
			<?php if ($show_price) : ?>
			<span class="jp-price"> +<?php print $jersey_print_prices['field_players']; ?></span>
			<?php endif; ?>
		</div>
	<?php endif; ?>
</div>