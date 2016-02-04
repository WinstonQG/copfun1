<?php
/**
 * @file
 * MD MegaMenu configuration filesource
 * @author Duy Nguyen
 */

/**
 * Implements create admin form for megamenu
 */
function md_megamenu_overview_page($mid = NULL) {
  if ($mid != NULL) {
    $results = array(MDMegaMenu::getById($mid));
    drupal_set_title(t('MD Megamenu: ' . $results[0]->title));
  }
  else {
    $results = MDMegaMenu::getAll();
  }

  $header = array(
    t('Title'),
    array('data' => t('Operations'), 'colspan' => '3')
  );
  $rows = array();
  foreach ($results as $menu) {
    $row = array(
      theme('md_megamenu_admin_overview', array(
        'title' => $menu->title,
        'description' => $menu->description
      ))
    );
    $row[] = array('data' => l(t('Configure'), 'admin/structure/md-megamenu/' . $menu->mid . '/configure'));
    $row[] = array('data' => l(t('Edit'), 'admin/structure/md-megamenu/' . $menu->mid . '/edit'));
    if (user_access('delete md_megamenu')) {
      $row[] = array('data' => l(t('Clone'), 'admin/structure/md-megamenu/' . $menu->mid . '/clone', array('query' => drupal_get_destination())));
    }
    $rows[] = $row;
  }

  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Implements create form edit megamenu or create new menu
 */
function md_megamenu_configure_form($form, &$form_state, $menu_ids = NULL) {
  $form = array();
  $settings = MDMegaMenu::getDefaultSettings();
  $module_path = drupal_get_path('module', 'md_megamenu');
  drupal_add_css($module_path . '/css/mega_menu.css');
  drupal_add_css($module_path . '/js/colorpicker/css/colorpicker.css');

  drupal_add_library('system', 'ui.tabs');
  drupal_add_library('system', 'jquery.cookie');
  drupal_add_js($module_path . '/js/colorpicker/js/colorpicker.js');
  drupal_add_js($module_path . '/js/jquery.choosefont.js');
  drupal_add_js($module_path . '/js/md.menu-settings.js');

  drupal_set_title(t('Create new megamenu'));

  $menu = NULL;
  if (!is_null($menu_ids) && count($menu_ids) > 0) {
    $menu = MDMegaMenu::getById($menu_ids[0]);
    if ($menu) {
      $settings = $menu->settings;
    }
    drupal_set_title(t('MD Megamenu Configure: ' . $menu->title));
  }

  $form['menu_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Menu name'),
    '#description' => t('The human readable name of menu.'),
    '#required' => TRUE,
    '#default_value' => ($menu) ? $menu->title : "",
  );

  $form['machine_name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine name'),
    '#default_value' => ($menu) ? $menu->machine_name : "",
    '#maxlength' => MENU_MAX_MENU_NAME_LENGTH_UI,
    '#description' => t('A unique name to construct the URL for the menu. It must only contain lowercase letters, numbers and hyphens.'),
    '#machine_name' => array(
      'exists' => 'md_megamenu_check_machine_name',
      'source' => array('menu_title'),
      'replace_pattern' => '[^a-z0-9-]+',
      'replace' => '-',
    ),
    '#disabled' => (($menu) && $menu->machine_name != ''),
  );

  $form['menu_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#description' => t('Short description for this menu and use only for admin.'),
    '#rows' => 2,
    '#resizable' => FALSE,
    '#default_value' => ($menu) ? $menu->description : "",
  );

  $form['menu_id_editted'] = array(
    '#type' => 'hidden',
    '#value' => ($menu) ? $menu->mid : 0,
  );

  $form['settings_header'] = array(
    '#markup' => '<div id="megamenu-settings" class="megamenu-settings clearfix">
      <div class="md-listleft">
      <ul class="clearfix">
      <li class="subtab-item clearfix first"><a class="subtab-link" href="#edit-general-settings">General</a></li>
      <li class="subtab-item clearfix"><a class="subtab-link" href="#edit-style-settings">Design</a></li>
      <li class="subtab-item clearfix "><a class="subtab-link" href="#edit-font-settings">Text &amp; Typography</a></li>
      <li class="subtab-item clearfix last"><a class="subtab-link" href="#edit-responsive-settings">Responsive setting</a></li>
      </ul>
      </div>
      <div class="md-listcontent">',
  );

  # General settings
  $form['general_settings'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('md-tabcontent', 'clearfix'),),
  );

  $form['general_settings']['dm_left'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('dmg-left')),
  );

  $form['general_settings']['dm_left']['menu_type'] = array(
    '#type' => 'select',
    '#title' => t('Menu type'),
    '#description' => t('Type of menu in desktop mode.'),
    '#options' => array(
      'standard' => t('Standard'),
      'top' => t('Fixed Top'),
      'bottom' => t('Fixed Bottom'),
      'left' => t('Left'),
      'outleft' => t('OutLeft'),
      'right' => t('Right'),
      'outright' => t('OutRight')
    ),
    '#default_value' => isset($settings['menu_type']) ? $settings['menu_type'] : 'standard'
  );

  $form['general_settings']['dm_left']['menu_desktop_trigger'] = array(
    '#type' => 'select',
    '#title' => t('Menu trigger'),
    '#description' => t('Mouse event to show submenu in desktop mode.'),
    '#options' => array(
      'hover' => t('Hover'),
      'click' => t('Click'),
      'toggle' => t('Toggle')
    ),
    '#default_value' => isset($settings['menu_desktop_trigger']) ? $settings['menu_desktop_trigger'] : 'hover'
  );

  $form['general_settings']['dm_left']['menu_animation'] = array(
    '#type' => 'select',
    '#title' => t('Animation'),
    '#options' => array(
        'fade' => t('Fade'),
        'fadeup' => t('Fade Up'),
        'fadedown' => t('Fade Down'),
        'fadeleft' => t('Fade Left'),
        'faderight' => t('Fade Right'),
        'zoom' => t('Zoom'),
        'rotateupleft' => t('Rotate Left'),
        'flipx' => t('FlipX'),
        'flipy' => t('flipY'),
        'flipyright' => t('Flipy Right'),
        'slideleft' => t('Slide Left'),
        'slideright' => t('Slide Right'),
        'none' => t('None')
    ),
    '#default_value' => isset($settings['menu_animation']) ? $settings['menu_animation'] : 'fadeup',
  );

  $form['general_settings']['dm_left']['default_animation_duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Animation duration'),
    '#description' => t('Time by milisecond to play animtion when opem/close submenu'),
    '#default_value' => isset($settings['default_animation_duration']) ? $settings['default_animation_duration'] :500,
    '#field_suffix' => 'ms',
    '#attributes' => array('class' => array('w60'))
  );

  $form['general_settings']['dm_left']['menu_sticky'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable sticky'),
    '#default_value' => isset($settings['menu_sticky']) ? $settings['menu_sticky'] : 0
  );

  $form['general_settings']['dm_left']['dmg_fullwidth'] = array(
    '#type' => 'checkbox',
    '#title' => t('Menu full width'),
    '#default_value' => $settings['general']['dmg_fullwidth'],
  );

  $form['general_settings']['dm_left']['dmg_customwidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Menu width'),
    '#default_value' => $settings['general']['dmg_customwidth'],
    '#field_suffix' => 'px',
    '#attributes' => array('class' => array('w60')),
  );

  $form['general_settings']['dm_left']['dmg_defaultheight'] = array(
    '#type' => 'checkbox',
    '#title' => 'Custom menu height',
    '#default_value' => $settings['general']['dmg_defaultheight'],
  );

  $form['general_settings']['dm_left']['dmg_customheight'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom height'),
    '#default_value' => $settings['general']['dmg_customheight'],
    '#field_suffix' => 'px',
    '#attributes' => array('class' => array('w60')),
  );

  $form['general_settings']['dm_left']['hover_delay'] = array(
    '#type' => 'textfield',
    '#title' => t('Hover active time'),
    '#description' => t('Time by milisecond to show when mouse enter menu item'),
    '#default_value' => isset($settings['hover_delay']) ? $settings['hover_delay'] :500,
    '#field_suffix' => 'ms',
    '#attributes' => array('class' => array('w60'))
  );

  $form['general_settings']['dm_right'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Others settings'),
    '#options' => array(
      'dmg_arrow' => t('Enable item arrow'),
      'dmg_cssclasses' => t('Custom css classes'),
      'dmg_menuicon' => t('Use menu icon'),
      'dmg_menuitemicon' => t('Use menu item icon'),
      'dmg_enable_logo' => t('Use system logo'),
      'dmg_enabled_load_transition' => t('Enable load transition'),
    ),
    '#default_value' => $settings['general']['dm_right'],
  );

  # Resposive setting
  $form['responsive_settings'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('md-tabcontent', 'clearfix')),
  );

  $form['responsive_settings']['res_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Responsive width'),
    '#description' => t('When window width equal value below menu is responsive'),
    '#default_value' => isset($settings['responsive']['res_width']) ? $settings['responsive']['res_width'] : 640,
    '#field_suffix' => 'px',
    '#attributes' => array('class' => array('w60'))
  );

  $form['responsive_settings']['mobile_menu_type'] = array(
    '#type' => 'select',
    '#title' => t('Menu type'),
    '#description' => t('Type of menu in mobile display mode.'),
    '#options' => array(
      'standard' => t('Standard'),
      'top' => t('Top'),
      'bottom' => t('Bottom'),
      'outleft' => t('OutLeft'),
      'outright' => t('OutRight')
    ),
    '#default_value' => (isset($settings['responsive']['mobile_menu_type'])) ? $settings['responsive']['mobile_menu_type'] : 'standard'
  );

  $form['responsive_settings']['mobile_trigger'] = array(
    '#type' => 'select',
    '#title' => t('Responsive trigger'),
    '#options' => array(
      'click' => t('Click'),
      'toggle' => t('Toggle')
    ),
    '#description' => t('Mouse event to active submenu when menu in mobile display mode.'),
    '#default_value' => (isset($settings['responsive']['mobile_trigger'])) ? $settings['responsive']['mobile_trigger'] : 'click'
  );

  $form['responsive_settings']['mobile_animation_duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Animation duration'),
    '#description' => t('Time by milisecond to show/hide submenu.'),
    '#default_value' => isset($settings['responsive']['mobile_animation_duration']) ? $settings['responsive']['mobile_animation_duration'] : 300,
    '#field_suffix' => 'ms',
    '#attributes' => array('class' => array('w60'))
  );

  $form['responsive_settings']['mobile_arrow'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show item arrow'),
    '#default_value' => isset($settings['responsive']['mobile_arrow']) ? $settings['responsive']['mobile_arrow'] : 1
  );

  $form['responsive_settings']['res_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter text show when menu responsive'),
    '#description' => t("When responsive value below will show"),
    '#default_value' => isset($settings['responsive']['res_text']) ? $settings['responsive']['res_text'] : 'Menu',
  );
  $form['responsive_settings']['res_text_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Menu text color'),
    '#attributes' => array(
      'class' => array('form-colorpicker'),
    ),
    '#default_value' => isset($settings['responsive']['res_text_color']) ? $settings['responsive']['res_text_color'] : '',
  );
  $form['responsive_settings']['res_bar_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Menu bar color'),
    '#attributes' => array(
      'class' => array('form-colorpicker'),
    ),
    '#default_value' => isset($settings['responsive']['res_bar_color']) ? $settings['responsive']['res_bar_color'] : '',
  );

  # Design settings
  $form['style_settings'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('md-tabcontent', 'clearfix'))
  );

  $form['style_settings']['dms_predefine'] = array(
    '#type' => 'select',
    '#title' => t('Predefined styles'),
    '#options' => array(
      'style1' => t('Style 1'),
      'style2' => t('Style 2'),
      'style3' => t('Style 3'),
      'style4' => t('Style 4'),
      'custom' => t('Custom style'),
    ),
    '#default_value' => $settings['design']['dms_predefine'],
    '#description' => t('@1. <div class="md-guide-custom-style"><p>@2</p><ul><li>@3</li><li>@4</li><li>@5</li><li>@6</li></ul></div>', array(
      '@1' => 'Choose style for your megamenu',
      '@2' => 'CSS file name suggest:',
      '@3' => 'your_default_theme/css/md-megamenu-machine_name.css',
      '@4' => 'your_default_theme/css/md-megamenu.css',
      '@5' => 'sites/all/libraries/megadrupal/megamenu/md-megamenu-machine_name.css',
      '@6' => 'sites/all/libraries/megadrupal/megamenu/md-megamenu.css',
    )),
  );

  $form['style_settings']['dms_custom'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom CSS'),
    '#resizable' => FALSE,
    '#default_value' => $settings['design']['dms_custom'],
  );


  $form['style_settings']['dms_style_header'] = array(
    '#markup' => '<div id="dms-subtabs" class="md-subtabs">
      <div class="md-subtabs-head">
      <ul class="clearfix">
      <li class="subtab-item clearfix first"><a class="subtab-link" href="#edit-style-top-level">Top level</a></li>
      <li class="subtab-item clearfix"> <a class="subtab-link" href="#edit-style-sub-level">Sub level</a> </li>
      <li class="subtab-item clearfix"> <a class="subtab-link" href="#edit-style-hoveritem-level">Hover mega item</a> </li>
      </ul>
      </div>',
  );

  # Design: Custom top level
  $form['style_settings']['style_top_level'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('md-subtabcontent', 'clearfix'))
  );
  md_megamenu_prepare_design_level_style($form, 'top', $settings['design']);

  # Design: Custom sub level
  $form['style_settings']['style_sub_level'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('md-subtabcontent', 'clearfix'))
  );

  md_megamenu_prepare_design_level_style($form, 'sub', $settings['design']);

  # Design: Custom hover mega item
  $form['style_settings']['style_hoveritem_level'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('md-subtabcontent', 'clearfix'))
  );

  md_megamenu_prepare_design_level_style($form, 'hoveritem', $settings['design']);

  $form['style_settings']['dms_style_footer'] = array(
    '#markup' => '</div>',
  );

  # Text/Typography settings
  $form['font_settings'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('md-tabcontent', 'clearfix')),
  );

  $form['font_settings']['dmf_ucf'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use custom font'),
    '#description' => t('Check this if you want to use font from Google Webfonts or Typekit'),
    '#default_value' => $settings['text_typography']['dmf_ucf'],
  );

  $form['font_settings']['dmf_google'] = array(
    '#type' => 'textarea',
    '#title' => t('@import'),
    '#resizable' => FALSE,
    '#rows' => 1,
    '#description' => t("For example: &lt;link href='<strong>http://fonts.googleapis.com/css?family=Roboto+Condensed</strong>' rel='stylesheet' type='text/css'&gt"),
    '#default_value' => $settings['text_typography']['dmf_google'],
    '#prefix' => '<div id="customfont-wrap" class="form-subform"><h3>Google Web Fonts</h3>
      <ul class="steps">
      <li>Go to <a href="http://www.google.com/webfonts" target="_blank">www.google.com/webfonts</a>, choose your fonts and add to collection</li>
      <li>Click &quot;Use&quot; in the bottom bar after choose fonts</li>
      <li>Find &quot;Add this code to your website&quot;, copy from <strong>http://</strong> to the nearest <strong>\'</strong> and paste it below to activate.</li>
      </ul>',
  );

  $form['font_settings']['dmf_typekit'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter Your Typekit ID'),
    '#description' => t('<strong>* Note:</strong> Your kit must contain fonts and be published before entering your Typekit ID below. Check out <a href="http://help.typekit.com/customer/portal/articles/6780-adding-fonts-to-your-site" target="_blank">this article at Typekit\'s Help Center</a> for detailed information on how to add fonts to your kit. (Make sure you skip the part about adding CSS selectors, and remember to republish your kit after making any changes.)'),
    '#default_value' => $settings['text_typography']['dmf_typekit'],
    '#prefix' => '<h3>Typekit</h3>
      <ul class="steps">
      <li>Go to <a href="http://typekit.com/" target="_blank">www.typekit.com</a> and Log in to your account</li>
      <li>In the top bar of the Typekit website, click the green &quot;Launch Kit Editor&quot; button.</li>
      <li>In the top bar of the popup that appears, click the &quot;Kit Settings&quot; link and paste your domain. Once you\'ve done this, click &quot;Save Settings.&quot;</li>
      <li>In the same top bar of the popup, click the &quot;embed code&quot; link.</li>
      <li>In the overlay that appears, there is a line at the   bottom that says, &quot;If you are using a plugin or service that asks for a   Typekit ID, use this: ____.&quot; This is your Typekit ID. Paste it below to activate.</li>
      </ul>',
    '#suffix' => '</div>',
  );

  $form['font_settings']['dmf_font_header'] = array(
    '#markup' => '<div id="dmf-subtabs" class="md-subtabs">
      <div class="md-subtabs-head">
      <ul class="clearfix">
      <li class="subtab-item clearfix first"><a class="subtab-link" href="#edit-font-top-level">Top level</a></li>
      <li class="subtab-item clearfix"> <a class="subtab-link" href="#edit-font-sub-level">Sub level</a> </li>
      </ul>
      </div>',
  );

  #Font: top level
  $form['font_settings']['font_top_level'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('md-subtabcontent', 'clearfix'))
  );

  $form['font_settings']['font_top_level']['typo_top_level_html'] = array(
    '#markup' => '<h3>' . t('Font style') . '</h3>',
  );

  $form['font_settings']['font_top_level']['typo_top_level'] = array(
    '#type' => 'hidden',
    '#default_value' => $settings['text_typography']['typo_top_level'],
    '#prefix' => '<div id="typo-top-level" class="choosefont clearfix">',
    '#suffix' => '</div>',
  );

  $form['font_settings']['font_top_level']['link_style_text'] = array(
    '#markup' => '<h3>Link style</h3>',
  );

  $form['font_settings']['font_top_level']['link_style_header'] = array(
    '#markup' => '<div id="md-font-top-level-tabs" class="md-subtabs">
      <div class="md-subtabs-head">
      <ul class="clearfix">
      <li class="subtab-item clearfix first"> <a class="subtab-link" href="#link-regular">Regular</a> </li>
      <li class="subtab-item clearfix"> <a class="subtab-link" href="#link-rollover">Rollover</a> </li>
      <li class="subtab-item clearfix"> <a class="subtab-link" href="#link-visited">Visited</a> </li>
      <li class="subtab-item clearfix last"> <a class="subtab-link" href="#link-on">On</a> </li>
      </ul>
      </div>',
  );

  // Link regular
  $form['font_settings']['font_top_level']['link_regular'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => array('link-regular'),
      'class' => array('md-subtabcontent', 'clearfix')
    ),
  );

  md_megamenu_prepare_link_style($form, 'regular', 'top', $settings['text_typography']);

  // Link rollover
  $form['font_settings']['font_top_level']['link_rollover'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => array('link-rollover'),
      'class' => array('md-subtabcontent', 'clearfix')
    ),
  );

  md_megamenu_prepare_link_style($form, 'rollover', 'top', $settings['text_typography']);

  // Link visited
  $form['font_settings']['font_top_level']['link_visited'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => array('link-visited'),
      'class' => array('md-subtabcontent', 'clearfix')
    ),
  );

  md_megamenu_prepare_link_style($form, 'visited', 'top', $settings['text_typography']);

  // Link on
  $form['font_settings']['font_top_level']['link_on'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => array('link-on'),
      'class' => array('md-subtabcontent', 'clearfix')
    ),
  );

  md_megamenu_prepare_link_style($form, 'on', 'top', $settings['text_typography']);

  $form['font_settings']['font_top_level']['link_style_footer'] = array(
    '#markup' => '</div><!-- /#md-font-top-level-tabs -->',
  );

  # Font: sub level
  $form['font_settings']['font_sub_level'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('md-subtabcontent', 'clearfix'))
  );

  $form['font_settings']['font_sub_level']['link_style_text'] = array(
    '#markup' => '<h3>Link style</h3>',
  );

  $form['font_settings']['font_sub_level']['link_style_header'] = array(
    '#markup' => '<div id="md-font-sub-level-tabs" class="md-subtabs">
      <div class="md-subtabs-head">
      <ul class="clearfix">
      <li class="subtab-item clearfix first"> <a class="subtab-link" href="#link-regular">Regular</a> </li>
      <li class="subtab-item clearfix"> <a class="subtab-link" href="#link-rollover">Rollover</a> </li>
      <li class="subtab-item clearfix"> <a class="subtab-link" href="#link-visited">Visited</a> </li>
      <li class="subtab-item clearfix last"> <a class="subtab-link" href="#link-on">On</a> </li>
      </ul>
      </div>',
  );

  // Link regular
  $form['font_settings']['font_sub_level']['link_regular'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => array('link-regular'),
      'class' => array('md-subtabcontent', 'clearfix')
    ),
  );

  md_megamenu_prepare_link_style($form, 'regular', 'sub', $settings['text_typography']);

  // Link rollover
  $form['font_settings']['font_sub_level']['link_rollover'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => array('link-rollover'),
      'class' => array('md-subtabcontent', 'clearfix')
    ),
  );

  md_megamenu_prepare_link_style($form, 'rollover', 'sub', $settings['text_typography']);

  // Link visited
  $form['font_settings']['font_sub_level']['link_visited'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => array('link-visited'),
      'class' => array('md-subtabcontent', 'clearfix')
    ),
  );

  md_megamenu_prepare_link_style($form, 'visited', 'sub', $settings['text_typography']);

  // Link on
  $form['font_settings']['font_sub_level']['link_on'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => array('link-on'),
      'class' => array('md-subtabcontent', 'clearfix')
    ),
  );

  md_megamenu_prepare_link_style($form, 'on', 'sub', $settings['text_typography']);

  $form['font_settings']['font_sub_level']['link_style_footer'] = array(
    '#markup' => '</div><!-- /#md-font-sub-level-tabs -->',
  );

  // text sublevel
  $form['font_settings']['font_sub_level']['text_sub_level_html'] = array(
    '#markup' => '<h3>' . t('Text style') . '</h3>',
  );

  $form['font_settings']['font_sub_level']['text_sub_level'] = array(
    '#type' => 'hidden',
    '#default_value' => $settings['text_typography']['text_sub_level'],
    '#prefix' => '<div id="text-sub-level" class="choosefont clearfix">',
    '#suffix' => '</div>',
  );

  $form['font_settings']['font_sub_level']['text_sub_level_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Color'),
    '#default_value' => $settings['text_typography']['text_sub_level_color'],
    '#prefix' => '<div class="form-font-color">',
    '#suffix' => '</div>',
    '#attributes' => array('class' => array('form-colorpicker')),
  );

  // header (.mm-header)
  $form['font_settings']['font_sub_level']['header_sub_level_html'] = array(
    '#markup' => '<h3>' . t('Header style') . '</h3>',
  );

  $form['font_settings']['font_sub_level']['header_sub_level'] = array(
    '#type' => 'hidden',
    '#default_value' => $settings['text_typography']['header_sub_level'],
    '#prefix' => '<div id="header-sub-level" class="choosefont clearfix">',
    '#suffix' => '</div>',
  );

  $form['font_settings']['font_sub_level']['header_sub_level_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Color'),
    '#default_value' => $settings['text_typography']['header_sub_level_color'],
    '#prefix' => '<div class="form-font-color">',
    '#suffix' => '</div>',
    '#attributes' => array('class' => array('form-colorpicker')),
  );

  $i = 1;
  while ($i <= 6) {
    $form['font_settings']['font_sub_level']['h' . $i . '_sub_level_html'] = array(
      '#markup' => '<h3>' . t('Header ' . $i . ' style') . '</h3>',
    );

    $form['font_settings']['font_sub_level']['h' . $i . '_sub_level'] = array(
      '#type' => 'hidden',
      '#default_value' => $settings['text_typography']['h' . $i . '_sub_level'],
      '#prefix' => '<div id="h' . $i . '-sub-level" class="choosefont clearfix">',
      '#suffix' => '</div>',
    );

    $form['font_settings']['font_sub_level']['h' . $i . '_sub_level_color'] = array(
      '#type' => 'textfield',
      '#title' => t('Color'),
      '#default_value' => $settings['text_typography']['h' . $i . '_sub_level_color'],
      '#prefix' => '<div class="form-font-color">',
      '#suffix' => '</div>',
      '#attributes' => array('class' => array('form-colorpicker')),
    );

    $i++;
  }

  $form['font_settings']['dmf_font_footer'] = array(
    '#markup' => '</div>',
  );
  $form['settings_footer'] = array(
    '#markup' => '</div></div>',
  );



  $form['savedcolor1'] = array(
    '#type' => 'hidden',
    '#default_value' => $settings['savedcolor'],
    '#attributes' => array('id' => 'savedcolor1'),
  );

  $form['save_menu'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  if ($form['menu_id_editted']['#value'] > 0) {
    $form['save_edit_menu_'] = array(
      '#type' => 'submit',
      '#value' => t('Save & Edit'),
    );

    # Check user permission to show delete button
    if (user_access('delete md_megamenu')) {
      $form['delete_menu'] = array(
        '#type' => 'submit',
        '#value' => 'Delete',
      );
    }
  }

  // Load font styles
  $fonts = load_font_configure($settings);
  drupal_add_js(array('font_array' => $fonts[0]), 'setting');
  drupal_add_js(array('font_vars' => $fonts[1]), 'setting');
  // add for fonts END

  return $form;
}

