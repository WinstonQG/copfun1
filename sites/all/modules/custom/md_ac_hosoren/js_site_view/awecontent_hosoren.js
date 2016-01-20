(function ($) {
    'use strict';
    $(document).ready(function () {
        // Products
        setTimeout(function(){
            var $products = $('.products.owl-carousel');
            // Render owlCarousel
            $products.each(function () {
                var $carousel = $(this);
                var data = $carousel.data();

                var items = $carousel.data('items');
                if (!items) items = 4;

                // Responsive
                var responsive = {};

                if (items == 4) {
                    responsive = {
                        0: {items: 1},
                        480: {items: 2},
                        768: {items: 3},
                        980: {items: 4}
                    };
                } else if (items == 3) {
                    responsive = {
                        0: {items: 1},
                        480: {items: 2},
                        768: {items: 2},
                        992: {items: 3}
                    };
                }

                // Default setting
                var sDefault = {
                    navigation: true,
                    pagination: false,
                    items: items,
                    responsive: responsive
                };

                $carousel.owlCarousel($.extend(sDefault, data));
            });


            // blog
            var $cNews = $('.home-section-posts.owl-carousel, .Awe_blog');

            // Render owlCarousel
            $cNews.each(function () {
                var $carousel = $(this);
                var data = $carousel.data();

                var items = $carousel.data('items');

                // Default setting
                var sDefault = {
                    items: 2,
                    navigation: true,
                    pagination: false,
                    responsive: {
                        320: {items: 1},
                        480: {tems: 2}
                    }
                };

                $carousel.owlCarousel($.extend(sDefault, data));
            });


            /* Testimonial */
            function aweTestimonialMasonry(e) {
                e || (e = $(".testimonial-masonry")), e.imagesLoaded(function () {
                    e.masonry({
                        itemSelector: ".column",
                        columnWidth: ".column"
                    })
                })
            }

            aweTestimonialMasonry();

            /* Customer Js*/
            function CustomerCarousel() {
                $('.customers-carousel').owlCarousel({
                    items: 1,
                    navigation: false,
                    pagination: true,
                    margin: 30,
                });
            }

            CustomerCarousel();
        }, 3000)

    });
})(jQuery);