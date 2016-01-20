<?php

/**
 * Implements hook_preprocess_page().
 */
function md_hosoren_preprocess_page(&$vars, $hook) {
  global $base_url;
  $args = arg();
  $node_type = menu_get_object();
  if(isset($args[2]) && $args[0] == 'taxonomy'){
    $taxonomy =  taxonomy_term_load($args[2]);
  }

  // Hide title front, type 
  if ($vars['is_front']) {
    $vars['title'] = '';
  }

  if ($args[0] == 'taxonomy' && $args[1] == 'term' && is_numeric($args[2])) {
    $vars['page']['content']['system_main']['nodes']['#prefix'] = '<div class="list_teaser clearfix">';
    $vars['page']['content']['system_main']['nodes']['#suffix'] = '</div>';
  }

  if ($args[0] == 'comment' && $args[1] == 'reply') {
    $node = node_load($args[2]);
    $vars['theme_hook_suggestions'][] = 'page__comment__reply__type__' . $node->type;
  }

  //Hook suggestion
  if (isset($vars['node'])) {
    $vars['theme_hook_suggestions'][] = 'page__node__type__' . $vars['node']->type;
  }
  
  if(isset($taxonomy)){
    if($taxonomy->vocabulary_machine_name == 'categories_blog'){
      $vars['theme_hook_suggestions'][] = 'page__category__blog';
    }
  }

  if(isset($taxonomy)){
    if($taxonomy->vocabulary_machine_name == 'tags_blog'){
      $vars['theme_hook_suggestions'][] = 'page__tags__blog';
    }
  }

  if ($args[0] == 'search') {
    $vars['theme_hook_suggestions'][] = 'page__search__results';
  }
	
  $vars['menu_header_style'] = 'header-style-default';
  if(theme_get_setting('header_type') != '0'){
      $vars['menu_header_style'] = 'header-style-'.theme_get_setting('header_type');
  }


  // Theme-setting Not-found
  $vars['title_notfound_big'] = theme_get_setting('not_found_title_big') ? theme_get_setting('not_found_title_big') : '404';
  $vars['title_notfound_mini'] = theme_get_setting('not_found_title_mini') ? theme_get_setting('not_found_title_mini') : 'PAGE';
  $vars['title_notfound'] = theme_get_setting('not_found_title') ? theme_get_setting('not_found_title') : 'The product not found';
  $vars['content_notfound'] = theme_get_setting('not_found_body') ? theme_get_setting('not_found_body') : 'Please try one of the following pages ';


  // LOGO SETTINGS
	if(theme_get_setting('toggle_logo') == 1){
		if (theme_get_setting('default_logo') == 0) {
				if (module_exists('media')) {
						$file_upload = theme_get_setting('logo_normal_file_uploaded');
						if ($file_upload['fid'] != 0) {
								$file = file_load($file_upload['fid']);
								$vars['logo'] = file_create_url($file->uri);
						}
						else {
								$vars['logo'] = $base_url . '/' . $themepath . '/logo.png';
						}
				}
				else {
						if ($logo_file = theme_get_setting('logo_normal_form_file')) {
								$vars['logo'] = file_create_url(file_build_uri($logo_file));
						}
				}
		}
  }

  // Theme-Settings BLog Single
  $vars['blog_single_left'] = '';
  $vars['blog_single_right'] = '';
  $vars['blog_class'] = '';
  if (theme_get_setting('blog_single_type') == 'nobar') {
    $vars['blog_single_left'] = 'col-md-9 col-centered';
    $vars['blog_single_right'] = 'display-none';
    $vars['blog_class'] = 'blog-nobar';
  }
  elseif (theme_get_setting('blog_single_type') == 'left') {
    $vars['blog_single_left'] = 'col-md-9 col-md-push-3';
    $vars['blog_single_right'] = 'col-md-3 col-md-pull-9';
    $vars['blog_class'] = 'blog-sidebar';
  }
  else {
    $vars['blog_single_left'] = 'col-md-9';
    $vars['blog_single_right'] = 'col-md-3';
    $vars['blog_class'] = 'blog-sidebar';
  }

  // Theme-Settings BLog Category
  $vars['blog_category_left'] = '';
  $vars['blog_category_right'] = '';
  $vars['blog_class_category'] = '';
  if (theme_get_setting('blog_taxonomy_option') == 'nobar') {
    $vars['blog_category_left'] = 'col-md-9 col-centered';
    $vars['blog_category_right'] = 'display-none';
    $vars['blog_class_category'] = 'blog-nobar';
  }
  elseif (theme_get_setting('blog_taxonomy_option') == 'left') {
    $vars['blog_category_left'] = 'col-md-9 col-md-push-3';
    $vars['blog_category_right'] = 'col-md-3 col-md-pull-9';
    $vars['blog_class_category'] = 'blog-sidebar';
  }
  else {
    $vars['blog_category_left'] = 'col-md-9';
    $vars['blog_category_right'] = 'col-md-3';
    $vars['blog_class_category'] = 'blog-sidebar';
  }

  // Theme-Settings BLog list
  $vars['blog_list_left'] = '';
  $vars['blog_list_right'] = '';
  if (theme_get_setting('blog_list_option') == 'nobar') {
    $vars['blog_list_left'] = 'col-md-9 col-centered';
    $vars['blog_list_right'] = 'display-none';
  }
  elseif (theme_get_setting('blog_list_option') == 'left') {
    $vars['blog_list_left'] = 'col-md-9 col-md-push-3';
    $vars['blog_list_right'] = 'col-md-3 col-md-pull-9';
  }
  else {
    $vars['blog_list_left'] = 'col-md-9';
    $vars['blog_list_right'] = 'col-md-3';
  }

  // Theme-Settings Footer Setting
  $set_footer_bootstrap = theme_get_setting('regiondata');
  $set_footer =  trim($set_footer_bootstrap, ']');
  $set_footer = trim( $set_footer , '[');
  if($set_footer == ',,,'){
    $set_footer = '3,3,3,3';
  }
  $footer_boostrap = explode(",",$set_footer);
  $vars['footer_setting_region_1'] = 'col-md-'.$footer_boostrap[0];
  $vars['footer_setting_region_2'] = 'col-md-'.$footer_boostrap[1];
  $vars['footer_setting_region_3'] = 'col-md-'.$footer_boostrap[2];
  $vars['footer_setting_region_4'] = 'col-md-'.$footer_boostrap[3];
 
  $vars['select_collum_footer'] = theme_get_setting('choose_collumn_footer');
  

  $path_theme = drupal_get_path('theme', 'md_hosoren');

	// Region header
	$vars['has_slider'] = FALSE;
  if(isset($vars['node'])){
    if($vars ['node']->promote == 1) $vars['has_slider'] = TRUE;   
  }
	
  // PAGE TITLE STYLE
	$vars['title_des'] = '';
  $vars['section_type'] ='';
  $vars['section_background'] = '';
	$vars['section_type'] = 'default';
  $vars['header_bg'] = 'url('. $base_url.'/'.$path_theme.'/images/heading-about-us.jpg)';
	
  $style_css_default = '';

  if (isset($vars['node'])) {
    $node_type = $vars['node']->type;
    $type_data = theme_get_setting('type_data');

    if (!empty($type_data)){
      $type_data = drupal_json_decode($type_data);
      $type_data = array_chunk($type_data, 7);

      foreach ($type_data as $key => $type) {
        if ($type[1]['value'] != NULL || $type[1]['value'] != '') {
          if ($node_type == $type[1]['value']) {
            $vars['title'] = t($type[2]['value']);
            $vars['title_des'] = t($type[3]['value']);
						if (!empty($type[0]['value'])) {
							$vars['header_bg'] = 'url(\'' . $type[0]['value']. '\')';
						}
            if ($type[1]['value'] == '<none>') {
              $vars['title'] = FALSE;
            }            

            if (!empty($type[4]['value'])) {
              $style_css_default .= ".section-header-overlay{";
              $style_css_default .= 'background: ' . $type[4]['value'] . ';';
              $style_css_default .= "}\n";
            }
            $vars['section_type'] = $type[5]['value'];

            if($type[6]['value']=='parallax'){
              $vars['section_background'] = 'background-parallax'; 
            }
						
          }
        }
      }
    }
  }	
	drupal_add_css($style_css_default, array('type' => 'inline'));
}

