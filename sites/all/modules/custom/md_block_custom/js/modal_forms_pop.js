(function ($) {
/**
* Provide the HTML to create the modal dialog.
*/

  Drupal.theme.prototype.CToolsModalDialog = function () {
    var html = ''
    html += '  <div id="ctools-modal">'
    html += '    <div class="ctools-modal-content">' // panels-modal-content
    html += '      <span id="modal-title" class="modal-title">&nbsp;</span><div id="modal-content" class="modal-content">';
    html += '      </div>';
    html += '    </div>';
    html += '  </div>';

    return html;
  }


})(jQuery);