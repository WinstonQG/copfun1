<?php
/**
 * @file theme.inc
 * Contain process for themes
 */

/**
 * Implements preprocess for theme_menu()
 * @param array $vars
 */
function template_preprocess_megamenu_theme(&$variables) {
  $menu_settings = $variables['menu_settings'];
  $menu_tabs = $variables['menu_tabs'];

  $classes[] = 'mdmegamenu';
  $classes[] = 'md-' . $menu_settings['general']['dmg_orientation'];
  if ($menu_settings['general']['dmg_verdir'] == 'rtl') {
    $classes[] = 'md-vertical-rtl';
  }
  $classes[] = ' md-' . $menu_settings['design']['dms_predefine'];
  if ($menu_settings['design']['sub_dms_dropshadow'] != 0) {
    $classes[] = 'md-dropshadow';
  }

  $toogle_out = '';
  if ($menu_settings['general']['dmg_fixed']) {
    $toogle = 'mm-toggle';
    if ($menu_settings['general']['dmg_position'] == 'center_bottom') {
      $classes[] = 'mm-fixed-bottom';
    }
    elseif ($menu_settings['general']['dmg_position'] == 'center_top') {
      $classes[] = 'mm-fixed-top';
    }

    if ($menu_settings['general']['dmg_showfixed']) {
      $toogle_out = '<a href="#" class="' . $toogle . '"></a>';
    }
  }

  if (in_array('dmg_desc', $menu_settings['general']['dm_right'])) {
    $classes[] = 'md-withdesc';
  }

  $variables['show_button'] = $toogle_out;
  $variables['menu_classes'] = implode(" ", $classes);
  $variables['is_vertical'] = ($menu_settings['design']['dms_predefine'] == "vertical") ? 'true' : 'false';

  if (count($menu_tabs) > 1) {
    $first = key($menu_tabs);
    end($menu_tabs);
    $last = key($menu_tabs);
    reset($menu_tabs);
    $item_index = 1;
    foreach ($menu_tabs as $key => &$tab) {
      $tab->icon_style = $menu_settings['design']['top_dmi_img'];
      $tab->item_icon_style = $menu_settings['design']['sub_dmi_img'];
      $tab->classes[] = 'mm-item';

      if ($tab->settings['general']['is_dropdown_menu']) {
        if (!empty($tab->items)) {
          $tab->classes[] = 'mm-dropdown';
          $tab->classes[] = 'mm-parent';
        }
      }
      else {
        $tab->classes[] = 'mm-parent';
      }

      # Add custom css class
      if ($tab->settings['general']['css_class']) {
        $tab->classes[] = $tab->settings['general']['css_class'];
      }

      switch ($key) {
        case $first:
          $tab->classes[] = 'first';
          $tab->classes[] = 'mm-item-1';
          break;

        case $last:
          $tab->classes[] = 'last';
          $tab->classes[] = 'mm-item-' . $item_index;
          break;

        default:
          $tab->classes[] = 'mm-item-' . $item_index;
          break;
      }

      # Render tab description
      render_tab_description($tab, $menu_settings['general']['dm_right'], $menu_settings['design']['top_dms_descc']);

      $item_index++;
    }
  }
  else {
    $menu_tabs[0]->icon_style = $menu_settings['design']['top_dmi_img'];
    $menu_tabs[0]->item_icon_style = $menu_settings['design']['sub_dmi_img'];
    $menu_tabs[0]->classes[] = 'first';
    $menu_tabs[0]->classes[] = 'last';
    $menu_tabs[0]->classes[] = 'mm-item';
    if ($menu_tabs[0]->settings['general']['is_dropdown_menu']) {
      if (!empty($menu_tabs[0]->items)) {
        $menu_tabs[0]->classes[] = 'mm-dropdown';
        $menu_tabs[0]->classes[] = 'mm-parent';
      }
    }
    else {
      $menu_tabs[0]->classes[] = 'mm-parent';
    }
    $menu_tabs[0]->classes[] = 'mm-item-1';

    # Add custom css class
    if ($menu_tabs[0]->settings['general']['css_class']) {
      $menu_tabs[0]->classes[] = $menu_tabs[0]->settings['general']['css_class'];
    }

    # Render tab description
    render_tab_description($menu_tabs[0], $menu_settings['general']['dm_right'], $menu_settings['design']['top_dms_descc']);
  }
  $variables['menu_tabs'] = $menu_tabs;

  $menu_animation = $menu_settings['animation'];

  $effect = array();
  $effect['effectTypeOpen'] = $menu_animation['dma_animation'];
  $effect['effectTypeClose'] = $menu_animation['dma_animation'];

  if ($menu_animation['dma_easing'] != '0') {
    $effect['effectOpen'] = $menu_animation['dma_easing'];
    $effect['effectClose'] = $menu_animation['dma_easing'];
  }

  if ($menu_animation['dma_delay'] != "") {
    $effect['effectSpeedClose'] = $menu_animation['dma_delay'];
    $effect['effectSpeedOpen'] = $menu_animation['dma_delay'];
  }

  $option['effects'] = $effect;

  if ($menu_animation['dma_show'] != "") {
    $option['timeBeforeOpening'] = $menu_animation['dma_show'];
  }

  if ($menu_animation['dma_hide'] != "") {
    $option['timeBeforeClosing'] = $menu_animation['dma_hide'];
  }

  $option['trigger'] = $menu_animation['dma_trigger'];

  if ($menu_settings['general']['dmg_orientation'] == 'vertical') {
    $option['vertical'] = TRUE;
  }

  if (in_array('dmg_arrow', $menu_settings['general']['dm_right'])) {
    $option['arrow'] = TRUE;
  }

  if (in_array('dmg_responsive', $menu_settings['general']['dm_right'])) {
    drupal_add_js(drupal_get_path('module', 'md_megamenu') . '/menu_styles/js/selectnav.min.js');
  }

  drupal_add_js(array('mmoptions_' . $variables['mid'] => $option), 'setting');

  load_text_typography_configure($menu_settings['text_typography']);
}

