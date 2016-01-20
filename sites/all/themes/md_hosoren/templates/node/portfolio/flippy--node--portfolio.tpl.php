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
$class = 'btn btn-sm btn-arrow btn-default btn-outline';
$textnext = '<i class="icon fontello icon-right-open" aria-hidden="true"></i>';
$textprev = '<i class="icon fontello icon-left-open" aria-hidden="true"></i>';
?>
<?php foreach ($links as $key => $link): ?>
  <?php if (!$link['href'] && !$show_empty): ?>
    <?php continue; ?>
  <?php endif; ?>

  <?php if (!$link['href']): ?>
  <?php else: ?>
    <?php if ($key == 'prev'): ?>
      <?php print l($textprev, $link['href'], array('html' => TRUE, 'attributes' => array('title' => $link['title'], 'data-toggle' => 'tooltip', 'class' => $class ))); ?>
    <?php elseif ($key == 'next'): ?>
      <?php print l($textnext, $link['href'], array('html' => TRUE, 'attributes' => array('title' => $link['title'], 'data-toggle' => 'tooltip', 'class'=> $class))); ?>
    <?php endif; ?>
  <?php endif; ?>

<?php endforeach; ?>