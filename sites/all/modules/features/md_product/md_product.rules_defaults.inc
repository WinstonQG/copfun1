<?php
/**
 * @file
 * md_product.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function md_product_default_rules_configuration() {
  $items = array();
  $items['rules_fck_cart_shipping_refresh'] = entity_import('rules_config', '{ "rules_fck_cart_shipping_refresh" : {
      "LABEL" : "FCK Cart shipping refresh",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "FCK" ],
      "REQUIRES" : [ "rules", "fck_order", "entity" ],
      "ON" : { "commerce_line_item_update" : [], "commerce_line_item_delete" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "product" : "product" } }
          }
        }
      ],
      "DO" : [
        { "fck_order_shipping_refresh" : { "commerce_order" : [ "commerce-line-item:order" ] } }
      ]
    }
  }');
  $items['rules_free_post_danmark_shipping'] = entity_import('rules_config', '{ "rules_free_post_danmark_shipping" : {
      "LABEL" : "Free Post Danmark Shipping",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "FCK" ],
      "REQUIRES" : [ "rules", "fck_order", "commerce_line_item", "commerce_shipping" ],
      "ON" : { "commerce_shipping_calculate_rate" : [] },
      "IF" : [
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item" ],
            "field" : "commerce_shipping_service"
          }
        },
        { "data_is" : {
            "data" : [ "commerce-line-item:commerce-shipping-service" ],
            "value" : "post_danmark"
          }
        },
        { "NOT commerce_order_nosh_compare_order_amount" : {
            "commerce_order" : [ "commerce-line-item:order" ],
            "operator" : "\\u003C",
            "total" : [ "site:fck-postdanmark-free-shipping-rate" ]
          }
        }
      ],
      "DO" : [
        { "commerce_line_item_unit_price_amount" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : "0",
            "component_name" : "flat_rate_post_danmark",
            "round_mode" : "1"
          }
        }
      ]
    }
  }');
  return $items;
}
