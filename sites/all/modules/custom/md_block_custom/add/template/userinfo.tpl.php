<?php
/*
 * @Megadrupal
 * @Thanhhust
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
global $base_url;
  ctools_include('modal');
  ctools_include('ajax');
  ctools_modal_add_js();
  ctools_add_js('modal_forms_pop', 'md_block_custom');
if (function_exists('ctools_modal_text_button')) {
  $login_pop = ctools_modal_text_button(t('Login'), 'user-form/nojs/login', t('Login'), 'mycoolmodulemodal login-link');
  $register_pop = ctools_modal_text_button(t('Register'), 'user-form/nojs/register', t('Register'), 'mycoolmodulemodal register-link');
}else{
  $login_pop= l(t('Login'), $base_url . '/user/login/', array('attributes' => array('class' => 'login-link'))) ;
  $register_pop = l(t('Register'), $base_url . '/user/register/', array('attributes' => array('class' => 'register-link'))) ;
};
if ($logged_in):
  $user_id = $variables['user']->uid;
  $user = user_load($user_id);
  $user_url = $base_url . '/user/' . $user->uid;
  $user_image_alt = isset($user->picture) ? $user->picture->alt : '';
  ?>
  <div class="container-fluid">
      <div class="header-account">
          <div class="header-account-avatar">
              <a href="<?php print $user_url; ?>" title="">
                <?php
                if ($user->picture) {
                  $picture_path = $user->picture->uri;
                  print $user_picture = theme_image_style(
                      array(
                        'style_name' => 'avatar_thumb',
                        'path' => $picture_path,
                        'attributes' => array(
                          'class' => 'img-circle user-avatar',
                          'alt' => $user_image_alt,
                        ),
                        'width' => 62,
                        'height' => 62,
                      )
                  );
                }
                else {
                  echo '<img src="' . $base_url . '/' . drupal_get_path('module', 'md_block_custom') . '/add/img/user_not_verified.png" class="img-circle user-avatar" style="width:62px"/>';
                };
                ?>
              </a>
          </div>
          <div class="header-account-username">
              <h4><a href="<?php print $user_url; ?>"><?php print ucfirst($user->name); ?></a></h4>
          </div>
          <ul>
              <li><?php print l(t('Account Infomation'), $base_url . '/user/', array('attributes' => array('class' => 'logout-link')));?></li>
              <li><?php print l(t('Logout'), $base_url . '/user/logout', array('attributes' => array('class' => 'logout-link')));?></li>
          </ul>
      </div>
  </div>
<?php else: ?>
<ul class="submenu dropdown not-logged-box">
    <li><?php print $login_pop;?></li>
    <li><?php print $register_pop;?></li>
</ul>
<?php endif; ?>
