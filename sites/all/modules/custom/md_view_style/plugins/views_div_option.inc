<?php

/**
 * @file
 * Contains the default style plugin.
 */

/**
 * Default style plugin to render rows one after another with no
 * decorations.
 *
 * @ingroup views_style_plugins
 */
class ViewsContentOption extends views_plugin_style {

  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['number'] = array('default' => '4');
    $options['class'] = array('default' => '');
    $options['wrapper_class'] = array('default' => '');

    return $options;
  }
	/**
   * Create forms to hold these values allowing the user to change the values
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
		

		$form['number'] = array(
      '#type' => 'select',
      '#title' => t('Number Layout'),
      '#options' => array(
        '2' => t('2'),
        '3' => t('3'),
        '4' => t('4'),
        '5' => t('5'),
        '6' => t('6'),
      ),
      '#default_value' => $this->options['number'],
    );
    $form['wrapper_class'] = array(
      '#title' => t('Wrapper class'),
      '#description' => t('The class to provide on the wrapper, outside the list.'),
      '#type' => 'textfield',
      '#size' => '30',
      '#default_value' => $this->options['wrapper_class'],
    );
    $form['class'] = array(
      '#title' => t('Content class'),
      '#description' => t('The class to provide on the list element itself.'),
      '#type' => 'textfield',
      '#size' => '30',
      '#default_value' => $this->options['class'],
    );
  }

}
