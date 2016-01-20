<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page while offline.
 *
 * All the available variables are mirrored in html.tpl.php and page.tpl.php.
 * Some may be blank but they are provided for consistency.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 *
 * @ingroup themeable
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
  <title><?php print $title; ?></title>	
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>">	
  <div class="comming-soon background-color-dark" style="background-image: url('<?php print $maintenance_pic ?>');">
    <div class="fp-table">
			<div class="fp-table-cell center">
				<div class="container">
						<header>
								<div class="comming-soon-logo">
										<a href="<?php print $base_path; ?>" title="<?php print t('Home'); ?>" rel="home">
											<img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
										</a>
								</div>
								<div class="comming-soon-heading">
										<h1><?php print $title; ?></h1>
										<p><?php print $construction_description; ?></p>
										<div class="content-maintenance center">
											<?php print $content; ?>
										</div>
								</div>
						</header>
						<div id="countdown-time" class="countdown-time">
								<div class="countdown-soon" data-time="<?php print $construction_time; ?>"></div>
								<div class="row">
										<div class="col-md-3 col-sm-3 col-xs-3">
												<div class="awe-counting days">
														<h4>Days</h4>
														<span>12</span>
												</div>
										</div>
										<div class="col-md-3 col-sm-3 col-xs-3">
												<div class="awe-counting hours">
														<h4>Hours</h4>
														<span>08</span>
												</div>
										</div>
										<div class="col-md-3 col-sm-3 col-xs-3">
												<div class="awe-counting minutes">
														<h4>Minutes</h4>
														<span>43</span>
												</div>
										</div>
										<div class="col-md-3 col-sm-3 col-xs-3">
												<div class="awe-counting seconds">
														<h4>Seconds</h4>
														<span>29</span>
												</div>
										</div>
								</div>
						</div>
						<footer>
								<p class="follow-us">Follow us on</p>
								<?php
										$block_view = module_invoke('md_block_custom', 'block_view', 'mls_social_blog');
										print render($block_view['content']);
								?>
						</footer>
				</div>
			</div>
		</div>
  </div> <!-- /page -->

</body>
</html>