/**
 * Implements preprocess for theme_tab()
 * @param array $vars
 */
function template_preprocess_megamenu_tab_theme(&$variables) {
  $tab = $variables['tab'];

  $variables['row_extends'] = '';
  $classes = array();
  $classes[] = 'mm-container';
  if (!$tab->settings['layout']['is_full_width'] && $tab->settings['layout']['submenu_width'] != '') {
    $classes[] = 'mm-customwidth';
    $variables['row_extends'] = ' style="width: ' . $tab->settings['layout']['submenu_width'] . 'px;"';
    $variables['row_extends'] .= ' data-width="' . $tab->settings['layout']['submenu_width'] . '"';
  }
  else {
    $classes[] = 'mm-fullwidth';
  }
  $classes[] = 'mmcontainer_' . $tab->settings['layout']['col_grid'];
  $variables['row_classes'] = implode(' ', $classes);

  $rows = $tab->settings['layout']['rows_setting'];
  foreach ($rows as $row_id => $row) {
    foreach ($row->cols as $col_id => &$col) {
      $classes = array();
      $classes[] = 'mmg_' . $col->length * $tab->settings['layout']['col_grid'] / 48;
      $col_style = render_col_style($col->style, $row->style);
      if ($col_style[0]['margin'] != '') {
        $classes[] = $col_style[0]['margin'];
      }
      if ($col_style[0]['bg'] != '') {
        $classes[] = 'background-color';
      }
      $col->classes = implode(' ', $classes);
      $col->items['items'] = $tab->items[$row_id][$col_id];
      $col->items['icon_style'] = $tab->item_icon_style;
      $col->div_col = $col_style[0]['bg'];
      $col->inner = $col_style[1];
    }

    $row->style = render_row_style($row->style);
  }
  $variables['rows'] = $rows;
  $variables['items'] = $tab->items;
  $variables['title'] = ($tab->settings['general']['title_enable']) ? $tab->settings['general']['title'] : '';
  $variables['path'] = ($tab->settings['general']['path'] != '') ? $tab->settings['general']['path'] : '#';

  if (is_active_link($variables['path'], $_GET['q'])) {
    $tab->classes[] = 'awemenu-active';
  }
  $variables['tab_classes'] = implode(' ', $tab->classes);
}

