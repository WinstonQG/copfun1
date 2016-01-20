(function($) {
    $(document).ready(function(){
       $('.wrap-form-media').each(function(){
            var self = this,
                fid = $(this).find('.input-fid').val();
           $(this).find('.media-delete').hide();
           if (fid > 0) {
               $.post(Drupal.settings.basePath + "?q=creat-image-style", {fid: fid}, function(response) {
                   if (response.status) {
                       var html = '<img src="'+ response.url +'"/>';
                       $(self).find('.media-preview').html(html);
                       $(self).find('.media-delete').show();
                   }
               });
           }
       });


       $('.media-change').click(function(event){
           event.preventDefault();
           var $wrapMedia = $(this).parents('.wrap-form-media');
           Drupal.media.popups.mediaBrowser(function(files) {
               var img = files[0];
               $.post(Drupal.settings.basePath + "?q=creat-image-style", {fid: img.fid}, function(response) {
                   if (response.status) {
                       var html = '<img src="'+ response.url +'"/>';
                       $wrapMedia.find('.media-preview').html(html);
                       $wrapMedia.find('.input-fid').val(img.fid);
                       $wrapMedia.find('.media-delete').show();
                   }
               });
           });
       });
        $('.media-delete').click(function(event){
            event.preventDefault();
            var $wrapMedia = $(this).parents('.wrap-form-media');
            $wrapMedia.find('.media-preview').html('');
            $wrapMedia.find('.input-fid').val(0);
            $(this).hide();
        })

    });
})(jQuery);