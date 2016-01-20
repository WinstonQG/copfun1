<?php

/**
 * @file
 * Theme settings .
 */
function md_hosoren_theme_settings_design(&$form, &$form_state) {
  global $base_url;
  $theme_default = variable_get('theme_default');

  $form['md_hosoren_settings']['design'] = array(
    '#type' => 'fieldset',
    '#weight' => -4,
    '#prefix' => '<div id="md-design" class="md-tabcontent clearfix">',
    '#suffix' => '</div><!-- / #md-design -->',
  );

  $form['md_hosoren_settings']['design']['design_htmllist'] = array(
    '#markup' => '<div id="md-content-sidebar" class="md-content-sidebar">
                        <ul class="clearfix">
                            <li><a href="#ds-preloader"><i class="fa-refresh icon fa"></i>Preloader</a></li>
                            <li><a href="#ds-header"><i class="fa-list-ul icon fa"></i>Header</a></li>
                            <li><a href="#ds-blog"><i class="fa-list-ul icon fa"></i>Blog</a></li>
                            <li><a href="#ds-footer"><i class="fa-list-ul icon fa"></i>Footer Setting</a></li>
                            <li><a href="#ds-portfolio"><i class="fa-list-ul icon fa"></i>Portfolio</a></li>
                            <li><a href="#ds-maintenance"><i class="fa-list-ul icon fa"></i>Under Maintenance</a></li>
                            <li><a href="#ds-not-found"><i class="fa-list-ul icon fa"></i>404</a></li>
                        </ul>
                    </div><!-- /.md-content-sidebar -->
                    <div class="md-content-main">',
    '#weight' => -15,
  );
  $form['md_hosoren_settings']['design']['design_htmllistclose'] = array(
    '#markup' => '</div><!-- /.md-listleft -->',
    '#weight' => 15,
  );
  //////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////// Preloader //////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  $form['md_hosoren_settings']['design']['ds_preloader'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#prefix' => '<div id="ds-preloader"><div class="md-tabcontent-row">',
    '#suffix' => '    </div></div><!-- / #ds-general -->',
  );
  $form['md_hosoren_settings']['design']['ds_preloader']['preload'] = array(
    '#type' => 'checkbox',
    '#field_suffix' => '<label class="label-checkbox" for="edit-preload' . '">' . t('Enable Preload') . '</label>',
    '#attributes' => array(
      'class' => array('input-checkbox')
    ),
    '#prefix' => '<div class="form-group">',
    '#suffix' => '</div>',
    '#default_value' => theme_get_setting('preload'),
  );
	/* Picture loading */
  $form['md_hosoren_settings']['design']['ds_preloader']['preload_loading'] = array(
      '#type' => 'hidden',
			'#prefix' => '<div class="wrap-form-media"><h3>Preload loading</h3><div class="media-preview"></div>',
			'#suffix' => '<div class="media-control"><a href="#" class="media-change md-button">Change</a><a href="#" class="media-delete md-button gray">Delete</a></div></div>',
			'#attributes' => array(
				'class' => array('input-fid')
			),
			'#default_value' => theme_get_setting('preload_loading'),
    );
  /////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////// header //////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////
  $form['md_hosoren_settings']['design']['ds_header'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#prefix' => '<div id="ds-header"><div class="md-tabcontent-row">',
    '#suffix' => '</div></div><!-- / #ds-general -->',
  );

  $form['md_hosoren_settings']['design']['ds_header']['header_setting'] = array(
    '#prefix' => '<h3 class="md-tabcontent-title">Setting header</h3><div class="form-group" style="margin-bottom: 0">',
    '#suffix' => '</div>',
  );

  // select header type
  $form['md_hosoren_settings']['design']['ds_header']['header_setting']['header_type'] = array(
    '#type' => 'select',
    '#title' => t('Choose header type'),
    '#default_value' => theme_get_setting('header_type'),
    '#options' => array(
      '0' => t('Default'),
      '1' => t('Header One'),
      '2' => t('Header Two'),
      '3' => t('Header Three'),
      '4' => t('Header Four'),
    ),
    '#attributes' => array(
      'class' => array('select')
    ),
    '#field_prefix' => '<div class="md-selection medium">',
    '#field_suffix' => '</div>'
  );

  /////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////// Blog //////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////
  $form['md_hosoren_settings']['design']['ds_blog'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#prefix' => '<div id="ds-blog"><div class="md-tabcontent-row">',
    '#suffix' => '</div></div><!-- / #ds-general -->',
  );

  $form['md_hosoren_settings']['design']['ds_blog']['blog_setting'] = array(
    '#prefix' => '<h3 class="md-tabcontent-title">Blog Type</h3><div class="form-group" style="margin-bottom: 0">',
  );



  // Blog Settings Single type
  $form['md_hosoren_settings']['design']['ds_blog']['blog_setting']['blog_single_type'] = array(
    '#type' => 'select',
    '#title' => t('Choose blog single type'),
    '#default_value' => theme_get_setting('blog_single_type'),
    '#options' => array(
      'nobar' => t('Single nobar'),
      'left' => t('Single left'),
      'right' => t('Single right'),
    ),
    '#attributes' => array(
      'class' => array('select')
    ),
    '#field_prefix' => '<div class="md-selection medium">',
    '#field_suffix' => '</div>'
  );

  // Blog Taxonomy
  $form['md_hosoren_settings']['design']['ds_blog']['blog_setting']['blog_taxonomy_option'] = array(
    '#type' => 'select',
    '#title' => t('Choose Blog Category & Blog Type'),
    '#default_value' => theme_get_setting('blog_taxonomy_option'),
    '#options' => array(
      'nobar' => t('Taxonomy nobar'),
      'left' => t('Taxonomy left'),
      'right' => t('Taxonomy right'),
    ),
    '#attributes' => array(
      'class' => array('select')
    ),
    '#field_prefix' => '<div class="md-selection medium">',
    '#field_suffix' => '</div>'
  );

  // Blog Settings List type
  $form['md_hosoren_settings']['design']['ds_blog']['blog_setting']['blog_list_option'] = array(
    '#type' => 'select',
    '#title' => t('Choose blog list type'),
    '#default_value' => theme_get_setting('blog_list_option'),
    '#options' => array(
      'nobar' => t('Blog list nobar'),
      'left' => t('Blog list left'),
      'right' => t('Blog list right'),
    ),
    '#attributes' => array(
      'class' => array('select')
    ),
    '#field_prefix' => '<div class="md-selection medium">',
    '#field_suffix' => '</div>'
  );

  /////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////// Footer Setting ///////////////////////////
  /////////////////////////////////////////////////////////////////////////////

  drupal_add_css('//code.jquery.com/ui/1.11.4/themes/smoothness/jquery-ui.css');

  drupal_add_css(drupal_get_path('theme', 'md_hosoren') . '/theme_setting/admin/css/footer.css');
  drupal_add_js(drupal_get_path('theme', 'md_hosoren') . '/theme_setting/admin/js/jquery-ui.js');


  $form['md_hosoren_settings']['design']['ds_footer'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#prefix' => '<div id="ds-footer"><div class="md-tabcontent-row">',
    '#suffix' => '</div></div><!-- / #ds-general -->',
  );


  $form['md_hosoren_settings']['design']['ds_footer']['footer_setting'] = array(
    '#prefix' => '<h3 class="md-tabcontent-title">Footer Setting</h3><div class="form-group" style="margin-bottom: 0">',
  );

