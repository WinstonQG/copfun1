<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>

<?php if ($view_mode == 'modal_product_detail'): ?>  
  <div class="product product-grid modal-product-detail <?php print $classes; ?> node-<?php print $node->nid; ?> clearfix"<?php print $attributes; ?>>    
  <?php if (isset($content['field_product_store'])):?>                              
    <div class="container-fluid"><div class="row">
      <div class="col-sm-6">  
        <div id="fck-modal-carousel" class="carousel slide" data-ride="carousel">
          <?php if (sizeof($content['product:field_product_images']['#items']) > 1) : ?>
          <ol class="carousel-indicators">
            <?php $active_class = "active"; ?>            
            <?php for ($i=0; $i< sizeof($content['product:field_product_images']['#items']); $i++) : ?>
              <li data-target="#fck-modal-carousel" data-slide-to="<?php print $i; ?>" class="<?php print $active_class; ?>"></li> 
              <?php if (!empty($active_class)) { $active_class = ""; } ?>
            <?php endfor; ?>
          </ol>
          <?php endif; ?>
          <div class="carousel-inner" role="listbox">
            <?php $active_class = "active"; ?>
            <?php foreach ($content['product:field_product_images']['#items'] as $item) : ?>
              <?php $url = image_style_url('product_modal_slider', $item['uri']); ?>
              <div class="item <?php print $active_class; ?>">
                <img data-src="holder.js/900x500/auto/#777:#555/text:First slide" alt="First slide [900x500]" src="<?php print $url; ?>" data-holder-rendered="true">
              </div>
              <?php if (!empty($active_class)) { $active_class = ""; } ?>
            <?php endforeach; ?>        
          </div>
          <?php if (sizeof($content['product:field_product_images']['#items']) > 1) : ?>
          <a target="_blank" class="left carousel-control" href="#fck-modal-carousel" role="button" data-slide="prev">
            <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
            <span class="sr-only">Previous</span>
          </a>
          <a target="_blank" class="right carousel-control" href="#fck-modal-carousel" role="button" data-slide="next">
            <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
            <span class="sr-only">Next</span>
          </a>
          <?php endif; ?>
        </div>                 
      </div>
      <div class="col-sm-6">
        <div class="product-body">
          <h2 class="product-name"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
          
          <div class="product-status">
            <?php if (isset($content['field_product_store'][0]['quantity'])):?>
                <span><?php print t('In Stock') ?></span><span>-</span><div class="small inline"><?php print render($content['product:sku']); ?></div>
            <?php else: ?>
                <h5><?php print t('SOLD OUT')?></h5>
            <?php endif; ?>
          </div>                      
          <!-- /.product-status -->

          <div class="product-price"><?php print render($content['product:commerce_price']); ?></div>
          <div class="product-description">
            <p><?php print render($content['body']['#items'][0]['summary']); ?></p>
          </div>

          <div class="product-list-actions-wrapper">
            <?php print render($content['field_product_store']); ?>              
          </div>
          <!-- /.product-actions-wrapper -->
          <?php if (0) : ?>
          <div class="product-meta"><span class="product-category"><span><?php print render($content['field_product_category']['#title']); ?>:</span><?php print $categories_list; ?></span><span> - </span><span class="product-tags"><span>Tags:</span><?php print render($content['field_tags']); ?></span></div>
          <?php endif; ?>
          <!-- /.product-meta -->
          </div>
        </div>
      </div>
    </div>                                
  <?php endif; ?>

  </div>
