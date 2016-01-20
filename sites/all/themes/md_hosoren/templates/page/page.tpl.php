<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
global $base_url;
//dsm($variables);
?>

<div id="page-wrapper">

		<header id="header" class="awe-menubar-header clearfix <?php print $menu_header_style; ?>">

        <?php if ($site_name || $site_slogan): ?>
          <div id="name-and-slogan">
              <?php if ($site_name): ?>
                <?php if ($title): ?>
                  <div id="site-name"><strong>
                          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
                      </strong></div>
                <?php else: ?>
                  <h1 id="site-name">
                      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
                  </h1>
                <?php endif; ?>
              <?php endif; ?>

              <?php if ($site_slogan): ?>
                <div id="site-slogan"><?php print $site_slogan; ?></div>
              <?php endif; ?>
          </div>
        <?php endif; ?>
        
        <?php if($menu_header_style == 'header-style-3'):?>
          <?php if ($page['header_first']): ?>
          <div class="header-top">
              <div class="header-top-relative">
                <nav class="navtop">
                  <?php if ($logo): ?>
                    <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
                        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
                    </a>
                  <?php endif; ?>
                  
                  <?php print render($page['header_first']); ?>
                </nav>
              </div>
          </div>
          <?php endif; ?>
          <?php print render($page['header_second']); ?>
        <?php elseif($menu_header_style == 'header-style-4'):?>
          <?php if ($page['header_first']): ?>
          <div class="header-top">
              <div class="header-top-relative">
                <nav class="navtop">
                  <?php if ($logo): ?>
                    <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
                        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
                    </a>
                  <?php endif; ?>
                  
                  <?php print render($page['header_first']); ?>
                </nav>
              </div>
          </div>
          <?php endif; ?>
          <?php print render($page['header_second']); ?>
        <?php elseif($menu_header_style == 'header-style-default'):?>
        <div class="container">
          <div class="header-top">
              <div class="header-top-relative">
                <nav class="navtop">

                <?php if ($logo): ?>
                  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
                      <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
                  </a>
                <?php endif; ?>
      
                <?php print render($page['header_first']); ?>
                
                </nav>
              </div>
          </div>
          <?php print render($page['header_second']); ?>
        </div>
          
        <?php else:?>
          <?php if ($page['header_first']): ?>
          <div class="header-top">
            <div class="container">
              <div class="header-top-relative">
                <nav class="navtop">
                  <?php if ($logo): ?>
                    <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
                        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
                    </a>
                  <?php endif; ?>
                  
                  <?php print render($page['header_first']); ?>
                </nav>
              </div>
            </div>
          </div>
          <?php endif; ?>
          <?php if($menu_header_style == 'header-style-2' ||$menu_header_style == 'header-style-1'):?>
            <nav class="awemenu-style-2">
              <div class="container">
                <div class="awemenu-container">
                  <?php print render($page['header_second']); ?>
                </div>
              </div>
            </nav>
          <?php else:?>
            <?php print render($page['header_second']); ?>
          <?php endif;?>
        <?php endif;?>
        

    </header>
    
    <?php if(($title) && ($has_slider == FALSE) && ($section_type=="one")): ?>
			<div class="main-header background <?php print $section_background; ?>" style="background-image: <?php print $header_bg; ?>">
				<div class="section-header-overlay"></div>
				<div class="container">
					<?php print render($title_prefix); ?>
						<h1><?php print $title; ?></h1>
					<?php print render($title_suffix); ?>
					<?php if ($title_des): ?>
						<p><?php print $title_des; ?></p>
					<?php endif; ?>
				</div>
			</div>
		<?php elseif(($title) && ($has_slider == FALSE) && ($section_type=="two")): ?>
			<div class="main-header background <?php print $section_background; ?>" style="background-image: <?php print $header_bg; ?>">
				<div class="section-header-overlay"></div>
				<div class="container text-left">
					<?php print render($title_prefix); ?>
						<h1><?php print $title; ?></h1>
					<?php print render($title_suffix); ?>
					<?php if ($title_des): ?>
						<p><?php print $title_des; ?></p>
					<?php endif; ?>
					<?php if ($breadcrumb): ?>
						<div id="breadcrumb">
								<?php print $breadcrumb; ?>
						</div>
					<?php endif; ?>
				</div>
			</div>  
		<?php endif; ?>

    
		<?php if ($page['highlighted']): ?>
			<?php print render($page['highlighted']); ?>
    <?php endif;?>

    <div id="main" class="clearfix">
				
      <?php if(($title) && ($has_slider == FALSE) && ($section_type=="one")): ?>
        <?php if ($breadcrumb): ?>
          <div id="breadcrumb">
            <div class="container">
              <?php print $breadcrumb; ?>
            </div>
          </div>
        <?php endif; ?>
      <?php elseif(($has_slider == FALSE) && ($section_type=="default")): ?>
				<?php if ($breadcrumb): ?>			
					<div id="breadcrumb">
						<div class="container">
							<?php print $breadcrumb; ?>
						</div>
					</div>
				<?php endif; ?>
      <?php endif; ?>

				<?php print $messages; ?>

        <div class="container">
            <div class="row">
                <?php if ($page['sidebar_first']): ?>
                  <div id="sidebar-first" class="col-md-3 sidebar">
                      <?php print render($page['sidebar_first']); ?>
                  </div>
                <?php endif; ?>

                <?php if ($page['sidebar_first'] && $page['sidebar_second']): ?>
                  <div id="content" class="col-md-6">
                      <a id="main-content"></a>
                      <?php print render($title_prefix); ?>
                      <?php print render($title_suffix); ?>
                      <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
                      <?php print render($page['help']); ?>
                      <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
                      <?php print render($page['content']); ?>
                      <?php print $feed_icons; ?>
                  </div>
                <?php elseif ($page['sidebar_first'] || $page['sidebar_second']): ?>
                  <div id="content" class="col-md-9">
                      <a id="main-content"></a>
                      <?php print render($title_prefix); ?>
                      <?php print render($title_suffix); ?>
                      <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
                      <?php print render($page['help']); ?>
                      <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
                      <?php print render($page['content']); ?>
                      <?php print $feed_icons; ?>
                  </div>
                <?php else: ?>
                  <div id="content">
                      <a id="main-content"></a>
                      <?php print render($title_prefix); ?>
                      <?php print render($title_suffix); ?>
                      <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
                      <?php print render($page['help']); ?>
                      <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
                      <?php print render($page['content']); ?>
                      <?php print $feed_icons; ?>
                  </div>
                <?php endif; ?>

                <?php if ($page['sidebar_second']): ?>
                  <div id="sidebar-second" class="col-md-3 sidebar">
                      <?php print render($page['sidebar_second']); ?>
                  </div>
                <?php endif; ?>
            </div>
        </div>

    </div>

