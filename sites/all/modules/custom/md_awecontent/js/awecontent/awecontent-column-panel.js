!function(e){"use strict";AWEContent.Views.ColumnPanel=AWEContent.Views.DefaultPanel.extend({className:"awe-obj-panel awe-panel panel-column",panelName:"column",initialize:function(){AWEContent.Views.DefaultPanel.prototype.initialize.call(this)},initPanel:function(){AWEContent.Views.DefaultPanel.prototype.initPanel.call(this);var t=this;e("#text-column-custom-id").change(function(){t.editingModel.get("settings").set("customID",e(this).val())}),e("#text-column-custom-classes").change(function(){t.editingModel.get("settings").set("customClass",e(this).val())}),e("#column-center-vertical input",t.el).change(function(l,o){o||t.editingModel.get("settings").set("centerVertical",parseInt(e(this).val()))}),e("#column-text-align",t.el).change(function(e,l){t.editingModel.get("settings").set("textAlign",l.value)}),e("#column-min-height",this.el).change(function(l,o){t.editingModel.get("settings").set("minHeight",o.value),-1==o.value&&e(".display-font",e(this)).text("DF")}),e("#column-background-color",t.el).change(function(e,l){l=l?l.toRgbString():"",t.editingModel.get("settings").set("bgColor",l)}),e("#column-background-image input",this.el).change(function(l,o){var n=e(this).val().trim(),i=n?JSON.parse(n):!1,a=i&&void 0!==i.file_url?i.file_url:"",c=i&&void 0!==i.fid?i.fid:-1;o||(t.editingModel.bgImageURL=a,t.editingModel.get("settings").set("bgFid",c)),0>=c?e("#column-background-mode, #column-background-position, #column-parallax-scrolling, .delete-bg-img",t.el).hide():(e(".delete-bg-img",t.el).show(),e("#column-background-mode",t.el).show().trigger("change",{value:t.editingModel.get("settings").get("bgMode")}))}),e("#column-background-mode",t.el).change(function(l,o){{var n=o.value;e(this).closest(".toggle-drop")}"fullcover"==n?e("#column-parallax-scrolling, #column-background-position",t.$el).hide():"parallax"==n?(e("#column-background-position",t.$el).hide(),e("#column-parallax-scrolling",t.$el).show()):(e("#column-background-position",t.$el).show(),e("#column-parallax-scrolling",t.$el).hide()),t.editingModel.get("settings").set("bgMode",o.value)}),e("#column-background-position",t.el).change(function(e,l){t.editingModel.get("settings").set("bgPosition",l.value)}),e("#column-parallax-scrolling input",t.el).change(function(l,o){o||t.editingModel.get("settings").set("enableScrolling",parseInt(e(this).val()))}),e("#column-background-enable-overlay input",t.el).change(function(l,o){parseInt(e(this).val())?e(this).closest(".toggle-enable").next().show():e(this).closest(".toggle-enable").next().hide(),o||t.editingModel.get("settings").set("enabledBgOverlay",parseInt(e(this).val()))}),e("#column-overlay-color",t.el).change(function(e,l){l=l?l.toRgbString():"",t.editingModel.get("settings").set("bgOverlayColor",l)}),e("#column-column-box-model",this.el).initBoxModelPanel(this,"boxModelSettings")},setPanelElementsValue:function(){var t=this,l=this.editingModel.get("settings").toJSON(),o=l.bgFid?{fid:l.bgFid}:{fid:-1};e("#text-column-custom-id",t.el).val(l.customID),e("#text-column-custom-classes",t.el).val(l.customClass),e("#column-center-vertical input",t.el).val(l.centerVertical).trigger("change",{isPanel:!0}),e("#column-text-align",t.el).aweSelect("value",l.textAlign),l.enableMinHeight?e("#column-min-height",t.el).show():e("#column-min-height",t.el).hide(),e("#column-min-height .display-font",t.el).text(l.minHeight).trigger("change",{isPanel:!0}),e("#column-min-height",t.el).aweSlider("value",l.minHeight),e("#column-background-color",t.el).aweColorPicker("value",l.bgColor),e("#column-background-mode",t.el).aweSelect("value",l.bgMode),e("#column-background-position",t.el).aweSelect("value",l.bgPosition),e("#column-background-image .img-bg",t.el).css("background-image","url("+encodeURI(this.editingModel.bgImageURL)+")"),e("#column-background-image input",t.el).val(JSON.stringify(o)).trigger("change",!0),e("#column-background-enable-overlay input",t.el).val(l.enabledBgOverlay).trigger("change",{isPanel:!0}),e("#column-overlay-color",t.el).aweColorPicker("value",l.bgOverlayColor),e("#column-column-box-model").initBoxModel(l.boxModelSettings)},buildPanel:function(){return{title:{type:"markup",markup:'<div class="awe-title"><h2>Custom column</h2></div>'},custom_definitions:{type:"section",custom_id:{type:"text_field",title:"ID",attributes:{placeholder:"Custom ID"},default_value:""},custom_classes:{type:"text_field",title:"Classes",attributes:{placeholder:"Custom classes"},default_value:""}},custom_interface:{type:"section",text_align:{type:"select",title:"Align",options:{"text-left":"Left","text-center":"Center","text-right":"Right"},default_value:"col-text-left"},min_height:{type:"slider",title:"Min Height",min_value:-1,max_value:1e3,default_value:120,allow_type:!0,unit:"px"}},custom_appearances:{type:"section",background_color:{type:"colorpicker",title:"Background color",options:{preferredFormat:"rgb",AlphaVerticle:!0,showAlpha:!0,allowEmpty:!0,showInput:!0}},background_image:{type:"media",title:"Background image"},background_mode:{type:"select",title:"Mode",options:{repeat:"Repeat All","repeat-x":"Repeat Horizontally","repeat-y":"Repeat Vertically","no-repeat":"No Repeat",fullcover:"FullCover",parallax:"Parallax"},default_value:"repeat"},background_position:{type:"select",title:"Position",options:{"left top":"Top Left","right top":"Top Right","center top":"Top Center","left center":"Center Left","right center":"Center Right","center center":"Center Center","left bottom":"Bottom Left","right bottom":"Bottom Right","center bottom":"Bottom Center"},default_value:"left top"},parallax_scrolling:{type:"toggle",title:"Parallax scrolling",default_value:0}},background_overlay:{type:"section",background_enable_overlay:{type:"toggle",title:"Enable background overlay",default_value:0},overlay_color:{type:"colorpicker",title:"Overlay color",options:{preferredFormat:"rgb",AlphaVerticle:!0,showAlpha:!0,allowEmpty:!0,showInput:!0}}},custom_box_model:{type:"section",column_box_model:{type:"tabs",tabs:[{tab_title:"Border",contents:{custom_border:{type:"box_border",min_value:0,max_value:100,default_value:0}}},{tab_title:"Radius",contents:{custom_border_radius:{type:"box_model",model_type:"border_radius",allow_type:!0,min_value:0,max_value:100,default_value:0}}},{tab_title:"Padding",contents:{custom_padding:{type:"box_model",model_type:"padding",allow_type:!0,min_value:0,max_value:100,default_value:0}}},{tab_title:"Margin",contents:{custom_margin:{type:"box_model",model_type:"margin",allow_type:!0,min_value:0,max_value:100,default_value:0}}}]}}}}})}(jQuery);