<?php elseif ($view_mode == 'modal_content'): ?>  
  <div class="product product-grid <?php print $classes; ?> node-<?php print $node->nid; ?> clearfix"<?php print $attributes; ?>>
    
    <div class="product-media">
      <div class="product-thumbnail">
        <?php if (isset($content['product:field_product_images']['#items'])): ?>
          <a href="<?php print $node_url; ?>">
            <?php if (isset($content['product:field_product_images']['#items'][1]['uri'])): ?>
              <img src="<?php print image_style_url('product_modal',$content['product:field_product_images']['#items'][0]['uri']); ?>" alt="product" class="current">
              <img src="<?php print image_style_url('product_modal',$content['product:field_product_images']['#items'][1]['uri']); ?>" alt="product">
            <?php else :?>
              <img src="<?php print image_style_url('product_modal',$content['product:field_product_images']['#items'][0]['uri']); ?>" alt="product" class="current">
            <?php endif; ?>
          </a>
        <?php endif; ?>

        <?php if (!isset($content['field_product_store'][0]['quantity'])):?>
          <div class="product-soldout">
              <div class="fp-table">
                  <div class="fp-table-cell">
                      <span class="soldout">Sold Out</span>
                  </div>
              </div>
          </div>
        <?php endif; ?>
      </div>
      <?php if (isset($content['field_product_store'][0]['quantity'])) : ?>
        <?php //watchdog('cc', '<pre>'.print_r($content['field_product_store'][0], TRUE).'</pre>');
        //watchdog('st', '<pre>'.print_r($content['field_product_store']['#items'], TRUE).'</pre>'); ?>
        <div class="product-hover">
          <div class="product-actions">                
            <?php if (sizeof($content['field_product_store']['#items']) > 1) : ?>
              <?php print ctools_modal_text_button('<i class="icon icon-basket"></i>', 'fck_modals/nojs/product/'.$node->nid, t('Add to cart'), 'awe-button product-add-cart'); ?>
              <?php if (!user_is_anonymous()) : ?>
                <?php print ctools_modal_text_button('<i class="icon icon-star-empty"></i>', 'fck_modals/nojs/product/'.$node->nid, t('Add to wishlist'), 'awe-button quick-view-product'); ?>
              <?php endif; ?>           
              <?php print ctools_modal_text_button('<i class="icon icon-eye"></i>', 'fck_modals/nojs/product/'.$node->nid, t('Quickview'), 'awe-button quick-view-product'); ?>
            <?php else : ?>
              <?php $product_id = $content['field_product_store']['#items'][0]['product_id']; ?>
              <?php print l('<i class="icon icon-basket"></i>', 
                'fck_modals/add/'.$product_id,
                array(
                  'query' => drupal_get_destination(),
                  'html' => TRUE,
                  'attributes' => array(
                    'class' => 'awe-button product-add-cart',                    
                    'title' => t('Add to cart'),
                  ),
                )); 
              ?>
                
              <?php print flag_create_link('wishlist_product', $product_id); ?>
                                      
              <?php print ctools_modal_text_button('<i class="icon icon-eye"></i>', 'fck_modals/nojs/product/'.$node->nid, t('Quickview'), 'awe-button quick-view-product'); ?>         
            <?php endif; ?>                                                
          </div>
        </div>
      <?php endif; ?>   
    

      
      <?php if (isset($content['field_group']) && fck_is_has_group($content['field_group']['#items'])) : ?>
        <span class="product-label"><span><?php print 'Ny'; ?></span></span>            
      <?php elseif (isset($content['field_label']) && isset($content['field_label']['#items'][0]['value'])): ?>
        <span class="product-label"><span><?php print $content['field_label']['#items'][0]['value']; ?></span></span>
      <?php endif; ?>

      <!-- /.product-media -->
    </div>

    <div class="product-body">
        <h2 class="product-name"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        <div class="product-category"><span><?php print $categories_list; ?></span></div>
        <div class="product-price"><?php print render($content['product:commerce_price']); ?><?php print render($content['product:field_price_old']); ?></div>
    </div>
  </div>

<?php elseif ($view_mode == 'teaser'): ?>
  <div class="product product-list <?php print $classes; ?> node-<?php print $node->nid; ?> shop_teaser clearfix"<?php print $attributes; ?>>
    
    <div class="product-media">
      <?php if (isset($content['product:field_product_images'])) : ?>
      <div class="product-thumbnail">
        <?php if (isset($content['product:field_product_images']['#items'])) : ?>
          <a href="<?php print $node_url; ?>">
            <img src="<?php print image_style_url('product_teaser',$content['product:field_product_images']['#items'][0]['uri'])?>" alt="<?php print render($content['product:field_product_images']['#items'][0]['alt']); ?>">
          </a>
        <?php endif; ?>
      </div>
      <?php endif; ?>
      <!-- /.product-thumbnail -->

      <?php if (isset($content['product:field_price_old'][0]['#markup'])): ?>
        <span class="product-label sale"><span><?php print t("SALE") ?></span></span>
      <?php elseif(isset($content['field_group']['#items'][0]['value'])): ?>
        <?php $output = 'Ny'; ?>
        <span class="product-label <?php print render($content['field_group']['#items'][0]['value']) ?>"><span><?php print $output; ?></span></span>
      <?php endif; ?> 
      <!-- /.product-media -->

    </div>
    <div class="product-body">
        <h2 class="product-name"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>

        <div class="product-category"><span><?php print $categories_list; ?></span></div>

        <div class="product-price"><?php print render($content['product:commerce_price']); ?></div>

        <?php if (0) : ?>
        <div class="product-stars"><?php print render($content['field_rate_five']); ?></div>
        <?php endif; ?>
        <div class="product-description">
            <p><?php print render($content['body']['#items'][0]['summary']); ?></p>
        </div>

        <div class="product-list-actions">
          <?php if (isset($content['field_product_store'][0]['quantity'])): ?>
            <?php unset($content['field_product_store'][0]['attributes']['field_size']); ?>
            <?php //unset($content['field_product_store'][0]['attributes']['field_color']); ?>
           
            <?php unset($content['field_product_store'][0]['field_jersey_print']); ?>
            <?php print render($content['field_product_store']); ?>
          <?php endif; ?>
          <?php if (isset($content['flag_wishlist']['#markup'])): ?>
            <?php print render($content['flag_wishlist']['#markup']); ?>
          <?php endif; ?>
        </div>
    </div>
    <!-- /.product-body -->

  </div>

