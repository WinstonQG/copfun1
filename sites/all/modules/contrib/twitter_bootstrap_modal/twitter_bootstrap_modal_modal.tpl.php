<?php
/**
 * @file
 * Template file for the theming the modal box.
 *
 * Available custom variables:
 * - $site_name
 * - $render_string
 *
 */
?>

	<div class="modal-header"><button type="button" class="close" data-dismiss="modal" aria-hidden="true">×</button></div>
  <div class="modal-body"><?php  print $render_string; ?></div>
  <div class="modal-footer"><button class="btn" data-dismiss="modal" aria-hidden="true">Close</button></div>
