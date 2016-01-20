<?php
/**
 * @file
 * Theme setting callbacks for the md_hosoren theme.
 */
global $base_url;
define('THEME_PATH', drupal_get_path('theme', 'md_hosoren'));
define('CURRENT_THEME', variable_get('theme_default'));
define('BASE_THEME', 'md_hosoren');

require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_hosoren') . '/theme_setting/admin/utilities.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_hosoren') . '/theme_setting/admin/theme-settings-general.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_hosoren') . '/theme_setting/admin/theme-settings-design.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_hosoren') . '/theme_setting/admin/theme-settings-text.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_hosoren') . '/theme_setting/admin/theme-settings-pages.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_hosoren') . '/theme_setting/admin/theme-settings-code.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_hosoren') . '/theme_setting/admin/theme-settings-config.inc';

/**
 * Implements hook_form_FORM_ID_alter().
 * @param $form
 * @param $form_state
 * @param null $form_id
 * @param bool $no_js_use
 */

function md_hosoren_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL, $no_js_use = FALSE) {
  global $base_url;
  $path = drupal_get_path('theme', 'md_hosoren');

  // Attach library, js , and css to form.

  //Add libraries
  $form['#attached']['library'] = array(
    array('system', 'jquery.cookie'),
    array('system', 'ui.widget'),
    array('system', 'ui.mouse'),
    array('system', 'ui.slider'),
    array('system', 'ui.tabs'),
    array('system', 'ui.dialog'),
    array('system', 'ui.draggable'),
    array('system', 'ui.sortable'),
    array('system', 'ui.slider'),
    array('system', 'ui.accordion'),
    array('system', 'ui.datepicker'),
    array('media', 'media_browser'),
    array('media', 'media_browser_settings'),
  );

  //Add js
  $form['#attached']['js'] = array(
    $path . '/theme_setting/admin/js/modernizr.custom.js',
    $path . '/theme_setting/admin/js/jquery-migrate.min.js',
    $path . '/theme_setting/admin/js/spectrum.js',
    $path . '/theme_setting/admin/js/bootstrap-dialog.js',
    $path . '/theme_setting/admin/js/jquery.choosefont.js',
    $path . '/theme_setting/admin/js/jquery.mCustomScrollbar.js',
    $path . '/theme_setting/admin/js/jquery.mousewheel.js',
    $path . '/theme_setting/admin/js/addmore.js',
    $path . '/theme_setting/admin/js/media-settings.js',
    $path . '/theme_setting/admin/js/page-settings.js',
    $path . '/theme_setting/admin/js/script.js',
  );

  // Add js settings
  $media_settings = array(
    'wysiwyg_allowed_attributes' => variable_get('media__wysiwyg_allowed_attributes', array(
      'height',
      'width',
      'hspace',
      'vspace',
      'border',
      'align',
      'style',
      'class',
      'id',
      'usemap',
      'data-picture-group',
      'data-picture-align'
    ))
  );
  $fonts = theme_load_font_configure();
  $js_settings = array(
    'themeDir' => $base_url . '/' . THEME_PATH,
    'baseUrl' => $base_url,
    'media' => $media_settings,
    'font_array' => $fonts[0],
    'font_vars' => $fonts[1]
  );
  $form['#attached']['js'][] = array(
    'data' => $js_settings,
    'type' => 'setting',
  );

  //Add css
  $form['#attached']['css'] = array(
    $path . '/theme_setting/admin/css/font-awesome.css',
    $path . '/theme_setting/admin/css/style-frame.css',
    $path . '/theme_setting/admin/css/style-drupal.css',
    $path . '/theme_setting/admin/css/spectrum.css',
    $path . '/theme_setting/admin/css/bootstrap-dialog.css',
    $path . '/theme_setting/admin/css/jquery.mCustomScrollbar.css',
    $path . '/theme_setting/admin/css/jquery.mCustomScrollbar.css',
    $path . '/theme_setting/admin/css/jquery-ui-1.10.4.css',
    $path . '/theme_setting/admin/css/jquery-ui-timepicker-addon.css',
  );
  if (isset($form_id)) {
    return;
  }
  // Need to hide default theme settings in system, we create it after
  unset($form['theme_settings']);
  hide($form['logo']);
  hide($form['favicon']);
  // Make default dialog markup for icon

  $form['md_hosoren_settings']['html_header'] = array(
    '#markup' => '<div id="md-framewp" class="md-framewp">
    <div id="md-framewp-header">
        <!-- /////////////////// ALERT BOX ///////////////// -->
        <div class="md-alert-boxs">
        </div>
      </div><!-- /#md-framewp-header -->
    <div id="md-framewp-body">
    <div id="md-tabs-framewp" class="md-tabs-framewp">
        <ul class="clearfix">
            <li><a href="#md-general">General</a></li>
            <li><a href="#md-design">Design</a></li>
            <li><a href="#md-pages">Pages</a></li>
            <li><a href="#md-text-typography">Text & Typography</a></li>
            <li><a href="#md-code">Custom Code</a></li>
            <li><a href="#md-config">Backup & Restore</a></li>
        </ul>
    </div><!-- /.md-tabs-framewp -->
    <div class="logo-right">
        <a href="http://megadrupal.com/forum">
            <img title="Visit our support forum" src="' . $base_url . '/' . THEME_PATH . '/theme_setting/admin/img/logo.png' . '" alt="Mega Drupal">
        </a>
    </div>
    <div class="md-content-framewp">',
    '#weight' => -99,
  );
  md_hosoren_theme_settings_general($form, $form_state);
  md_hosoren_theme_settings_design($form, $form_state);
  md_hosoren_theme_settings_pages($form, $form_state);
  md_hosoren_theme_settings_text($form, $form_state);
  md_hosoren_theme_settings_code($form, $form_state);
  md_hosoren_theme_settings_config($form, $form_state);


  $form['actions']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset Settings'),
    '#submit' => array('md_hosoren_reset_settings_submit'),
    '#weight' => 98,
    '#attributes' => array(
      'class' => array('btn btn-reset'),
      'onClick' => 'return confirm("Are you sure want to reset all settings to default ?")'
    )
  );
  $form['actions']['submit']['#weight'] = 97;
  $form['actions']['submit']['#attributes'] = array(
    'class' => array('btn btn-save'),
  );
	$form['#submit'][] = '_md_theme_submit';
  $form['actions']['#prefix'] = '</div><!-- /.md-content-framewp -->
                                    </div><!-- /#md-framewp-body -->
                                    <div id="md-framewp-footer" class="md-framewp-footer">
                                    <div class="footer-left">
                                    <div class="md-button-group">';
  $form['actions']['#suffix'] = '</div>
                                    </div>
                                    <div class="footer-right">
                                    <p class="md-copyright">Designed and Developed by <a href="http://megadrupal.com">Megadrupal</a></p>
                                    </div>
                                    </div>
                                    </div><!-- /.md-framewp -->';
  // Get all themes.
  $themes = list_themes();
  $active_theme = $GLOBALS['theme_key'];
  $form_state['build_info']['files'][$active_theme] = str_replace("/$active_theme.info", '', $themes[$active_theme]->filename) . '/theme-settings.php';
}