function theme_megamenu_col_content(&$variables) {
  $items = $variables['items']['items'];
  $icon_style = $variables['items']['icon_style'];

  $output = '';
  foreach ($items as $item) {
    $item_out = '';
    if (isset($item->class)) {
      $item->class = urldecode($item->class);
    }

    switch ($item->type) {
      case 'header':
        if ($item->h_icon != '') {
          $icon_id = get_icon_id($item->h_icon);
          $icon = file_load($icon_id);
          if ($icon_style != '') {
            $item->h_icon = image_style_url($icon_style, $icon->uri);
          }
          else {
            $item->h_icon = file_create_url($icon->uri);
          }
        }

        $item->title = urldecode($item->title);
        $item_out = theme('megamenu_essential_item_theme', array(
          'type' => 'header',
          'item' => $item
        ));
        break;

      case 'img':
        if ($item->img_path != '') {
          $img_id = get_icon_id($item->img_path);
          $img = file_load($img_id);
          if ($item->img_style != '') {
            $item->img_path = image_style_url($item->img_style, $img->uri);
          }
          else {
            $item->img_path = file_create_url($img->uri);
          }

          if ($item->class != '') {
            $item->class = explode(' ', $item->class);
          }
          else {
            $item->class = array();
          };

          $item->img_alt = urldecode($item->img_alt);
          $item_out = theme('megamenu_essential_item_theme', array(
            'type' => 'img',
            'item' => $item
          ));
        }
        break;

      case 'a':
        if ($item->a_icon != '') {
          $icon_id = get_icon_id($item->a_icon);
          $icon = file_load($icon_id);
          if ($icon_style != '') {
            $item->a_icon = image_style_url($icon_style, $icon->uri);
          }
          else {
            $item->a_icon = file_create_url($icon->uri);
          }
        }

        $attributes = array();
        if ($item->a_target != 'none') {
          $attributes['target'] = array($item->a_target);
        }

        if ($item->class != '') {
          $attributes['class'] = explode(' ', $item->class);
        }
        $item->attributes = $attributes;

        // process link for item a
        $item->a_path = urldecode($item->a_path);
        $item->a_title = urldecode($item->a_title);

        $path_elements = parse_url($item->a_path);
        $item->a_path = isset($path_elements['path']) ? $path_elements['path'] : '';
        $item->query = array();
        if (isset($path_elements['query'])) {
          parse_str($path_elements['query'], $item->query);
        }
        $item->fragment = isset($path_elements['fragment']) ? $path_elements['fragment'] : '';

        $item_out = theme('megamenu_essential_item_theme', array(
          'type' => 'a',
          'item' => $item
        ));
        break;

      case 'video':
        $item->video_link = urldecode($item->video_link);
        $iframe_par = "";
        if ($yt_id = md_megamenu_get_youtube_id_from_url($item->video_link)) {
          $item->video_link = "http://www.youtube.com/embed/{$yt_id}";
          $iframe_par = ' frameborder="0" allowfullscreen';
        }
        elseif ($vimeo_id = md_megamenu_get_vimeo_id_from_url($item->video_link)) {
          $item->video_link = "http://player.vimeo.com/video/{$vimeo_id}";
          $iframe_par = ' frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen';
        }
        $item->parameters = $iframe_par;

        if ($item->video_link != '') {
          $item_out = theme('megamenu_essential_item_theme', array(
            'type' => 'video',
            'item' => $item
          ));
        }
        break;

      case 'html':
        $item->html = urldecode($item->html);
        $item_out = theme('megamenu_essential_item_theme', array(
          'type' => 'html',
          'item' => $item
        ));
        break;

      case 'iframe':
        $item_out = theme('megamenu_essential_item_theme', array(
          'type' => 'iframe',
          'item' => $item
        ));
        break;

      case 'block':
        $item_out = theme('megamenu_block_item', array(
          'type' => 'header',
          'item' => $item
        ));
        break;

      case 'textblock':
        $item->textblock_text = urldecode($item->textblock_text);
        $item_out = theme('megamenu_essential_item_theme', array(
          'type' => 'textblock',
          'item' => $item
        ));
        break;

      case 'seperator':
        $item_out = theme('megamenu_essential_item_theme', array('type' => 'seperator'));
        break;

      case 'seperatortext':
        $item->seperator_text = urldecode($item->seperator_text);
        $item_out = theme('megamenu_essential_item_theme', array(
          'type' => 'seperatortext',
          'item' => $item
        ));
        break;

      case 'flickr':
        $item_out = theme('megamenu_essential_item_theme', array(
          'type' => 'flickr',
          'item' => $item
        ));
        break;

      case 'gmap':
        $item->url = urldecode($item->gmap_link);
        if ($item->gmap_type != 'm') {
          $item->url .= '&t=' . $item->gmap_type;
        }

        if ((int) $item->gmap_zoom > 14) {
          $item->url .= '&z=' . $item->gmap_zoom;
        }
        $item->url .= '&output=embed';
        $item->url = htmlentities($item->url);
        $item_out = theme('megamenu_essential_item_theme', array(
          'type' => 'gmap',
          'item' => $item
        ));
        break;

      case 'twitter':
        drupal_add_js(drupal_get_path('module', 'md_megamenu') . '/menu_styles/js/jquery.tweet.min.js');
        $item_out = theme('megamenu_essential_item_theme', array(
          'type' => 'twitter',
          'item' => $item
        ));
        break;
    }

    $output .= $item_out;
  }

  return $output;
}

