<div class="policy-header">
    <?php if (isset($policy_icon)): ?>
      <?php foreach ($policy_icon as $key => $data): ?>
        <?php

          $icon = $data[2];
          $icon = explode('|', $icon);
          $original_title = explode('-', $icon[1]);
          $element = array(
            '#theme' => 'icon',
            '#bundle' => $icon[0],
            '#icon' => $icon[1],
          );
        ?>
    <div class="policy">
                                    <div class="policy-icon">
                                        <?php print drupal_render($element); ?>
                                    </div>

                                    <div class="policy-text">
                                        <h4><?php print $data[0]; ?></h4>
                                        <p><?php print $data[1]; ?></p>
                                    </div>
                                </div>
                                <!-- /.policy -->
      <?php endforeach; ?>
    <?php endif; ?>
</div>
