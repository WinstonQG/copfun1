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
    AWEContent.Models.WeteamItem = AWEContent.Models.Item.extend({
        defaults: {
            machine_name: "team_awe",
            fid: -1,
            styleImage: 'none',
            srcImage : 'http://placehold.it/165x165',

            username: 'Name User',
            userjob: 'Job User',
            description: 'Description User',
            enableDescription: 0,

            NameColor: '',
            textColor: '',
            backgroundcolor: '',

            enablelistsocial : 0,
            listsocial: '[] ', // Array Json


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
            this.view = new AWEContent.Views.WeteamItem({model: this});
        },
        clone : function(){
            var cloneModel = {};
            $.each(this.toJSON(), function(key,value){
                cloneModel[key] = value;
            });
            cloneModel.boxModelSettings = new AWEContent.Models.BoxModelSettings(cloneModel.boxModelSettings);
            return new AWEContent.Models.WeteamItem(cloneModel);
        }
    });

    /**
     * Define View for WeteamItem
     */
    AWEContent.Views.WeteamItem = AWEContent.Views.Item.extend({
        user_template: _.template(
            '<div class="about-us-team awe-media member-team">\
              <div class="awe-media-header">\
                <div class="awe-media-image">\
                  <img src="<%= srcImage %>" alt="team">\
                </div>\
                <div class="awe-media-hover dark fullpage">\
                  <div class="fp-table">\
                    <div class="fp-table-cell center">\
                      <h6 class="upper margin-bottom-20">Connect</h6>\
                      <ul class="list-socials list-large list-light"></ul>\
                    </div>\
                  </div>\
                </div>\
              </div>\
              <div class="awe-media-body center">\
                <h3 class="awe-media-title text-upper user-name" style="color: <%= NameColor %>"><%= username %></h3>\
                <p class="awe-media-caption user-job"><span class="bold"><%= userjob %></span></p>\
                <p class="user-description margin-top-10"><%= description %></p>\
              </div>\
            </div>'
        ),
        social_list: _.template(
            '<% _.each(moresocial, function (listsocial){ %>\
                <li>\
                  <a href="<%= listsocial.link %>" data-toggle="<%= listsocial.entooltip %>" title="<%= listsocial.text %>" data-original-title="<%= listsocial.text %>"><i class="<%= listsocial.icon %>" style="color : <%= listsocial.socialcolor %>"></i></a>\
                </li>\
              <% }); %>'
        ),
        initialize: function(){
            AWEContent.Views.Item.prototype.initialize.call(this);
            this.listenTo(this.model.get('boxModelSettings'), 'change', this.applySettingsChanged);
        },
        renderItemContent: function() {
            var self = this,
                settings = self.model.toJSON(),
                html = '',
                moresocial = [],
                listsocialHtml = '',
                $ItemUserInfo = $('<div class="awe-team-user awe-item"></div>'),
                css = {
                    'background-color' : settings.backgroundcolor,
                    'color' : settings.textColor
                },
                $options = '';


            if (settings.listsocial != [] ) {
                moresocial = JSON.parse(settings.listsocial);
                listsocialHtml = self.social_list({moresocial: moresocial});
            }



            $options = {
                          srcImage: settings.srcImage,
                          username : settings.username,
                          NameColor: settings.NameColor,
                          userjob: settings.userjob,
                          description: settings.description
                      };

            $ItemUserInfo.html(self.user_template($options));

            $ItemUserInfo
                .css(css)
                .renderItemDefaultBoxModel(settings.boxModelSettings);

            if (settings.enableDescription == 0)
                $('.user-description', $ItemUserInfo).hide();

            // color p follow color wrapper
            $ItemUserInfo.find('p').css({'color' : settings.textColor});

            $ItemUserInfo.find('.list-socials').html(listsocialHtml);
            if (!settings.enablelistsocial)
                $ItemUserInfo.find('.list-socials').hide();

            self.iframeJQuery(this.el).delegate('.awe-team-user', "itemReady", function() {
                var heightBefore, heightAfter;
                self.initHallo(self.iframeJQuery(this).find('.user-name'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.user-job'), heightBefore, heightAfter);
                self.initHallo(self.iframeJQuery(this).find('.user-description'), heightBefore, heightAfter);
            });
            self.$el.defaultResponsive(settings);
            self.$el.attr('id', settings.customID);
            self.$el.addClass(settings.customClass);
            $ItemUserInfo.renderItemDefaultAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            if (settings.customEnableAnimations)
                $ItemUserInfo.processAnimations(settings.customDataAnimations)
            return $ItemUserInfo;
        },
        applySettingsChanged: function(model) {
            var self = this,
                settings = self.model.toJSON(),
                $ItemUserInfo = $('> .awe-team-user', self.el),
                heightBefore = self.$el.height(),
                moresocial = [];


            $.each(model.changedAttributes(), function(key, value){
                self.$el.changeResponsive(key, value);
                $ItemUserInfo.renderChangeSettingBoxModel(key, value, model);
                switch (key) {
                    case 'srcImage' :
                        var prevSrc= model.previousAttributes().srcImage;

                        if (prevSrc == '') {
                            self.$img.css({
                                'min-height' : '',
                                'background' : ''
                            });
                        }
                        $('.member-team img' , self.$el).attr('src', settings.srcImage);

                        // Setting src image for panel image
                        $('#team-awe-select-image img', AWEContent.Panels.image.$el).attr('src', value);
                        break;
                    case 'styleImage':
                        var styleImage = settings.styleImage,
                            styles = styleImage;

                        if (settings.fid != -1) {
                            $.post(AWEContent.Path.imageStyleURL, {fids: '' + settings.fid, styles: styles}, function (response) {
                                if ($.type(response) == 'string') {
                                    try {
                                        response = JSON.parse(response);
                                    }
                                    catch(e){}
                                }
                                if ($.type(response) == 'object') {
                                    self.model.set({
                                        srcImage: response[settings.fid][settings.styleImage]
                                    });
                                }
                            });
                        }
                        break;

                    // Description
                    case 'enableDescription':
                        if (value == 0)
                            $('.user-description', $ItemUserInfo).hide();
                        else
                            $('.user-description', $ItemUserInfo).show();
                        break; 

                    // List Social
                    case 'enablelistsocial':
                        if (value == 0)
                            $ItemUserInfo.find('.list-socials').hide();
                        else
                            $ItemUserInfo.find('.list-socials').show();
                        break;
                    case 'listsocial':
                        if (settings.listsocial != [] && settings.enablelistsocial == 1) {
                            moresocial = JSON.parse(settings.listsocial);
                            $ItemUserInfo.find('.list-socials').html(self.social_list({moresocial: moresocial}));
                        }
                        break;

                    // User Name
                    case "NameColor":
                            $('.user-name', $ItemUserInfo).css('color', value);
                        break;
                    case 'textColor' :
                        $ItemUserInfo.find('p').css('color', value);
                        break;                    
                    case 'backgroundcolor' :
                        $ItemUserInfo.css('background-color', value);
                        break;



                    case 'customID':
                        self.$el.attr('id', value);
                        break;
                    case 'customClass':
                        var prevClass = self.model.previousAttributes().customClass;
                        self.$el.removeClass(prevClass).addClass(value);
                        break;
                    case 'customEnableAttributes':
                        $ItemUserInfo.renderChangeSettingsAttributes(key, value, settings.customDataAttributes);
                        break;
                    case 'customActionAttributes':
                        $ItemUserInfo.renderChangeSettingsAttributes(key, value);
                        break;

                    case 'customEnableAnimations':
                        var animation, prevAnimation;
                        if (value) {
                            animation = settings.customDataAnimations;
                            prevAnimation = null;
                            $ItemUserInfo.processAnimations(animation);
                        }
                        else {
                            animation = null;
                            prevAnimation = settings.customDataAnimations;
                            $ItemUserInfo.processAnimations(animation, prevAnimation);
                        }

                        break;
                    case 'customDataAnimations':
                        var animation, prevAnimation;
                        animation = settings.customDataAnimations;
                        prevAnimation = self.model.previousAttributes().customDataAnimations;
                        $ItemUserInfo.processAnimations(animation, prevAnimation);
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
                case '.user-name':
                    this.model.set('username', _html);
                    break;
                case '.user-job':
                    this.model.set('userjob', _html);
                    break;
                case '.user-description':
                    this.model.set('description', _html);
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
        }
    });

    /**
     * Define view for Header Controller
     * li tag what is contained by items panel
     */
    AWEContent.Views.WeteamItemController = AWEContent.Views.ItemController.extend({
        machineName: 'team_awe',
        controllerHtml: function() {
            return '<div class="title-icon">We Team</div><i class="ic ac-icon-message"></i>';
        },
        createItemModel: function(templateData) {
            var boxModelSettings;
            if (templateData!= undefined) {

                boxModelSettings = new AWEContent.Models.BoxModelSettings(templateData.boxModelSettings);
                templateData.boxModelSettings = boxModelSettings;

                return new AWEContent.Models.WeteamItem(templateData);
            }

            return new AWEContent.Models.WeteamItem({'boxModelSettings' : new AWEContent.Models.BoxModelSettings()});
        }
    });

    /**
     * Define header panel
     */
    AWEContent.Views.WeteamPanel = AWEContent.Views.ItemPanel.extend({
        tagName: "div",
        className: "awe-obj-panel panel-welcome",
        panelName: "team_awe",
        initPanel: function() {
            AWEContent.Views.ItemPanel.prototype.initPanel.call(this);
            var self = this;
            $('#team-awe-select-image input[name=selected_media]', self.el).change(function () {
                var data = $(this).val(),
                    $img = $(this).prevAll('.image-content').children('img'),
                    jsonData = '',
                    fileUrl = '';

                try {
                    jsonData = JSON.parse(data);
                } catch (e) {}

                if (typeof jsonData == 'object') {
                    var styleImage = self.editingModel.get('styleImage'),
                        styles = styleImage;

                    if (AWEContent.Path.imageStyleURL != '') {
                        $.post(AWEContent.Path.imageStyleURL, {fids: "" + jsonData.fid, styles: styles}, function(response) {

                            if ($.type(response) == 'string') {
                                try {
                                    response = JSON.parse(response);
                                }
                                catch(e){}
                            }

                            // update image style url to gallery image view
                            if (typeof (response)  == 'object') {
                                self.editingModel.set ({
                                    fid: jsonData.fid,
                                    srcImage : response[jsonData.fid][self.editingModel.get('styleImage')]
                                });
                            }
                        });
                    }
                    else {
                        self.editingModel.set ({
                            fid: jsonData.fid,
                            srcImage : jsonData.file_url,
                            srcLightbox : jsonData.file_url
                        });
                    }
                    $img.attr('src', jsonData.file_url);
                }
            });
            $('#team-awe-thumb-style', this.el).change(function (event, values) {
                self.editingModel.set('styleImage', values.value);
            });


            $('#team-awe-column-box-model', self.el).initBoxModelPanel(self, 'boxModelSettings');
            $('#team-awe-custom-id', this.$el).change( function(){
                self.editingModel.set('customID', $(this).find('input').val());
            });
            $('#team-awe-custom-class', this.$el).change( function(){
                self.editingModel.set('customClass', $(this).find('input').val());
            });
            $('#team-awe-custom-attributes', this.el).initAttributesPanel(self);
            $('#team-awe-animations input[name=enabled_custom_animation]', this.el).change(function(event, data) {
                self.editingModel.set('customEnableAnimations', parseInt($(this).val()));
                if (data){
                    self.editingModel.set('customDataAnimations', JSON.stringify(data.animations));
                }
            });

            /* Image Style */
            $('#team-awe-enable-description input', this.$el).change(function (event, scrollEdit) {
                    if (!scrollEdit) {
                      self.editingModel.set('enableDescription', parseInt($(this).val()));
                    }
                });


            // User Name
            $('#team-awe-name-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('NameColor', color);
            });
            $('#team-awe-text-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('textColor', color);
            });
            $('#team-awe-background-color', this.$el).change( function(event, color) {
                if (color)
                    color = color.toRgbString();
                else
                    color = '';
                self.editingModel.set('backgroundcolor', color);
            });

            // List Social Panel Settings
            $('#team-awe-listsocial .togg-status', this.$el).click(function(event) {
                event.preventDefault();

                $(this).toggleClass("active");
                if ($(this).hasClass("active")){
                    $("input[name=toggle_value]", $(this)).val(1).trigger("change");
                    self.editingModel.set('enablelistsocial', 1);
                    $(this).next('i').show();
                }
                else{
                    $("input[name=toggle_value]", $(this)).val(0).trigger("change");
                    self.editingModel.set('enablelistsocial', 0);
                    $(this).next('i').hide();
                }
            });

            $('#team-awe-listsocial .ac-icon-edit', this.$el).click(function(event) {
                event.preventDefault();
                AWEContent.Panels.SocialPanel.editModel(self.editingModel);
            });

        },
        setPanelElementsValue: function() {
            var self = this,
                settings = this.editingModel.toJSON();

            $('#team-awe-select-image img', self.el).attr('src', settings.srcImage != '' ? settings.srcImage : '');
            if (AWEContent.Path.imageStyleURL != '') {
                $('#team-awe-thumb-style', self.el).aweSelect('value', settings.styleImage);
            }
          

            /* Description */
            if (settings.enableDescription) {
                $('#team-awe-enable-description input', self.el).val(settings.enableDescription).trigger("change", true);
              }

            // User Name
            $('#team-awe-name-color', this.$el).aweColorPicker('value', settings.NameColor);
            $('#team-awe-text-color', this.$el).aweColorPicker('value', settings.textColor);
            $('#team-awe-background-color', this.$el).aweColorPicker('value', settings.backgroundcolor);
            


            //List Social
            if (settings.enablelistsocial) {
                $('#team-awe-listsocial .togg-status', self.$el).addClass('active');
                $('#team-awe-listsocial i', self.$el).show()
            }
            else{
                $('#team-awe-listsocial .togg-status', self.$el).removeClass('active');
                $('#team-awe-listsocial i', self.$el).hide()
            }


            $('#team-awe-column-box-model', this.$el).initBoxModel(settings.boxModelSettings);
            $('#team-awe-custom-id input', this.el).val(settings.customID);
            $('#team-awe-custom-class input', this.el).val(settings.customClass);
            $('#team-awe-custom-attributes', this.$el).initAttributes(settings.customEnableAttributes, settings.customDataAttributes);
            $('#team-awe-animations input[name=enabled_custom_animation]', this.$el).val(settings.customEnableAnimations).trigger('change');
            $('#team-awe-animations input[name=enabled_custom_animation]', this.$el).attr('data-animations', settings.customDataAnimations).data('view', this.editingModel.view);
        },
        buildPanel: function() {
            return {
                "title": {
                    "type": "markup",
                    "markup": "<div class=\"awe-title\"><h2>User<\/h2><\/div>"
                },
                custom_style: {
                    'type': 'section',
                    'select_image': {
                        'type': 'button',
                        'title': 'Select Image'
                    },
                    image_style_title: {
                        type: 'markup',
                        markup: '<div class="awe-style-list-title image-style-title"><span>Image Style</span></div>'
                    },
                    'thumb_style': {
                        type: "image_style_list"
                    },
                },
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
                    "text_color": {
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
                    "name_color": {
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
                    "enable_description": {
                        "type": "toggle",
                        "title": "Enable Description",
                        "default_value": 0
                    }
                },
                "custom_listsocial": {
                    "type": "section",
                    "listsocial": {
                        type: 'markup',
                        markup: '<div id="team-awe-listsocial" class="aw-cus evr-change toggle-pull">\
                                    <span>Enable Social<i class="i-sign ic ac-icon-circle"></i></span>\
                                    <div class="togg-status">\
                                        <div class="butt-status"></div>\
                                        <input type="hidden" name="enabled_custom_attributes" value="0">\
                                    </div>\
                                    <i class="js-edit-animations ic ac-icon-edit"></i>\
                                </div>'
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

    AWEContent.Views.listsocialPanel = AWEContent.Views.DefaultPanel.extend({
        panelName: 'SocialPanel',
        className: 'awe-obj-panel child-panel listsocial-panel',
         buildPanel: function() {
            return {
                'title': {
                    type: 'markup',
                    markup: '<h2>Social</h2>'
                },
                add_form: {
                    type: 'section',
                    icon_background: {
                        type: 'markup',
                        markup:'<div id="item-social-choose-icon" class="tab-icon" data-name-icon="ic ac-icon-help">\
                                    <div class="title-tab">\
                                        <span>Choose Icons </span><i class="ic ac-icon-help"></i>\
                                    </div>\
                                </div>\
                                <div id="social-tooltip-choose" class="aw-cus evr-change toggle-pull">\
                                    <span>Enable Background Type<i class="i-sign ic ac-icon-circle" style="display: none;"></i></span>\
                                    <div class="togg-status">\
                                      <div class="butt-status"></div>\
                                      <input type="hidden" name="enabled_custom_social" value="0" id="awe-tooltip-value">\
                                    </div>\
                                    <i class="js-edit-animations ic ac-icon-edit" style="display: none;"></i>\
                                </div>'
                        },
                    social_text: {
                            "type": "text_field",
                            "title": "Type",
                            "attributes": {
                                "placeholder": "Social"
                            },
                            "default_value": ""
                        },
                    social_link: {
                            "type": "text_field",
                            "title": "Link",
                            "attributes": {
                                "placeholder": "http://"
                            },
                            "default_value": ""
                        },
                    social_color: {
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
                    main_button: {
                        type: 'markup',
                        markup:'<div class="add-attr">\
                                  <button><i class="ic ac-icon-add"></i>Add button</button>\
                              </div>'
                        }
                },
                list_links: {
                    type: 'section',
                    social_items: {
                        type: 'markup',
                        markup: '<div class="awe-social-list"></div>'
                    }
                }
            }
        },
        socialItemTemplate: _.template(
            '<div class="item-cus-data">\
                <div class="aw-norm" data-social-tooltip="<%= entooltip %>" data-social-text="<%= text %>" data-social-color="<%= socialcolor %>">\
                    <i class="<%= icon %>"></i>\
                    <span class="filldata"><%= link %></span>\
                    <div class="fl-right"><span class="rem-item-data"><i class="ic ac-icon-trash"></i></span></div>\
                </div>\
            </div>'
        ),
        initPanel: function() {
            var self = this;
            AWEContent.Views.DefaultPanel.prototype.initPanel.call(this);

            // Choose icon
            $('#item-social-choose-icon', this.el).click( function() {
                AWEContent.Panels.listIconPanel.processIcon($(this));
            }).change( function(event, data) {
                if (data) {
                    $('.title-tab > i', this).removeClass().addClass(data.nameIcon);
                    $(this).attr('data-name-icon', data.nameIcon);
                }
            });


            // background choose
            $('#socialpanel-social-text',  self.$el).hide();

            $('#social-tooltip-choose .togg-status', this.$el).click(function(event) {
                event.preventDefault();
                $(this).toggleClass("active");
                if ($(this).hasClass("active")){
                  $("input[name=enabled_custom_social]", $(this)).val(1).trigger("change");
                  $('#socialpanel-social-text',  self.$el).show(); 
                }else{
                  $("input[name=enabled_custom_social]", $(this)).val(0).trigger("change");
                  $('#socialpanel-social-text',  self.$el).hide();
                }
            });



            $('.add-attr button', this.$el).click(function(event) {
                event.preventDefault();

                var social_icon = $('#item-social-choose-icon', self.$el).attr('data-name-icon'),
                    social_tooltip = $('input#awe-tooltip-value', self.$el).val(),
                    social_link = $('#text-socialpanel-social-link', self.$el).val(),
                    social_color = $('#socialpanel-social-color input', self.$el).val(),
                    socialList = self.editingModel.get('listsocial'),
                    social_name = '';

                    if(social_tooltip ==1) social_tooltip="tooltip";


                    if($("input[name=enabled_custom_social]", this.$el).val() != 0){
                        social_name = $('#socialpanel-social-text input', self.$el).val();
                    }
                if (social_link) {
                    $('.awe-social-list', self.$el).append(self.socialItemTemplate({icon: social_icon, link: social_link, text: social_name, entooltip: social_tooltip, socialcolor: social_color}));

                    if (socialList)
                        socialList = JSON.parse(socialList);
                    else
                        socialList = [];

                    // add social link to list
                    socialList.push({icon: social_icon, link: social_link, text: social_name, entooltip: social_tooltip, socialcolor: social_color});

                    // update value to editing model
                    self.editingModel.set('listsocial', JSON.stringify(socialList));

                    // reset add form
                    $('#text-socialpanel-social-link', self.$el).val('');
                }
            });

            $('.awe-social-list', this.$el).delegate('.rem-item-data', 'click', function(event) {
                event.preventDefault();

                var $item = $(this).parents('.item-cus-data:first'),
                    id = $item.index(),
                    socialList = JSON.parse(self.editingModel.get('listsocial'));

                // remove item data in social list
                socialList.splice(id, 1);
                $item.remove();

                // update data to social list
                self.editingModel.set('listsocial', JSON.stringify(socialList));
            }).sortable({
                items: '.item-cus-data',
                axis: 'y',
                stop: function(event, ui) {
                    var socialList = [];

                    // get data of new sort list
                    $('.awe-social-list > .item-cus-data', self.$el).each(function() {
                        var social_icon = $('.aw-norm > i', this).attr('class'),
                            social_tooltip = $('.aw-norm', this).data('social-tooltip').trim(),
                            social_link = $('.aw-norm > span', this).text().trim(),
                            social_name = $('.aw-norm', this).data('social-text').trim(),
                            social_color = $('.aw-norm', this).data('social-color').trim();

                            if(social_tooltip ==1) social_tooltip="tooltip";

                        socialList.push({icon: social_icon, link: social_link, text: social_name, entooltip: social_tooltip, socialcolor: social_color});
                    });

                    // update social list
                    self.editingModel.set('listsocial', JSON.stringify(socialList));
                }
            });
        },
        setPanelElementsValue: function() {
            var self = this,
                socialList = this.editingModel.get('listsocial');

            if (socialList)
                socialList = JSON.parse(socialList);
            else
                socialList = [];

            // render list social item
            $('.awe-social-list', this.$el).html('');
            $.each(socialList, function() {
                $('.awe-social-list', self.$el).append(self.socialItemTemplate(this));
            });
        }
    });


    $(document).ready(function() {
        AWEContent.Controllers.team_awe = new AWEContent.Views.WeteamItemController();
        AWEContent.Panels.team_awe = new AWEContent.Views.WeteamPanel();
        AWEContent.Panels.SocialPanel = new AWEContent.Views.listsocialPanel();
    });
})(jQuery);