//  $set_footer_bootstrap = theme_get_setting('regiondata');
//  $setfooter =  trim($set_footer_bootstrap, ']');
//  $value_footer = trim( $setfooter , '[');
//  $footer_arr = explode(",",$value_footer);
//   dsm($variables);
  
  $form['md_hosoren_settings']['design']['ds_footer']['footer_setting']['choose_collumn_footer'] = array(
    '#type' => 'select',
    '#label' => 'Choose Number region footer',
    '#title' => t('Choose Collumn of footer'),
    '#default_value' => theme_get_setting('choose_collumn_footer'),
    '#options' => array(
      '1' => t('4 region'),
      '2' => t('3 region'),
      '3' => t('2 Region'),
      '4' => t('1 Region'),
    ),
    '#attributes' => array(
      'id' => 'select-collumn',
    ),
    '#field_prefix' => '<div class="setting-footer" >',
    '#field_suffix' => '</div>'
  );
    $markup = '
        <div class="awe-region-full">
        <div class="wrap-region">
        </div>
        </div>';

  $form['md_hosoren_settings']['design']['ds_footer']['footer_setting']['footermarkup'] = array(
    '#type' => 'markup',
    '#markup' => '<div class="setting-footer">' . $markup . '</div>',
  );
  $form['md_hosoren_settings']['design']['ds_footer']['footer_setting']['regiondata'] = array(
    '#type' => 'hidden',
    '#attributes' => array(
      'id' => 'region-data',
      'class' => array('setting-footer'),
    ),
    '#name' => 'regiondata',
    '#default_value' => theme_get_setting('regiondata'),
  );

  drupal_add_js(drupal_get_path('theme', 'md_hosoren') . '/theme_setting/admin/js/footer.js');



  // Footer Settings Region 1
