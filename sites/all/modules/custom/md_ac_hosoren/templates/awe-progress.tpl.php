<div <?php if($id) print 'id="'.$id.'"'; ?> class="progress <?php print $settings['ProgressSize']; ?> <?php print $classes; ?>" <?php print $attributes; ?>>
  <div class="progress-bar <?php print $settings['ProgressType']; ?>" style="width: <?php print $settings['percent'] ?>%;">
      <span><?php print $settings['title']; ?></span>
			<span class="percent"><?php print $settings['percent'] ?>%</span>
  </div>
</div>
