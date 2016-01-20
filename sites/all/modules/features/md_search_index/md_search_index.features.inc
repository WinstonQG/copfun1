<?php
/**
 * @file
 * md_search_index.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function md_search_index_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function md_search_index_default_search_api_index() {
  $items = array();
  $items['md_index'] = entity_import('search_api_index', '{
    "name" : "MD Index",
    "machine_name" : "md_index",
    "description" : null,
    "server" : "md_sever",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "comment_count" : { "type" : "integer" },
        "created" : { "type" : "date" },
        "field_product_brand" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_product_category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product_store" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "commerce_product" },
        "field_product_store:commerce_price:amount_decimal" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_product_store:field_color" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product_store:field_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product_store_commerce_price_amount_decimal_asc" : { "type" : "decimal" },
        "field_product_store_commerce_price_amount_decimal_desc" : { "type" : "decimal" },
        "search_api_aggregation_1" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_ranges_alter" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "fields" : { "field_product_store:commerce_price:amount_decimal" : "field_product_store:commerce_price:amount_decimal" } }
        },
        "commerce_search_api_product_display_filter" : { "status" : 0, "weight" : "-10", "settings" : [] },
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "commerce_search_api_alter_product_status" : { "status" : 0, "weight" : "-9", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Sort Price",
                "type" : "fulltext",
                "fields" : [ "field_product_store:commerce_price:amount_decimal" ],
                "description" : "A Fulltext aggregation of the following fields: Product Store \\u00bb Price \\u00bb Amount (decimal)."
              }
            }
          }
        },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "field_product_category:parent" : "field_product_category:parent" } }
        }
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
function md_search_index_default_search_api_server() {
  $items = array();
  $items['md_sever'] = entity_import('search_api_server', '{
    "name" : "MD Sever",
    "machine_name" : "md_sever",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : 1,
      "partial_matches" : 0,
      "indexes" : {
        "md_index" : {
          "type" : {
            "table" : "search_api_db_md_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_md_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_md_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "comment_count" : {
            "table" : "search_api_db_md_index",
            "column" : "comment_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_product_brand" : {
            "table" : "search_api_db_md_index",
            "column" : "field_product_brand",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_product_category" : {
            "table" : "search_api_db_md_index_field_product_category",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_md_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_product_store" : {
            "table" : "search_api_db_md_index_field_product_store",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:field_color" : {
            "table" : "search_api_db_md_index_field_product_store_field_color",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:field_size" : {
            "table" : "search_api_db_md_index_field_product_store_field_size",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:commerce_price:amount_decimal" : {
            "table" : "search_api_db_md_index_field_product_store_commerce_price_",
            "column" : "value",
            "type" : "list\\u003Cdecimal\\u003E",
            "boost" : "1.0"
          },
          "field_product_store_commerce_price_amount_decimal_asc" : {
            "table" : "search_api_db_md_index",
            "column" : "field_product_store_commerce_price_amount_decimal_asc",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "field_product_store_commerce_price_amount_decimal_desc" : {
            "table" : "search_api_db_md_index",
            "column" : "field_product_store_commerce_price_amount_decimal_desc",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "search_api_aggregation_1" : {
            "table" : "search_api_db_md_index",
            "column" : "search_api_aggregation_1",
            "type" : "string",
            "boost" : "1.0"
          }
        },
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
          "status" : {
            "table" : "search_api_db_product_display",
            "column" : "status",
            "type" : "integer",
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
          "field_tags" : {
            "table" : "search_api_db_product_display_field_tags",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_lookbook" : {
            "table" : "search_api_db_product_display",
            "column" : "field_product_lookbook",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_product_brand" : {
            "table" : "search_api_db_product_display",
            "column" : "field_product_brand",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_product_category" : {
            "table" : "search_api_db_product_display_field_product_category",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_store" : {
            "table" : "search_api_db_product_display_field_product_store",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_trending" : {
            "table" : "search_api_db_product_display",
            "column" : "field_trending",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_category_blog" : {
            "table" : "search_api_db_product_display",
            "column" : "field_category_blog",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_tags_blog" : {
            "table" : "search_api_db_product_display_field_tags_blog",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_portfolio_categories" : {
            "table" : "search_api_db_product_display_field_portfolio_categories",
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
          "search_api_aggregation_1" : {
            "table" : "search_api_db_product_display_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_aggregation_2" : {
            "table" : "search_api_db_product_display_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_aggregation_3" : {
            "table" : "search_api_db_product_display_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_aggregation_4" : {
            "table" : "search_api_db_product_display_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_aggregation_5" : {
            "table" : "search_api_db_product_display_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_aggregation_6" : {
            "table" : "search_api_db_product_display_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_aggregation_7" : {
            "table" : "search_api_db_product_display_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_aggregation_8" : {
            "table" : "search_api_db_product_display_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_aggregation_9" : {
            "table" : "search_api_db_product_display_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_tags:name" : {
            "table" : "search_api_db_product_display_field_tags_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_product_lookbook:name" : {
            "table" : "search_api_db_product_display",
            "column" : "field_product_lookbook_name",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_product_brand:name" : {
            "table" : "search_api_db_product_display",
            "column" : "field_product_brand_name",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_product_category:name" : {
            "table" : "search_api_db_product_display_field_product_category_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:field_color" : {
            "table" : "search_api_db_product_display_field_product_store_field_co",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:field_size" : {
            "table" : "search_api_db_product_display_field_product_store_field_si",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_trending:name" : {
            "table" : "search_api_db_product_display",
            "column" : "field_trending_name",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_category_blog:name" : {
            "table" : "search_api_db_product_display",
            "column" : "field_category_blog_name",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_tags_blog:name" : {
            "table" : "search_api_db_product_display_field_tags_blog_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_portfolio_categories:name" : {
            "table" : "search_api_db_product_display_field_portfolio_categories_n",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:commerce_price:amount_decimal" : {
            "table" : "search_api_db_product_display_field_product_store_commerce",
            "column" : "value",
            "type" : "list\\u003Cdecimal\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:field_color:name" : {
            "table" : "search_api_db_product_display_field_product_store_field__1",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_product_store:field_size:name" : {
            "table" : "search_api_db_product_display_field_product_store_field__2",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
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
