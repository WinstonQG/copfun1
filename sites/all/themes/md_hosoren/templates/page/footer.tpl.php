<?php global $base_url; ?>
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

                  <?php if ($page['footer_second'] & $colum_number != '4' ): ?>
                    <div class="<?php print $footer_setting_region_2;?>">
                        <?php print render($page['footer_second']); ?>
                    </div>
                  <?php endif; ?>

                  <?php if ($page['footer_third'] & $colum_number != '4' & $colum_number !='3' ): ?>
                    <div class="<?php print $footer_setting_region_3;?>">
                        <?php print render($page['footer_third']); ?>
                    </div>
                  <?php endif; ?>

                  <?php if ($page['footer_fourth'] & $colum_number != '4' & $colum_number !='3' & $colum_number != '2'  ): ?>
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