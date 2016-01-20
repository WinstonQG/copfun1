<div <?php if($id) print 'id="'.$id.'"'; ?>  class="awe-counting <?php print $classes; ?>" <?php print $attributes; ?>>

  <?php if($settings['enablesocial'] =='1'): ?>
    <div class="text-center counters-icon"><i class="<?php print $settings['SocialIcon'] ?>"></i></div>
  <?php endif; ?>
  <<?php print $tagname?> class="counters-title"><?php print $settings['title'] ?></<?php print $tagname?>>
  <span class="counter <?php print $settings['NumberWeight'] ?>"><?php print $settings['Numbercounters'] ?></span>

</div>