(function ($) {
    var PageSettings;

    PageSettings = function (select, context) {
        var $select = $(select, context),
            self = this;
        this.init = function() {
            self.initAcordion();
            self.updateData();
            self.changeData();
            self.addPage();
        }

        this.initAcordion = function() {
            $select.find('.wrap-accordion').accordion();
        }

        this.updateData = function() {
            var dataJson = $select.find('.page-data').val(),
                dataArray = $.parseJSON(dataJson);
                if (dataArray != undefined && dataArray != null) {
                    $select.find('.wrap-accordion').find(':input').each(function(index, value){
                        if (dataArray[index] != undefined){
                            if($(this).hasClass('header-img-url') && dataArray[index]['value'] != ''){
                               var src = dataArray[index]['value'];
                                $(this).parents('.content').prev().html('<img src="'+src+'" />');
                            }
                            $(this).val(dataArray[index]['value']);
                        }
                    });
                }
                // $('.page-setting-checkbox .input-checkbox').each(function(){
                //     if($(this).val()=="turn_on"){
                //       $(this).prop('checked', true);
                //     }
                //     else{
                //       $(this).prop('checked', false);
                //     }
                // });
        }
        this.changeData = function() {
                // $('.page-setting-checkbox .input-checkbox').change(function(){
                //      if($(this).attr('checked')){
                //           $(this).val('turn_on');
                //      }else{
                //           $(this).val('turn_off');
                //      }
                // });
            $select.find('.wrap-accordion').live('change', function() {
                var dataArray = $select.find('.wrap-accordion').find(':input').serializeArray();
                    // $(".page-setting-checkbox .input-checkbox:not(:checked)").each(function() {
                    //     dataArray.push({name: "enparallax", value: 'turn_off' });
                    // });
                var dataJson = JSON.stringify(dataArray);
                $select.find('.page-data').val(dataJson);
            });


            
        }

        this.addPage = function() {
            var template = '<h3>Page title: </h3>';
                template += '<div class="page-setting"><div class="content header-bg"></div>';
                template += '<div class="content element-invisible"><input class="header-img-url" type="text" name="img-url" value=""></div>';
                template += '<div class="content clear"><span>Page Url: </span> <input type="text" name="page-url" value=""></div>';
                template += '<div class="content"><span>Page Title : </span> <input type="text" name="title" value=""></div>';
                template += '<div class="content"><span>Description : </span> <input type="text" name="description" value=""></div>';
                template += '<div class="margin-small "><span>Color 1: </span> <input class="form-colorpicker" type="text" name="colorone" value=""></div>';
                template += '<div class="margin-small "><span>Color 2: </span> <input class="form-colorpicker" type="text" name="colorsecond" value=""></div>';
                template += '<div class="margin-small "><span>Overlay: </span> <input class="form-colorpicker" type="text" name="overlay" value=""></div>';
                template += '<div class="margin-small md-selection medium"><select class="select form-select" name="sectiontype"><option value="one">Style One</option><option value="two">Style Two</option></select></div>';
                template += '<div class="margin-small md-selection medium"><select class="select form-select" name="backgroundtype"><option value="background">Background</option><option value="parallax">Parallax</option></select></div></div>';

            $select.find('.add-page').click(function(event){
                event.preventDefault();
                $select.find('.wrap-accordion').append(template);
                $select.find('.wrap-accordion').accordion( "refresh" );

                //Color Picker
                if ($.fn.spectrum) {
                    $(".form-colorpicker").spectrum({
                        showAlpha: true,
                        showInput: true,
                        allowEmpty: true,
                        // showInitial: true,
                        preferredFormat: "rgb"
                    });
                }
            });
        }

    }
    Drupal.behaviors.pageSettings = {
        attach: function (context, settings) {
            var pagetype = new PageSettings('#page-type', context),
                pageurl = new PageSettings('#page-url', context);
                pagetype.init();
                pageurl.init();

            $('.header-bg').live('click', function(){
                var _self = $(this);
                Drupal.media.popups.mediaBrowser(function(files) {
                    var image = files[0],
                        url = image['url'],
                        img = '<img src="'+image["url"]+'">';
                    _self.html(img);
                    _self.next().find('input').val(url);
                    var dataArray = _self.parents('.wrap-accordion').find(':input').serializeArray(),
                        dataJson = JSON.stringify(dataArray);
                    _self.parents('.wrap-page-settings').find('.page-data').val(dataJson);
                });
            });

        }
    };
})(jQuery);