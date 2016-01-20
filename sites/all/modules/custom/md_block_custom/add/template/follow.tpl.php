<?php

?>
<ul class="list-socials">
    <?php if (isset($social)): ?>
      <?php foreach ($social as $key => $data): ?>
        <?php

          $icon = $data[1];
          $icon = explode('|', $icon);
          $original_title = explode('-', $icon[1]);
          $element = array(
            '#theme' => 'icon',
            '#bundle' => $icon[0],
            '#icon' => $icon[1],
          );
        ?>
        <li><a href="<?php print $data[0]; ?>" data-toggle="tooltip" title="<?php print ucfirst($original_title[1])?>"><?php print drupal_render($element); ?></a></li>
      <?php endforeach; ?>
    <?php endif; ?>
</ul>

