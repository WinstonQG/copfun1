/**
 * File: awecontent-button-item.js
 * Author: AWEThemes
 * Website: http://awethemes.com/
 */
(function($) {
    "use strict";
    /**
     * Define model for heder item
     */
    AWEContent.Models.ProgressItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "progress_awe",
            title: 'Progress Title',
            percent: 60,
            ProgressSize: 'progress-medium',
            ProgressType: 'progress-bar-success',

            color: '',
            bgcolor: '',

            boxModelSettings : {},
            customID : '',
            customClass : '',
            customEnableAttributes: 0,
            customDataAttributes: '[] ', // Array Json
            customActionAttributes: '{"newAction": "", "newAttrName": "", "newAttrValue": ""}',
            customEnableAnimations: 0,
            customDataAnimations: '{"type": "none"}', // Data Object
            lgResponsive: true,
            xsResponsive: true,
            mediumResponsive: true,
            smResponsive: true
        },
        createView: function() {
            this.view = new AWEContent.Views.ProgressItem({model: this});
        },
        relations: [
            {
                type: Backbone.HasOne,
                key: "boxModelSettings",
                relatedModel: AWEContent.Models.BoxModelSettings
            }
        ],
        clone : function() {
            var cloneModel = {};

            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);

            return new AWEContent.Models.ProgressItem(cloneModel);
        }
    });

    /**
     * Define View for HeaderItem
     */
    AWEContent.Views.ProgressItem = AWEContent.Views.Item.extend({
        initialize : function(){
            AWEContent.Views.Item.prototype.initialize.call(this);
            this.listenTo(this.model.get('boxModelSettings'), 'change', this.applySettingsChanged);
        },
        ProgressTemplate : _.template(
            '<div class="progress <%= ProgressSize %>">\
                  <div class="progress-bar <%= ProgressType %>" style="width: <%= percent %>%;">\
                          <span class="title"><%= title %></span>\
                          <span class="percent"><%= percent %>%</span>\
                  </div>\
              </div>'
            ),
        renderItemContent: function() {
            var self = this,
                $progress = $('<div class="awe-progress awe-item"></div>'),
                settings = self.model.toJSON(),
                options = {
                    title: settings.title,
                    ProgressSize: settings.ProgressSize,
                    ProgressType: settings.ProgressType,
                    percent: settings.percent,
                };

            $progress.html(self.ProgressTemplate(options)).renderItemDefaultBoxModel(settings.boxModelSettings);
            $progress.find('.progress-bar span').css('color', settings.color);
            $progress.find('.progress').css('background-color', settings.bgcolor);

            

            if (settings.customID != '') {
                $progress.attr('id', settings.customID);
            }
            if (settings.customClass!= '') {
                $progress.addClass(settings.customClass);
            }
            if (settings.customEnableAnimations) {
                $progress.processAnimations(settings.customDataAnimations)
            }
            $progress.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            self.iframeJQuery(this.el).delegate('.awe-progress.awe-item', "itemReady", function() {
                var heightBefore, heightAfter;
                self.initHallo(self.iframeJQuery(this).find('.title'), heightBefore, heightAfter);
            });
            self.$el.defaultResponsive(settings);

            return $progress;
        },
        applySettingsChanged: function(model) {
            var self = this,
                $progress = $('.awe-progress', self.$el),
                settings = model.toJSON(),
                heightBefore = self.$el.height();

            $.each(model.changedAttributes(), function(key, value) {
                self.$el.changeResponsive(key, value);
                $progress.renderChangeSettingBoxModel(key, value, model);
                console.log(key);
                switch (key){
                    case 'percent':
                        $progress.find('.progress-bar').css('width', value + '%');
                        $progress.find('span.percent').text(value + '%')
                        break;
                    case 'ProgressSize':
                        if (value) {
                            $('.progress' , self.$el).removeClass('progress-small progress-large progress-medium').addClass(value);
                        }
                        break;
                    case 'ProgressType':
                        if (value) {
                            $('.progress-bar' , self.$el).removeClass('progress-bar-success progress-bar-info progress-bar-warning progress-bar-danger progress-bar-dark').addClass(value);
                        }
                        break;
                    case 'color':
                        $progress.find('.title, .percent').css('color', value);
                        break;
                    case 'bgcolor':
                        $progress.find('.progress').css('background-color', value);
                        break;


                    case 'customID':
                        $progress.attr('id', value);
                        break;
                    case 'customClass':
                        var prevClass = self.model.previousAttributes().customClass;
                        $progress.removeClass(prevClass).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $progress.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;
                    case 'customActionAttributes':
                        $progress.renderChangeSettingsAttributes(key, value);
                        break;
                    case 'customEnableAnimations':
                        var animation, prevAnimation;
                        if (value) {
                            animation = settings.customDataAnimations;
                            prevAnimation = null;
                            $progress.processAnimations(animation);
                        }
                        else {
                            animation = null;
                            prevAnimation = settings.customDataAnimations;
                            $progress.processAnimations(animation, prevAnimation);
                        }
                        break;
                    case 'customDataAnimations':
                        var animation, prevAnimation;
                        animation = settings.customDataAnimations;
                        prevAnimation = self.model.previousAttributes().customDataAnimations;
                        $progress.processAnimations(animation, prevAnimation);
                        break;
                }
            });

            // Listen event change height of item
            setTimeout(function() {
                self.checkChangeHeight(heightBefore);
            }, 50);
        },
        changeContent : function(el){
            var self = this,
                settings = self.model.toJSON(),
                _html = $(el.currentTarget).html();
            this.model.set('title', _html);
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
    AWEContent.Views.ProgressItemController = AWEContent.Views.ItemController.extend({
        machineName: 'progress_awe',
        controllerHtml: function() {
            return '<div class="title-icon">Progress Bar</div><i class="ic ac-icon-circle"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {
                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.ProgressItem(templateData);
            }
            return new AWEContent.Models.ProgressItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define header panel
     */
    AWEContent.Views.ProgressPanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel panel-progress",
        panelName: "progress_awe",
        initPanel: function() {
            AWEContent.Views.ItemPanel.prototype.initPanel.call(this);
            var self = this;
            $('#progress-awe-color', self.el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('color', color);
            });
            $('#progress-awe-bgcolor', self.el).change(function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('bgcolor', color);
            });
            $('#progress-awe-bar-size', self.el).change(function (event, values) {
                self.editingModel.set('ProgressSize', values.value);
            });            
            $('#progress-awe-bar-type', self.el).change(function (event, values) {
                self.editingModel.set('ProgressType', values.value);
            });
            $('#progress-awe-percent', self.el).change(function(event, values) {
                self.editingModel.set('percent', values.value);
            });

            $('#progress-awe-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#text-progress-custom-id', self.el).change( function(){
                self.editingModel.set('customID', $(this).val());
            });
            $('#text-progress-custom-class', self.el).change( function(){
                self.editingModel.set('customClass', $(this).val());
            });
            $('#progress-awe-custom-attributes', this.el).initAttributesPanel(self);
            $('#progress-awe-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
                self.editingModel.set('customEnableAnimations', parseInt($(this).val()));
                if (data){
                    self.editingModel.set('customDataAnimations', JSON.stringify(data.animations));
                }
            });
        },
        setPanelElementsValue: function() {
            var self = this,
                settings = this.editingModel.toJSON();

            $('#progress-awe-color', this.$el).aweColorPicker('value', settings.color);
            $('#progress-awe-bgcolor', this.$el).aweColorPicker('value', settings.bgcolor);
            $('#progress-awe-bar-size', self.el).aweSelect('value', settings.ProgressSize);
            $('#progress-awe-bar-type', self.el).aweSelect('value', settings.ProgressType);
            // $('#progress-awe-percent .type-num', self.el).text(settings.percent);

            $('#progress-awe-column-box-model', self.el).initBoxModel(settings.boxModelSettings);
            $('#text-progress-custom-id', self.el).val(settings.customID);
            $('#text-progress-custom-class', self.el).val(settings.customClass);
            $('#progress-awe-custom-attributes', this.el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#progress-awe-animations input[name=enabled_custom_animation]', this.el).val(settings.customEnableAnimations).trigger('change');
            $('#progress-awe-animations input[name=enabled_custom_animation]', this.el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>Progress Bar<\/h2><\/div>"
                },
                "custom_style": {
                    "type": "section",
                    "percent": {
                        "type": "slider",
                        "title": "Percent",
                        "min_value": 0,
                        "max_value": 100,
                        "default_value": 60,
                        "allow_type": true,
                        "unit": "%"
                    },
                    "bar_size": {
                        "type": "select",
                        "title": "Progress Size",
                        "options": {
                            "progress-small" : "Small",
                            "progress-medium": "Medium",
                            "progress-large": "Large",
                        },
                        "default_value": "progress-medium"
                    },
                    "bar_type": {
                        "type": "select",
                        "title": "Progress Color",
                        "options": {
                            "progress-bar-success" : "Success",
                            "progress-bar-info": "Info",
                            "progress-bar-warning": "Warning",
                            "progress-bar-danger": "Danger",
                            "progress-bar-dark": "Dark",
                        },
                        "default_value": "progress-bar-success"
                    },
                    "color": {
                        "type": "colorpicker",
                        "title": "Progress color",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
                    "bgcolor": {
                        "type": "colorpicker",
                        "title": "Progress Background",
                        "options": {
                            "preferredFormat"  : "rgb",
                            "AlphaVerticle"  : true,
                            "showAlpha"  : true,
                            "allowEmpty" : true,
                            "showInput" : true
                        }
                    },
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
                                    'allow_type' : true,
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
                                    'allow_type' : true,
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
                                    'allow_type' : true,
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
                            "placeholder": "Custom ID"
                        },
                        "default_value": ""
                    },
                    "custom_class": {
                        "type": "text_field",
                        "title": "CSS class",
                        "attributes": {
                            "placeholder": "Custom class"
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
        AWEContent.Controllers.progress_awe = new AWEContent.Views.ProgressItemController();
        AWEContent.Panels.progress_awe = new AWEContent.Views.ProgressPanel();
    });
})(jQuery);
