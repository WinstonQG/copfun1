<?php

function user_form_ajax($js = NULL, $action = 'register') {
  global $base_url;

  // Fall back if $js is not set.
  if (!$js) {
    $output = '';
    switch ($action) {
      case 'login':
        $output = drupal_get_form('user_login');
        break;
      default:
        $output = drupal_get_form('user_register_form');
    }
    return $output;
  }
  ctools_include('modal');
  ctools_include('ajax');
  $form_state = array(
    'ajax' => TRUE,
  );

  $output = array();
  ctools_add_js('ajax-responder');
//  $custom_style = array(
//    'mycoolmodulemodal' => array(
//      'modalSize' => array(
//        'type' => 'fixed',
//        'width' => 400,
//        'height' => 230,
//      ),
//      'animation' => 'fadeIn',
//      'modalTheme' => 'happymodal',
//    ),
//  );
//  drupal_add_js($custom_style, 'setting');

  if ($action == 'register') {
    //$output='';
    $output = ctools_modal_form_wrapper('user_register_form', $form_state);
    $output[0]['output'] .= '<div class="mfp-ontent">
      <div id="login-popup" class="login-popup">
        <div role="tabpanel"><ul class="nav nav-tabs" role="tablist">
                <li role="presentation" >
                    ' . l(t('Login'), $base_url . '/user-form/nojs/login', array('attributes' => array('class' => 'ctools-use-modal mycoolmodulemodal')))
        . '</li>
                <li role="presentation" class="active">
' . l(t('Register'), $base_url . '/user-form/nojs/register', array('attributes' => array('class' => 'ctools-use-modal mycoolmodulemodal'))) . '
                </li>
            </ul><button type="button"  title="' . t("Close (Esc)") . '" class="mfp-close close ctools-close-modal">×</button>
            ';
    $output[0]['output'] .='</div></div></div>';
    if (!empty($form_state['executed'])) {
      // We'll just overwrite the form output if it was successful.

      if (isset($_GET['destination'])) {
        $output[] = ctools_ajax_command_redirect($_GET['destination']);
      }
      elseif (module_exists('login_destination')) {
        $destination = login_destination_get_destination('login');
        $output[] = ctools_ajax_command_redirect($destination['path']);
      }
      else {
        $output[] = ctools_ajax_command_reload();
      }
    }
  }
  if ($action == 'login') {
    $output = ctools_modal_form_wrapper('user_login', $form_state);
    $output[0]['output'] .= '<div class="mfp-ontent">
      <div id="login-popup" class="login-popup">
        <div role="tabpanel">
            <ul class="nav nav-tabs" role="tablist">
                <li role="presentation" class="active">' 
                  . l(t('Login'), $base_url . '/user-form/nojs/login', array('attributes' => array('class' => 'ctools-use-modal mycoolmodulemodal')))
                . '</li>
                <li role="presentation" >' 
                    . l(t('Register'), $base_url . '/user-form/nojs/register', array('attributes' => array('class' => 'ctools-use-modal mycoolmodulemodal'))) . '
                </li>
            </ul>';
    $output[0]['output'] .= '<button type="button" title="' . t("Close (Esc)") . '" class="mfp-close close ctools-close-modal">×</button>'; 
    $output[0]['output'] .= '</div></div></div>';
    
    if (!empty($form_state['executed'])) {
      // We'll just overwrite the form output if it was successful.
      if (isset($_GET['destination'])) {
        $output[] = ctools_ajax_command_redirect($_GET['destination']);
      }
      elseif (module_exists('login_destination')) {
        $destination = login_destination_get_destination('login');
        $output[] = ctools_ajax_command_redirect($destination['path']);
      }
      else {
        $output[] = ctools_ajax_command_reload();
      }
    }
  }
  print ajax_render($output);
}
