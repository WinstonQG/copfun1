<li class="<?php print $tab_classes?>">
  <?php if(count($items) > 0): ?>
    <span class="mdtoggle-sub"></span>
  <?php endif; ?>
  <?php print $tab->content;?>
  <?php print $tab_content; ?>
</li>