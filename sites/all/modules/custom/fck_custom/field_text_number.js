(function($) {		
  	Drupal.behaviors.fieldTextNumber = {
      
	    attach: function(data, settings) {    		    	
	    	var typingTimer;
			var doneTypingInterval = 600;

	    	$('input[id*="field-text-number"]').on('keyup', function (e) {
			  	if (e.which == 46 || e.which == 8 || 
	    			(e.which <= 90 && e.which >= 48) || 
	    			(e.keyCode >= 96 && e.keyCode <= 105)) {
					clearTimeout(typingTimer);
					if ($(this).val) {
						var trigid = $(this);
						typingTimer = setTimeout(function(){                    
							trigid.triggerHandler('finishedinput');
						}, doneTypingInterval);			    
					}
				}
			});

			$(document).ajaxComplete(function(event, request, settings) {
				if (settings.extraData == undefined || 
					settings.extraData._triggering_element_name == undefined) {
			  		return;
			  	}			  			  			  
			  	var id = settings.extraData._triggering_element_name;			  
			  	if (id !== undefined && id.indexOf('field_text_number') !== -1) {
			  		$('input[id*="field-text-number"]').focus();
			  	}			
			});
	    }
	};

})(jQuery);