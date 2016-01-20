(function ($) {

    $(document).ready(function () {

				var endDate = String($('.countdown-soon').data('time'));
        $('#countdown-time').countdown(endDate, function(e) {
            $(this).find('.days > span').text(e.offset.totalDays);
            $(this).find('.hours > span').text(e.offset.hours);
            $(this).find('.minutes > span').text(e.offset.minutes);
            $(this).find('.seconds > span').text(e.offset.seconds);
        });


    });

})(jQuery);