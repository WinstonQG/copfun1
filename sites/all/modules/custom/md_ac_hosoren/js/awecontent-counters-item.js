/**
 * File: awecontent-message-item.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function($) {
    "use strict";

    /**
     * Define model for header item
     */
    AWEContent.Models.NumberCountersItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "counters_awe",
            enablesocial : 0,
            SocialIcon: 'ic ac-icon-help',
            IconColor: '',
            enabletitle: 0,
            Tag_Name: "h4",
            title: 'Title Funfact',
            titlefontFamily: '',
            titlefontStyle: '',
            titlefontSize: -1,
            titleColor:'',
            NumberColor:'',
            Numbercounters: '10',
            NumberWeight: 'normal',
            
            background_color: '',
            color: '',
            hoverbackground_color: '',
            hovercolor: '',
            boxModelSettings : {},
            customID : '',
            customClass : '',
            customEnableAttributes: 0,
            customDataAttributes: '[] ', // Array Json
            customActionAttributes: '{"newAction": "", "newAttrName": "", "newAttrValue": ""}',
            customEnableAnimations: 0,
            customDataAnimations: '{"type" : "none"}', // Data Object
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
            this.view = new AWEContent.Views.NumberCountersItem({model: this});
        },
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.NumberCountersItem(cloneModel);
        }
    });

    /**
     * Define View for NumberCountersItem
     */
    AWEContent.Views.NumberCountersItem = AWEContent.Views.Item.extend({
        countersTemplate: _.template(
            '<div class="awe-counting">\
              <div class="text-center counters-icon" style="color: <%= IconColor %>"><i class="<%= classIcon %>"></i></div>\
              <<%= Tag_Name %> class="counters_title" style="color: <%= titleColor %>"><%= title %></<%= Tag_Name %>>\
              <span class="counter <%= NumberWeight %>" style="color: <%= NumberColor %>"><%= Numbercounters %></span>\
            </div>'
        ),
        initialize: function(){
            AWEContent.Views.Item.prototype.initialize.call(this);
            this.listenTo(this.model.get('boxModelSettings'), 'change', this.applySettingsChanged);
        },
        renderItemContent: function() {
            var self = this,
                settings = self.model.toJSON(),
                html = '',
                $countersinfo = $('<div class="counters-item awe-item"></div>'),
                $style = $('<style></style>'),
                fontStyleCss = '';
                

                fontStyleCss = {
                    'font-family' : settings.titlefontFamily,
                    'font-size': settings.titlefontSize == -1 ? '' : (settings.titlefontSize + 'px'),
                    'line-height': settings.lineHeight == -1 ? '' : (settings.lineHeight + 'px'),
                    'letter-spacing': settings.letterSpacing == -1 ? '' : (settings.letterSpacing + 'px'),
                    'color': settings.titleColor,
                };
                if (settings.titlefontStyle) {
                    fontStyleCss = $.extend({}, fontStyleCss, JSON.parse(settings.titlefontStyle));
                }

                self.$el.append($style);
                self.classContent = 'awe-content-' + self.cid;

            html = self.countersTemplate({
                classIcon: settings.SocialIcon,
                IconColor: settings.IconColor,
                Tag_Name: settings.Tag_Name,
                title : settings.title,
                titleColor: settings.titleColor,
                Numbercounters: settings.Numbercounters,
                NumberWeight: settings.NumberWeight,
                NumberColor: settings.NumberColor,
            });

            $countersinfo
                .html(html)
                .addClass(self.classContent)
                .renderItemDefaultBoxModel(settings.boxModelSettings);

            $('.counters_title', $countersinfo).css(fontStyleCss);
            if (!settings.enablesocial)
                $('.counters-icon', $countersinfo).hide();
            if (!settings.enabletitle)
                $('.counters_title', $countersinfo).hide();

            self.iframeJQuery(this.el).delegate('.counters-item', "itemReady", function() {
                var heightBefore, heightAfter;
                self.initHallo(self.iframeJQuery(this).find('span.counter'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.counters_title'), heightBefore, heightAfter);
            });
            $style.html(self.processStyle());
            self.$el.defaultResponsive(settings);
            self.$el.attr('id', settings.customID);
            self.$el.addClass(settings.customClass);
            $countersinfo.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            if (settings.customEnableAnimations)
                $countersinfo.processAnimations(settings.customDataAnimations)
            return $countersinfo;
        },
        applySettingsChanged: function(model) {
            var self = this,
                settings = self.model.toJSON(),
                $countersinfo = $('> .counters-item', self.el),
                heightBefore = self.$el.height(),
                $text_title = $('.counters_title', $countersinfo),
                $text_number = $('span.counter' , self.$el);


            $.each(model.changedAttributes(), function(key, value){
                self.$el.changeResponsive(key, value);
                $countersinfo.renderChangeSettingBoxModel(key, value, model);
                switch (key) {

                    // chooseicon
                    case 'enablesocial':
                        if (value == 0)
                            $('.counters-icon', $countersinfo).hide();
                        else
                            $('.counters-icon', $countersinfo).show();
                        break;
                    case 'SocialIcon' :
                        var prevIcon = self.model.previousAttributes().SocialIcon;
                        $('.counters-icon i', self.el).removeClass(prevIcon).addClass(value);
                        break;


                    case 'IconColor':
                        $('.counters-icon', self.el).css('color', value);
                        break;
                            

                    // Number
                    case 'NumberWeight':
                        var prevIcon = self.model.previousAttributes().NumberWeight;
                        if (value) {
                            $text_number.removeClass(prevIcon).addClass(value);
                        }
                        break;
                    case 'NumberColor':
                        $text_number.css('color', value);
                        break;


                    // title
                    case 'enabletitle':
                        if (value == 0)
                            $('.counters_title', $countersinfo).hide();
                        else
                            $('.counters_title', $countersinfo).show();
                        break;
                    case 'titlefontFamily':
                        if (value == 'Default')
                            $text_title.css('font-family', '');
                        else
                            $text_title.css('font-family', value);
                        break;
                    case 'titlefontStyle':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '100',"font-style":""};
                        $text_title.css(fontStyle);
                        break;

                    case 'titlefontSize':
                        value == -1 ? $text_title.css('font-size', '') : $text_title.css('font-size',value + 'px');
                        break;
                    case 'Tag_Name':
                        //  Replace tag
                        $countersinfo.remove();
                        self.$el.find('style').remove();
                        self.$el.append(self.renderItemContent());

                        // hallo for title
                         var heightBefore, heightAfter;
                        self.initHallo(self.iframeJQuery('span.counter', self.iframeJQuery(self.$el)), heightBefore, heightAfter);
                        self.initHallo(self.iframeJQuery('.counters_title', self.iframeJQuery(self.$el)), heightBefore, heightAfter);
                        break;

                    case 'titleColor':
                        $text_title.css('color', value);
                        break;


                    // setting
                    case 'background_color' :
                    case 'color':
                    case 'hoverbackground_color':
                    case 'hovercolor' :
                        self.generateStyle();
                        break;
                    case 'customID':
                        self.$el.attr('id', value);
                        break;
                    case 'customClass':
                        var prevClass = self.model.previousAttributes().customClass;
                        self.$el.removeClass(prevClass).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $countersinfo.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;
                    case 'customActionAttributes':
                        $countersinfo.renderChangeSettingsAttributes(key, value);
                        break;
                    case 'customEnableAnimations':
                        var animation, prevAnimation;
                        if (value) {
                            animation = settings.customDataAnimations;
                            prevAnimation = null;
                            $countersinfo.processAnimations(animation);
                        }
                        else {
                            animation = null;
                            prevAnimation = settings.customDataAnimations;
                            $countersinfo.processAnimations(animation, prevAnimation);
                        }
                        break;
                    case 'customDataAnimations':
                        var animation, prevAnimation;
                        animation = settings.customDataAnimations;
                        prevAnimation = self.model.previousAttributes().customDataAnimations;
                        $countersinfo.processAnimations(animation, prevAnimation);
                        break;
                }
            });

            // Listen event change height of item
            setTimeout(function() {
                self.checkChangeHeight(heightBefore);
            }, 50);
        },
        additionalEvents: {
           'keypress span.counter' : 'changeValueNumber' 
        },
        changeValueNumber:function(evt){
            var charCode = (evt.which) ? evt.which : event.keyCode
            if (charCode > 31 && (charCode < 48 || charCode > 57)){
                alert('Please input a number')
               return false;
           }
            return true;
        },
        changeContent: function(el, select){
            var _html = $(el.currentTarget).html();
            switch (select.selector) {
                case 'span.counter':
                    this.model.set('Numbercounters', _html);
                    break;
                case '.counters_title':
                    this.model.set('title', _html);
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
        processStyle : function(){
            var self = this,
                style = '',
                settings = this.model.toJSON(),
                $item = self.iframeJQuery(self.$el);

            style = '.' + this.classContent + '{' +
                'color :' + settings.color + ';' +
                'background-color:' + settings.background_color + ';' +
                '} ' +
                '.' + this.classContent + ':hover {' +
                'color :' + settings.hovercolor + ';' +
                'background:' + settings.hoverbackground_color + ';' +
                '}';
            return style;
        },
        generateStyle: function() {
            var self = this,
                style = '',
                settings = this.model.toJSON(),
                $item = self.iframeJQuery(self.$el);

            if (self.updateColor)
                clearTimeout(self.updateColor);

            self.updateColor = setTimeout(function() {
                console.log(settings);
                style = '.' + self.classContent + '{' +
                    'color :' + settings.color + ';' +
                    'background-color:' + settings.background_color + ';' +
                    '} ' +
                    '.' + self.classContent + ':hover {' +
                    'color :' + settings.hovercolor + ';' +
                    'background:' + settings.hoverbackground_color + ';' +
                    '}';

                // update style color
                $('style', self.el).html(style);

                // clear timeout
                self.updateColor = false;
            }, 100);
        }
    });

    /**
     * Define view for Header Controller
     * li tag what is contained by items panel
     */
    AWEContent.Views.NumberCountersItemController = AWEContent.Views.ItemController.extend({
        machineName: 'counters_awe',
        controllerHtml: function() {
            return '<div class="title-icon">counters</div><i class="ic ac-icon-message"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.NumberCountersItem(templateData);
            }

            return new AWEContent.Models.NumberCountersItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define header panel
     */
    AWEContent.Views.NumberCountersPanel = AWEContent.Views.ItemPanel.extend({
        Tag_Name: "div",
        className: "awe-obj-panel panel-welcome",
        panelName: "counters_awe",
        initPanel: function() {
            AWEContent.Views.ItemPanel.prototype.initPanel.call(this);
            var self = this;

            // Chooseicon
            $('#counters-awe-enable-icon .togg-status', this.$el).click(function(event) {
                    event.preventDefault();

                    $(this).toggleClass("active");
                    if ($(this).hasClass("active")){
                        $("input[name=toggle_value]", $(this)).val(1).trigger("change");
                        self.editingModel.set('enablesocial', 1);
                        $(this).next('i').show();
                        $('#counters-awe-icon-color',  self.$el).show();
                    }
                    else{
                        $("input[name=toggle_value]", $(this)).val(0).trigger("change");
                        self.editingModel.set('enablesocial', 0);
                        $(this).next('i').hide();
                        $('#counters-awe-icon-color',  self.$el).hide();
                    }
                });
            $('#counters-awe-enable-icon .ac-icon-edit', this.$el).click(function(event) {
                var $controller = $(this).closest('#counters-awe-enable-icon');
                AWEContent.Panels.listIconPanel.processIcon($controller);
            });


            $('#counters-awe-enable-icon', self.el).change( function(event, data) {
                if (data) {
                    self.editingModel.set('SocialIcon', data.nameIcon);
                }
            });


            // Icon Color
            $('#counters-awe-icon-color', this.el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('IconColor', color);
            });



            // Number            
            $('#counters-awe-number-style', this.$el).change(function (event, values) {
                self.editingModel.set('NumberWeight', values.value);
            });
            $('#counters-awe-number-color', this.el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('NumberColor', color);
            });


            // Title
            $('#counters-awe-enable-title input', this.$el).change(function (event, scrollEdit) {
                if (!scrollEdit) {
                    self.editingModel.set('enabletitle', parseInt($(this).val()));
                    if( $(this).val() == 0 ){
                        $('#counters-awe-title-font, #counters-awe-title-tag, #counters-awe-title-color',  self.$el).hide();
                    }
                    else{
                        $('#counters-awe-title-font, #counters-awe-title-tag, #counters-awe-title-color',  self.$el).show();
                    }
                }
            });


            $('#counters-awe-title-font', this.$el).bind('fontFamilyChange', function(event, fontName) {
                self.editingModel.set('titlefontFamily', fontName);
            }).bind('fontStyleChange', function(event, fontStyle) {
                self.editingModel.set('titlefontStyle', fontStyle.value);
            }).bind('fontSizeChange', function(event, fontSize) {
                self.editingModel.set('titlefontSize', fontSize.value);
            });

            $('#counters-awe-title-tag', this.el).change(function(event, tag) {
                self.editingModel.set('Tag_Name', tag.value.toLowerCase());
            });
            $('#counters-awe-title-color', this.el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('titleColor', color);
            });



            // Setting
            $('#counters-awe-background-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('background_color', color);
            });
            $('#counters-awe-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('color', color);
            });
            $('#counters-awe-hoverbackground-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('hoverbackground_color', color);
            });
            $('#counters-awe-hovercolor', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('hovercolor', color);
            });

            $('#counters-awe-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#counters-awe-custom-id', this.$el).change( function(){
                self.editingModel.set('customID', $(this).find('input').val());
            });
            $('#counters-awe-custom-class', this.$el).change( function(){
                self.editingModel.set('customClass', $(this).find('input').val());
            });
            $('#counters-awe-custom-attributes', this.el).initAttributesPanel(self);
            $('#counters-awe-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
                self.editingModel.set('customEnableAnimations', parseInt($(this).val()));
                if (data){
                    self.editingModel.set('customDataAnimations', JSON.stringify(data.animations));
                }
            });

        },
        setPanelElementsValue: function() {
            var self = this,
                settings = this.editingModel.toJSON();

            // chooseicon
            if (settings.enablesocial) {
                    $('#counters-awe-enable-icon .togg-status', self.$el).addClass('active');
                    $('#counters-awe-enable-icon i, #counters-awe-icon-color', self.$el).show();
                }
                else{
                    $('#counters-awe-enable-icon .togg-status', self.$el).removeClass('active');
                    $('#counters-awe-enable-icon i, #counters-awe-icon-color', self.$el).hide();
                }
            $('#counters-awe-enable-icon', self.el).attr('data-name-icon', settings.SocialIcon);

            // Icon Color
            $('#counters-awe-icon-color', this.el).aweColorPicker('value', settings.IconColor);


            // Number
            $('#counters-awe-number-style', self.el).aweSelect('value', settings.NumberWeight);
            $('#counters-awe-number-color', this.el).aweColorPicker('value', settings.NumberColor);


            // Title
            if (settings.enabletitle) {
                $('#counters-awe-enable-title input', self.el).val(settings.enabletitle).trigger("change", true);
                $('#counters-awe-title-font, #counters-awe-title-tag, #counters-awe-title-color', self.$el).show();
            }
            else{
                $('#counters-awe-title-font, #counters-awe-title-tag, #counters-awe-title-color', self.$el).hide();
            }

            $('#counters-awe-title-font', this.$el).aweFont('options', {
                fontFamily: settings.titlefontFamily,
                fontStyle: settings.titlefontStyle,
                fontSize: settings.titlefontSize,
            });
            $('#counters-awe-title-tag', this.$el).aweSlider('value', settings.Tag_Name.toUpperCase());
            $('#counters-awe-title-color', this.el).aweColorPicker('value', settings.titleColor);

            // settings
            $('#counters-awe-background-color', this.$el).aweColorPicker('value', settings.background_color);
            $('#counters-awe-color', this.$el).aweColorPicker('value', settings.color);
            $('#counters-awe-hoverbackground-color', this.$el).aweColorPicker('value', settings.hoverbackground_color);
            $('#counters-awe-hovercolor', this.$el).aweColorPicker('value', settings.hovercolor);
            $('#counters-awe-column-box-model', this.$el).initBoxModel(settings.boxModelSettings);
            $('#counters-awe-custom-id input', this.el).val(settings.customID);
            $('#counters-awe-custom-class input', this.el).val(settings.customClass);
            $('#counters-awe-custom-attributes', this.$el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#counters-awe-animations input[name=enabled_custom_animation]', this.$el).val(settings.customEnableAnimations).trigger('change');
            $('#counters-awe-animations input[name=enabled_custom_animation]', this.$el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>counters<\/h2><\/div>"
                },


                /* Custom Number */
                "custom_number": {
                    "type": "section",
                    "number_style": {
                        "type": "select",
                        "title": "Number Style",
                        "options": {
                            "text-weight-normal": "Normal",
                            "text-weight-lighter": "Lighter",
                            "text-weight-bold": "Bold",
                        },
                        "default_value": "normal"
                    },
                    "number_color": {
                        "type": 'colorpicker',
                        "title": "Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                },

                /* Custom Icon */
                "SocialIcon":{
                    "type": "section",
                    "enable_icon": {
                        type: 'markup',
                        markup: '<div id="counters-awe-enable-icon" class="aw-cus evr-change toggle-pull" data-name-icon="ic ac-icon-help">\
                                    <span>Enable Icon<i class="i-sign ic ac-icon-circle"></i></span>\
                                    <div class="togg-status">\
                                        <div class="butt-status"></div>\
                                        <input type="hidden" name="toggle_value" value="0">\
                                    </div>\
                                    <i class="js-edit-animations ic ac-icon-edit"></i>\
                                </div>'
                    },
                    "icon_color": {
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
                },

                /* Custom Text */
                "custom_title": {
                    "type": "section",
                    "enable_title": {
                        "type": "toggle",
                        "title": "Enable Title",
                        "default_value": 0
                    },
                    title_font:{
                      type: "font",
                        disabledElements: ['textAlign','lineSpacing','letterSpacing'],
                    },
                    title_tag: {
                            type: "slider",
                            title: "Heading tag",
                            values: ["H1", "H2", "H3", "H4", "H5", "H6","P"],
                            default_value: "H4",
                            allow_type: false
                    },
                    title_color: {
                        type: 'colorpicker',
                        title: "Color",
                        options: {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                },

                /* setting */
                "custom_color": {
                    "type": "section",
                    "background_color": {
                        "type": "colorpicker",
                        "title": "Background Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "color": {
                        "type": "colorpicker",
                        "title": "Text Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "hoverbackground_color": {
                        "type": "colorpicker",
                        "title": "Hover Background Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "hovercolor": {
                        "type": "colorpicker",
                        "title": "Hover Text Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    }
                },
                "custom_box_model": {
                    "type": "section",
                    "column_box_model": {
                        "type": "tabs",
                        "tabs": [{
                            "tab_title": "Border",
                            "contents": {
                                "custom_border": {
                                    "type": "box_border",
                                    "min_value": 0,
                                    "max_value": 100,
                                    "default_value": 0
                                }
                            }
                        }, {
                            "tab_title": "Radius",
                            "contents": {
                                "custom_border_radius": {
                                    "type": "box_model",
                                    "model_type": "border_radius",
                                    allow_type: true,
                                    "min_value": 0,
                                    "max_value": 100,
                                    "default_value": 0
                                }
                            }
                        }, {
                            "tab_title": "Padding",
                            "contents": {
                                "custom_padding": {
                                    "type": "box_model",
                                    "model_type": "padding",
                                    allow_type: true,
                                    "min_value": 0,
                                    "max_value": 100,
                                    "default_value": 0
                                }
                            }
                        }, {
                            "tab_title": "Margin",
                            "contents": {
                                "custom_margin": {
                                    "type": "box_model",
                                    "model_type": "margin",
                                    allow_type: true,
                                    "min_value": 0,
                                    "max_value": 100,
                                    "default_value": 0
                                }
                            }
                        }]
                    }
                },
                "custom_definitions": {
                    "type": "section",
                    "custom_id": {
                        "type": "text_field",
                        "title": "ID",
                        "attributes": {
                            "placeholder": "wrapper"
                        },
                        "default_value": ""
                    },
                    "custom_class": {
                        "type": "text_field",
                        "title": "CSS class",
                        "attributes": {
                            "placeholder": "wrapper"
                        },
                        "default_value": ""
                    },
                    "custom_attributes": {
                        "type": "custom_attributes"
                    },
                    animations: {
                        type: "animations"
                    }
                }
            };
        }
    });


    $(document).ready(function() {
        AWEContent.Controllers.counters_awe = new AWEContent.Views.NumberCountersItemController();
        AWEContent.Panels.counters_awe = new AWEContent.Views.NumberCountersPanel();
    });
})(jQuery);