function md_megamenu_prepare_design_level_style(&$form, $level, $settings = NULL) {
  if ($level == 'hoveritem') {
    $form['style_settings']['style_hoveritem_level']['hoveritem_dms_tc'] = array(
      '#type' => 'textfield',
      '#title' => t('Text color'),
      '#attributes' => array(
        'class' => array('form-colorpicker'),
      ),
      '#default_value' => $settings['hoveritem_dms_tc'],
    );
  }

  if ($level == 'top') {
    $form['style_settings']['style_top_level']['top_dms_descc'] = array(
      '#type' => 'textfield',
      '#title' => t('Description text color'),
      '#attributes' => array(
        'class' => array('form-colorpicker'),
      ),
      '#default_value' => $settings['top_dms_descc'],
    );
  }

  $form['style_settings']['style_' . $level . '_level'][$level . '_dms_bgc'] = array(
    '#type' => 'textfield',
    '#title' => t('Background color'),
    '#attributes' => array(
      'class' => array('form-colorpicker'),
    ),
    '#default_value' => $settings[$level . '_dms_bgc'],
  );

  if ($level == 'sub') {
    $form['style_settings']['style_sub_level']['sub_dms_dropshadow'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable dropshadow'),
      '#description' => t('Enable dropshadow for sub items'),
      '#default_value' => $settings['sub_dms_dropshadow'],
    );
  }

  $form['style_settings']['style_' . $level . '_level'][$level . '_border_radius_html'] = array(
    '#markup' => '<h3>' . t('Border radius') . '</h3>',
  );

  $form['style_settings']['style_' . $level . '_level'][$level . '_border_radius_equal'] = array(
    '#type' => 'checkbox',
    '#title' => t('Borders rounded equally'),
    '#description' => t('Check if your borders going to be rounded equally'),
    '#default_value' => $settings[$level . '_border_radius_equal'],
  );

  $form['style_settings']['style_' . $level . '_level'][$level . '_border_radius'] = array(
    '#type' => 'textfield',
    '#title' => t('Border Radius'),
    '#default_value' => $settings[$level . '_border_radius'],
    '#attributes' => array('class' => array('w60')),
    '#field_suffix' => 'px',
  );

  $form['style_settings']['style_' . $level . '_level'][$level . '_border_radius_tl'] = array(
    '#type' => 'textfield',
    '#title' => t('Top Left'),
    '#default_value' => $settings[$level . '_border_radius_tl'],
    '#prefix' => '<div id="' . $level . 'level-border-radius-not-equal">',
    '#attributes' => array('class' => array('w60')),
    '#field_suffix' => 'px',
  );

  $form['style_settings']['style_' . $level . '_level'][$level . '_border_radius_tr'] = array(
    '#type' => 'textfield',
    '#title' => t('Top Right'),
    '#default_value' => $settings[$level . '_border_radius_tr'],
    '#attributes' => array('class' => array('w60')),
    '#field_suffix' => 'px',
  );

  $form['style_settings']['style_' . $level . '_level'][$level . '_border_radius_br'] = array(
    '#type' => 'textfield',
    '#title' => t('Bottom Right'),
    '#default_value' => $settings[$level . '_border_radius_br'],
    '#attributes' => array('class' => array('w60')),
    '#field_suffix' => 'px',
  );

  $form['style_settings']['style_' . $level . '_level'][$level . '_border_radius_bl'] = array(
    '#type' => 'textfield',
    '#title' => t('Bottom Left'),
    '#default_value' => $settings[$level . '_border_radius_bl'],
    '#suffix' => '</div> <!-- #toplevel-border-radius-not-equal -->',
    '#attributes' => array('class' => array('w60')),
    '#field_suffix' => 'px',
  );

  $form['style_settings']['style_' . $level . '_level']['border_html'] = array(
    '#markup' => '<h3>' . t('Border') . '</h3>',
  );

  $form['style_settings']['style_' . $level . '_level'][$level . '_border_where'] = array(
    '#type' => 'checkboxes',
    '#options' => array(
      'top' => t('Top'),
      'right' => t('Right'),
      'bottom' => t('Bottom'),
      'left' => t('Left'),
    ),
    '#default_value' => $settings[$level . '_border_where'],
  );

  $form['style_settings']['style_' . $level . '_level'][$level . '_border_size'] = array(
    '#type' => 'textfield',
    '#title' => t('size'),
    '#default_value' => $settings[$level . '_border_size'],
    '#attributes' => array('class' => array('w60')),
    '#field_suffix' => 'px',
    '#prefix' => '<div class="border-style-wrap">',
  );

  $form['style_settings']['style_' . $level . '_level'][$level . '_border_type'] = array(
    '#type' => 'select',
    '#title' => t('type'),
    '#default_value' => $settings[$level . '_border_type'],
    '#options' => array(
      '0' => t('None'),
      'solid' => t('Solid'),
      'dashed' => t('Dashed'),
      'dotted' => t('Dotted'),
    ),
  );

  $form['style_settings']['style_' . $level . '_level'][$level . '_border_color'] = array(
    '#type' => 'textfield',
    '#title' => t('color'),
    '#attributes' => array(
      'class' => array('form-colorpicker'),
    ),
    '#default_value' => $settings[$level . '_border_color'],
    '#suffix' => '</div><!-- //.border-style-wrap -->',
  );

  if ($level != 'hoveritem') {
    $image_styles = image_style_options(FALSE);
    $img_style_title = array(
      'top' => t('Top level icon image style'),
      'sub' => t('Submenu icon image style')
    );
    $form['style_settings']['style_' . $level . '_level'][$level . '_dmi_img'] = array(
      '#type' => 'select',
      '#title' => $img_style_title[$level],
      '#empty_option' => t('Original image'),
      '#options' => $image_styles,
      '#default_value' => $settings[$level . '_dmi_img'],
      '#prefix' => '<div class="form-item-' . $level . '-img-wrap">',
      '#suffix' => t('You can') . ' ' . l(t('create new image style here'), 'admin/config/media/image-styles', array('attributes' => array('class' => 'dmi-new-imgstyle'))) . '</div>',
    );

  }
}

