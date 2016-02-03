;(function($, aweHosoren) {
    'use strict';

    /**
     * //
     *
     * @type {aweHosoren}
     */
    var hosoren = window.aweHosoren || {};

    /**
     * //
     *
     * @return {void}
     */
    hosoren.init = function() {
        this.bootstrapCore();
        this.bootstrapNanoScroller();
        this.bootstrapCarousel();
        this.bootstrapBacktop();
        this.bootstrapBackgroundParallax();
        this.bootstrapToogle();
        //this.bootstrapProductsThumbSwap();
    };

    hosoren.bootstrapProductsThumbSwap = function() {
        $('.product.product-grid, .product.product-list').each(function() {
            var $product = $(this);
            var $thumbs  = $product.find('.product-thumbnail');
            var $images  = $thumbs.find('img');

            if ($images.length <= 1) return;

            var interval, timeout;

            var imageCallback = function() {
                var $current = $thumbs.find('img.current');
                var $next = $current.next();

                if ($next.index() < 0) $next = $images.first();

                $current.removeClass('current');
                $next.addClass('current');
            };

            var setCurrent = function() {
                $images.removeClass('current');
                $images.first().addClass('current');
            };

            setCurrent();

            $product.hover(function() {
                timeout  = setTimeout(function() {
                    imageCallback();
                    interval = setInterval(imageCallback, 2500);
                }, 200);
            }, function() {
                clearTimeout(timeout);
                clearInterval(interval);
                setCurrent();
            });
        });
    }

    /**
     * //
     *
     * @return {void}
     */
    hosoren.bootstrapCore = function() {
        $('[data-toggle="tooltip"]').tooltip();
    };

    /**
     * //
     *
     * @return {void}
     */
    hosoren.bootstrapNanoScroller = function() {
        $('.nano').nanoScroller({
            alwaysVisible: true,
        });
    };

    /**
     * //
     *
     * @return {void}
     */
    hosoren.bootstrapCarousel = function() {
        $('.entry-carousel.owl-carousel').each(function() {
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

        $('[data-toggle="carousel"]').each(function() {
            var $carousel = $(this);

            var sDefault = {
                items: 1,
                pagination:  false,
                navigation:   false
            };

            $carousel.owlCarousel($.extend(sDefault, $carousel.data()));
        });
    };

    /**
     * //
     *
     * @return {void}
     */
    hosoren.bootstrapBacktop = function() {

        var handleScrollTop = function(e) {
            e.preventDefault();
            $('html, body').animate({ scrollTop: 0 }, 250);
        };

        $('footer > .back-top').on('click', function(e) {
            handleScrollTop(e);
        });

        $('.awemenu-nav').on('click', function(e) {
            var $target = $(e.target);

            if ($target && $target.hasClass('awemenu-nav')) {
                handleScrollTop(e);
            }
        });
    };

    /**
     * //
     *
     * @return {void}
     */
    hosoren.bootstrapBackgroundParallax = function() {
        $('.background.background-parallax').parallax('50%', 0.2);
    };

    /**
     * //
     *
     * @return {void}
     */
    hosoren.bootstrapAnimate = function() {
        var self = this;

        $('[data-animation]').each(function() {
            var $el = $(this);

            self.beforeAnimation($el);
            self.renderAnimation($el);
        });
    };

    /**
     * //
     *
     * @return {void}
     */
    hosoren.beforeAnimation = function($el) {
        $el.css({'opacity': 0});
    };

    /**
     * //
     *
     * @return {void}
     */
    hosoren.renderAnimation = function($el) {
        var timeout = 0;
        var animation = $el.data('animation');

        if ($el.data('animation-timeout')) {
            timeout = $el.data('animation-timeout');
        }

        if (!$el.hasClass('animated')) {
            $el.addClass('animated');
        }

        setTimeout(function() {
            $el.animate({opacity: 1});
            $el.addClass(animation);
        }, timeout);

        $el.one('webkitAnimationEnd mozAnimationEnd MSAnimationEnd oanimationend animationend', function() {
            $el.removeClass(animation);
        });
    };

    /**
     * //
     *
     * @return {void}
     */
    hosoren.bootstrapToogle = function() {
        $('[data-toggle="toggle"]').each(function() {
            var $node = $(this);
            var $target = $($(this).data('target'));

            $node.on('click', function() {
                if ($target.is(':hidden')) {
                    $target.show();
                } else {
                    $target.hide();
                }
            });
        });
    };

    /**
     * //
     *
     * @type {aweHosoren}
     */
    window.aweHosoren = hosoren;

})(window.jQuery, window.aweHosoren);
