<?php

/**
 * Implements hook_default_rules_configuration().
 */
function fck_cron_default_rules_configuration() {
  $rules = array();
   
  $rules['rules_update_new_products'] = rules_import('{ "rules_update_new_products" : {
      "LABEL" : "Update new products",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "FCK" ],
      "REQUIRES" : [ "fck_cron" ],
      "ACTION SET" : [ { "fck_cron_rules_new_product_update" : [] } ]
    }
  }');

  $rules['rules_new_option_scheduler'] = rules_import('{ "rules_new_option_scheduler" : {
      "LABEL" : "New option: Scheduler",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "FCK" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : { "cron" : [] },
      "DO" : [
        { "schedule" : { "component" : "rules_update_new_products", "date" : "+2 minute" } }
      ]
    }
  }');  
  
  return $rules;
}