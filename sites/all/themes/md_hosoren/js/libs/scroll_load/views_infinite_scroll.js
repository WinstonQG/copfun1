(function ($) {

    /**
     * Attach infinite scroll to the relevant views.
     */

    Drupal.behaviors.views_infinite_scroll = {
        attach: function (context, settings) {

            // Make sure that autopager plugin is loaded.
            // Load Image
            function loadImg(options, callback) {
                var seconds = 0,
                        maxSeconds = 10,
                        complete = false,
                        done = false;

                if (options.maxSeconds) {
                    maxSeconds = options.maxSeconds;
                }

                function tryImage() {
                    if (done) {
                        return;
                    }
                    if (seconds >= maxSeconds) {
                        callback({err: 'timeout'});
                        done = true;
                        return;
                    }
                    if (complete && img.complete) {
                        if (img.width && img.height) {
                            callback({img: img});
                            done = true;
                            return;
                        }
                        callback({err: '404'});
                        done = true;
                        return;
                    } else if (img.complete) {
                        complete = true;
                    }
                    seconds++;
                    callback.tryImage = setTimeout(tryImage, 1000);
                }
                var img = new Image();
                img.onload = tryImage();
                img.src = options.src;
                tryImage();
            }
            if (!$.autopager) {
                return;
            }

            var settings = settings.views_infinite_scroll[0];

            // Ensure we are refreshing the view component.
            var view_selector = 'div.view-id-' + settings.view_name + '.view-display-id-' + settings.display;
            var $view = $(context).is(view_selector) ? $(context) : $(context).find(view_selector);
            if ($view.length == 0) {
                return;
            }

            // Destroy an existing instance of autopager.
            $.autopager('destroy');

            var content_selector = view_selector + ' > ' + settings.content_selector;
            var $items = $view.find(settings.items_selector);
            var $pager = $view.find('> div.item-list ' + settings.pager_selector);
            var next_selector = view_selector + ' ' + settings.next_selector;
            var $next = $(next_selector);

            var $img_location = $view.find('div.view-content');
            var img_path = settings.img_path;
            var img = '<div id="views_infinite_scroll-ajax-loader"><img src="' + img_path + '" alt="loading..."/></div>';
            $($pager).hide();
            $.autopager({
                appendTo: content_selector,
                content: content_selector + ' ' + settings.items_selector,
                link: next_selector,
                page: 0,
                autoLoad: !settings.manual_load,
                start: function () {
                    $img_location.after(img);
                    //console.log('thanhz');

                    /*custom for  LOAD MORE + ISOTOPE <= width => content_selector === .view-content*/
                    $('.views-row', content_selector).addClass('load-done');
                },
                load: function (current, next) {
                    $('div#views_infinite_scroll-ajax-loader').remove();
                    Drupal.attachBehaviors(this);
                    // Use >= because of views page numbers begin at 0.
                    if (settings.manual_load && next.page >= settings.pager_max) {
                        $next.hide();
                    }

                    var $container = $(content_selector);
                    //console.log($container);
                    var newElements = $('.views-row', content_selector).not(".load-done");

                    var $grid = $container.masonry({
                        columnWidth: '.column',
                        itemSelector: '.column'
                    });
                    $grid.imagesLoaded(function () {
                        $grid.masonry('appended', newElements, true);
                        // JS for testimonial
                    });



                    $('.entry-carousel:not(.owl-carousel-inset)').each(function () {
                        var $carousel = $(this);
                        if (! $carousel.hasClass('owl-carousel-inset')) {
                            $carousel.addClass('owl-carousel-inset');
                        }

                        $carousel.owlCarousel({
                            items: 1,
                            navigation: true,
                            pagination: false,
                            singleItem:true
                        });
                    });

                }
            });

            if (settings.manual_load) {
                // The pager is hidden. Pop "next" link out so it will be visible.
                $next.text(settings.text);
                $next.click(function (e) {
                    e.preventDefault();
                    // do load
                    $.autopager('load');
                });
                $($pager).before($next);
                // Wrap the button to allow for easier styling in the theme
                $next.wrap('<div id="views_infinite_scroll_button" />');
            }
            else {
                $($pager).hide();
                // Trigger autoload if content height is less than doc height already
                var prev_content_height = $(content_selector).height();
                do {
                    var last = $($items).filter(':last');
                    if (last.offset().top + last.height() < $(document).scrollTop() + $(window).height()) {
                        last = $($items).filter(':last');
                        $.autopager('load');
                    }
                    else {
                        break;
                    }
                }
                while ($(content_selector).height() > prev_content_height);
            }
        }
    };

})(jQuery);