/**
 * Implements preprocess for theme_block_item()
 * @param array $vars
 */
function theme_megamenu_block_item(&$variables) {
  $block = $variables['item'];
  $block_content = module_invoke($block->block_module, 'block_view', $block->block_id);

  $output = '';
  if (isset($block_content['content'])) {
    if (is_array($block_content['content'])) {
      $output = drupal_render($block_content['content']);
    }
    else {
      $output = $block_content['content'];
    }
  }

  return $output;
}

/**
 * Implements preprocess for theme_dropdown_tab()
 * @param array $vars
 */
function template_preprocess_megamenu_dropdown_tab(&$variables) {
  $tab = $variables['tab'];
  $tab_path = $tab->settings['general']['path'];
  $variables['items'] = $tab->items;

  $actived = is_active_link($tab_path, $_GET['q']);

  $children_active = FALSE;
  $variables['tab_content'] = render_dropdown_tab_frontend($tab->items, $children_active, $actived);

  if ($children_active || $actived) {
    $tab->classes[] = 'awemenu-active';
  }
  $variables['tab_classes'] = implode(' ', $tab->classes);
}

function render_dropdown_tab_frontend($items, &$active, $parent_actived = FALSE) {
  $html = "";

  if (count($items)) {
    $html = '<ul class="mm-container">';
    foreach ($items as $item) {
      $current_active = FALSE;
      $child_active = FALSE;
      $html_sub = '';
      $li_classes = array();
      $a_classes = array();

      $item_path = ($item->setting->a_path != '#') ? url($item->setting->a_path, array('absolute' => TRUE)) : '';
      if (!$parent_actived && is_active_link($item_path, $_GET['q'])) {
        $current_active = TRUE;
        $a_classes[] = 'awemenu-active';
      }

      if (count($item->subItems)) {
        $li_classes[] = 'mm-parent';
        $html_sub = render_dropdown_tab_frontend($item->subItems, $child_active, $current_active);
      }

      if ($current_active || $child_active) {
        $active = TRUE;
        $li_classes[] = 'awemenu-active';
      }

      $options = array();
      if ($item_path == '') {
        $options['fragment'] = ' ';
        $options['external'] = TRUE;
      }

      if ($item->setting->class != '') {
        $a_classes += explode(',', $item->setting->class);
      }

      if (!empty($a_classes)) {
        $options['attributes']['class'] = $a_classes;
      }

      if ($item->setting->a_target != NULL && $item->setting->a_target != 'none') {
        $options['attributes']['target'] = array($item->setting->a_target);
      }

      $html .= '<li';
      $html .= (!empty($li_classes)) ? ' class="' . implode(' ', $li_classes) . '">' : '>';
      $html .= l($item->setting->a_title, $item_path, $options);
      $html .= $html_sub;
      $html .= '</li>';
    }

    $html .= '</ul>';
  }
  return $html;
}