//  $form['md_hosoren_settings']['design']['ds_footer']['footer_setting']['footer_region_1'] = array(
//    '#type' => 'select',
//    '#title' => t('Choose Footer Region 1 Style'),
//    '#default_value' => theme_get_setting('footer_region_1'),
//    '#options' => array(
//      'none' => t('Display: None'),
//      'col12' => t('Columns 12'),
//      'col6' => t('Columns 6'),
//      'col4' => t('Columns 4'),
//      'col3' => t('Columns 3'),
//      'col2' => t('Columns 2'),
//      'col1' => t('Columns 1'),
//    ),
//    '#attributes' => array(
//      'class' => array('select')
//    ),
//    '#field_prefix' => '<div class="md-selection medium">',
//    '#field_suffix' => '</div>'
//  );
  // Footer Settings Region 2
//  $form['md_hosoren_settings']['design']['ds_footer']['footer_setting']['footer_region_2'] = array(
//    '#type' => 'select',
//    '#title' => t('Choose Footer Region 2 Style'),
//    '#default_value' => theme_get_setting('footer_region_2'),
//    '#options' => array(
//      'none' => t('Display: None'),
//      'col12' => t('Columns 12'),
//      'col6' => t('Columns 6'),
//      'col4' => t('Columns 4'),
//      'col3' => t('Columns 3'),
//      'col2' => t('Columns 2'),
//      'col1' => t('Columns 1'),
//    ),
//    '#attributes' => array(
//      'class' => array('select')
//    ),
//    '#field_prefix' => '<div class="md-selection medium">',
//    '#field_suffix' => '</div>'
//  );
  // Footer Settings Region 3
//  $form['md_hosoren_settings']['design']['ds_footer']['footer_setting']['footer_region_3'] = array(
//    '#type' => 'select',
//    '#title' => t('Choose Footer Region 3 Style'),
//    '#default_value' => theme_get_setting('footer_region_3'),
//    '#options' => array(
//      'none' => t('Display: None'),
//      'col12' => t('Columns 12'),
//      'col6' => t('Columns 6'),
//      'col4' => t('Columns 4'),
//      'col3' => t('Columns 3'),
//      'col2' => t('Columns 2'),
//      'col1' => t('Columns 1'),
//    ),
//    '#attributes' => array(
//      'class' => array('select')
//    ),
//    '#field_prefix' => '<div class="md-selection medium">',
//    '#field_suffix' => '</div>'
//  );
  // Footer Settings Region 4