<footer class="footer clearfix">
        <div class="footer-wrapper">
            <div class="footer-widgets">
                <div class="container">
                    <div class="row">
                        <?php if ($page['footer_first']): ?>
                          <div class="<?php print $footer_setting_region_1;?>">
                              <?php print render($page['footer_first']); ?>
                          </div>
                        <?php endif; ?>

                        <?php if ($page['footer_second'] & $select_collum_footer != '4' ): ?>
                          <div class="<?php print $footer_setting_region_2;?>">
                              <?php print render($page['footer_second']); ?>
                          </div>
                        <?php endif; ?>

                        <?php if ($page['footer_third'] & $select_collum_footer != '4' & $select_collum_footer !='3' ): ?>
                          <div class="<?php print $footer_setting_region_3;?>">
                              <?php print render($page['footer_third']); ?>
                          </div>
                        <?php endif; ?>

                        <?php if ($page['footer_fourth'] & $select_collum_footer != '4' & $select_collum_footer !='3' & $select_collum_footer != '2'  ): ?>
                          <div class="<?php print $footer_setting_region_4;?>">
                              <?php print render($page['footer_fourth']); ?>
                          </div>
                        <?php endif; ?>
                    </div>
                </div>
            </div>
            <?php if ($page['footer_bottom']): ?>
              <div class="footer-copyright">
                <div class="container">
                  <?php print render($page['footer_bottom']); ?>
                </div>
              </div>
            <?php endif;?>
            <?php print render($page['footer']); ?>
        </div>
        <a href="#" class="back-top" title="">
                <span class="back-top-image">
                    <img src="<?php print $base_url.'/'.drupal_get_path('theme', 'md_hosoren');?>/images/back-top.png" alt="">
                </span>

                <small><?php print t('Back to top'); ?></small>
            </a>
    </footer>

</div>
