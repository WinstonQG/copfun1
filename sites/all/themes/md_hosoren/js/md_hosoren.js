(function ($) {

		$(window).load(function() {
        if (window.SHOW_LOADING) {
            var $body = $('body')
            $body.addClass('awe-body-loading');

            setTimeout(function() {
                $body.removeClass('awe-body-loading');
                $('.awe-page-loading').fadeOut(250);
            }, 1500);
        } else {
            $('.awe-page-loading').remove();
        }
    });

    $(document).ready(function () {

        $(function () {
            aweBlogMasonry();
            aweNewsBlogCarousel();
            aweDocsListIcons('fontawesome-icons');
        });

        /* Cart Number */
        $('.cart-icon > a.awemenu-item-link').append('<i class="icon icon-glyph-1"></i>');
        if ($('.cart-icon ul').hasClass('whishlist')) {
            var cartNumber = $('.cart-icon ul.whishlist li').length;
            $('.cart-icon > a.awemenu-item-link i').append('<span class="cart-number">' + cartNumber + '</span>');
        }

        // Add icon Search form
        $('.menubar-search-form .form-actions').append('<i class="icon icon-glyph-11"></i>');
        $('.header-style-1 #block-md-block-custom-mls-search-block').wrap('<div class="search-wrap"></div>');

        // Close Search form when Click
        $('.menubar-search-form .form-actions i').on('click', function (e) {
            $('.menubar-search-form').removeClass('open');
        });

        function aweNewsBlogCarousel() {
            $(".home-section-posts.owl-carousel").owlCarousel({
                items: 2,
                navigation: true,
                pagination: false,
                responsive: {
                    320: {items: 1},
                    480: {items: 2}
                }
            })
        }

        function aweTestimonialMasonry(e) {
            e || (e = $(".testimonial-masonry")), e.imagesLoaded(function () {
                e.masonry({
                    itemSelector: ".column",
                    columnWidth: ".column"
                })
            })
        }
        $(function () {
            aweTestimonialMasonry();
        });



        /* Product Single */
        if ($('.product-slider-main').length > 0) {
            aweProductRender(true);
        }

        if ($('.product-quickview-slider').length > 0) {
            $('.product-quickview-slider').owlCarousel({
                items: 1,
                navigation: true,
                pagination: false
            });
        }



        /* Product Grid */
        $('.quick-view-product').click(function () {
            var productID = $(this).attr('data-node-modal');
            $(this).closest('.product-grid').find('.' + productID).addClass("modal-quickview");
            return false;
        });
        $(document).click(function (e) {
            var select = $(e.target);
            if (select.is(".mfp-wrap") || select.is(".mfp-container") || select.is(".mfp-content") || select.is(".mfp-close"))
                $('.modal-product').removeClass("modal-quickview");
        });
        $('.product-grid .product-add-cart').click(function () {

            var node = $(this).attr('data-node-cart');
            $(this).closest('.product-grid').find('.' + node).find('.commerce-add-to-cart .form-submit').trigger('click');
            return false;
        });

        /* Sidebar Accordion */
        if ($('.category_accordion').has('a.active').length > 0) {
            var $this = $('.category_accordion').has('a.active');
            $this.addClass("active");
        }
        ;

        var acc_active = $(".category_accordion h5"),
                acc_body = $(".category_accordion ul");
        acc_active.click(function (e) {
            if ($(e.target).is("a"))
                return;
            var content_show = $(this).parent().find('ul');
            if (content_show.is(":visible")) {
                acc_body.slideUp('normal');
                $(this).removeClass('active');
                return false;
            }
            else {
                acc_body.slideUp('normal');
                content_show.slideDown('normal');
                acc_active.removeClass('active');
                $(this).addClass('active');
                return false;
            }
        });

        /* Sidebar nano scroll */
        if ($(".scroll-face .widget-content").length > 0) {
            $(".scroll-face .widget-content").nanoScroller({
                alwaysVisible: false,
                contentClass: 'item-list',
                paneClass: 'pane',
                sliderClass: 'slider',
            })
        }

        $.fn.NanoScroller = function () {
            $(this).nanoScroller({
                alwaysVisible: !0
            })
        }
        if ($.fn.NanoScroller) {
            $('.nano').NanoScroller();
        }
        $(".wishlist-icon, .cart-icon").click(function () {
            $(window).trigger('resize');
        });

        /* list slider product */
        if (!$.fn.owlCarousel) {
            throw 'jQuery owlCarousel must loaded before the script.';
        }
        var $products = $('.products.owl-carousel');
        $products.each(function () {
            var $carousel = $(this);
            var data = $carousel.data();

            var items = $carousel.data('items');
            if (!items)
                items = 4;

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


        /* Product sidebar face */
        function faceactivelink(linkfa) {
            if (linkfa.length > 0) {
                linkfa.html("(x) ");
                linkfa.parent().addClass("li-face-active");
            }
        }
        faceactivelink($('ul.facetapi-facetapi-links li a.facetapi-active'));
        faceactivelink($('ul.facetapi-search-api-ranges-ui-links li a.facetapi-active'));


        //Twitter Footer
        if ($('#block-awe-twitter').length) {
            $('#block-awe-twitter').twittie({
                dateFormat: '%b/%d/%Y',
                template: '<div class="tweet-content">{{tweet}}</div><div class="tweet-time"><a href="{{url}}">{{date}}</a></div>',
                count: 2,
                hideReplies: true,
                loadingText: "Loading!"
            });
        }
        //HeadRoom
        $(window).load(function () {
            if ($('.header-style-default').length) {
							var onMobile = false;

                if (/Android|webOS|iPhone|iPad|iPod|BlackBerry/i.test(navigator.userAgent)) {
                    onMobile = true;
                } 
								if (onMobile == false){
										$('.header-style-default').headroom({
												offset: 500,
										});
										
                    $offset_header = 0;
                    // if ($('#admin-menu').length>0){
                    //   $offset_header = $('#admin-menu').height();
                    // }
                    //if ($("#toolbar").length > 0) {
                    //    $offset_header = $("#toolbar").height();
                    //}
                    $padding_top = $offset_header + $('.header-style-default').height();
                    if ($(".main-header").length > 0) {
                        $padding_top = $padding_top + 60;
                        $('.main-header').css("padding-top", $padding_top + 'px');
                    } else {
                        $('#main').css("padding-top", $padding_top + 'px');
                    }



                    $('.header-style-default').headroom('init');
                }
            }
        });
        /* Customer Js*/
        function CustomerCarousel() {
            $('.customers-carousel').owlCarousel({
                items: 1,
                navigation: false,
                pagination: true,
                margin: 30,
                responsive: {
                    320: {items: 1},
                    480: {items: 1},
                    640: {items: 1}
                }
            });
        }
        CustomerCarousel();
        
        /*Portfolio js*/
        $(function () {
            var class1 = '.lasted-portfolio-carousel';
            var class2 = '.image';
            if (class1.length > 0 || class2.length > 0) {
                aweProfolioDetail();
            }
        });
        $(function () {
            aweProfolioIsotope();
        });
        $(function () {
            $('a[href="#login-popup"]').magnificPopup({
                type: 'inline',
                midClick: false,
                closeOnBgClick: false
            });
        });

    });



})(jQuery);