/**
 * @param $vars
 * Implement hook_process_page().
 */
function md_hosoren_process_page(&$vars) {
  global $base_url;
  $themepath = drupal_get_path("theme", "md_hosoren");

  // Background Page Blog
  $vars['background_title'] = '';
  if (module_exists('media')) {
    $file_upload = variable_get('background_header_title');
      if ($file_upload != 0) {
        $file = file_load($file_upload);
        $vars['background_title'] = file_create_url($file->uri);
      }else {
        $vars['background_title'] = $base_url . '/' . path_to_theme() . '/images/heading-blog.jpg';
      }
  }
  
 
  // Background Page 404 setting

  $vars['background_page404'] = '';
  if (module_exists('media')) {
    $file_upload = theme_get_setting('background_page404_image');
      if ($file_upload != 0) {
        $file = file_load($file_upload);
        $vars['background_page404'] = file_create_url($file->uri);
      }else {
        $vars['background_page404'] = $base_url . '/' . path_to_theme() . '/images/main-404.jpg';
      }
  }

 //  // PAGE TITLE STYLE
  $style_css = '';

  $current_path = current_path();
  $title_data = theme_get_setting('title_data');

  if (!empty($title_data)){
    $title_data = drupal_json_decode($title_data);
    $title_data = array_chunk($title_data, 9);
    foreach ($title_data as $key_title => $title_detail) {
      if ($title_detail[1]['value'] != '' && drupal_match_path($current_path,$title_detail[1]['value'])) {
				if (!empty($title_detail[2]['value'])) {
					$vars['title'] = t($title_detail[2]['value']);
				}
				if (!empty($title_detail[0]['value'])) {
					$vars['header_bg'] = 'url(\'' . $title_detail[0]['value']. '\')';
				}
        $vars['title_des'] = t($title_detail[3]['value']);
        if ($title_detail[2]['value'] == '<none>') {
          $vars['title'] = FALSE;
        }
        $vars['section_type'] = $title_detail[7]['value'];

        if($title_detail[8]['value']=='parallax'){
          $vars['section_background'] = 'background-parallax'; 
        }



        if (!empty($title_detail[4]['value'])) {
          $style_css .= ".main-header.background h1, .main-header p, .main-header .breadcrumb li:hover, .main-header .breadcrumb li.active{";
          $style_css .= 'color: ' . $title_detail[4]['value'] . ';';
          $style_css .= "}\n";
        }
        if (!empty($title_detail[5]['value'])) {
          $style_css .= ".main-header .breadcrumb li, .main-header .breadcrumb li:before, .main-header .breadcrumb a{";
          $style_css .= 'color: ' . $title_detail[5]['value'] . ';';
          $style_css .= "}\n";
        }
        if (!empty($title_detail[6]['value'])) {
          $style_css .= ".section-header-overlay{";
          $style_css .= 'background: ' . $title_detail[6]['value'] . ';';
          $style_css .= "}\n";
        }
				
      }
    }
	}		
	drupal_add_css($style_css, array('type' => 'inline'));

}