function render_tab_description(&$tab, $general_dm_right, $desc_color) {
  $general_settings = $tab->settings['general'];

  // generate description
  $description = '';
  if (in_array('dmg_desc', $general_dm_right) && $general_settings['description'] != '') {
    $description = '<span class="mm-desc"';
    $description .= ($desc_color != '') ? ' style="color: #' . $desc_color . '">' : '>';
    $description .= $general_settings['description'] . '</span>';
  }

  // Generate link
  $a_title = ($general_settings['title_enable']) ? $general_settings['title'] : '';
  $a_href = '#';
  if ($general_settings['path']) {
    $path_options = parse_url($general_settings['path']);
    $path_options['absolute'] = TRUE;
    $path_url = '';
    if (isset($path_options['path'])) {
      if (isset($path_options['scheme'])) {
        $path_url = $path_options['scheme'] . '://' . $path_options['host'] . $path_options['path'];
      }
      else {
        $path_url = $path_options['path'];
      }
      unset($path_options['path']);
    }
    if (isset($path_options['query'])) {
      $query = array();
      parse_str($path_options['query'], $query);
      $path_options['query'] = $query;
    }
    $a_href = url($path_url, $path_options);
  }

  $a_head = '<a href="' . $a_href . '">';

  // Generate icon
  $icon_html = '';
  if ($general_settings['icon'] != NULL && $general_settings['icon'] != '') {
    $icon_id = get_icon_id($general_settings['icon']);
    $icon = file_load($icon_id);
    if ($tab->icon_style != '') {
      $icon_url = image_style_url($tab->icon_style, $icon->uri);
    }
    else {
      $icon_url = file_create_url($icon->uri);
    }

    $icon_html = theme('image', array(
      'path' => $icon_url,
      'alt' => $general_settings['title']
    ));
  }

  $tab->content = $a_head . $icon_html . $a_title . $description . '</a>';
}

function load_text_typography_configure($settings) {
  $theme_default = variable_get('theme_default', 'Bartik');

  if ($settings['dmf_ucf']) {
    $theme_fonts = theme_get_setting('googlewebfonts', $theme_default);
    # Check google font setting
    if ($settings['dmf_google'] != '' && $settings['dmf_google'] != $theme_fonts) {
      drupal_add_css($settings['dmf_google'], array('type' => 'external'));
    }

    # Check typekit setting
    $theme_typekit = theme_get_setting('typekit_id', $theme_default);
    if ($settings['dmf_typekit'] != '' && $settings['dmf_typekit'] != $theme_typekit) {
      drupal_add_js('http://use.typekit.net/' . $settings['dmf_typekit'] . '.js', 'external');
      drupal_add_js('try{Typekit.load();}catch(e){}', 'inline');
    }
  }
}

/**
 * implements hook_preprocess_hook for awemenu theme
 */