function md_megamenu_prepare_link_style(&$form, $state, $level, $settings = NULL) {
  $form['font_settings']['font_' . $level . '_level']['link_' . $state]['l_' . $level . '_' . $state . '_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Text color'),
    '#default_value' => $settings['l_' . $level . '_' . $state . '_color'],
    '#prefix' => '<div class="form-style-color">',
    '#suffix' => '</div>',
    '#attributes' => array(
      'class' => array(
        'form-colorpicker',
      ),
    ),
  );

  $form['font_settings']['font_' . $level . '_level']['link_' . $state]['l_' . $level . '_' . $state . '_st'] = array(
    '#type' => 'checkbox',
    '#title' => t('Strikethrough'),
    '#default_value' => $settings['l_' . $level . '_' . $state . '_st'],
    '#prefix' => '<div class="form-text-effect form-item clearfix"><label>' . t('Text Effect') . '</label><div class="form-strikethrough">',
    // Open div
    '#suffix' => '</div>',
  );

  $form['font_settings']['font_' . $level . '_level']['link_' . $state]['l_' . $level . '_' . $state . '_hl'] = array(
    '#type' => 'checkbox',
    '#title' => t('Highlight'),
    '#default_value' => $settings['l_' . $level . '_' . $state . '_hl'],
    '#prefix' => '<div class="form-highlight">',
    '#suffix' => '</div>',
  );

  $form['font_settings']['font_' . $level . '_level']['link_' . $state]['l_' . $level . '_' . $state . '_hlc'] = array(
    '#type' => 'textfield',
    '#default_value' => $settings['l_' . $level . '_' . $state . '_hlc'],
    '#prefix' => '<div class="form-style-color form-link-color">',
    '#suffix' => '</div></div><!-- / .form-text-effect .form-item -->',
    // Close div
    '#attributes' => array('class' => array('form-colorpicker')),
  );

  $form['font_settings']['font_' . $level . '_level']['link_' . $state]['l_' . $level . '_' . $state . '_ts'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Text Style'),
    '#default_value' => $settings['l_' . $level . '_' . $state . '_ts'],
    '#options' => drupal_map_assoc(array(
      t('bold'),
      t('italic'),
      t('underline')
    )),
    '#prefix' => '<div class="form-text-style clearfix">',
    '#suffix' => '</div>',
  );
}

