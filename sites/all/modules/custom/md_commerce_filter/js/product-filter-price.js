(function($){
  Drupal.behaviors.productFilterPrice = {
    attach: function(context, settings) {
      
      PriceSlider();
      /*==========  Price Slider ==========*/
      function PriceSlider(){
          if($('.range-slider-bar').length) {
              $(".range-slider-bar").slider({
                  min: parseInt(Drupal.settings.priceFilter.setting.config_price_min),
                  max: parseInt(Drupal.settings.priceFilter.setting.config_price_max),
                  step: 5,
                  values: [ 
                    parseInt(Drupal.settings.priceFilter.setting.price_min), 
                    parseInt(Drupal.settings.priceFilter.setting.price_max) 
                  ],
                  range: true,
                  slide: function( event, ui ) {

                      var $this=$(this),

                          values=ui.values;

                      $('#range-price-min').text('$'+values[0]);

                      $('#range-price-max').text('$'+values[1]);

                  }
              });

              var values = $( ".range-slider-bar" ).slider( "option", "values" )

              $('#range-price-min').text('$'+values[0]);

              $('#range-price-max').text('$'+values[1]);
          }
      }
    
      
      
      
      function productFilters(jquery) {
        this.jquery = jquery;
      };  
      productFilters.prototype.filter = function (queryString) {
        window.location.href = Drupal.settings.priceFilter.setting.baseUrl + '?' + queryString;
      }
      
      productFilters.prototype.buildQueryString = function (data) {
        var currentFilters = Drupal.settings.priceFilter.setting.currentFilters;
        currentFilters = this.jquery.extend(currentFilters, data);
        return this.jquery.param(currentFilters);
      }
    
      var filterContainer = $('.filter-price-slider');
      productFilter = new productFilters($);
      filterContainer.find('.btn-filter').click(function(event) {
        event.preventDefault();
        
        var data = {};
        
        // Get price
        var values = $( ".range-slider-bar" ).slider( "option", "values" );
        data.price_min = values[0];
        data.price_max = values[1];
        
        var queryString = productFilter.buildQueryString(data);
        productFilter.filter(queryString);
      });
    
    // End attach
    }
  }
})(jQuery);
