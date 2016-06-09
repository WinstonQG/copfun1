<?php

/**
 * @file
 * Template for invoiced orders.
 */

?>

<div class="invoice-invoiced">
  <div class="header">
    <img src="<?php print $content['invoice_logo']['#value']; ?>"/>    
  </div>
  
  <div class="customer">
    <span class="customer-title">Info:</span>
    <?php print render($content['commerce_customer_billing']); ?>
    <?php print render($content['customer_mail']); ?>
  </div>    
  <div class="order-info">              
    <div class="order-id"><?php print render($content['order_id']); ?></div> 
    <div class="order-date"><?php print render($content['order_date']); ?></div> 
  </div>
</div>

<div class="text"><strong>Tak for din ordre!</strong> Lorem ipsum dolor sit amet, consectetur adipisicing elit.</div>

<div class="line-items">
  <div class="line-items-view"><?php print render($content['commerce_line_items']); ?></div>
  <div class="order-total"><?php print render($content['commerce_order_total']); ?></div>
</div>

<div class="table-bottom-text">
<div class="text-right">Ved ordren bonuses:</div>
<div>Gratis Levering 1 <span class="star">X</span> Gratis Levering 2 <span class="star">X</span></div>
<ul>
  <li>Med Vedlig hilsen</li>
  <li>F.C. Kopenhavn fanshop</li>
  <li>Oster Allen</li>
  <li>2100 Kopenhavn 0</li>
</ul>
<ul>
  <li>Telefon: 35 46 33 64, task #4</li>
  <li>Mail: fanshop@fck.dk</li>  
</ul>
</div>

<hr/>

<div class="text">Lorem ipsum dolor sit amet, consectetur adipisicing elit. Unde at, magnam totam eligendi ex nulla suscipit earum nesciunt quas, blanditiis quaerat nam et provident labore animi doloremque accusamus voluptate. Quo.</div>

<div class="text-line"><span class="text-line-title">Jeg returnere hermed</span></div>

<div class="text"><span class="rounded-rect">&nbsp;</span> Denne str.<span class="underscore">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span>onsker i stedet prokektet<span class="underscore">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span>.</div>

<div class="text"><span class="rounded-rect">&nbsp;</span> Og onsker blanditiis quaerat nam et provident labore animi.</div>

<div class="text-line"><span class="text-line-title">Bermakinder:</span></div>