function md_megamenu_configure_form_submit($form, &$form_state) {
  # Get custom settings in form
  $custom_settings = $form_state['values'];
  $action = 'updated.';

  if ($form_state['values']['op'] == t('Save') || $form_state['values']['op'] == t('Save & Edit')) {
    $settings = array();

    # Get general settings
    $general_settings = array();
    $general_settings['dmg_fullwidth'] = $custom_settings['dmg_fullwidth'];
    $general_settings['dmg_customwidth'] = $custom_settings['dmg_customwidth'];
    $general_settings['dmg_defaultheight'] = $custom_settings['dmg_defaultheight'];
    $general_settings['dmg_customheight'] = $custom_settings['dmg_customheight'];
    foreach ($custom_settings['dm_right'] as $value) {
      if (is_string($value)) {
        $general_settings['dm_right'][] = $value;
      }
    }
    $settings['general'] = array_merge(MDMegaMenu::getDefaultSettings('general'), $general_settings);

    # Get responsive settings
    $responsive_settings = array();
    $responsive_settings['res_width'] = $custom_settings['res_width'];
    $responsive_settings['mobile_arrow'] = $custom_settings['mobile_arrow'];
    $responsive_settings['mobile_trigger'] = $custom_settings['mobile_trigger'];
    $responsive_settings['mobile_animation_duration'] = $custom_settings['mobile_animation_duration'];
    $responsive_settings['mobile_menu_type'] = $custom_settings['mobile_menu_type'];
    $responsive_settings['res_text'] = $custom_settings['res_text'];
    $responsive_settings['res_text_color'] = $custom_settings['res_text_color'];
    $responsive_settings['res_bar_color'] = $custom_settings['res_bar_color'];
    $settings['responsive'] = array_merge(MDMegaMenu::getDefaultSettings('responsive'), $responsive_settings);

    # Get animation settings
    $settings['menu_animation'] = $custom_settings['menu_animation'];
    $settings['default_animation_duration'] = $custom_settings['default_animation_duration'];
    $settings['menu_desktop_trigger'] = $custom_settings['menu_desktop_trigger'];
    $settings['hover_delay'] = $custom_settings['hover_delay'];
    $settings['menu_type'] = $custom_settings['menu_type'];
    $settings['menu_sticky'] = $custom_settings['menu_sticky'];

    # Get images settings
    $design_settings = array();
    $design_settings['dms_predefine'] = $custom_settings['dms_predefine'];
    $design_settings['dms_custom'] = $custom_settings['dms_custom'];
    $design_settings['top_dms_descc'] = $custom_settings['top_dms_descc'];
    md_megamenu_get_design_style('top', $design_settings, $custom_settings);
    $design_settings['sub_dms_dropshadow'] = $custom_settings['sub_dms_dropshadow'];
    md_megamenu_get_design_style('sub', $design_settings, $custom_settings);
    $design_settings['hoveritem_dms_tc'] = $custom_settings['hoveritem_dms_tc'];
    md_megamenu_get_design_style('hoveritem', $design_settings, $custom_settings);

    $settings['design'] = array_merge(MDMegaMenu::getDefaultSettings('design'), $design_settings);

    # Get Text&Typography settings
    $text_settings['dmf_ucf'] = $custom_settings['dmf_ucf'];
    $text_settings['dmf_google'] = $custom_settings['dmf_google'];
    $text_settings['dmf_typekit'] = $custom_settings['dmf_typekit'];
    $text_settings['typo_top_level'] = $custom_settings['typo_top_level'];
    md_megamenu_get_link_style_by_level('top', $text_settings, $custom_settings);
    md_megamenu_get_link_style_by_level('sub', $text_settings, $custom_settings);
    $text_settings['text_sub_level'] = $custom_settings['text_sub_level'];
    $text_settings['text_sub_level_color'] = $custom_settings['text_sub_level_color'];
    $text_settings['header_sub_level'] = $custom_settings['header_sub_level'];
    $text_settings['header_sub_level_color'] = $custom_settings['header_sub_level_color'];

    $i = 1;
    while ($i <= 6) {
      $text_settings['h' . $i . '_sub_level'] = $custom_settings['h' . $i . '_sub_level'];
      $text_settings['h' . $i . '_sub_level_color'] = $custom_settings['h' . $i . '_sub_level_color'];
      $i++;
    }

    $settings['text_typography'] = array_merge(MDMegaMenu::getDefaultSettings('text_typography'), $text_settings);
    $settings['savedcolor'] = $custom_settings['savedcolor1'];

    if ($custom_settings['menu_id_editted'] == 0) {
      $menu = MDMegaMenu::create($custom_settings['menu_title'], $custom_settings['menu_description'], $custom_settings['machine_name'], $settings);

      $form_state['redirect'] = 'admin/structure/md-megamenu/' . $menu->mid . '/edit';
      $action = 'created.';
    }
    else {
      $menu = MDMegaMenu::getById($custom_settings['menu_id_editted']);
      $menu->settings = $settings;
      $menu->description = $form_state['values']['menu_description'];
      $menu->title = $form_state['values']['menu_title'];
      $menu->save();

      if ($form_state['values']['op'] == t('Save')) {
        $form_state['redirect'] = 'admin/structure/md-megamenu';
      }
      else {
        if (isset($_GET['destination'])) {
          $form_state['redirect'] = array(
            'admin/structure/md-megamenu/' . $menu->mid . '/edit',
            array('query' => drupal_get_destination())
          );
          unset($_GET['destination']);
        }
        else {
          $form_state['redirect'] = 'admin/structure/md-megamenu/' . $menu->mid . '/edit';
        }
      }
    }

    drupal_set_message(t('Megamenu <em>' . $menu->title . '</em>  has been ' . $action));
  }
  else {
    $form_state['redirect'] = 'admin/structure/md-megamenu/delete/confirm/' . $custom_settings['menu_id_editted'];
  }
}

