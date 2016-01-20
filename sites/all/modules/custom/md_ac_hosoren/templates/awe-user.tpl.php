<div <?php if($id) print 'id="'.$id.'"'; ?> class="member-team animated <?php print $classes; ?>" <?php print $attributes; ?>>
  <div class="awe-media-header">
    <div class="awe-media-image">
      <img src="<?php print $src_img ?>" alt="team">
    </div>
    <div class="awe-media-hover dark fullpage">
      <div class="fp-table">
        <div class="fp-table-cell center">
          <h6 class="upper margin-bottom-20">Connect</h6>
          <ul class="list-socials list-large list-light">
            <?php if (isset($list_more_socials)): ?>
              <?php foreach($list_more_socials as $key => $listsocial): ?>
                  <li><a href="<?php print $listsocial['link']; ?>" data-toggle="<?php print $listsocial['entooltip']; ?>" title="<?php print $listsocial['text']; ?>" data-original-title="<?php print $listsocial['text']; ?>">
                    <i class="<?php print $listsocial['icon']; ?>" style="color : <?php print $listsocial['socialcolor']; ?>"></i>
                  </a></li>
              <?php endforeach; ?>
          <?php endif; ?>
          </ul>
        </div>
      </div>
    </div>
  </div>
  <div class="awe-media-body center">
    <h3 class="awe-media-title text-upper"><?php print $settings['username'] ?></h3>
    <p class="awe-media-caption"><span class="bold"><?php print $settings['userjob'] ?></span></p>
		<?php if($settings['enableDescription'] == 1): ?>
			<p class="user-description margin-top-10"><?php print $settings['description'] ?></p>
		<?php endif; ?>
  </div>
</div>
