<?php
$instagram_id = $settings['setting_instagram_id'];
$instagram_client_id = $settings['setting_instagram_client_id'];
$instagram_photos_count = $settings['setting_instagram_number_img'];
$instagram_api = $settings['setting_instagram_api'];
$instagram_sort = $settings['setting_instagram_sort'];
?>
<div class='widget_instagram widget widget_tag_cloud'><ul id="instafeed" class="instagram-widget"></ul></div>

<script type="text/javascript">
    var feed = new Instafeed({
        clientId: '<?php print $instagram_client_id;?>',
        accessToken:'<?php print $instagram_api; ?>',
        get: 'user',
        userId: <?php print $instagram_id; ?>,
        sortBy: '<?php print $instagram_sort; ?>',
        limit: '<?php print $instagram_photos_count; ?>',
        template : '<li class="insta-li"><a href="{{link}}" class="insta-photo"><img src="{{image}}" /></a></li>'
    });
    feed.run();
</script>
