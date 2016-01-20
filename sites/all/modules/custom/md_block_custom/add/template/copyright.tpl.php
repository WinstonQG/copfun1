<?php 
    $text = $settings['md_hosoren_copyright_text']; 
    $menuid = $settings['md_hosoren_copyright_menu'];
    $menu_link = 'links__' . $menuid;
?>
<div class="copyright">
    <p><?php print $text;?></p>
</div>

<div class="footer-nav">
    <nav>
        <?php
          $menu = menu_navigation_links($menuid);
          print theme($menu_link, array('links' => $menu));
        ?>
    </nav>
</div>