<?php else: ?>  
  <div id="node-<?php print $node->nid; ?>" class="product_full <?php print $classes; ?> clearfix"<?php print $attributes; ?>>    
    <div class="row">
      <div class="col-md-6">
        <?php if (isset($content['product:field_product_images'])): ?>
          <div class="product-slider-wrapper thumbs-bottom">
            <?php print render($content['product:field_product_images']); ?>
          </div>
        <?php endif; ?>
      </div>
      <!-- /.swiper-container -->
        <div class="col-md-6">        
          <?php if(isset($content['flippy_pager'])):?>
            <nav class="pnav clearfix">
              <div class="pull-right">
                <?php print render($content['flippy_pager']); ?>
              </div>
            </nav>
          <?php endif; ?>
        <!-- /header -->

        <div class="product-details-wrapper productcart_inline">
          <h2 class="product-name"><?php print $title; ?></h2>
          
          <div class="product-status">
            <?php if (isset($content['field_product_store'][0]['quantity'])):?>
                <span><?php print t('In Stock') ?></span><span>-</span><div class="small inline"><?php print render($content['product:sku']); ?></div>
            <?php else: ?>
                <h5><?php print t('SOLD OUT')?></h5>
            <?php endif; ?>
          </div>          
          <!-- /.product-status -->
          
          <?php if (0) : ?>
          <div class="product-stars">
            <?php print render($content['field_rate_five']); ?>
          </div>
          <?php endif; ?>
          <!-- /.product-stars -->    
          <span class="product-price"><?php print render($content['product:commerce_price']); ?>
            <?php if (isset($content['product:field_price_old'])) : ?>
              <?php print render($content['product:field_price_old']); ?>
            <?php endif; ?>
          </span>
          <!-- /.product-price -->

          <?php if(!empty($content['body']['#items'][0]['summary'])): ?>
            <div class="product-description">
                <p><?php print render($content['body']['#items'][0]['summary']); ?></p>
            </div>
          <?php endif; ?>
          <div class="product-features">              
              <?php print render($content['body'][0]['#markup']); ?>
          </div>
          <!-- /.product-description -->          

          <?php if (isset($content['field_product_store'])): ?>
            <div class="product-actions-wrapper">
                <?php print render($content['field_product_store']); ?>
            </div>
          <?php endif; ?>                            
        </div>
      </div>
    </div>  

    <?php if(isset($content['sharethis'])): ?>
        <div class="product-socials">
          <?php print render($content['sharethis']); ?>
        </div>
    <?php endif; ?>
    <?php if (0) : ?>
     <div class="product-details-left">
        <div role="tabpanel" class="product-details">
          <?php if (isset($content['comments'])): ?>
            <nav>
                <ul class="nav" role="tablist">
                    <li role="presentation" class="active">
                        <a href="#product-description" data-toggle="tab"><?php print t("Description") ?></a>
                    </li>
                    <li role="presentation">
                        <a href="#product-infomation" data-toggle="tab"><?php print t("Additional Infomation") ?></a>
                    </li>
                    <li role="presentation">
                        <a href="#product-review" data-toggle="tab"><?php print t("Review") ?> <span>(<?php print $comment_count ?>)</span></a>
                    </li>
                </ul>
            </nav>
            <div class="tab-content">
                <div role="tabpanel" class="tab-pane active" id="product-description">
                    <?php print render($content['field_description'][0]['#markup']); ?>
                </div>
                <div role="tabpanel" class="tab-pane" id="product-infomation">
                    <?php print render($content['field_additional_infomation'][0]['#markup']); ?>
                </div>
                <div role="tabpanel" class="tab-pane" id="product-review">
                  <?php print render($content['comments']); ?>
                </div>
            </div>
          <?php else: ?>
            <nav>
              <ul class="nav" role="tablist">
                  <li role="presentation" class="active">
                      <a href="#product-description" data-toggle="tab"><?php print t("Description") ?></a>
                  </li>
                  <li role="presentation">
                      <a href="#product-infomation" data-toggle="tab"><?php print t("Additional Infomation") ?></a>
                  </li>
              </ul>
            </nav>
            <div class="tab-content">
              <div role="tabpanel" class="tab-pane active" id="product-description">
                  <?php print render($content['field_description'][0]['#markup']); ?>
              </div>
              <div role="tabpanel" class="tab-pane" id="product-infomation">
                  <?php print render($content['field_additional_infomation'][0]['#markup']); ?>
              </div>
            </div>
          <?php endif; ?>
          </div>
      </div>
      <?php endif; ?>
  </div>
<?php endif; ?>