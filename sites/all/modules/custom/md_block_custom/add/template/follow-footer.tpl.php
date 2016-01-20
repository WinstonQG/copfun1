<?php
?>
<ul class="list-socials">
    <?php if (isset($social_footer)): ?>
      <?php foreach ($social_footer as $key => $data): ?>
        <?php
          $icon = $data[1];
          $icon = explode('|', $icon);
          $element = array(
            '#theme' => 'icon',
            '#bundle' => $icon[0],
            '#icon' => $icon[1],
          );
        ?>
        <li><a href="<?php print $data[0]; ?>"><?php print drupal_render($element); ?></a></li>
      <?php endforeach; ?>
    <?php endif; ?>
</ul>