function md_hosoren_preprocess_maintenance_page(&$vars) {
  global $base_url;

  drupal_add_css('http://fonts.googleapis.com/css?family=Montserrat:400,700', 'external');
  drupal_add_css('http://fonts.googleapis.com/css?family=Roboto:300,400,700,400italic,700italic&amp;subset=latin,vietnamese', 'external');

  drupal_add_js(path_to_theme() . '/js/libs/bootstrap.min.js');
  drupal_add_js(path_to_theme() . '/js/libs/jquery.countdown.min.js');
  drupal_add_js(path_to_theme() . '/js/coming_soon.js');

  drupal_add_css(path_to_theme() . '/fonts/theme_font/css/awe-glyphicons-awesome.css');
  drupal_add_css(path_to_theme(). '/css/libs/bootstrap.css');
  drupal_add_css(path_to_theme() . '/css/maintenance-mode.css');


  // Logo  
  $vars['logo'] = $base_url . '/' . drupal_get_path('theme', 'md_hosoren') . '/logo.png';
  if (theme_get_setting('maintenance_logo')){
    $fid_logo_maintenance = theme_get_setting('maintenance_logo',null);
    $file = file_load($fid_logo_maintenance);
    if ($file) {
      $vars['logo'] = file_create_url($file->uri);
    }
  }
  elseif (theme_get_setting('default_logo') == 0) {
      if (module_exists('media')) {
          $file_upload = theme_get_setting('logo_normal');
          if ($file_upload != 0) {
              $file = file_load($file_upload);
              $vars['logo'] = file_create_url($file->uri);
          }
      }
      else {
          if ($logo_file = theme_get_setting('logo_normal_form_file')) {
              $vars['logo'] = file_create_url(file_build_uri($logo_file));
          }
      }
  }


  $vars['maintenance_pic'] = $base_url.'/'.path_to_theme().'/images/main-comming-soon.jpg';
  if (theme_get_setting('maintenance_picture')){
    $fid_preload_loading = theme_get_setting('maintenance_picture', null);
    $file = file_load($fid_preload_loading);
    if ($file) {
      $vars['maintenance_pic'] = file_create_url($file->uri);
    }
  }


  // Comming
  $vars['title'] = 'Lauching Soon';
  $vars['construction_description'] = 'Have no fear, we are lauching soon. We just have to do it and cross it';
  $vars['construction_time'] = "2018/08/24";
  if (theme_get_setting('maintenance_title')) {
    $vars['title'] = theme_get_setting('maintenance_title');
  }
  if (theme_get_setting('maintenance_description')) {
    $vars['construction_description'] = theme_get_setting('maintenance_description');
  }
  if (theme_get_setting('maintenance_time')) {
    $vars['construction_time'] = theme_get_setting('maintenance_time');
  }
}
