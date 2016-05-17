<?php

/**
 * @file
 * Theme the more link.
 *
 * - $view: The view object.
 * - $more_url: the url for the more link.
 * - $link_text: the text for the more link.
 *
 * @ingroup views_templates
 */
?>
<?php if ($view->name == "product_small_wishlist" || 
					$view->name == "product_small_wishlist_product") :?>
	<div class="whishlist-action">
			<a href="<?php print $more_url ?>" title="" class="btn btn-dark btn-lg btn-outline btn-block"><?php print $link_text; ?></a>
	</div>
<?php else: ?>
	<div class="more-link">
		<a href="<?php print $more_url ?>">
			<?php print $link_text; ?>
		</a>
	</div>
<?php endif; ?>