function _md_theme_submit($form, &$form_state) {
  $logo_fid = $form_state['values']['logo_normal'];
  if ($file = file_load($logo_fid)) {
    $form_state['values']['logo_path'] = $file->uri;
  }
}
/**
 * @param $form
 * @param $form_state
 * Reset all theme settings
 */
function md_hosoren_reset_settings_submit($form, &$form_state) {
  $theme_settings = variable_get('theme_' . variable_get('theme_default') . '_settings');
  $default_settings = _md_hosoren_theme_default_settings($theme_settings);
  variable_set('theme_' . variable_get('theme_default') . '_settings', NULL);
  variable_set('theme_' . variable_get('theme_default') . '_settings', $default_settings);
  drupal_set_message('All settings reset to default');
  cache_clear_all();
}



/**
 * Restore Theme settings
 */
function md_hosoren_restore_theme_settings($form, &$form_state) {
  $values = $form_state['values'];
  $theme = variable_get('theme_default');
  if ($values['restore_type'] != NULL) {
    if ($values['restore_type'] == 'upload') {
      if ($form_state['values']['restore_file_media_upload'] != NULL) {
        $data_decode = drupal_json_decode($form_state['values']['restore_file_media_upload']);
        $file = file_load($data_decode['fid']);
        if (!$file) {
          drupal_set_message(t("Your file upload isn't correct, please upload again"), 'error');
          return;
        }
        $file_content = file_get_contents($file->uri);
        $restore_settings = drupal_json_decode(base64_decode(unserialize($file_content)));
        if (is_array($restore_settings)) {
          variable_set('theme_' . $theme . '_settings', array());
          variable_set('theme_' . $theme . '_settings', $restore_settings);
          file_delete($file, $force = TRUE);
          cache_clear_all();
          drupal_set_message(t('All your theme settings have been restored'));
        }
        else {
          drupal_set_message(t("Your file upload isn't correct, please upload again"), 'warning');
          return;
        }
      }
      else {
        drupal_set_message(t('Please choose your file upload'), 'error');
        return;
      }
    }
    else {
      if ($values['restore_from_file'] == NULL) {
        drupal_set_message('Choose your backup file in list or move back up to backup folder', 'warning');
        return;
      }
      else {
        $file_content = file_get_contents("public://" . variable_get('theme_default') . "_backup/{$values['restore_from_file']}");
        $restore_settings = drupal_json_decode(base64_decode(unserialize($file_content)));
        if (is_array($restore_settings)) {
          variable_set('theme_' . $theme . '_settings', array());
          variable_set('theme_' . $theme . '_settings', $restore_settings);
          cache_clear_all();
          drupal_set_message(t('All your theme settings have been restored'));
        }
        else {
          drupal_set_message(t("Your choosen backup file isn't correct, please choose again"), 'warning');
          return;
        }
      }
    }
  }


  if ($restore_file = file_save_upload('restore_file_simple_upload')) {
    $file_content = file_get_contents($restore_file->uri);
    $restore_settings = drupal_json_decode(base64_decode(unserialize($file_content)));
    variable_set('theme_' . $theme . '_settings', $restore_settings);
    cache_clear_all();
    drupal_set_message(t('All your theme settings have been restored'));
  }
  if (isset($form_state['values']['restore_file_media_upload'])) {

  }

}

