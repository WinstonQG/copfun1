<?php
/**
 * Overwrite theme_pager()
 * @param $variables
 * @return string
 * @throws \Exception
 */

/**
 * Implements theme_pager().
 */
function md_hosoren_pager_first($vars) {
  $text = $vars['text'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];
  global $pager_page_array;
  $output = '';

  if ($pager_page_array[$element] > 0) {
    $output = theme('pager_link', array('text' => t('1'), 'page_new' => pager_load_array(0, $element, $pager_page_array), 'element' => $element, 'parameters' => $parameters));
  }

  return $output;
}

function md_hosoren_pager_previous($vars) {
  $text = $vars['text'];
  $element = $vars['element'];
  $interval = $vars['interval'];
  $parameters = $vars['parameters'];
  global $pager_page_array;
  $output = '';

  // If we are anywhere but the first page
  if ($pager_page_array[$element] > 0) {
    $page_new = pager_load_array($pager_page_array[$element] - $interval, $element, $pager_page_array);
    $output = theme('pager_link', array('text' => $text, 'page_new' => $page_new, 'element' => $element, 'parameters' => $parameters));
  }

  return $output;
}

function md_hosoren_pager_next($vars) {
  $text = $vars['text'];
  $element = $vars['element'];
  $interval = $vars['interval'];
  $parameters = $vars['parameters'];
  global $pager_page_array, $pager_total;
  $output = '';

  // If we are anywhere but the last page
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $page_new = pager_load_array($pager_page_array[$element] + $interval, $element, $pager_page_array);
    $output = theme('pager_link', array('text' => $text, 'page_new' => $page_new, 'element' => $element, 'parameters' => $parameters));
  }

  return $output;
}

function md_hosoren_pager_last($vars) {
  $text = $vars['text'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];
  global $pager_page_array, $pager_total;
  $output = '';

  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $output = theme('pager_link', array('text' => $pager_total[$element], 'page_new' => pager_load_array($pager_total[$element] - 1, $element, $pager_page_array), 'element' => $element, 'parameters' => $parameters));
  }

  return $output;
}

function md_hosoren_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.
  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('<')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('>')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_previous) {
      $items[] = array(
        'class' => array('pagination-prev'),
        'data' => $li_previous,
      );
    }

    if ($li_first && $pager_first > 1 && $quantity < $pager_max) {
      $items[] = array(
        'class' => array('pagination-first'),
        'data' => $li_first,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '<a>...</a>',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('active'),
            'data' => '<a href="#">' . $i . '</a>',
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '<a>...</a>',
        );
      }
    }
    // End generation.
    if ($li_last && $pager_last < $pager_max) {
      $items[] = array(
        'class' => array('pagination-last'),
        'data' => $li_last,
      );
    }

    if ($li_next) {
      $items[] = array(
        'class' => array('pagination-next'),
        'data' => $li_next,
      );
    }

    $output = '<div class="list-pagination"><ul class="pagination">';
    foreach ($items as $item) {
      $output .= '<li class="' . $item['class'][0] . '">' . $item['data'] . "</li>\n";
    }
    $output .= '</ul></div>';

    return $output;
  }
}

/**
 * Overwrite theme_textarea().
 */
function md_hosoren_textarea($variables) {
  $element = $variables['element'];  
	/*if (isset($element['#title'])){
		$element['#attributes']['placeholder'] = $element['#title'];
	}*/
  element_set_attributes($element, array('id', 'name', 'cols', 'rows'));
  _form_set_class($element, array('form-control','control-textarea'));

  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    drupal_add_library('system', 'drupal.textarea');
    $wrapper_attributes['class'][] = 'resizable';
    $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
    $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
    $output .= '</div>';
    return $output;
  }
  else {
    $output = '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
    return $output;
  }
}

/**
 * Overwrite theme_textfield().
 */
