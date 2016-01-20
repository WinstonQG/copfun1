<?php

/**
 * @file
 * Customize the display of a complete webform.
 *
 * This file may be renamed "webform-form-[nid].tpl.php" to target a specific
 * webform on your site. Or you can leave it "webform-form.tpl.php" to affect
 * all webforms on your site.
 *
 * Available variables:
 * - $form: The complete form array.
 * - $nid: The node ID of the Webform.
 *
 * The $form array contains two main pieces:
 * - $form['submitted']: The main content of the user-created form.
 * - $form['details']: Internal information stored by Webform.
 *
 * If a preview is enabled, these keys will be available on the preview page:
 * - $form['preview_message']: The preview message renderable.
 * - $form['preview']: A renderable representing the entire submission preview.
 */
?>
    <!-- Contact Info -->
      <?php foreach ($info as $key => $value): ?>
        <div class="col-sm-4 col-xs-12">
          <div class="ts-contact-info text-center">
            <!-- Icon -->
            <i class="<?php print $value[0] ?>"></i>
            <?php if(!empty($value[2])): ?>
              <a href="<?php print $value[2]; ?>" target="_blank"><?php print $value[3]; ?></a>
            <?php else: ?>
              <span><?php print $value[3]; ?></span>
            <?php endif; ?>  
          </div>  
        </div>

      <?php endforeach; ?>
    <!-- End Contact Info -->
      <div class="contact-wrapper">
      <?php print drupal_render($form['submitted']['name']); ?>
      <?php print drupal_render($form['submitted']['email']); ?>
      <?php print drupal_render($form['submitted']['website']); ?>
      <?php print drupal_render($form['submitted']['your_comment']); ?>
      <!-- Send Button -->
      <?php print drupal_render($form['actions']); ?>
      </div>


<?php
// Print out the progress bar at the top of the page
print drupal_render($form['progressbar']);

// Print out the preview message if on the preview page.
if (isset($form['preview_message'])) {
  print '<div class="messages warning">';
  print drupal_render($form['preview_message']);
  print '</div>';
}

// Print out the main part of the form.
// Feel free to break this up and move the pieces within the array.
print drupal_render($form['submitted']);

// Always print out the entire $form. This renders the remaining pieces of the
// form that haven't yet been rendered above (buttons, hidden elements, etc).
print drupal_render_children($form);
