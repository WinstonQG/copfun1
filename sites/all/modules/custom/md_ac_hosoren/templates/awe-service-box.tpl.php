<div <?php if($id) print 'id="'.$id.'"'; ?>  class="awe-box <?php print $classes; ?> <?php print $settings['layout'] ?>" <?php print $attributes; ?>>
    <div class="awe-box-media">
      <div class="awe-box-icon <?php print $settings['sizeIcon'] ?>">
          <i class="icon <?php print $settings['SocialIcon'] ?>"></i>
      </div>
    </div>
    <div class="awe-box-content">
      <h3><?php print $settings['title'] ?></h3>
      <?php if($settings['enableDescription'] == 1 || $settings['layout'] != "center"): ?>
        <p><?php print $settings['description'] ?></p>
      <?php endif; ?>
    </div>
</div>