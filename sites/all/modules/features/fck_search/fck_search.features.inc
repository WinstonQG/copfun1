<?php
/**
 * @file
 * fck_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fck_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function fck_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function fck_search_default_search_api_index() {
  $items = array();
  $items['shop_product'] = entity_import('search_api_index', '{
    "name" : "Shop Product",
    "machine_name" : "shop_product",
    "description" : null,
    "server" : "db_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "shop_product" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_accessories" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_accessories:tid" : { "type" : "integer" },
        "field_accessories:vocabulary:machine_name" : { "type" : "string" },
        "field_baby" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_baby:tid" : { "type" : "integer" },
        "field_baby:vocabulary:machine_name" : { "type" : "string" },
        "field_clothing" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_clothing:tid" : { "type" : "integer" },
        "field_clothing:vocabulary:machine_name" : { "type" : "string" },
        "field_gifts" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_gifts:tid" : { "type" : "integer" },
        "field_gifts:vocabulary:machine_name" : { "type" : "string" },
        "field_group" : { "type" : "string" },
        "field_match_kits" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_match_kits:tid" : { "type" : "integer" },
        "field_match_kits:vocabulary:machine_name" : { "type" : "string" },
        "field_player_jerseys" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_player_jerseys:tid" : { "type" : "integer" },
        "field_player_jerseys:vocabulary" : { "type" : "integer", "entity_type" : "taxonomy_vocabulary" },
        "field_player_jerseys:vocabulary:machine_name" : { "type" : "string" },
        "field_product_store" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "commerce_product" },
        "field_product_store:commerce_price:amount_decimal" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_product_store:commerce_stock" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_product_store:field_foot_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product_store:field_outwear_adult_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product_store:field_outwear_baby_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product_store:field_outwear_children_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product_store_commerce_price_amount_decimal_asc" : { "type" : "decimal" },
        "field_product_store_commerce_price_amount_decimal_desc" : { "type" : "decimal" },
        "field_sale" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_sale:tid" : { "type" : "integer" },
        "field_weight_accessories" : { "type" : "integer" },
        "field_weight_baby" : { "type" : "integer" },
        "field_weight_clothing" : { "type" : "integer" },
        "field_weight_gifts" : { "type" : "integer" },
        "field_weight_jersey" : { "type" : "integer" },
        "field_weight_match_kits" : { "type" : "integer" },
        "field_weight_new" : { "type" : "integer" },
        "field_weight_sale" : { "type" : "integer" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_ranges_alter" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "fields" : { "field_product_store:commerce_price:amount_decimal" : "field_product_store:commerce_price:amount_decimal" } }
        },
        "commerce_search_api_product_display_filter" : { "status" : 1, "weight" : "-10", "settings" : [] },
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "commerce_search_api_alter_product_status" : { "status" : 1, "weight" : "-9", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "product_shop_title_and_body",
                "type" : "fulltext",
                "fields" : [ "title", "body:value", "body:summary" ],
                "description" : "A Fulltext aggregation of the following fields: Title, The main body text \\u00bb Text, The main body text \\u00bb Summary."
              }
            }
          }
        },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function fck_search_default_search_api_server() {
  $items = array();
  $items['db_server'] = entity_import('search_api_server', '{
    "name" : "Db server",
    "machine_name" : "db_server",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 0,
      "indexes" : {
        "product_display" : {
          "nid" : {
            "table" : "search_api_db_product_display",
            "column" : "nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_product_display",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_product_display",
            "column" : "title",
            "type" : "string",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_product_display",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_product_display",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_product_store" : {
            "table" : "search_api_db_product_display_field_product_store",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_product_display",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_product_store_commerce_price_amount_decimal_asc" : {
            "table" : "search_api_db_product_display",
            "column" : "field_product_store_commerce_price_amount_decimal_asc",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "field_product_store_commerce_price_amount_decimal_desc" : {
            "table" : "search_api_db_product_display",
            "column" : "field_product_store_commerce_price_amount_decimal_desc",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "field_product_store:commerce_price:amount_decimal" : {
            "table" : "search_api_db_product_display_field_product_store_commerce_pri",
            "column" : "value",
            "type" : "list\\u003Cdecimal\\u003E",
            "boost" : "1.0"
          },
          "field_accessories" : {
            "table" : "search_api_db_product_display",
            "column" : "field_accessories",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_clothing" : {
            "table" : "search_api_db_product_display",
            "column" : "field_clothing",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_match_kits" : {
            "table" : "search_api_db_product_display",
            "column" : "field_match_kits",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_baby" : {
            "table" : "search_api_db_product_display",
            "column" : "field_baby",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_gifts" : {
            "table" : "search_api_db_product_display",
            "column" : "field_gifts",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_clothing:vocabulary" : {
            "table" : "search_api_db_product_display",
            "column" : "field_clothing_vocabulary",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_clothing:vocabulary:machine_name" : {
            "table" : "search_api_db_product_display",
            "column" : "field_clothing_vocabulary_machine_name",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_clothing:tid" : {
            "table" : "search_api_db_product_display",
            "column" : "field_clothing_tid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_product_store:field_outwear_adult_size" : {
            "table" : "search_api_db_product_display_field_product_store_field_outwea",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:field_outwear_baby_size" : {
            "table" : "search_api_db_product_display_field_product_store_field_outw_1",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:field_outwear_children_size" : {
            "table" : "search_api_db_product_display_field_product_store_field_outw_2",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:field_foot_size" : {
            "table" : "search_api_db_product_display_field_product_store_field_foot_s",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:commerce_stock" : {
            "table" : "search_api_db_product_display_field_product_store_commerce_sto",
            "column" : "value",
            "type" : "list\\u003Cdecimal\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:commerce_product_commerce_line_item" : {
            "table" : "search_api_db_product_display_field_product_store_commerce_pro",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          }
        },
        "shop_product" : {
          "nid" : {
            "table" : "search_api_db_shop_product",
            "column" : "nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_shop_product",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_shop_product_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_shop_product",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_shop_product",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_product_store" : {
            "table" : "search_api_db_shop_product_field_product_store",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_accessories" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_accessories",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_clothing" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_clothing",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_match_kits" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_match_kits",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_baby" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_baby",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_gifts" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_gifts",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_shop_product",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_product_store:field_outwear_adult_size" : {
            "table" : "search_api_db_shop_product_field_product_store_field_outwear_a",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:field_outwear_baby_size" : {
            "table" : "search_api_db_shop_product_field_product_store_field_outwear_b",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:field_outwear_children_size" : {
            "table" : "search_api_db_shop_product_field_product_store_field_outwear_c",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:field_foot_size" : {
            "table" : "search_api_db_shop_product_field_product_store_field_foot_size",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:commerce_price:amount_decimal" : {
            "table" : "search_api_db_shop_product_field_product_store_commerce_price_",
            "column" : "value",
            "type" : "list\\u003Cdecimal\\u003E",
            "boost" : "1.0"
          },
          "field_accessories:vocabulary:machine_name" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_accessories_vocabulary_machine_name",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_clothing:vocabulary:machine_name" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_clothing_vocabulary_machine_name",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_match_kits:vocabulary:machine_name" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_match_kits_vocabulary_machine_name",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_baby:vocabulary:machine_name" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_baby_vocabulary_machine_name",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_gifts:vocabulary:machine_name" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_gifts_vocabulary_machine_name",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_product_store_commerce_price_amount_decimal_asc" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_product_store_commerce_price_amount_decimal_asc",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "field_product_store_commerce_price_amount_decimal_desc" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_product_store_commerce_price_amount_decimal_desc",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "field_accessories:tid" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_accessories_tid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_clothing:tid" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_clothing_tid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_match_kits:tid" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_match_kits_tid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_baby:tid" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_baby_tid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_gifts:tid" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_gifts_tid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_shop_product_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "body:summary" : {
            "table" : "search_api_db_shop_product_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_group" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_group",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_sale" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_sale",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_player_jerseys" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_player_jerseys",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_player_jerseys:vocabulary" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_player_jerseys_vocabulary",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_player_jerseys:vocabulary:machine_name" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_player_jerseys_vocabulary_machine_name",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_sale:tid" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_sale_tid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_player_jerseys:tid" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_player_jerseys_tid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_product_store:commerce_stock" : {
            "table" : "search_api_db_shop_product_field_product_store_commerce_stock",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_shop_product",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_weight_clothing" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_weight_clothing",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_weight_new" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_weight_new",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_weight_jersey" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_weight_jersey",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_weight_accessories" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_weight_accessories",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_weight_match_kits" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_weight_match_kits",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_weight_gifts" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_weight_gifts",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_weight_baby" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_weight_baby",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_weight_sale" : {
            "table" : "search_api_db_shop_product",
            "column" : "field_weight_sale",
            "type" : "integer",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