function md_megamenu_preprocess_md_megamenu(&$vars) {
  $menu = $vars['menu'];
  $items = $vars['items'];
  $vars['menu_id'] = "md-megamenu-{$menu->mid}";
  $menu_classes = &$vars['classes_array'];

  // process settings to add logo to menu
  $vars['logo'] = '';
  if (in_array('dmg_enable_logo', $menu->settings['general']['dm_right'])) {
    $themes = list_themes();
    $theme_active = variable_get('theme_default', 'bartik');
    $theme_object = $themes[$theme_active];
    $theme_settings = variable_get('theme_' . $theme_active . '_settings', '');
    if ($theme_settings['default_logo']) {
      $logo = file_create_url(dirname($theme_object->filename) . '/logo.png');
    }
    elseif ($theme_settings['logo_path']) {
      $logo = file_create_url($theme_settings['logo_path']);
    }
    $vars['logo'] = $logo;
    $menu_classes[] = 'awemenu-has-logo';

  }

  // add menu classes
  $menu_classes = array_merge($menu_classes, array(
    "md-megamenu-{$menu->mid}",
    "md-megamenu-{$menu->machine_name}",
    'awemenu-nav'
  ));
  if (isset($menu->settings['menu_type']) && in_array($menu->settings['menu_type'], array(
      'left',
      'outleft',
      'right',
      'outright'
    ))
  ) {
    $menu_classes[] = 'md-vertical-menu';
  }
  else {
    $menu_classes[] = 'md-hozirontal-menu';
  }

  // create renderable array for menu items
  $items_render = array();
  foreach ($items as $item) {
    $general_settings = $item->settings['general'];
    $layout_settings = $item->settings['layout'];

    if (!isset($general_settings['hide_when_logged_in']) || !$general_settings['hide_when_logged_in']) {
      $item_data = array(
        'title_enabled' => $item->settings['general']['title_enable'],
        'title' => $item->settings['general']['title'],
        'path' => $item->settings['general']['path'],
        'target' => '',
        'icon' => $item->settings['general']['icon'],
        'classes' => $item->settings['general']['css_class'],
        'position' => isset($item->settings['general']['item_position']) ? $item->settings['general']['item_position'] : 'auto'
      );

      $is_fullwidth = TRUE;
      if (isset($general_settings['submenu_fullwidth'])) {
        $is_fullwidth = $general_settings['submenu_fullwidth'];
      }
      elseif (isset($layout_settings['is_full_width'])) {
        $is_fullwidth = $layout_settings['is_full_width'];
      }

      $submenu_width = !$general_settings['is_dropdown_menu'] ? 250 : '100%';
      if (isset($general_settings['submenu_width'])) {
        $submenu_width = $general_settings['submenu_width'];
      }
      elseif (isset($layout_settings['submenu_width'])) {
        $submenu_width = $layout_settings['submenu_width'];
      }

      $submenu = array(
        'data' => $item->items,
        'settings' => array(
          'is_mega' => !$general_settings['is_dropdown_menu'],
          'is_fullwidth' => $is_fullwidth,
          'submenu_width' => $submenu_width
        )
      );

      if (!$item->settings['general']['is_dropdown_menu']) {
        $submenu['layout'] = $item->settings['layout'];
      }
      $items_render[] = array(
        '#theme' => 'awemenu_item',
        '#menu' => $menu,
        '#item' => $item_data,
        '#submenu' => $submenu,
        '#level' => 1
      );
    }
  }
  $vars['menu_items'] = $items_render;
}

/**
 * implements hook_preprocess_hook for awemenu_item theme
 */
