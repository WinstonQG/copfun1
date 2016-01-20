/**
 * File: awecontent-text-item.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function($) {
    "use strict";

    /**
     * Define model for heder item
     */
    AWEContent.Models.PricingItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "pricing_awe",

            contentColor: '',
            contentBG: '',
            headerColor: '',
            headerBg: '',
            EnableBorder: 0,
            BorderRadius: '4',
            BorderColor:'',

            enableIcon: 0,
            icon: 'ic ac-icon-help',
            // Iconsize: 'iconbox-2x',
            IconColor: '',
            titlecolor: '',
            title: 'Title Pricing Table',
            titlefontFamily: '',
            titlefontStyle: '',
            titlefontSize: -1,
            titletransform: 'none',
            colorPrice:'',
            price: '69',
            pricefontFamily: '',
            pricefontStyle: '',
            pricefontSize: -1,
            currency: '$',
            perTime: '/mon',
            enableplanbtn: 0,
            planbtn: 'Get a free month',
            enableBorderHeader: 0,
            borderHeaderColor: '',


            enablelisticon: 0,
            listicontext: '[] ',
            enablelistborder: 0,
            enablelistpadding: 0,
            listiconstyle: 'normal',

            enableInfo: 0,
            pricingInfo: 'Sit aspernatur aut odit aut fugit sed quia quuntur.',
            enableNote: 0,
            pricingNote: 'Sit aspernatur aut odit aut fugit sed quia quuntur.',

            
            button_text: 'Button',
            button_link: '#',
            button_target: '_blank',
            button_color: '',
            button_bg: '',
            button_hover_color: '',
            button_hover_bg: '',
            EnableButtonBorder: 0,
            ButtonBorderColor:'',
            // footer_color: '',

            boxModelSettings : {},
            customID : '',
            customClass : '',
            customEnableAttributes: 0,
            customDataAttributes: '[]',// Array Json ex : [{"attrName":"autoPlay","attrValue":"true"}]
            customActionAttributes: '{"newAction": "", "newAttrName": "", "newAttrValue": ""}',
            customEnableAnimations: 0,
            customDataAnimations: '{"type": "none"}', // Data Object {"type":"spinin","duration":"5000","delay":"0","advance":{"direction":"clockwise","numberOfSpin":"3"}}
            lgResponsive: true,
            xsResponsive: true,
            mediumResponsive: true,
            smResponsive: true
        },
        relations: [
            {
                type: Backbone.HasOne,
                key: "boxModelSettings",
                relatedModel: AWEContent.Models.BoxModelSettings
            }
        ],
        createView: function() {
            this.view = new AWEContent.Views.PricingItem({model: this});
        },
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });

            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.PricingItem(cloneModel);
        }
    });

    /**
     * Define View for HeaderItem
     */
    AWEContent.Views.PricingItem = AWEContent.Views.Item.extend({
        initialize: function(){
            AWEContent.Views.Item.prototype.initialize.call(this);
            this.listenTo(this.model.get("boxModelSettings"), "change", this.applySettingsChanged);
        },
        pricingTemplate: _.template(
          '<div class="single-pricing center <%= planbutton %> <%= pricingborder %>">\
              <div class="pricing-head <%= headerborder %>">\
                <i class="<%= icon %>"></i>\
                <h4 class="pricing-heading"><%= title %></h4>\
                <div class="price">\
                  <h3>\
                    <span class="dollar"><%= currency %></span>\
                    <span class="price"><%= price %></span>\
                    <span class="month"><%= perTime %></span>\
                  </h3>\
                </div>\
                <div class="text-center plan-top-btn"><span class="offer"><%= planbtn %></span></div>\
              </div>\
              <div class="pricing-planebt-content">\
                <div class="pricing-info">\
                    <%= info %>\
                </div>\
                <ul class="package-features <%= listiconstyle %> <%= planlist %> <%= palist %>">\
                </ul>\
                <div class="pricing-notes">\
                    <%= notes %>\
                </div>\
              </div>\
              <div class="sign-up">\
                <a href="<%= buttonLink %>" target="<%= buttonTarget %>" class="btn <%= Btnborder %> btn-rounded hover-effect">\
                  <%= buttonText %>\
                </a>\
              </div>\
            </div>'
        ),
        list_pricing: _.template(
          '<% _.each(icontextlist, function(iconlisttext) { %>\
              <li><span class="<%= iconlisttext.icon %>"></span><%= iconlisttext.text %></li>\
          <% }); %>'  
        ),
        styleButton: _.template(
          '.<%= priceClass %> .sign-up a:hover{\
          color: <%= color %> !important;\
          background-color: <%= bgColor %> !important;}\
          '
        ),
        renderItemContent: function() {
            var self= this,
                settings = self.model.toJSON(),
                options = {
                    icon: settings.icon,
                    // IconSize: settings.Iconsize,
                    title: settings.title,
                    currency: settings.currency,
                    price: settings.price,
                    perTime: settings.perTime,
                    planbtn: settings.planbtn,
                    intro: settings.intro,
                    featureList: settings.pricingList,
                    info: settings.pricingInfo,
                    listiconstyle: settings.listiconstyle,
                    notes: settings.pricingNote,
                    buttonLink: settings.button_link,
                    buttonTarget: settings.button_target,
                    buttonText: settings.button_text
                },
                $pricing = $('<div class="awe-pricing-item awe-item"></div>');

                
                if(settings.EnableBorder) options.pricingborder = '';
                else options.pricingborder = 'border-none';

                if(settings.enableBorderHeader) options.headerborder = 'heade_line';
                else options.headerborder = '';

                if(settings.enablelistborder) options.planlist = 'list_border';
                else options.planlist = '';

                if(settings.enablelistpadding) options.palist = 'pading_list';
                else options.palist = '';

                if(settings.EnableButtonBorder) options.Btnborder = 'button-line';
                else options.Btnborder = '';

                
                if (settings.enableplanbtn == 1){
                  options.planbutton = 'pricing-planebt';
                }else{
                  $('.plan-top-btn', $pricing).hide();
                  options.planbutton = '';
                }




                        self.classContent = 'awe-content-' + self.cid;                      
            $pricing.html(self.pricingTemplate(options))
                    .addClass(self.classContent)
                    .renderItemDefaultBoxModel(settings.boxModelSettings);


            var addmorelist = [];
                if (settings.listicontext != []) {
                    addmorelist = JSON.parse(settings.listicontext);
                    $pricing.find('ul.package-features').html(self.list_pricing({icontextlist: addmorelist}));
                }
                if (!settings.enablelisticon)
                    $pricing.find('ul.package-features').hide();


            if (settings.enableIcon == 0)
                $('.pricing-head i', $pricing).hide();
            if (settings.enableInfo == 0)
                $('.pricing-info', $pricing).hide();
            if (settings.enableNote == 0)
                $('.pricing-notes', $pricing).hide();


                        
                        var style = {
                    color: settings.button_hover_color,
                    bgColor: settings.button_hover_bg,
                                        priceClass: self.classContent,
                };
                        

            $('.single-pricing', $pricing).css({
                'border-color' : settings.BorderColor
            });
            $('.single-pricing', $pricing).css({
                'border-radius' : settings.BorderRadius,
                '-webkit-border-radius' : settings.BorderRadius,
                '-moz-border-radius' : settings.BorderRadius
            });
            $('.pricing-head i', $pricing).css({
                'color' : settings.IconColor
            });
            $pricing.find('.pricing-head').css({
                'color' : settings.headerColor,
                'background-color' : settings.headerBg,
                'border-color' : settings.borderHeaderColor,
            });
            $pricing.find('.pricing-heading').css({
                'color' : settings.titlecolor,
            });
            $pricing.find('.price h3').css({
                'color' : settings.colorPrice,
            });
            $pricing.find('.single-pricing').css({
                'color' : settings.contentColor,
                'background-color' : settings.contentBG
            });
            // $pricing.find('.sign-up').css({
            //     'background-color' : settings.footer_color
            // });
            $pricing.find('.sign-up a').css({
                'color' : settings.button_color,
                'background-color' : settings.button_bg,
                'border-color' :  settings.ButtonBorderColor
            });
            $pricing.append('<style>' +self.styleButton(style) + '</style>');


            // font & style for title/price
            var titleStyle = '',
                priceStyle = '';

            titleStyle = {
                'font-family' : settings.titlefontFamily,
                'font-size': settings.titlefontSize == -1 ? '' : (settings.titlefontSize + 'px'),
                'color': settings.titleColor,
            };
            if (settings.titlefontStyle) {
                titleStyle = $.extend({}, titleStyle, JSON.parse(settings.titlefontStyle));
            }


            priceStyle = {
                'font-family' : settings.pricefontFamily,
                'font-size': settings.pricefontSize == -1 ? '' : (settings.pricefontSize + 'px'),
                'color': settings.colorPrice,
            };
            if (settings.pricefontStyle) {
                priceStyle = $.extend({}, priceStyle, JSON.parse(settings.pricefontStyle));
            }
            $('.pricing-heading', $pricing).css("text-transform",settings.titletransform);
            $('.pricing-heading', $pricing).css(titleStyle);
            $('span.price', $pricing).css(priceStyle);




            self.iframeJQuery(this.el).delegate('.awe-pricing-item', "itemReady", function() {
                var heightBefore, heightAfter;
                self.initHallo(self.iframeJQuery(this).find('.pricing-heading'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.dollar'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.month'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('span.price'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.plan-top-btn .offer'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.pricing-info'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.pricing-notes'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.sign-up a'), heightBefore, heightAfter);
            });


            if (settings.customID != '') {
                $pricing.attr('id', settings.customID);
            }
            if (settings.customClass!= '') {
                $pricing.addClass(settings.customClass);
            }
            if (settings.customEnableAnimations) {
                $pricing.processAnimations(settings.customDataAnimations)
            }
            $pricing.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);

            self.$el.defaultResponsive(settings);

            return $pricing;
        },
        applySettingsChanged: function(model) {
            var self = this,
                $pricing = $('.awe-pricing-item', self.el),
                $iconheader = $('.pricing-head i', $pricing),
                $header = $('.pricing-head', $pricing),
                $title = $('.pricing-heading', $pricing),
                $content = $('.pricing-planebt-content', $pricing),
                $footer = $('.sign-up', $pricing),
                settings = model.toJSON(),
                animation, prevAnimation,
                heightBefore = self.$el.height();

            $.each(model.changedAttributes(), function(key, value){
                self.$el.changeResponsive(key, value);
                $pricing.renderChangeSettingBoxModel(key, value, model);
                console.log(key);
                switch (key) {

                    case 'contentColor':
                        $('.single-pricing',  self.$el).css('color', value);
                        break;
                    case 'contentBG':
                        $('.single-pricing',  self.$el).css('background-color', value);
                        break;

                    case 'headerColor':
                        $header.css('color', value);
                        break;
                    case 'headerBg':
                        $header.css('background-color', value);
                        break;

                    case 'EnableBorder':
                        if (value == 0)
                            $('.single-pricing',  self.$el).addClass('border-none');
                        else
                            $('.single-pricing',  self.$el).removeClass('border-none');
                        break;
                    case 'BorderRadius':
                            $('.single-pricing',  self.$el).css('border-radius', value);
                            $('.single-pricing',  self.$el).css('-webkit-border-radius', value);
                            $('.single-pricing',  self.$el).css('-moz-border-radius', value);
                        break;
                    case 'BorderColor':
                            $('.single-pricing',  self.$el).css('border-color', value);
                        break;



                    case 'icon':
                        var prevIcon = self.model.previousAttributes().icon;
                        $iconheader.removeClass(prevIcon).addClass(value);
                        break;
                    case 'enableIcon':
                        if (value == 1)
                            $iconheader.show();
                        else
                            $iconheader.hide();
                        break;
                    case 'IconColor':
                        $iconheader.css('color', value);
                        break;
                    // case 'Iconsize':
                    //     if (value)
                    //         $iconheader.removeClass('iconbox-2x iconbox-3x').addClass(value);
                    //     break;

                    case 'titlecolor':
                        $title.css('color', value);
                        break;
                    case 'titletransform':
                        $title.css('text-transform', value);
                        break;
                    case 'titlefontFamily':
                        if (value == 'Default')
                            $('h4.pricing-heading', $header).css('font-family', '');
                        else
                            $('h4.pricing-heading', $header).css('font-family', value);
                        break;
                    case 'titlefontStyle':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '100',"font-style":""};
                        $('h4.pricing-heading', $header).css(fontStyle);
                        break;
                    case 'titlefontSize':
                        value == -1 ? $('h4.pricing-heading', $header).css('font-size', '') : $('h4.pricing-heading', $header).css('font-size',value + 'px');
                        break;

                    case 'colorPrice':
                        $('.price h3', $pricing).css('color', value);
                        break;
                    case 'pricefontFamily':
                        if (value == 'Default')
                            $('span.price', $header).css('font-family', '');
                        else
                            $('span.price', $header).css('font-family', value);
                        break;
                    case 'pricefontStyle':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '100',"font-style":""};
                        $('span.price', $header).css(fontStyle);
                        break;
                    case 'pricefontSize':
                        value == -1 ? $('span.price', $header).css('font-size', '') : $('span.price', $header).css('font-size',value + 'px');
                        break;


                    case 'enableplanbtn':
                        if (value == 0){
                          $('.single-pricing',  self.$el).removeClass("pricing-planebt");
                          $('.plan-top-btn', $header).hide();
                        }
                        else{
                          $('.single-pricing',  self.$el).addClass("pricing-planebt");
                          $('.plan-top-btn', $header).show();
                        }
                        break;
                    case 'enableBorderHeader':
                        if (value == 0)
                            $header.removeClass('heade_line');
                        else
                            $header.addClass('heade_line');
                        break;             
                    case 'borderHeaderColor':
                        $header.css('border-color', value);
                        break;    


                    // Content
                    case 'enablelisticon':
                        if (value == 0)
                            $content.find('ul.package-features').hide();
                        else
                            $content.find('ul.package-features').show();
                        break;
                    case 'listicontext':
                        var addmorelist = [];
                        if (settings.listicontext != [] && settings.enablelisticon == 1) {
                            addmorelist = JSON.parse(settings.listicontext);
                            $content.find('ul.package-features').html(self.list_pricing({icontextlist: addmorelist}));
                        }
                        break;
                    case 'enablelistborder':
                        if (value == 0)
                            $content.find('ul.package-features').removeClass('plan_list');
                        else
                            $content.find('ul.package-features').addClass('plan_list');
                        break;  
                    case 'enablelistpadding':
                        if (value == 0)
                            $content.find('ul.package-features').removeClass('pading_list');
                        else
                            $content.find('ul.package-features').addClass('pading_list');
                        break;
                    case'listiconstyle':
                          $('ul.package-features', $content).removeClass('normal icon_position').addClass(value);
                        break;

                    case 'enableInfo':
                        if (value == 0)
                            $('.pricing-info', $content).hide();
                        else
                            $('.pricing-info', $content).show();
                        break;
                    case 'enableNote':
                        if (value == 0)
                            $('.pricing-notes', $content).hide();
                        else
                            $('.pricing-notes', $content).show();
                        break;


                    // Button
                    case 'button_link':
                        $footer.find('a').attr('href', value);
                        break;
                    case 'button_target':
                        $footer.find('a').attr('target', value);
                        break;
                    case 'button_color':
                        $footer.find('a').css('color', value);
                        break;
                    case 'button_bg':
                        $footer.find('a').css('background-color', value);
                        break;
                    case 'button_hover_color':
                    case 'button_hover_bg':
                        if (self.updateColor)
                            clearTimeout(self.updateColor);
                        self.updateColor = setTimeout(function() {
                            var style = self.styleButton({
                               color: settings.button_hover_color,
                               bgColor: settings.button_hover_bg,
                                                             priceClass: self.classContent,
                            });
                            $pricing.find('style').html(style);
                            // clear timeout
                            self.updateColor = false;
                        }, 100);
                        break;

                    
                    case 'EnableButtonBorder':
                        if (value == 0)
                            $('a.btn', $footer).removeClass('button-line');
                        else
                            $('a.btn', $footer).addClass('button-line');
                        break;
                    case 'ButtonBorderColor':
                        $footer.find('a.btn').css('border-color', value);
                        break;

                    // case 'footer_color':
                    //     $footer.css('background-color', value);
                    //     break;




                    case 'customID':
                        $pricing.attr('id', value);
                        break;
                    case 'customClass':
                        var prev_class = self.model.previousAttributes().customClass;
                        $pricing.removeClass(prev_class).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $pricing.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;
                    case 'customActionAttributes':
                        $pricing.renderChangeSettingsAttributes(key, value);
                        break;
                    case 'customEnableAnimations':
                        var animation, prevAnimation;
                        if (value) {
                            animation = settings.customDataAnimations;
                            prevAnimation = null;
                            $pricing.processAnimations(animation);
                        }
                        else {
                            animation = null;
                            prevAnimation = settings.customDataAnimations;
                            $pricing.processAnimations(animation, prevAnimation);
                        }

                        break;
                    case 'customDataAnimations':
                        var animation, prevAnimation;
                        animation = settings.customDataAnimations;
                        prevAnimation = self.model.previousAttributes().customDataAnimations;
                        $pricing.processAnimations(animation, prevAnimation);
                        break;
                }
            });

            // Listen event change height of item
            setTimeout(function() {
                self.checkChangeHeight(heightBefore);
            }, 50);
        },
        changeContent : function(el, select){
            var _html = $(el.currentTarget).html();
            switch (select.selector) {
                case '.pricing-heading':
                    this.model.set('title', _html);
                    break;
                case '.dollar':
                    this.model.set('currency', _html);
                    break;
                case '.month':
                    this.model.set('perTime', _html);
                    break;
                case 'span.price':
                    this.model.set('price', _html);
                    break;
                case '.plan-top-btn .offer':
                    this.model.set('planbtn', _html);
                    break;
                case '.pricing-info':
                    this.model.set('pricingInfo', _html);
                    break;
                case '.pricing-notes':
                    this.model.set('pricingNote', _html);
                    break;
                case '.sign-up a':
                    this.model.set('button_text', _html);
                    break;
            }
        },
        initHallo: function(select, heightBefore, heightAfter) {
            var self = this;
            select.hallo({
                plugins: {
                    halloformat: {
                        formattings: {
                            bold: true,
                            italic: true,
                            underline: true,
                            strikethrough: true
                        }
                    },
                    hallojustify: {},
                    hallolists: {
                        lists: {
                            ordered: true,
                            unordered: true
                        }
                    }
                },
                create : function(){
                    this.addEventListener("paste", function(e) {
                        e.preventDefault();
                        var text = e.clipboardData.getData("text/plain");
                        AWEContent.documentIframe.execCommand("insertHTML", false, text);

                    });
                },
                editable: true,
                activate: function (event) {
                    heightBefore = $(event.target).height();
                },
                deactivated: function(event) {
                    self.changeContent(event, select);
                    heightAfter = $(event.target).height();
                    if (heightAfter != heightBefore) {
                        self.resizeItem();
                    }
                }
            });
        },
    });

    /**
     * Define view for Header Controller
     * li tag what is contained by items panel
     */
    AWEContent.Views.PricingItemController = AWEContent.Views.ItemController.extend({
        machineName : 'pricing_awe',
        controllerHtml: function() {
            return '<div class="title-icon">Pricing Table</div><i class="ic ac-icon-text"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.PricingItem(templateData);
            }
            return new AWEContent.Models.PricingItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define header panel
     */
    AWEContent.Views.PricingPanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel pricing-panel",
        panelName: "pricing_awe",
        initPanel: function() {
            AWEContent.Views.ItemPanel.prototype.initPanel.call(this);
            var self = this;

            // General          
            $('#pricing-awe-bg-content', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('contentBG', color);
            });
            $('#pricing-awe-text-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('contentColor', color);
            });
            $('#pricing-awe-bg-header', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('headerBg', color);
            });
            $('#pricing-awe-color-header', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('headerColor', color);
            });  
            // $('#pricing-awe-footer-color', this.$el).change(function(event, color) {
            //     if (color)
            //         color = color.toRgbString();
            //     else
            //         color = '';
            //     self.editingModel.set('footer_color', color);
            // });

            // Border
             $('#pricing-awe-enable-border input', this.$el).change(function (event, scrollEdit) {
                if (!scrollEdit) {
                    self.editingModel.set('EnableBorder', parseInt($(this).val()));
                    
                    if( $(this).val() == 0 ){
                      $('#pricing-awe-border-color',  self.$el).hide();
                    }
                    else{
                      $('#pricing-awe-border-color',  self.$el).show();
                    }
                }
            });
            // Line
            $('#pricing-awe-border-radius input', this.$el).keypress(function(evt) {
                var charCode = (evt.which) ? evt.which : event.keyCode;
                if (charCode > 31 && (charCode < 48 || charCode > 57)){
                    alert('Please input a number')
                    return false;
                }
                return true;
            });
            $('#pricing-awe-border-radius input', this.$el).keyup(function(evt) {
                var number = parseInt($(this).val());
                if (number > 100) {
                    alert('Please input value less than 100');
                    return false;
                }
            });
            $('#pricing-awe-border-radius', this.$el).change( function(){
                self.editingModel.set('BorderRadius', $(this).find('input').val());
            });
            $('#pricing-awe-border-color', this.el).change(function(event, color) {
                        if (color)
                            color = color.toRgbString();
                        else
                            color = '';
                        self.editingModel.set('BorderColor', color);
                    });




            // Icon
            $('#pricing-awe-enable-icon .togg-status', this.$el).click(function(event) {
                event.preventDefault();
                $(this).toggleClass("active");
                if ($(this).hasClass("active")){
                    $("input[name=toggle_value]", $(this)).val(1).trigger("change");
                    self.editingModel.set('enableIcon', 1);
                    $(this).next('i').show();
                    $('#pricing-awe-icon-size',  self.$el).show();
                    $('#pricing-awe-icon-color',  self.$el).show();
                }
                else{
                    $("input[name=toggle_value]", $(this)).val(0).trigger("change");
                    self.editingModel.set('enableIcon', 0);
                    $(this).next('i').hide();
                    $('#pricing-awe-icon-size',  self.$el).hide();
                    $('#pricing-awe-icon-color',  self.$el).hide();
                }
            });
            $('#pricing-awe-enable-icon .ac-icon-edit', this.$el).click(function(event) {
                var $controller = $(this).closest('#pricing-awe-enable-icon');
                AWEContent.Panels.listIconPanel.processIcon($controller);
            });
            $('#pricing-awe-enable-icon', self.el).change( function(event, data) {
                if (data) {
                    self.editingModel.set('icon', data.nameIcon);
                }
            });
            // Icon Color
            $('#pricing-awe-icon-color', this.el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('IconColor', color);
            });
            // Icon Size
            // $('#pricing-awe-icon-size', this.$el).change(function (event, values) {
            //     self.editingModel.set('Iconsize', values.value);
            // });

            // Title color
            $('#pricing-awe-color-title', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('titlecolor', color);
            });
            $('#pricing-awe-title-transform', this.$el).change(function (event, values) {
                self.editingModel.set('titletransform', values.value);
            });
            $('#pricing-awe-title-font', this.$el).bind('fontFamilyChange', function(event, fontName) {
                self.editingModel.set('titlefontFamily', fontName);
            }).bind('fontStyleChange', function(event, fontStyle) {
                self.editingModel.set('titlefontStyle', fontStyle.value);
            }).bind('fontSizeChange', function(event, fontSize) {
                self.editingModel.set('titlefontSize', fontSize.value);
            });

            // Price
            $('#pricing-awe-color-price', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('colorPrice', color);
            });
            $('#pricing-awe-price-font', this.$el).bind('fontFamilyChange', function(event, fontName) {
                self.editingModel.set('pricefontFamily', fontName);
            }).bind('fontStyleChange', function(event, fontStyle) {
                self.editingModel.set('pricefontStyle', fontStyle.value);
            }).bind('fontSizeChange', function(event, fontSize) {
                self.editingModel.set('pricefontSize', fontSize.value);
            });


            // Description            
            $('#pricing-awe-enable-planbtn input', this.$el).change(function (event, scrollEdit) {
              if (!scrollEdit) {
                self.editingModel.set('enableplanbtn', parseInt($(this).val()));
              }
            });


            // Header
            $('#pricing-awe-enable-border-header input', this.$el).change(function (event, scrollEdit) {
              if (!scrollEdit) {
                self.editingModel.set('enableBorderHeader', parseInt($(this).val()));
                    if( $(this).val() == 0 ){
                      $('#pricing-awe-border-header-color',  self.$el).hide();
                    }
                    else{
                      $('#pricing-awe-border-header-color',  self.$el).show();
                    }
              }
            });
            $('#pricing-awe-border-header-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('borderHeaderColor', color);
            });


            // Content
            $('#pricing-awe-enable-content-info input', this.$el).change(function (event, scrollEdit) {
              if (!scrollEdit) {
                self.editingModel.set('enableInfo', parseInt($(this).val()));
              }
            });


            $('#pricing-awe-listicon .togg-status', this.$el).click(function(event) {
                event.preventDefault();
                $(this).toggleClass("active");
                if ($(this).hasClass("active")){
                    $("input[name=toggle_value]", $(this)).val(1).trigger("change");
                    self.editingModel.set('enablelisticon', 1);
                    $(this).next('i').show();
                    $('#pricing-awe-listicon-type, #pricing-awe-enable-listicon-border, #pricing-awe-enable-listicon-padding', this.$el).show(); 
                }
                else{
                    $("input[name=toggle_value]", $(this)).val(0).trigger("change");
                    self.editingModel.set('enablelisticon', 0);
                    $(this).next('i').hide();
                    $('#pricing-awe-listicon-type, #pricing-awe-enable-listicon-border, #pricing-awe-enable-listicon-padding', this.$el).hide(); 
                }
            });
            $('#pricing-awe-listicon .ac-icon-edit', this.$el).click(function(event) {
                event.preventDefault();
                AWEContent.Panels.iconPanel.editModel(self.editingModel);
            });
            $('#pricing-awe-enable-listicon-border input', this.$el).change(function (event, scrollEdit) {
              if (!scrollEdit) {
                self.editingModel.set('enablelistborder', parseInt($(this).val()));
              }
            });
            $('#pricing-awe-enable-listicon-padding input', this.$el).change(function (event, scrollEdit) {
              if (!scrollEdit) {
                self.editingModel.set('enablelistpadding', parseInt($(this).val()));
              }
            });
            $('#pricing-awe-listicon-type', this.$el).change(function (event, values) {
                self.editingModel.set('listiconstyle', values.value);
            });


            $('#pricing-awe-enable-content-note input', this.$el).change(function (event, scrollEdit) {
              if (!scrollEdit) {
                self.editingModel.set('enableNote', parseInt($(this).val()));
              }
            });


            
            // Footer
            $('#pricing-awe-button-link', this.el).change(function(event, data){
                self.editingModel.set('button_link', $(this).val());
            });
            $('#pricing-awe-button-target', this.$el).change(function (event, values) {
                self.editingModel.set('button_target', values.value);
            });

            $('#pricing-awe-button-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('button_color', color);
            });
            $('#pricing-awe-button-bg', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('button_bg', color);
            });


            $('#pricing-awe-button-hover-color', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('button_hover_color', color);
            });

            $('#pricing-awe-button-hover-bg', this.$el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('button_hover_bg', color);
            });

             // Button Border
             $('#pricing-awe-enable-button-border input', this.$el).change(function (event, scrollEdit) {
                if (!scrollEdit) {
                    self.editingModel.set('EnableButtonBorder', parseInt($(this).val()));
                    
                    if( $(this).val() == 0 ){
                      $('#pricing-awe-button-border-color',  self.$el).hide();
                    }
                    else{
                      $('#pricing-awe-button-border-color',  self.$el).show();
                    }
                }
            });
            $('#pricing-awe-button-border-color', this.el).change(function(event, color) {
                        if (color)
                            color = color.toRgbString();
                        else
                            color = '';
                        self.editingModel.set('ButtonBorderColor', color);
                    });




            // Setting
            $('#pricing-awe-layout-tab', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#text-pricing-awe-custom-id', this.$el).change( function(){
                self.editingModel.set('customID', $(this).val());
            });
            $('#text-pricing-awe-custom-classes', this.el).change(function() {
                self.editingModel.set('customClass', $(this).val());
            });
            $('#pricing-awe-custom-attributes', this.el).initAttributesPanel(self);
            $('#pricing-awe-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
                self.editingModel.set('customEnableAnimations', parseInt($(this).val()));
                if (data){
                    self.editingModel.set('customDataAnimations', JSON.stringify(data.animations));
                }
            });
        },
        setPanelElementsValue: function() {
            var settings = this.editingModel.toJSON();

            // General
            $('#pricing-awe-bg-content', this.$el).aweColorPicker('value', settings.contentBG);
            $('#pricing-awe-text-color', this.$el).aweColorPicker('value', settings.contentColor);
            $('#pricing-awe-bg-header', this.$el).aweColorPicker('value', settings.headerBg);
            $('#pricing-awe-color-header', this.$el).aweColorPicker('value', settings.headerColor);
            // $('#pricing-awe-footer-color', this.$el).aweColorPicker('value', settings.footer_color);
            if (settings.EnableBorder) {
                $('#pricing-awe-enable-border input', self.el).val(settings.EnableBorder).trigger("change", true);
                $('#pricing-awe-border-color',  self.$el).show();
            }
            else{
                $('#pricing-awe-border-color',  self.$el).hide();
            }
            // Line
            $('#pricing-awe-border-radius input', self.el).val(settings.BorderRadius);
            $('#pricing-awe-border-color', this.$el).aweColorPicker('value', settings.BorderColor);


            //Setting Icon
            $('#pricing-awe-enable-icon', self.el).attr('data-name-icon', settings.icon);
            if (settings.enableIcon) {
                $('#pricing-awe-enable-icon .togg-status', self.$el).addClass('active');
                $('#pricing-awe-enable-icon i', self.$el).show();
                $('#pricing-awe-icon-size',  self.$el).show();
                $('#pricing-awe-icon-color',  self.$el).show();
            }
            else{
                $('#pricing-awe-enable-icon .togg-status', self.$el).removeClass('active');
                $('#pricing-awe-enable-icon i', self.$el).hide();
                $('#pricing-awe-icon-size',  self.$el).hide();
                $('#pricing-awe-icon-color',  self.$el).hide();
            }
            $('#pricing-awe-icon-color', this.el).aweColorPicker('value', settings.IconColor);
            // $('#pricing-awe-icon-size', self.el).aweSelect('value', settings.Iconsize);

            // Title
            $('#pricing-awe-color-title', this.$el).aweColorPicker('value', settings.titlecolor);
            $('#pricing-awe-title-transform', self.el).aweSelect('value', settings.titletransform);
            $('#pricing-awe-title-font', this.$el).aweFont('options', {
                fontFamily: settings.titlefontFamily,
                fontStyle: settings.titlefontStyle,
                fontSize: settings.titlefontSize,
            });

            // Price
            $('#pricing-awe-color-price', this.$el).aweColorPicker('value', settings.colorPrice);
            $('#pricing-awe-price-font', this.$el).aweFont('options', {
                fontFamily: settings.pricefontFamily,
                fontStyle: settings.pricefontStyle,
                fontSize: settings.pricefontSize,
            });

            if (settings.enableplanbtn) {
                $('#pricing-awe-enable-planbtn input', self.el).val(settings.enableplanbtn).trigger("change", true);
              }

            if (settings.enableBorderHeader) {
                $('#pricing-awe-enable-border-header input', self.el).val(settings.enableBorderHeader).trigger("change", true);
                    $('#pricing-awe-border-header-color', self.$el).show();
              }
              else{
                    $('#pricing-awe-border-header-color', self.$el).hide();
              }
            $('#pricing-awe-border-header-color', this.$el).aweColorPicker('value', settings.borderHeaderColor);  



            // Content
            if (settings.enableInfo) {
                $('#pricing-awe-enable-content-info input', self.el).val(settings.enableInfo).trigger("change", true);
              }


            if (settings.enablelisticon) {
                $('#pricing-awe-listicon .togg-status', self.$el).addClass('active');
                $('#pricing-awe-listicon i', self.$el).show();
                $('#pricing-awe-listicon-type, #pricing-awe-enable-listicon-border, #pricing-awe-enable-listicon-padding', this.$el).show();
            }
            else{
                $('#pricing-awe-listicon .togg-status', self.$el).removeClass('active');
                $('#pricing-awe-listicon i', self.$el).hide();
                $('#pricing-awe-listicon-type, #pricing-awe-enable-listicon-border, #pricing-awe-enable-listicon-padding', this.$el).hide();
            }
            if (settings.enablelistborder) {
                $('#pricing-awe-enable-listicon-border input', self.el).val(settings.enablelistborder).trigger("change", true);
              }
            if (settings.enablelistpadding) {
                $('#pricing-awe-enable-listicon-padding input', self.el).val(settings.enablelistpadding).trigger("change", true);
              }  
            $('#pricing-awe-listicon-type', self.el).aweSelect('value', settings.listiconstyle);

            if (settings.enableNote) {
                $('#pricing-awe-enable-content-note input', self.el).val(settings.enableNote).trigger("change", true);
              }

            

            // Footer    
            $('#pricing-awe-button-link', this.el).val( settings.button_link);
            $('#pricing-awe-button-target', self.el).aweSelect('value', settings.button_target);

            $('#pricing-awe-button-color', this.$el).aweColorPicker('value', settings.button_color);
            $('#pricing-awe-button-bg', this.$el).aweColorPicker('value', settings.button_bg);
            $('#pricing-awe-button-hover-color', this.$el).aweColorPicker('value', settings.button_hover_color);
            $('#pricing-awe-button-hover-bg', this.$el).aweColorPicker('value', settings.button_hover_bg);
            
            if (settings.EnableButtonBorder) {
                $('#pricing-awe-enable-button-border input', self.el).val(settings.EnableButtonBorder).trigger("change", true);
                if(settings.EnableButton) $('#pricing-awe-button-border-color',  self.$el).show();
            }
            else{
                $('#pricing-awe-button-border-color',  self.$el).hide();
            }
            $('#pricing-awe-button-border-color', this.$el).aweColorPicker('value', settings.ButtonBorderColor);



            $('#text-pricing-custom-id', this.el).val( settings.customID);
            $('#text-pricing-custom-classes', this.el).val( settings.customClass);
            $('#pricing-awe-layout-tab', this.$el).initBoxModel(settings.boxModelSettings);
            $('#pricing-awe-custom-attributes input[name=enabled_custom_attributes]', this.el).val(settings.customEnableAttributes).trigger('change');
            $('#pricing-awe-custom-attributes input[name=attributes_data]', this.el).val(settings.customDataAttributes);
            $('#pricing-awe-custom-attributes', this.el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#pricing-awe-animations input[name=enabled_custom_animation]', this.el).val(settings.customEnableAnimations).trigger('change');
            $('#pricing-awe-animations input[name=enabled_custom_animation]', this.el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>Pricing Table<\/h2><\/div>"
                },
                'table_settings' : {
                  type: 'section',
                  table_tab: {
                      type: 'tabs',
                      tabs: [
                          {
                              tab_title: "General",
                              contents: {
                                  bg_content: {
                                      "type": 'colorpicker',
                                      "title": "Pricing Background Color",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },
                                  text_color: {
                                      "type": 'colorpicker',
                                      "title": "Pricing Text Color",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },
                                  bg_header: {
                                      "type": 'colorpicker',
                                      "title": "Header Background",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },
                                  color_header: {
                                      "type": 'colorpicker',
                                      "title": "Header Color",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },
                                  // footer_color: {
                                  //     "type": 'colorpicker',
                                  //     "title": "Footer BG Color",
                                  //     "options": {
                                  //         "preferredFormat"  : "rgb",
                                  //         "AlphaVerticle"  : true,
                                  //         "showAlpha"  : true,
                                  //         "allowEmpty" : true,
                                  //         "showInput" : true
                                  //     }
                                  // }
                                  enable_border: {
                                      "type": "toggle",
                                      "title": "Enable Border",
                                      "default_value": 0
                                  },
                                  border_color: {
                                      "type": "colorpicker",
                                      "title": "Border Color",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },
                                  border_radius: {
                                      "type": "text_field",
                                      "title": "Radius",
                                      "attributes": {
                                          "placeholder": "30"
                                      },
                                      "default_value": "4"
                                  },
                              },
                          },
                          {
                              tab_title: "Header",
                              contents: {
                                  enable_icon : {
                                      type: 'markup',
                                      markup: '<div id="pricing-awe-enable-icon" class="aw-cus evr-change toggle-pull" data-name-icon="ic ac-icon-help">\
                                                        <span>Enable Icon<i class="i-sign ic ac-icon-circle"></i></span>\
                                                        <div class="togg-status">\
                                                            <div class="butt-status"></div>\
                                                            <input type="hidden" name="toggle_value" value="0">\
                                                        </div>\
                                                        <i class="js-edit-animations ic ac-icon-edit"></i>\
                                                    </div>'
                                  },
                                  // icon_size: {
                                  //     "type": "select",
                                  //     "title": "Icon Size",
                                  //     "options": {
                                  //         "iconbox-2x": "Medium",
                                  //         "iconbox-3x": "Large",
                                  //     },
                                  //     "default_value": "iconbox-2x"
                                  // },
                                  icon_color: {
                                      "type": "colorpicker",
                                      "title": "Icon Color",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },
                                  color_title: {
                                      "type": 'colorpicker',
                                      "title": "Title Color",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },
                                  title_font: {
                                    type: "font",
                                    disabledElements: ['textAlign','lineSpacing','letterSpacing'],
                                  },
                                  title_transform: {
                                      "type": "select",
                                      "title": "Title Transform",
                                      "options": {
                                          "none": "None",
                                          "capitalize": "Capitalize",
                                          "uppercase": "Uppercase",
                                          "lowercase": "Lowercase",
                                      },
                                      "default_value": "none"
                                  },
                                  color_price: {
                                      "type": 'colorpicker',
                                      "title": "Price Color",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },
                                  price_font: {
                                    type: "font",
                                    disabledElements: ['textAlign','lineSpacing','letterSpacing'],
                                  },
                                  enable_planbtn: {
                                      "type": "toggle",
                                      "title": "Enable Buton Plan",
                                      "default_value": 0
                                  },
                                  enable_border_header: {
                                      "type": "toggle",
                                      "title": "Enable Border",
                                      "default_value": 0
                                  },
                                  border_header_color: {
                                      "type": 'colorpicker',
                                      "title": "Border Color",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },
                              }
                          },
                          {
                              tab_title: "Content",
                              contents: {
                                  enable_content_info: {
                                      "type": "toggle",
                                      "title": "Enable Info",
                                      "default_value": 0
                                  },
                                  enable_listicon: {
                                      type: 'markup',
                                      markup: '<div id="pricing-awe-listicon" class="aw-cus evr-change toggle-pull">\
                                                  <span>Enable List Icon<i class="i-sign ic ac-icon-circle"></i></span>\
                                                  <div class="togg-status">\
                                                      <div class="butt-status"></div>\
                                                      <input type="hidden" name="toggle_value" value="0">\
                                                  </div>\
                                                  <i class="js-edit-animations ic ac-icon-edit"></i>\
                                              </div>'
                                  },
                                  enable_listicon_border: {
                                      "type": "toggle",
                                      "title": "Enable List Icon Border",
                                      "default_value": 0
                                  },
                                  enable_listicon_padding: {
                                      "type": "toggle",
                                      "title": "Enable List Icon Padding",
                                      "default_value": 0
                                  },
                                  listicon_type: {
                                              "type": "select",
                                              "title": "List Icon Type",
                                              "options": {
                                                  "normal": "Normal",
                                                  "icon_position": "Position",
                                              },
                                              "default_value": "normal"
                                      },
                                  enable_content_note: {
                                      "type": "toggle",
                                      "title": "Enable Notes",
                                      "default_value": 0
                                  },
                              }
                          },
                          {
                              tab_title: "Footer",
                              contents: {
                                  button_link : {
                                      "type": "text_field",
                                      "title": "Button Link",
                                      "attributes": {
                                          "placeholder": "http:\/\/..."
                                      },
                                      "default_value": "http:\/\/"
                                  },
                                  button_target : {
                                      "type": "select",
                                      "title": "Button Target",
                                      "options": {
                                          "_blank" : "_blank",
                                          "_self" : "_self",
                                          "_parent" : "_parent",
                                          "_top" : "_top",
                                      },
                                      "default_value": "_blank"
                                  },
                                  button_color: {
                                      "type": 'colorpicker',
                                      "title": "Button Color",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },
                                  button_bg: {
                                      "type": 'colorpicker',
                                      "title": "Button Background Color",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },
                                  button_hover_color: {
                                      "type": 'colorpicker',
                                      "title": "Button hover Color",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },
                                  button_hover_bg: {
                                      "type": 'colorpicker',
                                      "title": "Button hover BG Color",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },
                                  enable_button_border: {
                                      "type": "toggle",
                                      "title": "Enable Button Border",
                                      "default_value": 0
                                  },
                                  button_border_color: {
                                      "type": "colorpicker",
                                      "title": "Button Border Color",
                                      "options": {
                                          "preferredFormat"  : "rgb",
                                          "AlphaVerticle"  : true,
                                          "showAlpha"  : true,
                                          "allowEmpty" : true,
                                          "showInput" : true
                                      }
                                  },

                              }
                          },
                      ]
                  }
                },
                'box_settings' : {
                    type: "section",
                    layout_tab: {
                        type: "tabs",
                        tabs: [
                            {
                                tab_title: "Border",
                                contents: {
                                    header_border: {
                                        type: "box_border",
                                        min_value: 0,
                                        max_value: 100,
                                        default_value: 0
                                    }
                                }
                            },
                            {
                                tab_title: "Radius",
                                contents: {
                                    header_boder_radius: {
                                        type: "box_model",
                                        model_type: "border_radius",
                                        min_value: 0,
                                        max_value: 100,
                                        allow_type: true
                                    }
                                }
                            },
                            {
                                tab_title: "Padding",
                                contents: {
                                    header_padding: {
                                        type: "box_model",
                                        model_type: "padding",
                                        allow_type: true,
                                        min_value: 0,
                                        max_value: 100
                                    }
                                }
                            },
                            {
                                tab_title: "Margin",
                                contents: {
                                    header_margin: {
                                        type: "box_model",
                                        model_type: "margin",
                                        allow_type: true,
                                        min_value: 0,
                                        max_value: 100
                                    }
                                }
                            }
                        ]
                    }
                },
                'definitions' : {
                    type: "section",
                    custom_id: {
                        type: "text_field",
                        title: "ID",
                        default_value: "ID"
                    },
                    custom_classes: {
                        type: "text_field",
                        title: "Classes",
                        default_value: "className"
                    },
                    custom_attributes: {
                        type: "custom_attributes"
                    },
                    animations: {
                        type: "animations"
                    }
                }
            };
        }
    });

    AWEContent.Views.listiconPanel = AWEContent.Views.DefaultPanel.extend({
        panelName: 'socialPanel',
        className: 'awe-obj-panel child-panel listicon-panel',
        buildPanel: function() {
            return {
                'title': {
                    type: 'markup',
                    markup: '<h2>List Icon</h2>'
                },
                add_form: {
                    type: 'section',
                    main: {
                        type: 'markup',
                        markup:
                        '<div class="add-data">\
                            <form>\
                                <div id="awe-choose-icon" class="tab-icon" data-name-icon="ic ac-icon-help">\
                                    <div class="title-tab">\
                                        <span>Choose Icons </span><i class="ic ac-icon-help"></i>\
                                    </div>\
                                </div>\
                                <div class="aw-input">\
                                    <label for="awe-add-attr-value">Text</label>\
                                    <input type="text" placeholder="..." class="valdata" id="awe-text-value">\
                                </div>\
                            </form>\
                        </div>\
                        <div class="add-list-icontext">\
                            <button><i class="ic ac-icon-add"></i>Add List Icon</button>\
                        </div>'
                    }
                },
                list_links: {
                    type: 'section',
                    social_items: {
                        type: 'markup',
                        markup: '<div class="add-icontextpanel-list"></div>'
                    }
                }
            }
        },
        listicontextItemTemplate: _.template(
            '<div class="item-cus-data">\
                <div class="aw-norm">\
                    <i class="<%= icon %>"></i>\
                    <span class="filldata"><%= text %></span> \
                    <div class="fl-right"><span class="rem-item-data"><i class="ic ac-icon-trash"></i></span></div>\
                </div>\
            </div>'
        ),
        initPanel: function() {
            var self = this;
            AWEContent.Views.DefaultPanel.prototype.initPanel.call(this);

            $('#awe-choose-icon', this.el).click( function() {
                AWEContent.Panels.listIconPanel.processIcon($(this));
            }).change( function(event, data) {
                if (data) {
                    //self.editingModel.set('nameIcon', data.nameIcon);
                    $('.title-tab > i', this).removeClass().addClass(data.nameIcon);
                    $(this).attr('data-name-icon', data.nameIcon);
                }
            });

            $('.add-list-icontext button', this.$el).click(function(event) {
                event.preventDefault();

                var icon_item = $('#awe-choose-icon', self.$el).attr('data-name-icon'),
                    description_item = $('input#awe-text-value', self.$el).val(),
                    icotextlist = self.editingModel.get('listicontext');

                if (icon_item && description_item) {
                    $('.add-icontextpanel-list', self.$el).append(self.listicontextItemTemplate({icon: icon_item, text: description_item}));

                    if (icotextlist)
                        icotextlist = JSON.parse(icotextlist);
                    else
                        icotextlist = [];

                    // add social description_item to list
                    icotextlist.push({icon: icon_item, text: description_item});

                    // update value to editing model
                    self.editingModel.set('listicontext', JSON.stringify(icotextlist));

                    // reset add form
                    $('input#awe-text-value', self.$el).val('');
                }
            });

            $('.add-icontextpanel-list', this.$el).delegate('.rem-item-data', 'click', function(event) {
                event.preventDefault();

                var $item = $(this).parents('.item-cus-data:first'),
                    id = $item.index(),
                    icotextlist = JSON.parse(self.editingModel.get('listicontext'));

                // remove item data in social list
                icotextlist.splice(id, 1);
                $item.remove();

                // update data to social list
                self.editingModel.set('listicontext', JSON.stringify(icotextlist));
            }).sortable({
                items: '.item-cus-data',
                axis: 'y',
                stop: function(event, ui) {
                    var icotextlist = [];

                    // get data of new sort list
                    $('.add-icontextpanel-list > .item-cus-data', self.$el).each(function() {
                        var icon_item = $('.aw-norm > i', this).attr('class'),
                            description_item = $('.aw-norm > span', this).text().trim();

                        icotextlist.push({icon: icon_item, text: description_item});
                    });

                    // update social list
                    self.editingModel.set('listicontext', JSON.stringify(icotextlist));
                }
            });
        },
        setPanelElementsValue: function() {
            var self = this,
                icotextlist = this.editingModel.get('listicontext');

            if (icotextlist)
                icotextlist = JSON.parse(icotextlist);
            else
                icotextlist = [];

            // render list social item
            $('.add-icontextpanel-list', this.$el).html('');
            $.each(icotextlist, function() {
                $('.add-icontextpanel-list', self.$el).append(self.listicontextItemTemplate(this));
            });
        }
    });


    $(document).ready(function() {
        AWEContent.Controllers.pricing_awe = new AWEContent.Views.PricingItemController();
        AWEContent.Panels.pricing_awe = new AWEContent.Views.PricingPanel();
        AWEContent.Panels.iconPanel = new AWEContent.Views.listiconPanel();
    });
})(jQuery);