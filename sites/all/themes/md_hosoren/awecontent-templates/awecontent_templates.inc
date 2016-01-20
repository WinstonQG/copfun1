<?php
/**
 * @File: awecontent_templates.inc
 */

/**
 * Callback to return list templates default by this theme
 */
function md_hosoren_awecontent_templates($type='') {
  $templates = array(
    'section' => array(
          array(
          'tid' => 55,
          'title' => 'Bars Normal',
          'type' => 'section',
          'data' => 'bars_normal/data.inc',
          'favourite' => 0,
          'thumbnail' => 'bars_normal/9.jpg',
          'category' => 'Custom',
          'created' => 1445516290,
        ),
          array(
          'tid' => 54,
          'title' => 'Tabs',
          'type' => 'section',
          'data' => 'tabs/data.inc',
          'favourite' => 0,
          'thumbnail' => 'tabs/8.jpg',
          'category' => 'Custom',
          'created' => 1445513672,
        ),
          array(
          'tid' => 53,
          'title' => 'Button',
          'type' => 'section',
          'data' => 'button/data.inc',
          'favourite' => 0,
          'thumbnail' => 'button/11.jpg',
          'category' => 'Custom',
          'created' => 1445513644,
        ),
          array(
          'tid' => 52,
          'title' => 'Tearm',
          'type' => 'section',
          'data' => 'tearm/data.inc',
          'favourite' => 0,
          'thumbnail' => 'tearm/7.jpg',
          'category' => 'Custom',
          'created' => 1445513600,
        ),
          array(
          'tid' => 51,
          'title' => 'Service',
          'type' => 'section',
          'data' => 'service/data.inc',
          'favourite' => 0,
          'thumbnail' => 'service/6.jpg',
          'category' => 'Custom',
          'created' => 1445513450,
        ),
          array(
          'tid' => 50,
          'title' => 'Alert',
          'type' => 'section',
          'data' => 'alert/data.inc',
          'favourite' => 0,
          'thumbnail' => 'alert/13.jpg',
          'category' => 'Custom',
          'created' => 1445513407,
        ),
          array(
          'tid' => 48,
          'title' => 'Bars',
          'type' => 'section',
          'data' => 'bars/data.inc',
          'favourite' => 0,
          'thumbnail' => 'bars/10.jpg',
          'category' => 'Custom',
          'created' => 1445513109,
        ),
          array(
          'tid' => 43,
          'title' => 'Customer Say',
          'type' => 'section',
          'data' => 'customer_say/data.inc',
          'favourite' => 0,
          'thumbnail' => 'customer_say/2.jpg',
          'category' => 'Custom',
          'created' => 1445510830,
        ),
          array(
          'tid' => 31,
          'title' => 'Policy And Subcriber',
          'type' => 'section',
          'data' => 'policy_and_subcriber/data.inc',
          'favourite' => 0,
          'thumbnail' => 'policy_and_subcriber/12.jpg',
          'category' => 'Custom',
          'created' => 1445426194,
        ),
          array(
          'tid' => 29,
          'title' => 'Advertiserment Section',
          'type' => 'section',
          'data' => 'advertiserment_ection/data.inc',
          'favourite' => 0,
          'thumbnail' => 'advertiserment_ection/5.jpg',
          'category' => 'Custom',
          'created' => 1445425815,
        ),
          array(
          'tid' => 28,
          'title' => 'Subscriber Box',
          'type' => 'section',
          'data' => 'subscriber_box/data.inc',
          'favourite' => 0,
          'thumbnail' => 'subscriber_box/4.jpg',
          'category' => 'Custom',
          'created' => 1445425738,
        ),
        ),
    'page' => array(
          array(
        'tid' => 58,
        'title' => 'Testimonial',
        'type' => 'page',
        'data' => 'testimonial/data.inc',
        'thumbnail' => 'testimonial/p2.jpg',
        'created' => 1445517282,
      ),
          array(
        'tid' => 57,
        'title' => 'About',
        'type' => 'page',
        'data' => 'about/data.inc',
        'thumbnail' => 'about/p1.jpg',
        'created' => 1445517239,
      ),
          array(
        'tid' => 56,
        'title' => 'Home Footer',
        'type' => 'page',
        'data' => 'home_footer/data.inc',
        'thumbnail' => 'home_footer/h5.jpg',
        'created' => 1445517208,
      ),
          array(
        'tid' => 47,
        'title' => 'Home Four',
        'type' => 'page',
        'data' => 'home_four/data.inc',
        'thumbnail' => 'home_four/h4.jpg',
        'created' => 1445511955,
      ),
          array(
        'tid' => 46,
        'title' => 'Home Three',
        'type' => 'page',
        'data' => 'home_three/data.inc',
        'thumbnail' => 'home_three/h3.jpg',
        'created' => 1445511914,
      ),
          array(
        'tid' => 45,
        'title' => 'Home Two',
        'type' => 'page',
        'data' => 'home_two/data.inc',
        'thumbnail' => 'home_two/h2.jpg',
        'created' => 1445511868,
      ),
          array(
        'tid' => 44,
        'title' => 'Home One',
        'type' => 'page',
        'data' => 'home_one/data.inc',
        'thumbnail' => 'home_one/h1.jpg',
        'created' => 1445511438,
      ),
        )
  );
  if ($type && isset($templates[$type])) {
    return $templates[$type];
  }

  return $templates;
}
