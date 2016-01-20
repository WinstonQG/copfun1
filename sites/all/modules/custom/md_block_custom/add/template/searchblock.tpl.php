<?php 

?>
<ul class="navbar-search">
    <li>
        <a href="#" title="" class="awemenu-icon awe-menubar-search" id="open-search-form">
            <span class="sr-only">Search</span>
            <span class="icon icon-search"></span>
        </a>

        <div class="menubar-search-form" id="menubar-search-form">
            <?php
                $search_box = drupal_get_form('search_block_form');
                print drupal_render($search_box);
            ?>
        </div><!-- /.menubar-search-form -->
    </li>
</ul>