//  $form['md_hosoren_settings']['design']['ds_footer']['footer_setting']['footer_region_4'] = array(
//    '#type' => 'select',
//    '#title' => t('Choose Footer Region 4 Style'),
//    '#default_value' => theme_get_setting('footer_region_4'),
//    '#options' => array(
//      'none' => t('Display: None'),
//      'col12' => t('Columns 12'),
//      'col6' => t('Columns 6'),
//      'col4' => t('Columns 4'),
//      'col3' => t('Columns 3'),
//      'col2' => t('Columns 2'),
//      'col1' => t('Columns 1'),
//    ),
//    '#attributes' => array(
//      'class' => array('select')
//    ),
//    '#field_prefix' => '<div class="md-selection medium">',
//    '#field_suffix' => '</div>'
//  );
//  
  //////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////// Portfolio //////////////////////
  //////////////////////////////////////////////////////////////////////////////
  $form['md_hosoren_settings']['design']['ds_portfolio'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#prefix' => '<div id="ds-portfolio"><div class="md-tabcontent-row">',
    '#suffix' => '    </div></div><!-- / #ds-general -->',
  );
  // Background Title setting
  $form['md_hosoren_settings']['design']['ds_portfolio']['portfolio_setting'] = array(
    '#type' => 'fieldset',
    '#weight' => 3,
    '#prefix' => '<h3 class="md-tabcontent-title">Background Single Portfolio</h3>',
    '#collapsible' => TRUE
  );

  $form['md_hosoren_settings']['design']['ds_portfolio']['portfolio_setting']['portfolio_main_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Portfolio Page : Path'),
    '#description' => t('Insert the path for <b>Back to Portfolio</b> button of every portfolio detail page. As default, click on  <b>Back to Portfolio</b> button leads you to portfolio list page'),
    '#default_value' => theme_get_setting('portfolio_main_url'),
    '#attributes' => array(
      'class' => array('input-border big')
    ),
    '#prefix' => '<div class="form-group">',
    '#suffix' => '</div>',
  );

  //////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////// Page Maintenance //////////////////////
  //////////////////////////////////////////////////////////////////////////////
  $form['md_hosoren_settings']['design']['ds_maintenance'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#prefix' => '<div id="ds-maintenance"><div class="md-tabcontent-row">',
    '#suffix' => '    </div></div><!-- / #ds-general -->',
  );
  $form['md_hosoren_settings']['design']['ds_maintenance']['maintenance_logo'] = array(
    '#type' => 'hidden',
    '#prefix' => '<div class="wrap-form-media"><h3>Maintenance Logo</h3><div class="media-preview"></div>',
    '#suffix' => '<div class="media-control"><a href="#" class="media-change md-button">Change</a><a href="#" class="media-delete md-button gray">Delete</a></div></div>',
    '#attributes' => array(
      'class' => array('input-fid')
    ),
    '#default_value' => theme_get_setting('maintenance_logo'),
  );
  $form['md_hosoren_settings']['design']['ds_maintenance']['maintenance_picture'] = array(
    '#type' => 'hidden',
    '#prefix' => '<div class="wrap-form-media"><h3>Background</h3><div class="media-preview"></div>',
    '#suffix' => '<div class="media-control"><a href="#" class="media-change md-button">Change</a><a href="#" class="media-delete md-button">Delete</a></div></div>',
    '#attributes' => array(
      'class' => array('input-fid')
    ),
    '#default_value' => theme_get_setting('maintenance_picture'),
  );
  $form['md_hosoren_settings']['design']['ds_maintenance']['maintenance_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => theme_get_setting('maintenance_title'),
    '#attributes' => array(
      'class' => array('input-border big')
    ),
    '#prefix' => '<div class="form-group">',
    '#suffix' => '</div>',
  );
  $form['md_hosoren_settings']['design']['ds_maintenance']['maintenance_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#resizable' => FALSE,
    '#rows' => 2,
    '#default_value' => theme_get_setting('maintenance_description'),
    '#attributes' => array(
      'class' => array('input-border')
    )
  );
  $form['md_hosoren_settings']['design']['ds_maintenance']['maintenance_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Comming Soon'),
    '#default_value' => theme_get_setting('maintenance_time'),
    '#description' => t('example: 2020/10/24'),
    '#attributes' => array('class' => array('date-picker-form')),
  );
  //////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////// Page 404 //////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  $form['md_hosoren_settings']['design']['ds_notfound'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#prefix' => '<div id="ds-not-found"><div class="md-tabcontent-row">',
    '#suffix' => '    </div></div><!-- / #ds-general -->',
  );
  $form['md_hosoren_settings']['design']['ds_notfound']['not_found_title_big'] = array(
    '#type' => 'textfield',
    '#title' => t('Big Title'),
    '#description' => t('Big Title on 404 page - Default : 404'),
    '#default_value' => theme_get_setting('not_found_title_big'),
    '#attributes' => array(
      'class' => array('input-border big')
    ),
    '#prefix' => '<div class="form-group">',
    '#suffix' => '</div>',
  );
  $form['md_hosoren_settings']['design']['ds_notfound']['not_found_title_mini'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Mini Title on 404 page - Default : Page'),
    '#default_value' => theme_get_setting('not_found_title_mini'),
    '#attributes' => array(
      'class' => array('input-border big')
    ),
    '#prefix' => '<div class="form-group">',
    '#suffix' => '</div>',
  );
  $form['md_hosoren_settings']['design']['ds_notfound']['not_found_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Medium Title'),
    '#description' => t('Medium Title on 404 page - Default : The product not found'),
    '#default_value' => theme_get_setting('not_found_title'),
    '#attributes' => array(
      'class' => array('input-border big')
    ),
    '#prefix' => '<div class="form-group">',
    '#suffix' => '</div>',
  );
  $form['md_hosoren_settings']['design']['ds_notfound']['not_found_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Content'),
    '#resizable' => FALSE,
    '#rows' => 5,
    '#default_value' => theme_get_setting('not_found_body'),
    '#description' => t('The following text will be added in page 404.'),
    '#attributes' => array(
      'class' => array('input-border')
    )
  );
  $form['md_hosoren_settings']['design']['ds_notfound']['background_page404_image'] = array(
    '#type' => 'hidden',
    '#prefix' => '<div class="wrap-form-media"><h3>Background 404 page</h3><div class="media-preview"></div>',
    '#suffix' => '<div class="media-control"><a href="#" class="media-change md-button">Change</a><a href="#" class="media-delete md-button gray">Delete</a></div></div>',
    '#attributes' => array(
      'class' => array('input-fid')
    ),
    '#default_value' => theme_get_setting('background_page404_image'),
  );
}
