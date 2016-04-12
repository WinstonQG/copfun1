(function($) {		
	
  	Drupal.behaviors.jerseyPrintPreview = {
      
	    attach: function(data, settings) { 	    		    	 	    		    	
	    	var work_container = $(".work_container", data);
	    	if (!work_container.size()) {
	    		return;
	    	}

	    	var labelText = work_container.data('label-text');
	    	labelText = labelText === '-' ? '' : labelText;
	    	var numberText = work_container.data('number-text');
	    	numberText = numberText === '-' ? '' : numberText;

	    	var inputName =  $(".name_input", data);	    	
		    var nameInsEl = $("#name_inscription", data);
		    var namberInscrEl = $('#number_inscription', data);

		    var nameInsElWids = nameInsEl.css('width');
		    var nameInsElHeight = nameInsEl.css('height');
		    var nextLetter;
		    var nameCss = {
		        el : [],
		        length : 0,
		        width : [],
		        height : [],
		        transformRotate : [],
		        angleOfRotation : 4
		    };		    
		        
	        nextLetter = ''+ labelText;	        
	        nameCss.length = nextLetter.length;

	        if(nextLetter !== '' && nameCss.length < 13 ) {
	            nameInsEl.html('');
	            for(var i=0; i < nameCss.length; i++){	            	
	                var newLetterDiv = '<div class= "letter_container" id= "letter_'+ i+'">'+
	                                                nextLetter[i] +
	                                              '</div>';

	                nameInsEl.append(newLetterDiv);                              
	                nameCss.el = $("#letter_"+ i);

	                var angleOffset = 0.5 * (nameCss.length -1) * nameCss.angleOfRotation;
	                var elRot = i * nameCss.angleOfRotation;
	                nameCss.el.css('transform','rotate('+ (elRot - angleOffset)+'deg)');

	            }
	        }	
	        
	        //if(namStr.length < 3 ) {
	        namberInscrEl.html('');
	        namberInscrEl.append(numberText);

	        //}	        		       		 		    

		    function drawName (nextLetter) {
		       if(nameCss.length < 13 ) {
		            nameInsEl.html('');
		            for(var i=0; i < nameCss.length; i++){

		                var newLetterDiv = '<div class= "letter_container" id= "letter_'+ i+'">'+
		                                                nextLetter[i] +
		                                              '</div>';

		                nameInsEl.append(newLetterDiv);                              
		                nameCss.el = $("#letter_"+ i);

		                var angleOffset = 0.5 * (nameCss.length -1) * nameCss.angleOfRotation;
		                var elRot = i * nameCss.angleOfRotation;
		                nameCss.el.css('transform','rotate('+ (elRot - angleOffset)+'deg)');

		            }


		        }

		    }




		    /*
		    var inputFontSizeEl = $('.font_sz_input');

		    inputFontSizeEl.on('input', function(event){
		        //console.log("inputFontSize   "+ inputFontSizeEl.val());
		        var letterCon = $('.letter_container');
		        letterCon.css('font-size',  inputFontSizeEl.val()+'px');

		        letterCon.css('width', (0.6 * inputFontSizeEl.val())+'px');
		        letterCon.css('margin-left', '-'+(0.3 * inputFontSizeEl.val())+'px');
		    });    



		    var inputFontIntEl = $('.font_int_input');
		    //console.log("nextLetter   "+ nextLetter);
		    inputFontIntEl.on('input', function(event){
		   
		        var inpVal = inputName.val();
		        nameCss.angleOfRotation = inputFontIntEl.val();
		        //console.log("inpVal   "+ inputName.val());
		        //console.log("nameCss.length   "+ nameCss.length);
		        for(var i=0; i < nameCss.length; i++){

		                                                   
		                nameCss.el = $("#letter_"+ i);

		                var angleOffset = 0.5 * (nameCss.length -1) * nameCss.angleOfRotation;

		                var elRot = i * nameCss.angleOfRotation;
		             
		                nameCss.el.css('transform','rotate('+ (elRot - angleOffset)+'deg)');

		            }
		         
		    }); 



		    var inputRadiusEl = $('.radius_input');

		    inputRadiusEl.on('input', function(event){
		        
		        //var oldRad = parseInt($('.name_wrapper').css('height'));
		        //var newRad = Math.round (oldRad * 0.01 * inputRadiusEl.val());
		        var newRad = inputRadiusEl.val();

		        $('.name_wrapper').css('height',  newRad+'px');
		        
		    });    

		    var inputNameOffEl = $('.name_offset_input');

		    inputNameOffEl.on('input', function(event){
		       // var oldTop = parseInt($('.name_wrapper').css('top'));
		        //var newTop = Math.round (oldTop * 0.01 * inputNameOffEl.val());
		        var newTop = inputNameOffEl.val();
		        $('.name_wrapper').css('top',  newTop+'%');
		        
		    }); 

		    // Ð²ÑÑ‚Ð°Ð²Ð»ÑÐµÐ¼ Ð½Ð¾Ð¼ÐµÑ€
		    var namberInpEl = $('.number_input');
		    var namberInscrEl = $('#number_inscription');

		    namberInpEl.on('input paste', function(event){
		        
		        var namStr = (''+ namberInpEl.val());
		        console.log("namberInpEl.val()   "+ namberInpEl.val());

		        if(namStr.length < 3 ) {
		            namberInscrEl.html('');
		            namberInscrEl.append(namberInpEl.val());

		        }   
		    });   



		    
		    var inputNamSzEl = $('.nam_size_input');

		    inputNamSzEl.on('input', function(event){
		   
		        namberInscrEl.css('font-size',  inputNamSzEl.val()+'px');
		        
		    });    

		    var inputNamOffEl = $('.nam_offset_input');

		    inputNamOffEl.on('input', function(event){
		   


		         namberInscrEl.css('top',  inputNamOffEl.val()+'%');
		    });    

			*/
	    }
	};

})(jQuery);