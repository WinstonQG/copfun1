/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
(function ($) {
    Drupal.behaviors.footer = {
        attach: function (context, settings) {

            //GET DATABASE FOOTER DEFAULT
            getfooterfromDB = function () {
                if($('#region-data', context).val() == ',,,'){
                    $('#region-data', context).val('3,3,3,3') ;
                };
                var listText = $.trim($('#region-data', context).val()),
                        listArray = listText.split(","),
                        html = '';
                console.log(listArray);
                
                var ChooseCollumn = $.trim($('#select-collumn', context).val());
                console.log(ChooseCollumn);
                switch (ChooseCollumn) {
                    case '2' :
                        var class_four = 'display-none';
                        break;
                    case '3' :
                        var class_three = 'display-none';
                        var class_four = 'display-none';
                        break;
                    case '4' :
                        var class_two = 'display-none';
                        var class_three = 'display-none';
                        var class_four = 'display-none';
                        break;
                }
                html += '<div id="region-one" class="awe-region region-one region-' + listArray[0] + '" data-column="' + listArray[0] + '"><div class="footer-text">Footer 1</div></div>'
                        + '<div id="region-two" class="xxx awe-region region-two region-' + listArray[1] + ' ' + class_two + '" data-column="' + listArray[1] + '"><div class="footer-text">Footer 2</div></div>'
                        + '<div id="region-three" class="awe-region region-three region-' + listArray[2] + ' ' + class_three + '" data-column="' + listArray[2] + '"><div class="footer-text">Footer 3</div></div>'
                        + '<div id="region-four" class="awe-region region-four region-' + listArray[3] + ' ' + class_four + '" data-column="' + listArray[3] + '"><div class="footer-text">Footer 4</div></div>';
                $('.wrap-region', context).html(html);
            }
            getfooterfromDB();


            // FUNCTION RESIZE
            $(".awe-region").each(function () {
                var self = $(this);
                $(this).resizable({
                    handles: "e",
                    minWidth: 50,
                    maxWidth: 600,
                    stop: function (event, ui) {
                        var width = ui.size.width,
                                regionData = [],
                                column = parseInt(width / 50);
                        self.removeClass().addClass('awe-region ui-resizable region-' + column);
                        self.addClass('awe-region ui-resizable region-' + column);
                        self.attr('data-column', column);
                        self.css({'width': ''})
                        $('.awe-region').each(function () {
                            var regionColum = $(this).attr('data-column');
                            regionData.push(
                                    regionColum
                                    )
                        });
                        $('#region-data').val(regionData);
                        console.log($('#region-data').val());

                    }});
            });

            // FUNCTION SET COLUMN FOOTER
            $("#select-collumn").bind('change', function () {
                switch ($('#select-collumn').val()) {
                    case '4':
                        $('#region-four').addClass('display-none');
                        $('#region-three').addClass('display-none');
                        $('#region-two').addClass('display-none');
                        break;
                    case '3':
                        $('#region-two').removeClass('display-none');
                        $('#region-four').addClass('display-none');
                        $('#region-three').addClass('display-none');
                        break;
                    case '2':
                        $('#region-two').removeClass('display-none');
                        $('#region-three').removeClass('display-none');
                        $('#region-four').addClass('display-none');
                        console.log('casee 2');
                        break;
                    case '1':
                        $('#region-two').removeClass('display-none');
                        $('#region-three').removeClass('display-none');
                        $('#region-four').removeClass('display-none');
                }
                ;
            });
        }
    };
})(jQuery);