function md_megamenu_preprocess_awemenu_item(&$vars) {
  $menu = $vars['menu'];
  $item = $vars['item'];
  $submenu = $vars['submenu'];
  $level = $vars['level'];

  // add custom classes
  $vars['classes_array'][] = "awemenu-item-level-{$level}";
  if (in_array('dmg_cssclasses', $menu->settings['general']['dm_right'])) {
    $vars['classes_array'][] = $item['classes'];
  }

  // process item position
  if ($item['position'] == 'right') {
    $vars['classes_array'][] = 'awemenu-item-right';
  }

  // create link url
  $vars['item_url'] = _megamenu_create_item_url($item);
  if (is_active_link($item['path'], $_GET['q'])) {
    $vars['classes_array'][] = 'awemenu-active-trail';
  }

  // create link classes
  $vars['item_link_classes'] = array('awemenu-item-link');

  // create item link content
  $vars['item_link_content'] = '';
  $enable_icon = ($level === 1 && in_array('dmg_menuicon', $menu->settings['general']['dm_right'])) || ($level > 1 && in_array('dmg_menuitemicon', $menu->settings['general']['dm_right']));
  if ($enable_icon && $item['icon']) {
    $icon_data = array();
    parse_str($item['icon'], $icon_data);

    if (isset($icon_data['id'])) {
      $icon = file_load($icon_data['id']);
      if ($icon) {
        if (isset($menu->settings['design']['top_dmi_img']) && $menu->settings['design']['top_dmi_img']) {
          $icon_url = image_style_url($menu->settings['design']['top_dmi_img'], $icon->uri);
        }
        else {
          $icon_url = file_create_url($icon->uri);
        }
        $vars['item_link_content'] .= sprintf('<span class="awemenu-item-icon"><img src="%s" alt="" /></span>', $icon_url);
      }
    }
  }
  if ($item['title_enabled']) {
    $vars['item_link_content'] .= sprintf('<span class="awemenu-item-title">%s</span>', $item['title']);
  }

  // process submenu render
  $attributes = array();
  $vars['submenu_render'] = array();
  $vars['submenu_classes'] = array('awemenu-submenu');
  if (isset($submenu['layout'])) {
    // add class define submenu is megamenu
    $vars['submenu_classes'][] = 'awemenu-megamenu';


    // create render array for submenu
    $rows = array();
    foreach ($submenu['layout']['rows_setting'] as $rid => $row) {
      $row_render = array();
      foreach ($row->cols as $cid => $column) {
        $col_number = $column->length / 4;
        $column_render = array(
          'classes' => array("col-md-{$col_number}", 'col-xs-12'),
          'content' => array()
        );

        // create render array for column contents
        foreach ($submenu['data'][$rid][$cid] as $item) {
          if ($item->type == 'block') {
            // render block
            $block = block_load($item->block_module, $item->block_id);
            $block_renderable = _block_get_renderable_array(_block_render_blocks(array($block)));
            $column_render['content'][] = array(
              '#markup' => drupal_render($block_renderable)
            );
          }
          else {
            $column_render['content'][] = array(
              '#theme' => 'megamenu_essential_item_theme',
              '#item' => $item
            );
          }
        }

        $row_render[] = $column_render;
      }
      $rows[] = $row_render;
    }

    $vars['submenu_render'] = array(
      '#theme' => 'md_submenu_megamenu',
      '#rows' => $rows
    );
  }
  else {
    // add class define submenu is dropdown menu
    $vars['submenu_classes'][] = 'awemenu-dropdown';

    // create render for submenu
    foreach ($submenu['data'] as $item) {
      $vars['submenu_render'][] = array(
        '#theme' => 'awemenu_item',
        '#menu' => $menu,
        '#item' => array(
          'title_enabled' => TRUE,
          'title' => $item->setting->a_title,
          'path' => $item->setting->a_path,
          'target' => $item->setting->a_target,
          'icon' => $item->setting->a_icon,
          'classes' => $item->setting->class,
          'position' => 'auto'
        ),
        '#submenu' => array(
          'data' => $item->subItems,
          'settings' => array(
            'is_mega' => FALSE,
            'is_fullwidth' => FALSE,
            'submenu_width' => isset($item->settings['a_submenu_width']) ? $item->settings['a_submenu_width'] : 250
          )
        ),
        '#level' => $vars['level'] + 1
      );
    }
  }

  // process submenu width
  if ($submenu['settings']['is_mega'] && $submenu['settings']['is_fullwidth']) {
    $attributes[] = 'data-width="100%"';
  }
  else {
    if ($submenu['settings']['submenu_width'] && intval($submenu['settings']['submenu_width']) > 0) {
      $attributes[] = sprintf('data-width="%d"', intval($submenu['settings']['submenu_width']));
    }
  }

  $vars['submenu_attributes'] = '';
  if (count($attributes) > 0) {
    $vars['submenu_attributes'] = ' ' . implode(' ', $attributes);
  }
}

/**
 * Callback to create item URL
 */
function _megamenu_create_item_url($item_data) {
  $path = urldecode($item_data['path']);
  $path_elements = parse_url($path);
  if (isset($path_elements['host']) && $_SERVER['HTTP_HOST'] != $path_elements['host']) {
    return $path;
  }
  $path = isset($path_elements['path']) ? $path_elements['path'] : $path;
  $url_query = array();
  if (isset($path_elements['query'])) {
    parse_str($path_elements['query'], $url_query);
  }
  $url_fragment = isset($path_elements['fragment']) ? $path_elements['fragment'] : '';

  if (strpos($path, '#') === 0) {
    return $path;
  }

  return url($path, array('query' => $url_query, 'fragment' => $url_fragment));
}

/**
 * implements hook_preprocess_hook for megamenu_essential_item_theme
 */
