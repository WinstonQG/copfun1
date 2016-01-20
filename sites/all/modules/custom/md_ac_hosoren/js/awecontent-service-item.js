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
    AWEContent.Models.ServiceItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "service_awe",

            title: 'Title Service',
            titlefontFamily: '',
            titlefontStyle: '',
            titlefontSize: -1,
            TitleColor: '',
            TitleColorHover: '',

            enableDescription: 1,
            description: 'Description Service',
            DetailBackground: '',
            DetailColor: '',

            SocialIcon: 'ic ac-icon-help',
            IconColor: '',
            IconColorHover:'',
            sizeIcon: 'icon-large',

            layout: 'center',
            
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
            this.view = new AWEContent.Views.ServiceItem({model: this});
        },
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.ServiceItem(cloneModel);
        }
    });

    /**
     * Define View for ServiceItem
     */
    AWEContent.Views.ServiceItem = AWEContent.Views.Item.extend({
        service_template: _.template(
          '<div class="awe-box <%=layout%>">\
              <div class="awe-box-media">\
                  <div class="awe-box-icon <%= sizeIcon %> icon-choose">\
                      <i class="icon <%= classIcon %>"></i>\
                  </div>\
              </div>\
              <div class="awe-box-content">\
                  <h3 class="service-title"><%= title %></h3>\
                  <p class="service-description"><%= description %></p>\
              </div>\
          </div>'
          ),
        initialize: function(){
            AWEContent.Views.Item.prototype.initialize.call(this);
            this.listenTo(this.model.get('boxModelSettings'), 'change', this.applySettingsChanged);
        },
        renderItemContent: function() {
            var self = this,
                settings = self.model.toJSON(),
                $options = '',
                $Contentdetail = $('<div class="awe-service-item awe-item"></div>'),
                $style = $('<style></style>'),
                fontStyleCss = '';

                self.$el.append($style);
                self.classContent = 'awe-content-' + self.cid;



            $options = {
                layout : settings.layout,
                title : settings.title,
                description : settings.description,
                Type: settings.Type,
                classIcon: settings.SocialIcon,
                IconColor: settings.IconColor,
                sizeIcon: settings.sizeIcon,
            };

            $Contentdetail
                .html(self.service_template($options))
                .addClass(self.classContent)
                .renderItemDefaultBoxModel(settings.boxModelSettings);

            if (settings.enableDescription == 0 && settings.layout == "center")
                $('.service-description', $Contentdetail).hide();
            

            fontStyleCss = {
                'font-family' : settings.titlefontFamily,
                'font-size': settings.titlefontSize == -1 ? '' : (settings.titlefontSize + 'px'),
            };
            if (settings.titlefontStyle) {
                fontStyleCss = $.extend({}, fontStyleCss, JSON.parse(settings.titlefontStyle));
            }
            $('.service-title', $Contentdetail).css(fontStyleCss);

            self.iframeJQuery(this.el).delegate('.awe-service-item', "itemReady", function() {
                var heightBefore, heightAfter;
                self.initHallo(self.iframeJQuery(this).find('h3.service-title'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('p.service-description'), heightBefore, heightAfter);
            });
            $style.html(self.processStyle());
            self.$el.defaultResponsive(settings);
            self.$el.attr('id', settings.customID);
            self.$el.addClass(settings.customClass);
            $Contentdetail.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            if (settings.customEnableAnimations)
                $Contentdetail.processAnimations(settings.customDataAnimations)
            return $Contentdetail;
        },
        applySettingsChanged: function(model) {
            var self = this,
                settings = self.model.toJSON(),
                heightBefore = self.$el.height(),
                $Contentdetail = $('> .awe-service-item', self.el);


            $.each(model.changedAttributes(), function(key, value){
                self.$el.changeResponsive(key, value);
                $Contentdetail.renderChangeSettingBoxModel(key, value, model);         

                switch (key) {

                    // chooseicon
                    case 'SocialIcon' :
                            var prevIcon = self.model.previousAttributes().SocialIcon;
                            $('.icon-choose i', self.el).removeClass(prevIcon).addClass(value);
                            break;

                    // Icon Color
                    // case 'IconColor':
                    //     $('.icon-choose', $Contentdetail).css('color', value);
                    //     break;

                    // Icon Size                   
                    case 'sizeIcon':
                        if (value) {
                            $('.icon-choose' , self.$el).removeClass('icon-large icon-normal icon-small').addClass(value);
                        }
                        break;

                    // Box info Detail
                    case 'titlefontFamily':
                        if (value == 'Default')
                            $('h3.service-title', $Contentdetail).css('font-family', '');
                        else
                            $('h3.service-title', $Contentdetail).css('font-family', value);
                        break;
                    case 'titlefontStyle':
                        var fontStyle = (value) ? JSON.parse(value) : {'font-weight': '100',"font-style":""};
                        $('h3.service-title', $Contentdetail).css(fontStyle);
                        break;
                    case 'titlefontSize':
                        value == -1 ? $('h3.service-title', $Contentdetail).css('font-size', '') : $('h3.service-title', $Contentdetail).css('font-size',value + 'px');
                        break;
                    // case "TitleColor":
                    //         $('h3.service-title', $Contentdetail).css('color', value);
                    //     break;


                    // Description
                    case 'enableDescription':
                        if (value == 0)
                            $('.service-description', $Contentdetail).hide();
                        else
                            $('.service-description', $Contentdetail).show();
                        break;

                    // Layout                    
                    case 'layout':
                        if (value) {
                            $('.awe-box' , self.$el).removeClass('center box-left box-right').addClass(value);
                        }
                        if(value!='center')
                          $('.service-description', $Contentdetail).show();
                        else if(settings.enableDescription == 0)
                          $('.service-description', $Contentdetail).hide();
                        break;

                        
                    case 'DetailBackground':
                    case 'DetailColor' :
                    case 'TitleColorHover' :
                    case 'IconColorHover' :
                    case "TitleColor":
                    case 'IconColor':
                        self.generateStyle();
                        break;                    


                    // setting
                    case 'customID':
                        self.$el.attr('id', value);
                        break;
                    case 'customClass':
                        var prevClass = self.model.previousAttributes().customClass;
                        self.$el.removeClass(prevClass).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $Contentdetail.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;
                    case 'customActionAttributes':
                        $Contentdetail.renderChangeSettingsAttributes(key, value);
                        break;
                    case 'customEnableAnimations':
                        var animation, prevAnimation;
                        if (value) {
                            animation = settings.customDataAnimations;
                            prevAnimation = null;
                            $Contentdetail.processAnimations(animation);
                        }
                        else {
                            animation = null;
                            prevAnimation = settings.customDataAnimations;
                            $Contentdetail.processAnimations(animation, prevAnimation);
                        }
                        break;
                    case 'customDataAnimations':
                        var animation, prevAnimation;
                        animation = settings.customDataAnimations;
                        prevAnimation = self.model.previousAttributes().customDataAnimations;
                        $Contentdetail.processAnimations(animation, prevAnimation);
                        break;
                }
            });

            // Listen event change height of item
            setTimeout(function() {
                self.checkChangeHeight(heightBefore);
            }, 50);
        },
        changeContent: function(el, select){
            var _html = $(el.currentTarget).html();
            switch (select.selector) {
                case 'p.service-description':
                    this.model.set('description', _html);
                    break;
                case 'h3.service-title':
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

            style = '.' + this.classContent + ' .awe-box{' +
                  'color :' + settings.DetailColor + ';' +
                  'background:' + settings.DetailBackground + ';' +
                '}' +
                '.' + this.classContent + ' p{' +
                  'color :' + settings.DetailColor + ';' +
                '}' +
                '.' + this.classContent + ':hover .awe-box-icon{' +
                  'color :' + settings.IconColorHover + ';' +
                '}'+
                '.' + this.classContent + ' .awe-box-icon{' +
                  'color :' + settings.IconColor + ';' +
                '}'+
                '.' + this.classContent + ':hover h3{' +
                  'color :' + settings.TitleColorHover + ';' +
                '}'+
                '.' + this.classContent + ' h3{' +
                  'color :' + settings.TitleColor + ';' +
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
                style = '.' + self.classContent + ' .awe-box{' +
                    'color :' + settings.DetailColor + ';' +
                      'background:' + settings.DetailBackground + ';' +
                    '}' +
                    '.' + self.classContent + ' p{' +
                      'color :' + settings.DetailColor + ';' +
                    '}' +
                    '.' + self.classContent + ':hover .awe-box-icon{' +
                      'color :' + settings.IconColorHover + ';' +
                    '}' +
                    '.' + self.classContent + ' .awe-box-icon{' +
                      'color :' + settings.IconColor + ';' +
                    '}' +
                    '.' + self.classContent + ':hover h3{' +
                      'color :' + settings.TitleColorHover + ';' +
                    '}' +
                    '.' + self.classContent + ' h3{' +
                      'color :' + settings.TitleColor + ';' +
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
    AWEContent.Views.ServiceItemController = AWEContent.Views.ItemController.extend({
        machineName: 'service_awe',
        controllerHtml: function() {
            return '<div class="title-icon">Service</div><i class="ic ac-icon-message"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.ServiceItem(templateData);
            }

            return new AWEContent.Models.ServiceItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define header panel
     */
    AWEContent.Views.ServicePanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel panel-welcome",
        panelName: "service_awe",
        initPanel: function() {
            AWEContent.Views.ItemPanel.prototype.initPanel.call(this);
            var self = this;

            // Chooseicon
            $('#choose-icons .title-tab', self.el).click( function() {
                var $controller = $(this).closest('#choose-icons');
                AWEContent.Panels.listIconPanel.processIcon($controller);
            });

            $('#choose-icons', self.el).change( function(event, data) {
                if (data) {
                    self.editingModel.set('SocialIcon', data.nameIcon);
                    $('.title-tab > i', this).removeClass().addClass(data.nameIcon);
                }
            });

            // Icon Color
            $('#service-awe-icon-color', this.el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('IconColor', color);
            });
            $('#service-awe-icon-color-hover', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('IconColorHover', color);
            });

            // Icon Size
            $('#service-awe-icon-size', this.$el).change(function (event, values) {
                self.editingModel.set('sizeIcon', values.value);
            });           


            // Box Title
            $('#service-awe-title-font', this.$el).bind('fontFamilyChange', function(event, fontName) {
                self.editingModel.set('titlefontFamily', fontName);
            }).bind('fontStyleChange', function(event, fontStyle) {
                self.editingModel.set('titlefontStyle', fontStyle.value);
            }).bind('fontSizeChange', function(event, fontSize) {
                self.editingModel.set('titlefontSize', fontSize.value);
            });
            $('#service-awe-title-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('TitleColor', color);
            });
            $('#service-awe-title-color-hover', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('TitleColorHover', color);
            });


            $('#service-awe-detailbackground', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('DetailBackground', color);
            });
            $('#service-awe-detailcolor', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('DetailColor', color);
            });


            // Layout Choose
            $('#service-awe-content-layout', this.$el).change(function (event, values) {
                self.editingModel.set('layout', values.value);
                if(values.value != "center"){
                  $('#service-awe-enable-description',  self.$el).hide();
                }else{
                  $('#service-awe-enable-description',  self.$el).show();
                }
            });     


            // Description
            $('#service-awe-enable-description input', this.$el).change(function (event, scrollEdit) {
              if (!scrollEdit) {
                self.editingModel.set('enableDescription', parseInt($(this).val()));
              }
            });

          


            // Setting
            $('#service-awe-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#service-awe-custom-id', this.$el).change( function(){
                self.editingModel.set('customID', $(this).find('input').val());
            });
            $('#service-awe-custom-class', this.$el).change( function(){
                self.editingModel.set('customClass', $(this).find('input').val());
            });
            $('#service-awe-custom-attributes', this.el).initAttributesPanel(self);
            $('#service-awe-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
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
            $('#choose-icons i', self.el).attr('class', settings.SocialIcon);

            // Icon Color
            $('#service-awe-icon-color', this.el).aweColorPicker('value', settings.IconColor);
            $('#service-awe-icon-color-hover', this.$el).aweColorPicker('value', settings.IconColorHover);

						// Icon Size      
            if (settings.sizeIcon) {
                $('#service-awe-icon-size', self.el).aweSelect('value', settings.sizeIcon);
            };


            // Layout Choose
            if (settings.layout) {
                $('#service-awe-content-layout', self.el).aweSelect('value', settings.layout);
                if(settings.layout != "center"){
                  $('#service-awe-enable-description',  self.$el).hide();
                }else{
                  $('#service-awe-enable-description',  self.$el).show();
                }
            };
            
            // Box Icon Info
            $('#service-awe-title-font', this.$el).aweFont('options', {
                fontFamily: settings.titlefontFamily,
                fontStyle: settings.titlefontStyle,
                fontSize: settings.titlefontSize,
            });
            $('#service-awe-title-color', this.$el).aweColorPicker('value', settings.TitleColor);
            $('#service-awe-title-color-hover', this.$el).aweColorPicker('value', settings.TitleColorHover);

            $('#service-awe-detailbackground', this.$el).aweColorPicker('value', settings.DetailBackground);
            $('#service-awe-detailcolor', this.$el).aweColorPicker('value', settings.DetailColor);


            // Description
            if (settings.enableDescription) {
                $('#service-awe-enable-description input', self.el).val(settings.enableDescription).trigger("change", true);
              }


            // settings
            $('#service-awe-column-box-model', this.$el).initBoxModel(settings.boxModelSettings);
            $('#service-awe-custom-id input', this.el).val(settings.customID);
            $('#service-awe-custom-class input', this.el).val(settings.customClass);
            $('#service-awe-custom-attributes', this.$el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#service-awe-animations input[name=enabled_custom_animation]', this.$el).val(settings.customEnableAnimations).trigger('change');
            $('#service-awe-animations input[name=enabled_custom_animation]', this.$el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>Service<\/h2><\/div>"
                },


                /* Content setting */
                "content_setting":{
                    "type": "section",
                    "choose_icons": {
                            "type": "tabs_icon",
                            "title": "<div class=\"title-tab\"><span>Choose Icons <\/span><i class=\"\"><\/i><\/div>",
                            "tabs": []
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
                    "icon_color_hover": {
                        "type": "colorpicker",
                        "title": "Icon Color Hover",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "icon_size": {
                        "type": "select",
                        "title": "Icon Size",
                        "options": {
                            "icon-large": "Large",
                            "icon-normal": "Normal",
                            "icon-small": "Small",
                        },
                        "default_value": "icon-large"
                    },
                    "title_color": {
                        "type": "colorpicker",
                        "title": "Title Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "title_color_hover": {
                        "type": "colorpicker",
                        "title": "Title Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "title_font":{
                      type: "font",
                      disabledElements: ['textAlign','lineSpacing','letterSpacing'],
                    },
                    "content_layout": {
                        "type": "select",
                        "title": "Layout",
                        "options": {
                            "center": "Center",
                            "box-left": "Left",
                            "box-right": "Right",
                        },
                        "default_value": "center"
                    },
                    "enable_description": {
                        "type": "toggle",
                        "title": "Enable Description",
                        "default_value": 0
                    },
                    "detailcolor": {
                        "type": "colorpicker",
                        "title": "Detail Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "detailbackground": {
                        "type": "colorpicker",
                        "title": "Detail Background Color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                },

                
                /* setting */
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
        AWEContent.Controllers.service_awe = new AWEContent.Views.ServiceItemController();
        AWEContent.Panels.service_awe = new AWEContent.Views.ServicePanel();
    });
})(jQuery);
