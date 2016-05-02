<?php

/**
 * Implements hook_default_rules_configuration().
 */
function fck_cron_default_rules_configuration() {
  $rules = array();
  /*
  $rules_export = '{ "rules_stock_enable_product_variant_when_in_stock" : {
    "LABEL" : "Stock: enable product variant when back in stock",
    "PLUGIN" : "reaction rule",    
    "TAGS" : [ "Commerce Stock Filter" ],
    "REQUIRES" : [ "rules", "entity" ],
    "ON" : { "commerce_product_presave" : [] },
    "IF" : [
      { "entity_is_of_type" : { "entity" : [ "commerce-product" ], "type" : "commerce_product" } },
      { "data_is" : {
          "data" : [ "commerce-product:commerce-stock" ],
          "op" : "\u003E",
          "value" : "0"
        }
      }
    ],
    "DO" : [
      { "data_set" : { "data" : [ "commerce-product:status" ], "value" : 1 } }
    ]
    }
  }';  
  $rules['rules_stock_disable_product_variant_when_out_of_stock'] = rules_import($rules_export);

  $rules_export = '{ "rules_stock_disable_product_variant_when_out_of_stock" : {
    "LABEL" : "Stock: disable product variant when out of stock",
    "PLUGIN" : "reaction rule",    
    "TAGS" : [ "Commerce Stock Filter" ],
    "REQUIRES" : [ "rules", "entity" ],
    "ON" : { "commerce_product_presave" : [] },
    "IF" : [
      { "entity_is_of_type" : { "entity" : [ "commerce-product" ], "type" : "commerce_product" } },
      { "data_is" : { "data" : [ "commerce-product:commerce-stock" ], "value" : "0" } }
    ],
    "DO" : [
      { "data_set" : { "data" : [ "commerce-product:status" ], "value" : 0 } }
    ]
  }
  }';
  $rules['rules_stock_enable_product_variant_when_in_stock'] = rules_import($rules_export);

  $rules_export = '{ "rules_stock_unpublish_product_node_when_all_out_of_stock" : {
    "LABEL" : "Stock: unpublish product node when all out of stock",
    "PLUGIN" : "reaction rule",    
    "TAGS" : [ "Commerce Stock Filter" ],
    "REQUIRES" : [ "rules", "commerce_stock_filter", "entity" ],
    "ON" : { "commerce_product_update" : [], "commerce_product_insert" : [] },
    "IF" : [
      { "entity_is_of_type" : { "entity" : [ "commerce-product" ], "type" : "commerce_product" } },
      { "data_is" : { "data" : [ "commerce-product:commerce-stock" ], "value" : "0" } }
    ],
    "DO" : [
      { "commerce_stock_filter_unpublish_product_display" : { "commerce_product" : [ "commerce-product" ] } }
    ]
  }
  }';
  $rules['rules_stock_unpublish_product_node_when_all_out_of_stock'] = rules_import($rules_export);
  
  $rules_export = '{ "rules_stock_publish_product_node_when_any_in_stock" : {
    "LABEL" : "Stock: publish product node when any in stock",
    "PLUGIN" : "reaction rule",    
    "TAGS" : [ "Commerce Stock Filter" ],
    "REQUIRES" : [ "rules", "commerce_stock_filter", "entity" ],
    "ON" : { "commerce_product_presave" : [] },
    "IF" : [
      { "entity_is_of_type" : { "entity" : [ "commerce-product" ], "type" : "commerce_product" } },
      { "data_is" : {
          "data" : [ "commerce-product:commerce-stock" ],
          "op" : "\u003E",
          "value" : "0"
        }
      }
    ],
    "DO" : [
      { "commerce_stock_filter_publish_product_display" : { "commerce_product" : [ "commerce-product" ] } }
    ]
  }
  }';
  $rules['rules_stock_publish_product_node_when_any_in_stock'] = rules_import($rules_export);  
  */
  return $rules;
}