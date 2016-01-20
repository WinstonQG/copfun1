<?php
/**
 * Implements hook_preprocess_acrousel()
 */
function md_ac_hosoren_preprocess_awe_carousel(&$vars) {
  drupal_add_js(drupal_get_path('module', 'md_ac_hosoren') . '/css_js_front/frontend-carousel.js');
  drupal_add_css(drupal_get_path('module', 'md_ac_hosoren') . '/css_js_front/frontend-carousel.css');
  $style = '';
  $settings = $vars['settings'];
  $data_carousel['data-items'] = $settings['items'];
  $data_carousel['data-responsive'] = $settings['itemsResponsive'];
  $slides_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $slides_id;
  $vars['classes_array'] = array('awe-item', 'awe-carousel', $vars['class_random']);
  $slides_class = $settings['customClass'];

  $node_style = _ac_render_item_id_tag($slides_id, $slides_class, $vars['class_random']);
  if ($node_style['isChange']) {
    $slides_class = $node_style['isChange'];
    if ($slides_class != $vars['class_random'])
      $vars['classes_array'][] = $slides_class;
  }
  $node_style = $node_style['result'];
  if ($data_carousel['data-responsive']) {
    $data_carousel['data-items-desktop-small'] = $settings['itemsDesktopSmall'];
    $data_carousel['data-items-tablet'] = $settings['itemsTablet'];
    $data_carousel['data-items-mobile'] = $settings['itemsMobile'];
    $data_carousel['data-items-mobile'] = $settings['itemsMobile'];
  }
  $data_carousel['data-auto'] = $settings['autoPlay'];
  if ($data_carousel['data-auto']) {
    $data_carousel['data-time-auto'] = $settings['timeAutoPlay'];
    $data_carousel['data-stop-on-hover'] = $settings['stopOnHover'] ? 'true' : 'false';
  }
  $data_carousel['data-navigation'] = $settings['navigation']  ? 'true' : 'false';
  $data_carousel['data-pagination'] = $settings['pagination'] ? 'true' : 'false';
  !$settings['mouseDrag'] ? $data_carousel['data-mousedrag'] = 'false' : '';
  !$settings['touchDrag'] ? $data_carousel['data-touchdrag'] = 'false' : '';
  $data_carousel['data-items'] == 1 ? $data_carousel['data-effect'] = $settings['effect'] : '';

  $slides = $settings['slides'];
  unset($slides[count($slides) -1]);
  foreach ($slides as $key_slide => $slide) {
    $slides['content'][] = _awecontent_preprocess_columns($slide['content'], $vars['class_random'], $vars['node']);
  }
  $vars['slides'] = $slides;
  if ($settings['navigation'] != '')
    $vars['classes_array'][] = $settings['paginationStyle'];
  if ($settings['pagination'] != "") {
    $vars['classes_array'][] = $settings['paginationStyle'];
  }


  /* Setting */


  $attributes = array(
    'enable' => $settings['customEnableAttributes'],
    'attributes' => $settings['customDataAttributes']
  );

  $animations = array(
    'enable' => $settings['customEnableAnimations'],
    'animations' => $settings['customDataAnimations']
  );
  $responsive = array(
    'lgResponsive' => $settings['lgResponsive'],
    'xsResponsive' => $settings['xsResponsive'],
    'mediumResponsive' => $settings['mediumResponsive'],
    'smResponsive' => $settings['smResponsive']
  );
  $box_model = $settings['boxModelSettings'];
  $attributes = _ac_render_item_attributes_settings($attributes);
  $animations = _ac_render_item_animations_settings($animations);
  $responsive = _ac_render_item_responsive_settings($responsive);
  $boxModel = _ac_render_item_box_model_settings($box_model);
  if ($responsive != '')
    $vars['classes_array'][] = $responsive;

  $vars['attributes_array'] = array_merge($vars['attributes_array'], $data_carousel, $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';

  $style .= render_css($node_style, array($boxModel));

  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}

/**
 * Implements hook_preprocess_pricing_table()
 */
function md_ac_hosoren_preprocess_awe_pricing_table(&$vars) {
  $settings = $vars['settings'];

  if ($settings['EnableBorder'] == 0) {
    $vars['pricingborder'] = 'border-none';
  }else{
    $vars['pricingborder'] = '';
  }

  if ($settings['enableplanbtn'] == 1) {
    $vars['planbutton'] = 'pricing-planebt';
  }else{
    $vars['planbutton'] = '';
  }

  if ($settings['enableBorderHeader'] == 1) {
    $vars['header_boder'] = 'heade_line';
  }else{
    $vars['header_boder'] = '';
  }

  if ($settings['enablelistborder'] == 1) {
    $vars['planlist'] = 'list_border';
  }else{
    $vars['planlist'] = '';
  }
  if ($settings['enablelistpadding'] == 1) {
    $vars['palist'] = 'pading_list';
  }else{
    $vars['palist'] = '';
  }


  if ($settings['EnableButtonBorder'] == 1) {
    $vars['Btnborder'] = 'button-line';
  }else{
    $vars['Btnborder'] = '';
  }

  // List icon text
  if ($settings['listicontext'] != '') {
    $vars['listicontext'] = drupal_json_decode($settings['listicontext']);
  }

  // Css
  $header_color = array(
    'color' => $settings['headerColor'],
    'background' => $settings['headerBg']
  );
  $content_color = array(
    'color' => $settings['contentColor'],
    'background' => $settings['contentBG']
  );
  $title_color = array(
    'color' => $settings['titlecolor'],
  );
  $font_settings = array(
    'fontFamily' => $settings['titlefontFamily'],
    'fontStyle' => $settings['titlefontStyle'],
    'fontSize' => $settings['titlefontSize'],
    'unit' => 'px'
  );
  $font_settings = _ac_render_item_font_settings($font_settings);


  $price_color = array(
    'color' => $settings['colorPrice']
  );
  $pice_font_settings = array(
    'fontFamily' => $settings['pricefontFamily'],
    'fontStyle' => $settings['pricefontStyle'],
    'fontSize' => $settings['pricefontSize'],
    'unit' => 'px'
  );
  $pice_font_settings = _ac_render_item_font_settings($pice_font_settings);

  $icon_color = array(
    'color' => $settings['IconColor']
  );
  $button_color = array(
    'color' => $settings['button_color'],
    'background' => $settings['button_bg'],
    'hoverColor' => $settings['button_hover_color'],
    'hoverBackground' => $settings['button_hover_bg'],
  );
  // $footer_color = array(
  //   'background' => $settings['footer_color'],
  // );


  /* Setting basic*/
  $counters_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $counters_id;
  $vars['classes_array'] = array('awe-item', 'awe-pricing-item', $vars['class_random']);
  $counters_class = $settings['customClass'];

  $node_style = _ac_render_item_id_tag($counters_id, $counters_class, $vars['class_random']);
  if ($node_style['isChange']) {
    $pricing_class = $node_style['isChange'];
    if ($pricing_class != $vars['class_random'])
      $vars['classes_array'][] = $pricing_class;
  }
  $node_style = $node_style['result'];

  /* Setting */
  $box_model = $settings['boxModelSettings'];
  $attributes = array(
    'enable' => $settings['customEnableAttributes'],
    'attributes' => $settings['customDataAttributes']
  );
  $animations = array(
    'enable' => $settings['customEnableAnimations'],
    'animations' => $settings['customDataAnimations']
  );
  $responsive = array(
    'lgResponsive' => $settings['lgResponsive'],
    'xsResponsive' => $settings['xsResponsive'],
    'mediumResponsive' => $settings['mediumResponsive'],
    'smResponsive' => $settings['smResponsive']
  );

  $title_color = _ac_render_item_hover_settings($title_color);
  $icon_color = _ac_render_item_hover_settings($icon_color);
  $price_color = _ac_render_item_hover_settings($price_color);
  $header_color = _ac_render_item_hover_settings($header_color);
  $content_color = _ac_render_item_hover_settings($content_color);
  $button_color = _ac_render_item_hover_settings($button_color);
  // $footer_color = _ac_render_item_hover_settings($footer_color);
  $box_model = _ac_render_item_box_model_settings($box_model);
  $attributes = _ac_render_item_attributes_settings($attributes);
  $animations = _ac_render_item_animations_settings($animations);
  $responsive = _ac_render_item_responsive_settings($responsive);

  if ($responsive)
    $vars['classes_array'][] = $responsive;
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  if (!empty($attributes))
    $vars['attributes_array']['data-animation'] = $animations;

  $style = render_css($node_style, array($content_color['normal'], $box_model));
  if ($settings['EnableBorder'] != ''){
    $style .="$node_style {border-color: $settings[BorderColor]}";
  }

  $style .="$node_style {border-radius: $settings[BorderRadius]; -webkit-border-radius: $settings[BorderRadius]; -moz-border-radius: $settings[BorderRadius];}";
 
  if ($settings['enableBorderHeader'] != ''){
    $style .="$node_style .pricing-head {border-color: $settings[borderHeaderColor]}";
  }
  $style .= render_css($node_style . ' .pricing-head', array($header_color['normal']));
  $style .= render_css($node_style . ' .pricing-head i', array($icon_color['normal']));
  $style .= render_css($node_style . ' .pricing-heading', array($font_settings, $title_color['normal']));
  $style .= render_css($node_style . ' .price h3', array($pice_font_settings,$price_color['normal']));
  $style .= render_css($node_style . ' .sign-up a', array($button_color['normal']));
  $style .= render_css($node_style . ' .sign-up a:hover', array($button_color['hover']));
  if ($settings['ButtonBorderColor'] != ''){
    $style .="$node_style .sign-up a.button-line{border-color: $settings[ButtonBorderColor]}";
  }
  // $style .= render_css($node_style . ' .pricing-table-footer', array($footer_color['normal']));

  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}


/**
 * Implements hook_preprocess_awe_progress()
 */
function md_ac_hosoren_preprocess_awe_progress(&$vars) {
  $settings = $vars['settings'];

  $bar_color = array(
    'color' => $settings['color']
  );
  $progress_color = array(
    'background' => $settings['bgcolor']
  );

  
  $bar_color = _ac_render_item_hover_settings($bar_color);
  $progress_color = _ac_render_item_hover_settings($progress_color);

  /* Setting basic*/
  $counters_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $counters_id;
  $vars['classes_array'] = array('awe-item', 'awe-progress', $vars['class_random']);
  $progress_class = $settings['customClass'];

  $node_style = _ac_render_item_id_tag($counters_id, $progress_class, $vars['class_random']);
  if ($node_style['isChange']) {
    $progress_class = $node_style['isChange'];
    if ($progress_class != $vars['class_random'])
      $vars['classes_array'][] = $progress_class;
  }
  $node_style = $node_style['result'];

  /* Setting */
  $box_model = $settings['boxModelSettings'];
  $attributes = array(
    'enable' => $settings['customEnableAttributes'],
    'attributes' => $settings['customDataAttributes']
  );
  $animations = array(
    'enable' => $settings['customEnableAnimations'],
    'animations' => $settings['customDataAnimations']
  );
  $responsive = array(
    'lgResponsive' => $settings['lgResponsive'],
    'xsResponsive' => $settings['xsResponsive'],
    'mediumResponsive' => $settings['mediumResponsive'],
    'smResponsive' => $settings['smResponsive']
  );
  $box_model = _ac_render_item_box_model_settings($box_model);
  $attributes = _ac_render_item_attributes_settings($attributes);
  $animations = _ac_render_item_animations_settings($animations);
  $responsive = _ac_render_item_responsive_settings($responsive);
  if ($responsive)
    $vars['classes_array'][] = $responsive;
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  if (!empty($attributes))
    $vars['attributes_array']['data-animation'] = $animations;

  $style = render_css($node_style, array($progress_color['normal'], $box_model));
  $style .= render_css($node_style . '.progress .progress-bar span', array($bar_color['normal']));
  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}


/**
 * Implement hook_preprocess_awe_use()
 */
function md_ac_hosoren_preprocess_awe_user(&$vars) {
  $settings = $vars['settings'];

  $vars['src_img'] = 'http://placehold.it/165x165';
  if ($settings['fid'] != -1){
    $file = file_load($settings['fid']);
    if (isset($file->uri)){
      $src_img = $settings['styleImage'] != 'none'
        ? image_style_url($settings['styleImage'], $file->uri)
        : file_create_url($file->uri);
      $vars['src_img'] = $src_img;
    }
  }

  /* Chose icon */
  if ($settings['listsocial'] != '') {
    $vars['list_more_socials'] = drupal_json_decode($settings['listsocial']);
  }

  $color_name = array(
    'color' => $settings['NameColor'],
  );
  $color_settings = array(
    'color' => $settings['textColor'],
  );
  $color_background_settings = array(
    'color' => $settings['textColor'],
    'background' => $settings['backgroundcolor']
  );

  /* Setting basic*/
  $vars['classes_array'] = array('awe-item', 'awe-user', 'awe-media', $vars['class_random']);
  $user_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $user_id;
  $user_class = $settings['customClass'];

  $node_style = _ac_render_item_id_tag($user_id, $user_class, $vars['class_random']);
  if ($node_style['isChange']) {
    $user_class = $node_style['isChange'];
    if ($user_class != $vars['class_random'])
      $vars['classes_array'][] = $user_class;

  }
  $node_style = $node_style['result'];

  /* Setting */
  $box_model = $settings['boxModelSettings'];
  $attributes = array(
    'enable' => $settings['customEnableAttributes'],
    'attributes' => $settings['customDataAttributes']
  );
  $animations = array(
    'enable' => $settings['customEnableAnimations'],
    'animations' => $settings['customDataAnimations']
  );
  $responsive = array(
    'lgResponsive' => $settings['lgResponsive'],
    'xsResponsive' => $settings['xsResponsive'],
    'mediumResponsive' => $settings['mediumResponsive'],
    'smResponsive' => $settings['smResponsive']
  );
  // process data
  $box_model = _ac_render_item_box_model_settings($box_model);
  $attributes = _ac_render_item_attributes_settings($attributes);
  $animations = _ac_render_item_animations_settings($animations);
  $responsive = _ac_render_item_responsive_settings($responsive);

  $color_name = _ac_render_item_hover_settings($color_name);
  $color_settings = _ac_render_item_hover_settings($color_settings);
  $color_background_settings = _ac_render_item_hover_settings($color_background_settings);
  if ($responsive != '')
    $vars['classes_array'][] = $responsive;
  // set value for variable

  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';

  $style = render_css($node_style, array($color_background_settings['normal'], $box_model));
  $style .= render_css($node_style." p", array($color_settings['normal']));
  $style .= render_css($node_style." h4.team-name", array($color_name['normal']));
  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}



/**
 * @param $vars
 */
function md_ac_hosoren_preprocess_awe_service(&$vars) {
  $settings = $vars['settings'];

  // CSS
  $font_settings = array(
    'fontFamily' => $settings['titlefontFamily'],
    'fontStyle' => $settings['titlefontStyle'],
    'fontSize' => $settings['titlefontSize'],
    'unit' => 'px'
  );
  $font_settings = _ac_render_item_font_settings($font_settings);
  $title_color = array(
    'color' => $settings['TitleColor'],
    'hoverColor' => $settings['TitleColorHover'],
  );
  $title_color = _ac_render_item_hover_settings($title_color);

  // Icon Color  
  $icon_color = array(
    'color' => $settings['IconColor'],
    'hoverColor' => $settings['IconColorHover'],
  );
  $icon_color = _ac_render_item_hover_settings($icon_color);

  // Text Color
  $color_settings = array(
    'color' => $settings['DetailColor'],
  );
  $color_settings = _ac_render_item_hover_settings($color_settings);

  $service_setting = array(
    'color' => $settings['DetailColor'],
    'background' => $settings['DetailBackground']
  );
  $service_setting = _ac_render_item_hover_settings($service_setting);


  // This Class
  $IconBox_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $IconBox_id;
  $vars['classes_array'] = array('awe-item', $vars['class_random']);
  $IconBox_class = $settings['customClass'];

  $node_style = _ac_render_item_id_tag($IconBox_id, $IconBox_class, $vars['class_random']);
  if ($node_style['isChange']) {
    $IconBox_class = $node_style['isChange'];
    if ($IconBox_class != $vars['class_random'])
      $vars['classes_array'][] = $IconBox_class;
  }
  $node_style = $node_style['result'];


  /* Setting basic*/
  $box_model = $settings['boxModelSettings'];
  $attributes = array(
    'enable' => $settings['customEnableAttributes'],
    'attributes' => $settings['customDataAttributes']
  );
  $animations = array(
    'enable' => $settings['customEnableAnimations'],
    'animations' => $settings['customDataAnimations']
  );
  $responsive = array(
    'lgResponsive' => $settings['lgResponsive'],
    'xsResponsive' => $settings['xsResponsive'],
    'mediumResponsive' => $settings['mediumResponsive'],
    'smResponsive' => $settings['smResponsive']
  );
  // process data
  $box_model = _ac_render_item_box_model_settings($box_model);
  $attributes = _ac_render_item_attributes_settings($attributes);
  $animations = _ac_render_item_animations_settings($animations);
  $responsive = _ac_render_item_responsive_settings($responsive);
  $IconBox_class .= $responsive;

  // set value for variable
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';


  $style = render_css($node_style, array($service_setting['normal'],$box_model));
  $style .= render_css($node_style." h3", array($font_settings, $title_color['normal']));
  $style .= render_css($node_style." p", array($color_settings['normal']));
  $style .= render_css($node_style." i", array($icon_color['normal']));
  $style .= render_css($node_style . ':hover i', array($icon_color['hover']));
  $style .= render_css($node_style . ':hover h3', array($title_color['hover']));

  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}



/**
 * @param $vars
 */
function md_ac_hosoren_preprocess_awe_counters(&$vars) {
  $settings = $vars['settings'];
  $tagname = $settings['Tag_Name'];
  $vars['tagname'] = $tagname;

  // icon
  $IconColor = array(
    'color' => $settings['IconColor'],
  );
  $IconColor = _ac_render_item_hover_settings($IconColor);

  // title
  $font_settings = array(
    'fontFamily' => $settings['titlefontFamily'],
    'fontStyle' => $settings['titlefontStyle'],
    'fontSize' => $settings['titlefontSize'],
    'unit' => 'px'
  );
  $font_settings = _ac_render_item_font_settings($font_settings);
  $title_color = array(
    'color' => $settings['titleColor'],
  );
  $title_color = _ac_render_item_hover_settings($title_color);

  // number
  $NumberColor = array(
    'color' => $settings['NumberColor'],
  );
  $NumberColor = _ac_render_item_hover_settings($NumberColor);


  /* Setting basic*/
  $counters_id = $settings['customID'] != '' ? drupal_html_id($settings['customID']) : FALSE;
  $vars['id'] = $counters_id;
  $vars['classes_array'] = array('awe-item', 'awe-counters', $vars['class_random']);
  $counters_class = $settings['customClass'];

  $node_style = _ac_render_item_id_tag($counters_id, $counters_class, $vars['class_random']);
  if ($node_style['isChange']) {
    $counters_class = $node_style['isChange'];
    if ($counters_class != $vars['class_random'])
      $vars['classes_array'][] = $counters_class;
  }
  $node_style = $node_style['result'];

  $bgcolor_settings = array(
    'color' => $settings['color'],
    'background' => $settings['background_color'],    
    'hoverColor' => $settings['hovercolor'],
    'hoverBackground' => $settings['hoverbackground_color'],
  );
  $box_model = $settings['boxModelSettings'];
  $attributes = array(
    'enable' => $settings['customEnableAttributes'],
    'attributes' => $settings['customDataAttributes']
  );
  $animations = array(
    'enable' => $settings['customEnableAnimations'],
    'animations' => $settings['customDataAnimations']
  );
  $responsive = array(
    'lgResponsive' => $settings['lgResponsive'],
    'xsResponsive' => $settings['xsResponsive'],
    'mediumResponsive' => $settings['mediumResponsive'],
    'smResponsive' => $settings['smResponsive']
  );
  // process data
  $bgcolor_settings = _ac_render_item_hover_settings($bgcolor_settings);
  $box_model = _ac_render_item_box_model_settings($box_model);
  $attributes = _ac_render_item_attributes_settings($attributes);
  $animations = _ac_render_item_animations_settings($animations);
  $responsive = _ac_render_item_responsive_settings($responsive);
  if ($responsive != '') {
    $vars['classes_array'][] = $responsive;
  }


  // set value for variable
  $vars['attributes_array'] = array_merge($vars['attributes_array'], $attributes);
  $animations !== '' ? $vars['attributes_array']['data-animation'] = $animations : '';

  $style = render_css($node_style, array($bgcolor_settings['normal'], $box_model));
  $style .= render_css($node_style . ':hover', array($bgcolor_settings['hover']));
  $style .= render_css($node_style." .counters-title", array($font_settings, $title_color['normal']));
  $style .= render_css($node_style." .counters-icon", array($IconColor['normal']));
  $style .= render_css($node_style." .counter", array($NumberColor['normal']));
  drupal_add_css( $style, array('type' => 'inline', 'group' => CSS_THEME));
}