function md_hosoren_textfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'text';
  /*if (isset($element['#title'])){
    $element['#attributes']['placeholder'] = $element['#title'];
  }*/
  element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength'));
  _form_set_class($element, array('form-control'));

  $extra = '';
  if ($element['#autocomplete_path'] && drupal_valid_path($element['#autocomplete_path'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#attributes']['id'] . '-autocomplete';
    $attributes['value'] = url($element['#autocomplete_path'], array('absolute' => TRUE));
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }
  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';
  return $output . $extra;
}


/**
 * Overwrite theme_menu_local_tasks()
 * Style for menu T
 * @param $variables
 * @return string
 */

function md_hosoren_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables ['primary'])) {
    $variables ['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables ['primary']['#prefix'] .= '<ul class="tabs tab_primary tabs-content nav nav-tabs">';
    $variables ['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables ['primary']);
  }
  if (!empty($variables ['secondary'])) {
    $variables ['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables ['secondary']['#prefix'] .= '<ul class="tabs tab_secondary tabs-content nav nav-tabs">';
    $variables ['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables ['secondary']);
  }

  return $output;
}

//Bread crumb
function md_hosoren_breadcrumb($variables) {
    $crumbs = '<ol class="breadcrumb">';
    $breadcrumb = $variables['breadcrumb'];
    // /dsm($variables);
    if (!empty($breadcrumb)) {
        $breadcrumb[0] = '<a href="' . url('<front>', array('absolute' => TRUE)) . '">Home</a>';
        foreach ($breadcrumb as $value) {
            $crumbs .= '<li>' . $value . '</li>';
        }
        $crumbs .= '<li class="active">' . drupal_get_title() . '</li>';

        $crumbs .='</ol>';
        return $crumbs;
    } else {
        return NULL;
    }
}

/**************************************
*  Messenger 
***************************************/
function md_hosoren_status_messages($variables) {
  $display = $variables ['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    //dsm($type);
    $output .= '<div class="container messages-content"><div class="row">';
    if($type=='status'){
          $output .= "<div class=\"alert alert-success\">\n";
          if (!empty($status_heading [$type])) {
            $output .= '<h2 class="element-invisible">' . $status_heading [$type] . "</h2>\n";
          }
            if (count($messages) > 1) {
              $output .= " <ul class=\"list-unstyled\">\n";
              foreach ($messages as $message) {
                $output .= '  <li> ' . $message . "</li>\n";
              }
              $output .= " </ul>\n";
            }
            else {
              $output .= reset($messages);
            }
          $output .= "</div>\n";  
    }
    elseif($type=="error"){
          $output .= "<div class=\"alert alert-danger\">\n";
          if (!empty($status_heading [$type])) {
            $output .= '<h2 class="element-invisible">' . $status_heading [$type] . "</h2>\n";
          }
            if (count($messages) > 1) {
              $output .= " <ul class=\"list-unstyled\">\n";
              foreach ($messages as $message) {
                $output .= '  <li> ' . $message . "</li>\n";
              }
              $output .= " </ul>\n";
            }
            else {
              $output .= reset($messages);
            }
          $output .= "</div>\n";  
    }
    elseif($type=="warning"){
          $output .= "<div class=\"alert alert-warning\">\n";
          if (!empty($status_heading [$type])) {
            $output .= '<h2 class="element-invisible">' . $status_heading [$type] . "</h2>\n";
          }
            if (count($messages) > 1) {
              $output .= " <ul class=\"list-unstyled\">\n";
              foreach ($messages as $message) {
                $output .= ' <li> ' . $message . "</li>\n";
              }
              $output .= " </ul>\n";
            }
            else {
              $output .= reset($messages);
            }
          $output .= "</div>\n";  
    }
    $output .= "</div></div>\n";
  }
  return $output;
}

/* ------------------------------------
*  Main Menu
--------------------------------------*/

//Custom One Page
function md_hosoren_links__page_one_menu($variables) {
    $html = "";
    foreach ($variables['links'] as $link) {
      $link['attributes']['class'] = array('smooth-scroll');
      $html .= "<li>".l($link['title'], $link['href'], $link)."</li>";
    }
    $html .= "";
    return $html;
}


//Custom Footer Link
function md_hosoren_links__menu_list($variables) {
    $html = "";
    foreach ($variables['links'] as $link) {
       $html .= "<li>".l($link['title'], $link['href'], $link)."</li>";
    }
    $html .= "";
    return $html;
}


// Full node Add to Cart
// function md_hosoren_form_commerce_cart_add_to_cart_form_alter(&$form, &$form_state) {
//   $line_item = $form_state['line_item'];
//   $product = commerce_product_load($line_item->commerce_product[LANGUAGE_NONE][0]['product_id']);
//   if ($product->type == 'product') {
    
//     unset($form['quantity']['#title']);
//     if(isset($form['attributes'])){
//         $form['attributes']['field_size']['#attributes']['class']=array('form-control','ordering');
//         $form['attributes']['field_size']['#prefix'] = '<div class="form-group">';
//         $form['attributes']['field_size']['#suffix'] = '</div>';
//     }
//     if($form['quantity']['#type']!='hidden'){
//         $form['quantity']['#attributes']['class']=array('input-quantity');
//         $form['quantity']['#prefix'] = '<div class="inputQty">';
//         $form['quantity']['#suffix'] = '</div>';
//     }
//   }
// }

/**
 * Implement hook_form_alter()
 * @param $form
 * @param $form_state
 * @param $form_id
 */
function md_hosoren_form_alter(&$form, &$form_state, $form_id) {
  //dsm($form);
  if (($form_id == 'user_login') || ($form_id == 'user_register_form') || ($form_id == 'user_pass')) {
      $form['pass']['#attributes'] = array('class' => array('form-control'));
      $form['actions']['submit']['#attributes'] = array('class' => array('btn','btn-primary'));
  }
  elseif (stristr($form_id, "webform_client_form")) {
    $form['#attributes']['id'] = 'contact-form';
    $form['actions']['submit']['#value'] = 'Send Message';  
    $form['actions']['submit']['#attributes'] = array('class' => array('btn', 'btn-dark', 'btn-lg'));
  }
  else{
  switch ($form_id) {
      case 'comment_node_blog_form':
        $form['actions']['submit']['#attributes']['class'] = array(
          'btn', 'btn-dark', 'btn-lg', 'btn-outline'
        );
        $form['author']['homepage']['#attributes']['placeholder'] = t('Website');
        $form['author']['mail']['#attributes']['placeholder'] = t('Email');
        $form['author']['name']['#attributes']['placeholder'] = t('Name');
        $form['subject']['#attributes']['placeholder'] = t('Subject');
        $form['comment_body']['und'][0]['#attributes']['placeholder'] = t('Your comment');
        unset($form['author']['mail']['#description']);
        unset($form['actions']['preview']);
        break;
      case 'search_form':
        //$form['basic']['keys']['#title'] = t("New Search");
        //$form['basic']['keys']['#description'] = t("If you are not happy with the results bellow please do another search.");
        $form['advanced']['submit']['#attributes'] = array('class' => array('btn','btn-primary'));
        break;
      case 'search_block_form':
        $form['search_block_form']['#attributes']['placeholder'] = t("Search your entry here...");
        break;

    }
  }
}

/**
 * Implement hook_theme()
 */
function md_hosoren_theme() {
  $themes = array();
  $path = drupal_get_path('theme', 'md_hosoren') . '/templates';

  $themes['comment_form__node_blog'] = array(
    'render element' => 'form',
    'template' => 'comment-form--node-blog',
    'path' => $path . '/comment',
  );
  $themes['comment_form__node_shop_product'] = array(
    'render element' => 'form',
    'template' => 'comment-form--node-shop-product',
    'path' => $path . '/comment',
  );
  /*$themes['contact_site_form'] = array(
    'render element' => 'form',
    'template' => 'contact-us--form',
    'path' => $path . '/comment',
  );*/
  $themes['search_api_ranges_block_slider_view_form'] = array(
    'render element' => 'form',
    'template' => 'facet-slider-shop-product',
    'path' => $path . '/form',
  );
  $themes['simplenews_block_form'] = array(
    'render element' => 'form',
    'template' => 'simplenews-block-form',
    'path' => $path . '/simplenews',
  );
  // Categories list
  $themes['md_hosoren_categories_list'] = array(    
    'variables' => array(
      'page' => NULL,       
    ),
    'template' => 'categories-list',
    'path' => $path . '/page'
  );
  // Footer
  $themes['md_hosoren_footer'] = array(    
    'variables' => array(
      'page' => NULL, 
      'colum_number' => 0,
      'footer_setting_region_1' => '',
      'footer_setting_region_2' => '',
      'footer_setting_region_3' => '',
      'footer_setting_region_4' => '',     
    ),
    'template' => 'footer',
    'path' => $path . '/page'
  );

  return $themes;
}

/**
 * Implements hook_preprocess_search_results().
 */
function md_hosoren_preprocess_search_results(&$vars) {
  
  $vars['search_keylabel']=arg(2);
  // search.module shows 10 items per page (this isn't customizable)
  $itemsPerPage = 10;

  // Determine which page is being viewed
  // If $_REQUEST['page'] is not set, we are on page 1
  $currentPage = (isset($_REQUEST['page']) ? $_REQUEST['page'] : 0) + 1;

  // Get the total number of results from the global pager
  if(isset($GLOBALS['pager_total_items'])){
      $total = $GLOBALS['pager_total_items'][0];
      $end = (($itemsPerPage * $currentPage) >= $total) ? $total : ($itemsPerPage * $currentPage);
  }

  // Determine which results are being shown ("Showing results x through y")
  $start = (10 * $currentPage) - 9;
  // If on the last page, only go up to $total, not the total that COULD be
  // shown on the page. This prevents things like "Displaying 11-20 of 17".
  

  // if ($total > $itemsPerPage) {
  //   $vars['search_totals'] = t('Displaying !start - !end of !total results', array(
  //     '!start' => $start,
  //     '!end' => $end,
  //     '!total' => $total,
  //   ));
  // }
  // else {
  //   // Only one page of results, so make it simpler
  //   $vars['search_totals'] = t('Displaying !total !results_label', array(
  //     '!total' => $total,
  //     // Be smart about labels: show "result" for one, "results" for multiple
  //     '!results_label' => format_plural($total, 'result', 'results'),
  //   ));
  // }

  // If there is more than one page of results:
  if(isset($total)){
    $vars['search_totals'] = t('!total  Search results for:', array(
      '!total' => $total,
    ));
  }

}
function md_hosoren_preprocess_search_result(&$vars) {
  $vars['node_type'] = $vars['result']['type'];
  $vars['number_item'] = $vars['id'];
  $vars['classes_array'][]= "search-results-item";

  $vars['row_search_result'] = '';
  $vars['left_col_search_result'] = '';
  $vars['right_col_search_result'] = '';
  $vars['output'] = '';
  switch ($vars['result']['node']->type) {
      case 'blog':
        $field_media_blog = field_get_items('node', $vars['result']['node'], 'field_media_blog');
        break;
      case 'portfolio':
        $field_media_portfolio = field_get_items('node', $vars['result']['node'], 'field_multimedia');
        break;
      case 'shop_product':
           $product = commerce_product_load($vars['result']['node']->field_product_store['und'][0]['product_id']);
           $field_media_product = field_get_items('commerce_product', $product, 'field_product_images');
      break;
  }
  if(isset($field_media_blog) && $field_media_blog != '' || isset($field_media_portfolio) && $field_media_portfolio != '' || isset($field_media_product) && $field_media_product != ''){
    $vars['row_search_result'] = 'row';
    $vars['left_col_search_result'] = 'col-md-3';
    $vars['right_col_search_result'] = 'col-md-9';
  }
  if(isset($field_media_blog) && $field_media_blog != ''){
    $vars['output'] = field_view_field('node', $vars['result']['node'], 'field_media_blog');
  }elseif(isset($field_media_portfolio) && $field_media_portfolio != ''){
    $vars['output'] = field_view_field('node', $vars['result']['node'], 'field_multimedia');
  }elseif(isset($field_media_product) && $field_media_product != ''){
    $vars['output'] = field_view_field('commerce_product', $product, 'field_product_images','search_product');
  }

}



/**
 * Implement hook_preprocess_comment()
 */
function md_hosoren_preprocess_comment(&$variables) {
  $comment = $variables['elements']['#comment'];
  $link_reply = $variables['elements']['links']['comment']['#links']['comment-reply']['href'];


  $variables['custom_date']   = date('F j, o',$comment->created);
  $variables['link_comment_repply'] = l('Reply', $link_reply, array('html' => 'true', 'attributes' => array('class' =>  array('btn','btn-primary','btn-xs'))));


  $uri = entity_uri('comment', $comment);
  $uri['options'] += array('attributes' => array('class' => 'permalink', 'rel' => 'bookmark'));
  $variables['submitted'] = t('!username  on !datetime', array('!username' => $variables['author'], '!datetime' => date('F.j.o',$comment->created)));
}

/**
 * Implement hook_preprocess_webform_form()
 */
function md_hosoren_preprocess_webform_form(&$vars) {
  $info = theme_get_setting('address_info');
  $info = explode('||', $info);
  array_pop($info);
  foreach ($info as $key => $value) {
    $info[$key] = $key != 0 ? substr($value, 1, -1) : substr($value, 0, -1);
  }
  $vars['info'] = array_chunk($info, 4);

}
/**
 * Implement hook_preprocess_simplenews_block_form()
 */
function md_hosoren_preprocess_simplenews_block_form(&$vars) {
  $form = $vars['form'];
  $form['mail']['#title_display'] = 'invisible';
  $form['mail']['#atrributes']['placeholder'] = t('Enter your email address');
  $form['submit']['#attributes']['class'][] = 'btn btn-primary';
  $vars['form'] = $form;
}

/**
 * Overwirte template_button()
 */
function md_hosoren_button($variables) {
    $element = $variables['element'];
    $element['#attributes']['type'] = 'submit';
    element_set_attributes($element, array('id', 'name', 'value'));

    if (!isset($element['#attributes']['class']) || !in_array("ts-button", $element['#attributes']['class'])) {
      $element['#attributes']['class'][] = 'btn btn-primary form-' . $element['#button_type'];
    }
    if (!empty($element['#attributes']['disabled'])) {
        $element['#attributes']['class'][] = 'form-button-disabled';
    }
    return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

/**
 *  Quicktabs style
 */

function md_hosoren_qt_quicktabs_tabset($vars) {
  $variables = array(
    'attributes' => array(
      'class' => 'nav nav-tabs nav-justified quicktabs-tabs',
    ),
    'items' => array(),
  );
  foreach (element_children($vars['tabset']['tablinks']) as $key) {
    $item = array();
    if (is_array($vars['tabset']['tablinks'][$key])) {
      $tab = $vars['tabset']['tablinks'][$key];
      if ($key == $vars['tabset']['#options']['active']) {
        $item['class'] = array('active');
      }
      $item['data'] = drupal_render($tab);
      $variables['items'][] = $item;
    }
  }
  return theme('item_list', $variables);
}
/**
* Rate widget
*/

function md_hosoren_process_rate_template_thumbs_up(&$variables) {
  extract($variables);

  $classes = 'icon ';  

  if (isset($results['user_vote']) && $results['user_vote'] == $links[0]['value']) {
    $classes .= 'icon-heart user-voted';
  } else {
    $classes .= 'icon-heart-empty user-not-voted';
  }

  $variables['up_button'] = theme('rate_button', array('href' => $links[0]['href'], 'class' => $classes));
}

/**
 * Implement hook_preprocess_flippy()
 */
function md_hosoren_preprocess_flippy(&$vars){
  if ($node = menu_get_object('node')) {
    $vars['node'] = $node;
  }
  if (isset($vars['node'])) {
    $vars['theme_hook_suggestions'][] = 'flippy__node__' . $vars['node']->type;
  }

}


/**
 * Overwire theme_username()
 */

function md_hosoren_username($variables) {
  if (isset($variables ['link_path'])) {
    $output = l(ucfirst($variables ['name']) . $variables ['extra'], $variables ['link_path'], $variables ['link_options']);
  }
  else {
    $output = '<span>' . ucfirst($variables ['name']) . $variables ['extra'] . '</span>';
  }
  return $output;
}

function md_hosoren_views_mini_pager($vars) {
  global $pager_page_array, $pager_total;

  $tags = $vars['tags'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];

  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  if ($pager_total[$element] > 1) {

    $li_previous = theme('pager_previous',
      array(
        'text' => (isset($tags[1]) ? $tags[1] : t('‹‹')),
        'element' => $element,
        'interval' => 1,
        'parameters' => $parameters,
      )
    );
    if (empty($li_previous)) {
      $li_previous = "&nbsp;";
    }

    $li_next = theme('pager_next',
      array(
        'text' => (isset($tags[3]) ? $tags[3] : t('››')),
        'element' => $element,
        'interval' => 1,
        'parameters' => $parameters,
      )
    );

    if (empty($li_next)) {
      $li_next = "&nbsp;";
    }

    $items[] = array(
      'class' => array('pager-previous'),
      'data' => $li_previous,
    );

    $items[] = array(
      'class' => array('pager-current'),
      'data' => t('@current of @max', array('@current' => $pager_current, '@max' => $pager_max)),
    );

    $items[] = array(
      'class' => array('pager-next'),
      'data' => $li_next,
    );
    return theme('item_list',
      array(
        'items' => $items,
        'title' => NULL,
        'type' => 'ul',
        'attributes' => array('class' => array('pager')),
      )
    );
  }
}

function md_hosoren_preprocess_views_view_fields(&$vars) {
  //dsm($vars);
  global $base_url;
  $author = '';
  if(isset($vars['fields']['uid']->content)){
    $author = user_load($vars['fields']['uid']->content);
  }
  if (user_is_logged_in()) {
    if(isset($vars['fields']['uid']->content)){
      $vars['author_name'] = '<a href="'.$base_url.'/user/'.$author->uid.'">'. ucfirst($author->name).'</a>';
    }
  }else{
    if(isset($vars['fields']['uid']->content)){
      $vars['author_name'] = '<a>'.ucfirst($author->name).'</a>';
    }
  }
}
