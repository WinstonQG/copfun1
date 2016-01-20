<?php

/**
 * @file
 * Theme settings .
 */
function md_hosoren_theme_settings_pages(&$form, &$form_state) {
  $form['md_hosoren_settings']['pages'] = array(
    '#type' => 'fieldset',
    '#weight' => -2,
    '#prefix' => '<div id="md-pages" class="md-tabcontent clearfix">',
    '#suffix' => '</div><!-- / #md-pages -->',
  );

  $form['md_hosoren_settings']['pages']['pages_htmllist'] = array(
    '#markup' => '<div id="md-content-sidebar" class="md-content-sidebar">
                        <ul class="clearfix">
                            <li><a href="#page-type"><i class="fa-refresh icon fa"></i>Page Contentype Title</a></li>
                            <li><a href="#page-url"><i class="fa-list-ul icon fa"></i>Page Title</a></li>
                        </ul>
                    </div><!-- /.md-content-sidebar -->
                    <div class="md-content-main">',
    '#weight' => -15,
  );
  $form['md_hosoren_settings']['pages']['pages_htmllistclose'] = array(
    '#markup' => '</div><!-- /.md-listleft -->',
    '#weight' => 15,
  );

  //////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////// Content Type ///////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  $form['md_hosoren_settings']['pages']['pages_type'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#title' => t('Settings Page Title for node detail'),
    '#prefix' => '<div id="page-type" class="wrap-page-settings"><div class="md-tabcontent-row">',
    '#suffix' => '    </div></div><!-- / #ds-general -->',
  );
  $types = node_type_get_types();

  $types_markup = '<div id="type-accordion" class="wrap-accordion">';

  foreach ($types as $key => $type) {
		if($type->orig_type !='simplenews' && $type->orig_type !='webform'){
      $types_markup .= '<h3>' . $type->name . '</h3>';
      $types_markup .= '<div class="page-setting"><div class="content header-bg"></div>';
      $types_markup .= '<div class="content element-invisible"><input class="header-img-url" type="hidden" name="img-url" value=""></div>';
      $types_markup .= '<div class="content"><input type="hidden" name="type" value="' . $key . '"></div>';
      $types_markup .= '<div class="content clear"><span>Title: </span> <input type="text" name="'.$key.'-title" value=""></div>';
      $types_markup .= '<div class="content"><span>Description : </span> <input type="text" name="'.$key.'-description" value=""></div>';
      $types_markup .= '<div class="margin-small"><span>Overlay: </span> <input class="form-colorpicker" type="text" name="'.$key.'-overlay" value=""></div>';
      $types_markup .= '<div class="margin-small md-selection medium"><select class="select form-select" name="sectiontype"><option value="one">Style One</option><option value="two">Style Two</option></select></div>';
      $types_markup .= '<div class="margin-small md-selection medium"><select class="select form-select" name="backgroundtype"><option value="background">Background</option><option value="parallax">Parallax</option></select></div></div>';
		}
  }
  $types_markup .= '</div>';
  $form['md_hosoren_settings']['pages']['pages_type']['wrap'] = array(
    '#type' => 'markup',
    '#markup' => $types_markup,
    '#prefix' => '<div class="form-group">',
    '#suffix' => '</div>',
  );



  $form['md_hosoren_settings']['pages']['pages_type']['type_data'] = array(
    '#type' => 'hidden',
    '#attributes' => array(
      'class' => array('page-data'),
    ),
    '#default_value' => theme_get_setting('type_data') ? theme_get_setting('type_data') : ''
  );

  //////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////// Page Url ///////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  $form['md_hosoren_settings']['pages']['pages_url'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#title' => t('Settings Page Title for Url'),
    '#prefix' => '<div id="page-url" class="wrap-page-settings"><div class="md-tabcontent-row">',
    '#suffix' => '    </div></div><!-- / #ds-general -->',
  );
  $title_template = '<h3>Page Title: @title</h3>';
  $title_template .= '<div class="page-setting"><div class="content header-bg"></div>';
  $title_template .= '<div class="content element-invisible"><input class="header-img-url"  type="text" name="img-url" value="@imgurl"></div>';
  $title_template .= '<div class="content clear"><span>Page Url: </span> <input type="text" name="page-url" value="@url"></div>';
  $title_template .= '<div class="content"><span>Page Title: </span> <input type="text" name="title" value="@title"></div>';
  $title_template .= '<div class="content"><span>Description : </span> <input type="text" name="description" value="@description"></div>';
  $title_template .= '<div class="margin-small"><span>Color 1: </span> <input class="form-colorpicker" type="text" name="colorone" value="@colorone"></div>';
  $title_template .= '<div class="margin-small"><span>Color 2: </span> <input class="form-colorpicker" type="text" name="colorsecond" value="@colorsecond"></div>';
  $title_template .= '<div class="margin-small"><span>Overlay: </span> <input class="form-colorpicker" type="text" name="overlay" value="@overlay"></div>';
  $title_template .= '<div class="margin-small md-selection medium"><select class="select form-select" name="sectiontype"><option value="one">Style One</option><option value="two">Style Two</option></select></div>';
  $title_template .= '<div class="margin-small md-selection medium"><select class="select form-select" name="backgroundtype"><option value="background">Background</option><option value="parallax">Parallax</option></select></div></div>';

  if (!theme_get_setting('title_data')) {
    $title_markup = format_string($title_template, array('@title' => '', '@url' => '', '@title' => '', '@imgurl' => '', '@description' => '', '@colorone' => '', '@colorsecond' => '', '@overlay' => ''));
  }
  else {
    $title_data = drupal_json_decode(theme_get_setting('title_data'));
    $title_markup = '';
    $title_data = array_chunk($title_data, 9);
    foreach ($title_data as $key => $data) {
      if ($key == 0){
        $title_markup .= format_string($title_template, array(
          '@title' => $data[2]['value'],
          '@imgurl' => $data[0]['value'],
          '@url' => $data[1]['value'],
          '@title' => $data[2]['value'],
          '@description' => $data[3]['value'],
          '@colorone' => $data[4]['value'],
          '@colorsecond' => $data[5]['value'],
          '@overlay' => $data[6]['value'],
          )
        );
      }
      elseif ( $data[1]['value'] != '') {
        $title_markup .= format_string($title_template, array(
            '@title' => $data[2]['value'],
            '@imgurl' => $data[0]['value'],
            '@url' => $data[1]['value'],
            '@title' => $data[2]['value'],
            '@description' => $data[3]['value'],
            '@colorone' => $data[4]['value'],
            '@colorsecond' => $data[5]['value'],
            '@overlay' => $data[6]['value'],
          )
        );
      }

    }

  }
  $button_control = '<div class="control"><a class="add-page" href="#">'. t('Add Page Title') .'</a></div>';
  $form['md_hosoren_settings']['pages']['pages_url']['wrap'] = array(
    '#type' => 'markup',
    '#markup' => $button_control .'<div id="url-accordion" class="wrap-accordion">' . $title_markup . '</div>',
    '#prefix' => '<div class="form-group">',
    '#suffix' => '</div>',
  );

  $form['md_hosoren_settings']['pages']['pages_url']['title_data'] = array(
    '#type' => 'hidden',
    '#attributes' => array(
      'class' => array('page-data'),
    ),
    '#default_value' => theme_get_setting('title_data') ? theme_get_setting('title_data') : ''
  ) ;

}