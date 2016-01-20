<?php

/**
 * @file
 * flippy.tpl.php
 *
 * Theme implementation to display a simple pager.
 *
 * Default variables:
 * - $links: An array of links to render, keyed by their class. The array
 *   contains 'title' and 'href'.
 * 
 * Other variables:
 * - $current['nid']: The Node ID of the current node.
 * - $first['nid']: The Node ID of the first node.
 * - $prev['nid']: The Node ID of the previous node.
 * - $next['nid']: The Node ID of the next node.
 * - $last['nid']: The Node ID of the last node.
 *
 * - $current['title']: The Node title of the current node.
 * - $first['title']: The Node title of the first node.
 * - $prev['title']: The Node title of the previous node.
 * - $next['title']: The Node title of the next node.
 * - $last['title']: The Node title of the last node.
 * 
 * - $show_empty: TRUE if links without hrefs should be rendered.
 *
 * @see template_preprocess_flippy()
 */

global $base_url;
$xhtml = $node_prev = $node_next = '';$fr = '';
$node_prev = node_load($prev['nid']);
$node_next = node_load($next['nid']);

if(empty($node_prev)){
  $fr = 'fr';
}

?>

<?php 
foreach ($links as $key => $link){
  

  $node_flippy = explode('/', $links[$key]['href']);
  if (!$link['href'] && !$show_empty){
    continue;
  }

  if (!$link['href']){
    //print $link['title']; 
  }else{
    $type = $key == 'prev' ?  'entry-navigation-prev-post' : 'entry-navigation-next-post';
    if($key == 'prev'){
      $node_title = $node_prev->title;
      $user_node = user_load($node_prev->uid);
      if (user_is_logged_in()) {
        $author_name = '<a href="'.$base_url.'/user/'.$user_node->uid.'">'. ucfirst($user_node->name).'</a>';
      }else{
        $author_name = '<a>'.ucfirst($user_node->name).'</a>';
      }
      $cmt_count = $node_prev->comment_count;
      $field_category = field_view_field('node', $node_prev, 'field_category_blog');
      $path = $links['prev']['href'];

    }elseif($key == 'next'){
      $node_title = $node_next->title;
      $user_node = user_load($node_next->uid);
      if (user_is_logged_in()) {
        $author_name = '<a href="'.$base_url.'/user/'.$user_node->uid.'">'. ucfirst($user_node->name).'</a>';
      }else{
        $author_name = '<a>'.ucfirst($user_node->name).'</a>';
      }
      $cmt_count = $node_next->comment_count;
      $field_category = field_view_field('node', $node_next, 'field_category_blog');
      $path = $links['next']['href'];

    }

 
    $xhtml .= '<div class="col-md-6 col-sm-6 '.$fr.'">
                <div class="'.$type.'">
                    <div class="entry-navigation-header">
                        <span>'.$link['title'].'</span>
                    </div>

                    <h2 class="entry-navigation-title">
                        <a href="'.$base_url. '/' .$path.'" title="">'.$node_title.'</a>
                    </h2>

                    <div class="entry-navigation-meta">
                        <span>'.t('Posted by').'</span>
                        <strong class="entry-author">'.ucfirst($author_name).'</strong>
                        <span>-</span>
                        <span class="entry-category">'.drupal_render($field_category).'  </span>
                        <span>-</span>
                        <span class="entry-comment-count"><a href="'.$base_url. '/' .$path. '#comments'.'" title="">'.$cmt_count . ' ' . t('Comments').'</a></span>
                    </div>
                </div>
            </div>';

  }
}
if(!empty($node_prev)){
  $prev_icon = '<a href="'.$base_url. '/' .$links['prev']['href'].'" class="entry-navigation-prev">
                    <i class="icon fontello icon-left-open"></i>
                </a>';
}else{
  $prev_icon = '';
}
if(!empty($node_next)){
  $next_icon = '<a href="'.$base_url. '/' .$links['next']['href'].'" class="entry-navigation-next">
                    <i class="icon fontello icon-right-open"></i>
                </a>';
}else{
  $next_icon = '';
}
  $output = '<div class="row cols-border flippy-cols">'.$xhtml.'</div>
            <div class="entry-navigation-button">
                '.$prev_icon.$next_icon.'
            </div>
            '; 
  print $output;
?>