function md_megamenu_get_design_style($level, &$settings, $custom_settings) {
  $settings[$level . '_dms_bgc'] = $custom_settings[$level . '_dms_bgc'];
  $settings[$level . '_border_radius_equal'] = $custom_settings[$level . '_border_radius_equal'];
  $settings[$level . '_border_radius'] = $custom_settings[$level . '_border_radius'];
  $settings[$level . '_border_radius_tl'] = $custom_settings[$level . '_border_radius_tl'];
  $settings[$level . '_border_radius_tr'] = $custom_settings[$level . '_border_radius_tr'];
  $settings[$level . '_border_radius_br'] = $custom_settings[$level . '_border_radius_br'];
  $settings[$level . '_border_radius_bl'] = $custom_settings[$level . '_border_radius_bl'];
  foreach ($custom_settings[$level . '_border_where'] as $value) {
    $settings[$level . '_border_where'][] = $value;
  }

  $settings[$level . '_border_size'] = $custom_settings[$level . '_border_size'];
  $settings[$level . '_border_type'] = $custom_settings[$level . '_border_type'];
  $settings[$level . '_border_color'] = $custom_settings[$level . '_border_color'];
  if ($level != 'hoveritem') {
    $settings[$level . '_dmi_img'] = $custom_settings[$level . '_dmi_img'];
  }
}