function md_megamenu_preprocess_megamenu_essential_item_theme(&$vars) {
  _md_megamenu_process_essential_item_data($vars['item']);
  $vars['type'] = $vars['item']->type;
}

/**
 * callback process data for essential item
 */
function _md_megamenu_process_essential_item_data(&$item) {
  $item_render = array();

  switch ($item->type) {
    case 'header':
      if ($item->h_icon != '') {
        $icon_id = get_icon_id($item->h_icon);
        $icon = file_load($icon_id);
        if ($icon_style != '') {
          $item->h_icon = image_style_url($icon_style, $icon->uri);
        }
        else {
          $item->h_icon = file_create_url($icon->uri);
        }
      }

      $item->title = urldecode($item->title);
      break;

    case 'img':
      if ($item->img_path != '') {
        $img_id = get_icon_id($item->img_path);
        $img = file_load($img_id);
        if ($item->img_style != '') {
          $item->img_path = image_style_url($item->img_style, $img->uri);
        }
        else {
          $item->img_path = file_create_url($img->uri);
        }

        if ($item->class != '') {
          $item->class = explode(' ', $item->class);
        }
        else {
          $item->class = array();
        };

        $item->img_alt = urldecode($item->img_alt);
      }
      break;

    case 'a':
      if ($item->a_icon != '') {
        $icon_id = get_icon_id($item->a_icon);
        $icon = file_load($icon_id);
        if ($icon_style != '') {
          $item->a_icon = image_style_url($icon_style, $icon->uri);
        }
        else {
          $item->a_icon = file_create_url($icon->uri);
        }
      }

      $attributes = array();
      if ($item->a_target != 'none') {
        $attributes['target'] = array($item->a_target);
      }

      if ($item->class != '') {
        $attributes['class'] = explode(' ', $item->class);
      }
      $item->attributes = $attributes;

      // process link for item a
      $item->a_path = urldecode($item->a_path);
      $item->a_title = urldecode($item->a_title);

      $path_elements = parse_url($item->a_path);
      if (isset($path_elements['host']) && $_SERVER['HTTP_HOST'] != $path_elements['host']) {
        $item->query = array();
        $item->fragment = '';
        break;
      }
      $item->a_path = isset($path_elements['path']) ? $path_elements['path'] : '';
      $item->query = array();
      if (isset($path_elements['query'])) {
        parse_str($path_elements['query'], $item->query);
      }
      $item->fragment = isset($path_elements['fragment']) ? $path_elements['fragment'] : '';

      break;

    case 'video':
      $item->video_link = urldecode($item->video_link);
      $iframe_par = "";
      if ($yt_id = md_megamenu_get_youtube_id_from_url($item->video_link)) {
        $item->video_link = "http://www.youtube.com/embed/{$yt_id}";
        $iframe_par = ' frameborder="0" allowfullscreen';
      }
      elseif ($vimeo_id = md_megamenu_get_vimeo_id_from_url($item->video_link)) {
        $item->video_link = "http://player.vimeo.com/video/{$vimeo_id}";
        $iframe_par = ' frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen';
      }
      $item->parameters = $iframe_par;
      break;

    case 'html':
      $item->html = urldecode($item->html);
      break;


    case 'block':
      $item_out = theme('megamenu_block_item', array(
        'type' => 'header',
        'item' => $item
      ));
      break;

    case 'textblock':
      $item->textblock_text = urldecode($item->textblock_text);
      break;

    case 'seperatortext':
      $item->seperator_text = urldecode($item->seperator_text);
      break;

    case 'gmap':
      $item->url = urldecode($item->gmap_link);

      if ($item->gmap_type != 'm') {
        $item->url .= '&t=' . $item->gmap_type;
      }

      if ((int) $item->gmap_zoom > 14) {
        $item->url .= '&z=' . $item->gmap_zoom;
      }
      $item->url .= '&output=embed';
      $item->url = htmlentities($item->url);
      break;

    case 'twitter':
      drupal_add_js(drupal_get_path('module', 'md_megamenu') . '/menu_styles/js/jquery.tweet.min.js');
      break;
  }
}
