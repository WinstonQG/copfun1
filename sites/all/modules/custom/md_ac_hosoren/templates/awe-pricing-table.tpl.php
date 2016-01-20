<div <?php if($id) print 'id="'.$id.'"'; ?>  class="single-pricing center <?php print $pricingborder; ?> <?php print $planbutton; ?> <?php print $classes; ?>" <?php print $attributes; ?>>
  <div class="pricing-head <?php print $header_boder ?>">
    <?php if($settings['enableIcon']): ?>
      <i class="<?php print $settings['icon']; ?>"></i>
    <?php endif; ?>
    <h4 class="pricing-heading" style="text-transform: <?php print $settings['titletransform']?>"><?php print $settings['title']; ?></h4>
    <div class="price">
      <h3>
        <span class="dollar"><?php print $settings['currency']; ?></span>
        <span class="price"><?php print $settings['price']; ?></span>
        <span class="month"><?php print $settings['perTime']; ?></span>
      </h3>
    </div>
    <?php if($settings['enableplanbtn']): ?>
      <div class="text-center plan-top-btn"><span class="offer"><?php print $settings['planbtn']; ?></span></div>
    <?php endif; ?>
  </div>
  <div class="pricing-planebt-content">
    <?php if($settings['enableInfo']): ?>
      <div class="pricing-info">
          <?php print $settings['pricingInfo']; ?>
      </div>
    <?php endif; ?>
    <?php if($settings['enablelisticon']): ?>
      <ul class="package-features <?php print $settings['listiconstyle']; ?> <?php print $planlist; ?> <?php print $palist; ?>">
          <?php if (isset($listicontext)): ?>
            <?php foreach($listicontext as $key => $item): ?>
                <li>
                    <span class="<?php print $item['icon']; ?>"></span>
                    <?php print $item['text']; ?>
                </li>
            <?php endforeach; ?>
          <?php endif; ?>
      </ul>
    <?php endif; ?>
    <?php if($settings['enableNote']): ?>
      <div class="pricing-notes">
        <?php print $settings['pricingNote']; ?>
      </div>
    <?php endif; ?>
    <div class="sign-up">
      <a href="<?php print $settings['button_link']; ?>" target="<?php print $settings['button_target']; ?>" class="btn <?php print $Btnborder; ?> btn-rounded hover-effect">
        <?php print $settings['button_text']; ?>
      </a>
    </div>
  </div>
</div>