function md_megamenu_get_link_style($state, &$settings, $custom_settings) {
  $settings['l_' . $state . '_color'] = $custom_settings['l_' . $state . '_color'];
  $settings['l_' . $state . '_st'] = $custom_settings['l_' . $state . '_st'];
  $settings['l_' . $state . '_hl'] = $custom_settings['l_' . $state . '_hl'];
  $settings['l_' . $state . '_hlc'] = $custom_settings['l_' . $state . '_hlc'];

  foreach ($custom_settings['l_' . $state . '_ts'] as $value) {
    if (is_string($value)) {
      $settings['l_' . $state . '_ts'][] = $value;
    }
  }
}

function md_megamenu_get_link_style_by_level($level, &$settings, $custom_settings) {
  md_megamenu_get_link_style($level . '_regular', $settings, $custom_settings);
  md_megamenu_get_link_style($level . '_rollover', $settings, $custom_settings);
  md_megamenu_get_link_style($level . '_visited', $settings, $custom_settings);
  md_megamenu_get_link_style($level . '_on', $settings, $custom_settings);
}

function md_megamenu_edit_links_form($form, &$form_state, $menu_ids) {
  $form = array();
  $module_path = drupal_get_path('module', 'md_megamenu');
  $tabs = MDMegaTab::getTabsByMenu($menu_ids);

  # Check menu_id
  $menu = MDMegaMenu::getById($menu_ids);
  if (!$menu) {
    $form['error_message'] = array(
      '#markup' => '<p style="font-size: 30px;">This menu does not exist</p>',
    );

    return $form;
  }

  # Set breadcrump & title
  drupal_set_title(t('MD Megamenu Edit: ' . $menu->title));
  replace_breadcrump();

  # Add css for cleditor
  global $base_url;
  $attributes = array(
    'href' => $base_url . '/' . $module_path . '/js/cleditor/jquery.cleditor.css',
    'rel' => 'stylesheet',
    'type' => 'text/css',
  );

  // Load media browser
  drupal_add_library('media', 'media_browser');
  drupal_add_library('media', 'media_browser_settings');
  
  // Add js and css libraries
  drupal_add_html_head_link($attributes);
  drupal_add_css($module_path . '/css/admin_grid.css');
  drupal_add_css($module_path . '/css/mega_menu.css');
  drupal_add_css($module_path . '/js/colorpicker/css/colorpicker.css');

  drupal_add_library('system', 'ui.tabs');
  drupal_add_library('system', 'ui.sortable');
  drupal_add_library('system', 'ui.draggable');
  drupal_add_library('system', 'ui.droppable');
  drupal_add_library('system', 'ui.dialog');
  drupal_add_library('system', 'jquery.cookie');

  drupal_add_js($module_path . '/js/cleditor/jquery.cleditor.js');
  drupal_add_js($module_path . '/js/cleditor/jquery.cleditor.megastyle.js');
  drupal_add_js($module_path . '/js/cleditor/jquery.cleditor.table.min.js');
  drupal_add_js($module_path . '/js/jquery.validate.js');
  drupal_add_js($module_path . '/js/jquery.numeric.js');
  drupal_add_js($module_path . '/js/colorpicker/js/colorpicker.js');
  drupal_add_js($module_path . '/js/md.utils.js', array(
    'type' => 'file',
    'scope' => 'footer'
  ));
  drupal_add_js($module_path . '/js/md.tree-menu.js', array(
    'type' => 'file',
    'scope' => 'footer'
  ));
  drupal_add_js($module_path . '/js/md.menu-item.js', array(
    'type' => 'file',
    'scope' => 'footer'
  ));
  drupal_add_js($module_path . '/js/md.menu-layout.js', array(
    'type' => 'file',
    'scope' => 'footer'
  ));
  drupal_add_js($module_path . '/js/md.menu-tab.js', array(
    'type' => 'file',
    'scope' => 'footer'
  ));
  drupal_add_js($module_path . '/js/md.js', array(
    'type' => 'file',
    'scope' => 'footer'
  ));

  $doc_css_file = base_path() . $module_path . '/js/cleditor/doc.cleditor.' . $menu->settings['design']['dms_predefine'] . '.css';
  drupal_add_js(array('cleditor_docfile' => $doc_css_file), 'setting');

  $form['html_form'] = array(
    '#markup' => theme('menu_admin_form'),
  );

  $form['menu_id'] = array(
    '#type' => 'hidden',
    '#default_value' => $menu_ids,
  );

  $form['menu_title'] = array(
    '#type' => 'hidden',
    '#default_value' => $menu->title,
  );

  $form['save_btn'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['save_continue_btn'] = array(
    '#type' => 'submit',
    '#value' => t('Save & Continue'),
  );

  $form['save_data'] = array(
    '#type' => 'textarea',
    '#default_value' => '',
    '#resizable' => FALSE,
    '#attributes' => array('class' => array('md-megamenu-data-save')),
  );

  return $form;
}

/**
 * Implements hook md_megamenu_edit_links_form_submit form
 */
function md_megamenu_edit_links_form_submit($form, &$form_state) {
  $tabs = json_decode($form_state['values']['save_data']);
  $settings = array();

  foreach ($tabs as $pos => $tab) {
    # process for tab
    $tab_settings = $tab->settings;

    $settings['general']['is_dropdown_menu'] = $tab_settings->mnu_fly_type;
    $settings['general']['submenu_width'] = isset($tab_settings->submenu_width) ? $tab_settings->submenu_width: 250;
    $settings['general']['hide_when_logged_in'] = isset($tab_settings->hide_when_logged_in) ? $tab_settings->hide_when_logged_in: FALSE;
    $settings['general']['submenu_fullwidth'] = isset($tab_settings->submenu_fullwidth) ? $tab_settings->submenu_fullwidth : TRUE;
    $settings['general']['item_position'] = isset($tab_settings->item_position) ? $tab_settings->item_position : 'auto';
    $settings['general']['title_enable'] = $tab_settings->title_enabled;
    $settings['general']['title'] = $tab_settings->mnu_title;
    $settings['general']['path'] = $tab_settings->mnu_path;
    $settings['general']['icon'] = $tab_settings->icon_url;
    $settings['general']['css_class'] = $tab_settings->mnu_class;

    $settings['layout']['col_grid'] = $tab_settings->mnu_layout->numCol;
    $settings['layout']['rows_setting'] = $tab_settings->mnu_layout->setting;

    if ($tab_settings->tab_id == 0) {
      $tab_record = MDMegaTab::create($tab_settings->mnu_id, $pos, $tab->subMenu, $settings);
    }
    else {
      $tab_record = MDMegaTab::getTabById($tab_settings->tab_id);
      $tab_record->position = $pos;
      $tab_record->settings = $settings;
      $tab_record->items = $tab->subMenu;

      $tab_record->save();
    }
  }

  if ($form_state['values']['op'] == t('Save')) {
    $form_state['redirect'] = 'admin/structure/md-megamenu';
  }
  else {
    if (isset($_GET['destination'])) {
      $form_state['redirect'] = array(
        current_path(),
        array('query' => drupal_get_destination())
      );
      unset($_GET['destination']);
    }
  }

  drupal_set_message(t('Megamenu <em>' . $form_state['values']['menu_title'] . '</em> has been edited.'));
}

/**
 * Delete tab in md_megamenu_tabs
 */
function delete_tab() {
  $response = array('message' => t('Delete failed'));

  if (isset($_POST['token_value']) && $_POST['token_value'] == drupal_get_token('delete_tab')) {
    if (isset($_POST['tab']) && MDMegaTab::delete($_POST['tab'])) {
      $response['message'] = t('OK');
    }
  }

  drupal_json_output($response);
}

/**
 * Clone menu from other existing
 */
function md_megamenu_clone_menu($mid) {
  $org_menu = MDMegaMenu::getById($mid);
  $clone = MDMegaMenu::create('clone of ' . $org_menu->title, $org_menu->description, NULL, $org_menu->settings);
  $org_tabs = MDMegaTab::getTabsByMenu($mid);
  foreach ($org_tabs as $tab) {
    MDMegaTab::create($clone->mid, $tab->position, $tab->items, $tab->settings);
  }

  drupal_goto(drupal_get_destination());
}

/**
 * Form confirm delete menu
 */
function md_megamenu_confirm_delete_form($form, &$form_state, $mid) {
  $menu = MDMegaMenu::getById($mid);
  drupal_set_title(t("Are you sure want to delete '" . $menu->title . "' ?"));

  $form['confirm_msg'] = array(
    '#markup' => '<div>This action can not be undone.</div>',
  );

  $form['confirm_menu_title'] = array(
    '#type' => 'hidden',
    '#default_value' => $menu->title,
  );

  $form['confirm_mid'] = array(
    '#type' => 'hidden',
    '#default_value' => $mid,
  );

  $form['confirm_delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
  );

  $form['confirm_cancel'] = array(
    '#markup' => l(t('Cancel'), 'admin/structure/md-megamenu'),
  );

  return $form;
}

/**
 * Handle submit form confirm delete menu
 */
function md_megamenu_confirm_delete_form_submit($form, &$form_state) {
  MDMegaMenu::delete($form_state['values']['confirm_mid']);
  $form_state['redirect'] = 'admin/structure/md-megamenu';

  drupal_set_message(t('Megamenu <em>' . $form_state['values']['confirm_menu_title'] . '</em> has been deleted.'));
}

/**
 * Ajax callback for get essential item form
 */
function get_essential_item() {
  print theme('item_setting_forms', array('parameters' => $_POST));
  exit();
}

/**
 * Theme function for overview page
 */
function theme_md_megamenu_admin_overview($variables) {
  $output = check_plain($variables['title']);
  $output .= '<div class="description">' . filter_xss_admin($variables['description']) . '</div>';

  return $output;
}

/**
 * Render dropdown tab in edit form
 */
function render_dropdown_tab($items, $menu) {
  $output = '<ul>';
  foreach ($items as $item) {
    prepare_subitem_icon($menu->settings['design']['sub_dmi_img'], $item->setting);
    $output .= "<li class='dragitem ei-processed'><div class='dropzone ui-droppable'></div><input class='setting' type='hidden' value='";
    $output .= htmlentities(json_encode($item->setting), ENT_QUOTES) . "' />";
    $output .= "<dl class='sm2_s_published ui-droppable clearfix'><a class='mdd-handle' href='#'></a><dt><a class='sm2_title' href='#'>";
    $output .= $item->setting->a_title;
    $output .= "</a></dt><dd class='mdd-change'><a class='fly-item-edit' href='#'>edit</a>|<a class='fly-item-delete' href='#'>delete</a></dd></dl>";
    if (count($item->subItems)) {
      $output .= render_dropdown_tab($item->subItems, $menu);
    }
    else {
      $output .= '</li>';
    }
  }

  $output .= '</ul>';
  return $output;
}

/**
 * Remove last breadcrumb
 */
function replace_breadcrump() {
  $breads = drupal_get_breadcrumb();
  array_pop($breads);
  array_pop($breads);

  drupal_set_breadcrumb($breads);
}

/**
 * Create form for overview page
 */
function menu_manage($mid, $option = 'configure') {
  $form['md_megamenu'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $menu_array = array();

  if ($option == 'edit') {
    $breadcrumps = drupal_get_breadcrumb();
    $breadcrumps[] = '<a></a>';
    drupal_set_breadcrumb($breadcrumps);
    $data = drupal_get_form('edit_menu', $mid);

    $menu_array[0] = array(
      '#type' => 'markup',
      'markup' => $data,
    );

    $form['md_megamenu'] += $menu_array;
  }
  elseif ($option == 'configure') {
    $data = drupal_get_form('configure_menu', $mid);

    $menu_array[0] = array(
      '#type' => 'markup',
      'markup' => $data,
    );

    $form['md_megamenu'] += $menu_array;
  }

  return $form;
}

/**
 * Analys goole link to get font information
 */
function _md_megamenu_process_google_web_font($fonts) {
  if (strpos($fonts, '@import url(') !== FALSE) {
    preg_match("/http:\/\/\s?[\'|\"]?(.+)[\'|\"]?\s?(\)|\')/Uix", $fonts, $ggwflink);
  }

  preg_match('/([^\?]+)(\?family=)?([^&\']+)/i', $fonts, $matches);
  $gfonts = explode("|", $matches[3]);

  for ($i = 0; $i < count($gfonts); $i++) {
    $gfontsdetail = explode(":", $gfonts[$i]);
    $gfontname = str_replace("+", " ", $gfontsdetail['0']);
    $fontarray[] = $gfontname;
    if (array_key_exists('1', $gfontsdetail)) {
      $tmpft = explode(",", $gfontsdetail['1']);
      $gfontweigth[$i] = "";
      for ($j = 0; $j < count($tmpft); $j++) {
        if (preg_match("/italic/i", $tmpft[$j])) {
          $gfontstyle = "i";
        }
        else {
          $gfontstyle = "n";
        }
        $tmpw = str_replace("italic", "", $tmpft[$j]);
        $seperator = ",";

        if ($j == (count($tmpft) - 1)) {
          $seperator = "";
        }

        if ($tmpw) {
          $gfontweigth[$i] .= $gfontstyle . str_replace("00", "", $tmpw) . $seperator;
        }
        else {
          $gfontweigth[$i] .= "n4" . $seperator;
        }
      }
    }
    else {
      $gfontweigth[$i] = "n4";
    }
    $fontvars[] = array(
      'CSS' => '"' . $gfontname . '"',
      'Weight' => $gfontweigth[$i],
    );
  }

  return array($fontarray, $fontvars);
}

/**
 * Get fonts information from type-kit id
 */
function md_megamenu_process_typekit_font($typekit_id) {
  $tk_url = 'http://typekit.com/api/v1/json/kits/' . $typekit_id . '/published';
  $typekit = json_decode(file_get_contents($tk_url), TRUE);
  for ($i = 0; $i < count($typekit['kit']['families']); $i++) {
    $fontarray[] = $typekit['kit']['families'][$i]['name'];
    $fontweight = "";
    for ($j = 0; $j < count($typekit['kit']['families'][$i]['variations']); $j++) {
      if (($j + 1) == count($typekit['kit']['families'][$i]['variations'])) {
        $fontweight .= $typekit['kit']['families'][$i]['variations'][$j];
      }
      else {
        $fontweight .= $typekit['kit']['families'][$i]['variations'][$j] . ',';
      }
    }
    $fontvars[] = array(
      'CSS' => $typekit['kit']['families'][$i]['css_stack'],
      'Weight' => $fontweight,
    );
  }

  return array($fontarray, $fontvars);
}

/**
 * Load font configure
 */
function load_font_configure($settings) {
  $theme_default = variable_get('theme_default', 'Bartik');
  $fontarray = array(
    t('Default'),
    t('Arial'),
    t('Verdana'),
    t('Trebuchet MS'),
    t('Georgia'),
    t('Times New Roman'),
    t('Tahoma'),
  );

  $fontvars = array(
    array('CSS' => '', 'Weight' => 'n4'),
    array('CSS' => 'Arial, sans-serif', 'Weight' => 'n4, n7, i4, i7'),
    array('CSS' => 'Verdana, Geneva, sans-serif', 'Weight' => 'n4, n7, i4, i7'),
    array(
      'CSS' => 'Trebuchet MS, Tahoma, sans-serif',
      'Weight' => 'n4, n7, i4, i7'
    ),
    array('CSS' => 'Georgia, serif', 'Weight' => 'n4, n7, i4, i7'),
    array('CSS' => 'Times New Roman, serif', 'Weight' => 'n4, n7, i4, i7'),
    array(
      'CSS' => 'Tahoma, Geneva, Verdana, sans-serif',
      'Weight' => 'n4, n7, i4, i7'
    ),
  );

  $google_font = '';
  if ($settings['text_typography']['dmf_ucf'] && $settings['text_typography']['dmf_google'] != '') {
    $google_font = $settings['text_typography']['dmf_google'];
  }

  if ($google_font != '') {
    $result = _md_megamenu_process_google_web_font($google_font);
    add_font_style($result, $fontarray, $fontvars);
  }


  $google_font = '';
  if (theme_get_setting('googlewebfonts', $theme_default)) {
    $google_font = theme_get_setting('googlewebfonts', $theme_default);
  }

  if ($google_font != '') {
    $result = _md_megamenu_process_google_web_font($google_font);
    add_font_style($result, $fontarray, $fontvars);
  }

  $typekit = '';
  if ($settings['text_typography']['dmf_ucf'] && $settings['text_typography']['dmf_typekit'] != '') {
    $typekit = $settings['text_typography']['dmf_typekit'];
  }

  if ($typekit != '') {
    $result = md_megamenu_process_typekit_font($typekit);
    add_font_style($result, $fontarray, $fontvars);
  }

  $typekit = '';
  if (theme_get_setting('typekit_id', $theme_default)) {
    $typekit = theme_get_setting('typekit_id', $theme_default);
  }

  if ($typekit != '') {
    $result = md_megamenu_process_typekit_font($typekit);
    add_font_style($result, $fontarray, $fontvars);
  }

  return array($fontarray, $fontvars);
}

function add_font_style($results, &$font_array, &$font_vars) {
  if (is_array($results)) {
    foreach ($results[0] as $id => $font_name) {
      $key = array_search($font_name, $font_array);
      if ($key === FALSE) {
        $font_array[] = $font_name;
        $font_vars[] = $results[1][$id];
      }
      else {
        $font_vars[$key] = $results[1][$id];
      }
    }
  }
}

/**
 * Get font configure by google font link or typekit id
 * @return string json for font style
 */
function get_font_configure() {
  $output = '';

  if (array_key_exists('type', $_POST)) {
    switch ($_POST['type']) {
      case 'edit-dmf-google':
        $results = _md_megamenu_process_google_web_font($_POST['data']);
        $output = drupal_json_output($results);
        break;

      case 'edit-dmf-typekit':
        $results = md_megamenu_process_typekit_font($_POST['data']);
        $output = drupal_json_output($results);
        break;
    }
  }

  return $output;
}

/**
 * Callback to check machine name
 */
function md_megamenu_check_machine_name($value) {
  $respone = db_select('md_megamenus', 'mdm')
    ->fields('mdm')
    ->condition('machine_name', $value)
    ->execute()
    ->fetchAll(PDO::FETCH_CLASS, 'MDMegaMenu');

  return count($respone);
}

/**
 * Import and Export form
 */
function md_megamenu_import_form($form, &$form_state) {
  # Get all CuteSliders are existing
  $menus = MDMegaMenu::getAll();

  $menu_options = array();
  foreach ($menus as $menu) {
    $menu_options[$menu->mid] = $menu->title;
  }
  $form['export'] = array(
    '#type' => 'fieldset',
    '#title' => t('Export'),
    '#collapsible' => FALSE,
  );

  $form['export']['menus'] = array(
    '#type' => 'radios',
    '#title' => t('Choose menu to export'),
    '#options' => $menu_options,
    '#default_value' => array(),
  );

  $form['export']['export_button'] = array(
    '#markup' => '<div><input type="button" name="export-button" class="form-submit" value="Export" /></div>'
  );

  $form['export']['export_data'] = array(
    '#type' => 'textarea',
    '#title' => t('Export data'),
    '#default_value' => '',
    '#description' => t('Copy this data and paste into input in Import form of site that you want to import.'),
    '#resizable' => FALSE,
  );

  $form['import'] = array(
    '#type' => 'fieldset',
    '#title' => t('Import'),
    '#collapsible' => FALSE,
  );

  $form['import']['machine_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Machine name'),
    '#default_value' => '',
    '#description' => t('Enter the machine name to use for this MD Megamenu if it is different from the source MD Megamenu. Leave blank to use the name of the MD Megamenu.'),
    '#resizable' => FALSE,
  );

  $form['import']['import_data'] = array(
    '#type' => 'textarea',
    '#title' => t('Import data'),
    '#default_value' => '',
    '#description' => t('Paste MDMegamenu data export from another site here to import to this site.'),
    '#resizable' => FALSE,
  );

  $form['import']['import_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );

  drupal_add_js(drupal_get_path('module', 'md_megamenu') . '/js/md-megamenu-export.js');

  return $form;
}

/**
 * Handle import submit form
 */
function md_megamenu_import_form_submit($form, &$form_state) {
  $import_data = $form_state['values']['import_data'];
  $machine_name = $form_state['values']['machine_name'];

  if ($import_data == '') {
    drupal_set_message(t('Data import is invalided.'), 'error');
    return;
  }

  $import_menu = drupal_json_decode($import_data);

  if (!isset($import_menu['machine_name']) || !isset($import_menu['title'])
    || !isset($import_menu['description']) || !isset($import_menu['settings']) || !isset($import_menu['tabs'])
  ) {
    drupal_set_message(t('Data import is invalided.'), 'error');
    return;
  }

  if ($machine_name == '') {
    if (md_megamenu_check_machine_name($import_menu['machine_name'])) {
      drupal_set_message(t('A MD MegaMenu by that machine name already exists; please choose a different machine name'));
      return;
    }
  }

  $menu = MDMegaMenu::create($import_menu['title'], $import_menu['description'], ($machine_name != '') ? $machine_name : $import_menu['machine_name'], $import_menu['settings']);

  if (!$menu) {
    drupal_set_message(t('MD Megamenu: Import failed. Please check data and try again'), 'error');
    return FALSE;
  }

  foreach ($import_menu['tabs'] as $tab) {
    MDMegaTab::create($menu->mid, $tab['position'], $tab['items'], $tab['settings']);
  }

  drupal_set_message(t('MD Megamenu: Import success.'));
}

/**
 * Callback for export data
 */
function md_megamenu_export_data() {
  if (!isset($_POST['mids']) || $_POST['mids'] == '') {
    print 'Data invalid';
    exit;
  }
  else {
    $mids = $_POST['mids'];

    $menu = MDMegaMenu::getById($mids);
    $tabs = MDMegaTab::getTabsByMenu($mids);

    $menu_data = array(
      'title' => $menu->title,
      'description' => $menu->description,
      'machine_name' => $menu->machine_name,
      'settings' => $menu->settings
    );
    $menu_data['tabs'] = md_megamenu_get_tabs_data($menu->mid, $tabs);

    print drupal_json_encode($menu_data);
  }
}

/**
 * Get slider slides data
 */
function md_megamenu_get_tabs_data($mid, &$tabs) {
  $output = array();
  foreach ($tabs as $key => $tab) {
    if ($tab->mid == $mid) {
      $output[] = array(
        'position' => $tab->position,
        'settings' => $tab->settings,
        'items' => $tab->items
      );
      unset($tabs[$key]);
    }
  }

  return $output;
}

/**
 * Validate submit form
 */
function md_megamenu_import_form_validate($form, &$form_state) {
  if ($form_state['values']['machine_name'] != '' && !preg_match('/^[a-z0-9\-]{1,}$/', $form_state['values']['machine_name'])) {
    form_set_error('machine_name', t('Machine name does not valid.'));
  }
}

/**
 * Common settings form for MD MegaMenu
 */
function md_megamenu_common_settings_form($form, &$form_state) {
  $form["help"] = array(
    "#markup" => '<div class="settings-twitter">You need to have a twitter App for your usage in order to obtain OAuth credentials, see <a href="https://dev.twitter.com/apps">https://dev.twitter.com/apps</a> for help.</div>'
  );

  $form['twitter_app_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Consumer Key'),
    '#default_value' => variable_get('twitter_app_consumer_key', ""),
  );

  $form['twitter_app_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Consumer Secret'),
    '#default_value' => variable_get('twitter_app_consumer_secret', ""),
  );

  $form['twitter_app_access_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Access Token'),
    '#default_value' => variable_get('twitter_app_access_token', ""),
  );

  $form['twitter_app_access_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Access Token Secret'),
    '#default_value' => variable_get('twitter_app_access_secret', ""),
  );


  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t("Save"),
  );


  return $form;
}


/**
 * Handle submit common settings form
 */
function md_megamenu_common_settings_form_submit($form, &$form_state) {
  $values = $form_state["values"];

  variable_set("twitter_app_consumer_key", $values["twitter_app_id"]);
  variable_set("twitter_app_consumer_secret", $values["twitter_app_secret"]);
  variable_set("twitter_app_access_token", $values["twitter_app_access_token"]);
  variable_set("twitter_app_access_secret", $values["twitter_app_access_secret"]);
}


/**
 * Response data for twitter layer
 */
function _md_megamenu_tweet() {
  $config = array(
    "app_key" => variable_get("twitter_app_consumer_key", ""),
    "app_secret" => variable_get("twitter_app_consumer_secret", ""),
    "access_token" => variable_get("twitter_app_access_token", ""),
    "access_secret" => variable_get("twitter_app_access_secret", ""),
  );
  $tweet = new Tweet($config);
  $tweet->fetch();
}