/**
 * Default theme settings
 */
function _md_hosoren_theme_default_settings($theme_settings) {
  $default_settings = array();
  foreach ($theme_settings as $key => $setting) {
    $default_settings[$key] = NULL;
  }
  $default_settings['toggle_logo'] = 0;
  $default_settings['toggle_name'] = 0;
  $default_settings['toggle_slogan'] = 0;
  $default_settings['toggle_node_user_picture'] = 1;
  $default_settings['toggle_comment_user_picture'] = 1;
  $default_settings['toggle_comment_user_verification'] = 1;
  $default_settings['toggle_favicon'] = 1;
  $default_settings['toggle_fvicon'] = 1;
  $default_settings['toggle_main_menu'] = 0;
  $default_settings['toggle_secondary_menu'] = 0;
  $default_settings['default_logo'] = 1;
  $default_settings['default_favicon'] = 1;
  $default_settings['css3_textarea'] = 0;
  $default_settings['webclip_precomp'] = 1;

  $default_settings['skin_color'] = 'none';
  $default_settings['preload'] = 0;
  $default_settings['header_type'] = 'one';
  $default_settings['header_fixed'] = 0;

  $default_settings['blog_single_type'] = 'nobar';
  $default_settings['blog_taxonomy_option'] = 'nobar';
  $default_settings['blog_list_option'] = 'nobar';

  $default_settings['footer_region_1'] = 'col4';
  $default_settings['footer_region_2'] = 'col2';
  $default_settings['footer_region_3'] = 'col2';
  $default_settings['footer_region_4'] = 'col4';	
	
	$default_settings['title_data'] = '';

  $default_settings['maintenance_title'] = 'Lauching Soon';
  $default_settings['maintenance_description'] = 'Have no fear, we are lauching soon. We just have to do it and cross it';
  $default_settings['maintenance_time'] = '2018/08/24';
  

  $default_settings['maintenance_title'] = 'Under Construction';
  $default_settings['maintenance_description'] = 'We will be back in:';
  $default_settings['maintenance_time'] = 'May 12, 2016 09:03:25';
  
  $default_settings['not_found_title'] = 'Oops... Page Not Found!';
  $default_settings['not_found_body'] = 'We\'re sorry, but the page you were looking for doesn\'t exist. You can try to search bellow';
  $default_settings['contact_decs'] = 'Uniquely negotiate equity invested systems and high standards in applications. Energistically maintain proactive manufactured products for client-centered users.';
  $default_settings['address_info'] = 'icon fontello icon-phone,||,font_icon|icon-phone,||,,||,+1 (415) 521-8775-123,||';
  return $default_settings;
}



