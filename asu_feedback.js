 (function ($) {
   Drupal.behaviors.cluetip = {
     attach: function(context, settings) {
     $('#asu-feedback-tooltip').removeClass('nojs');
     var cluetipHeight = $('#asu-feedback-tooltip').height();
       $('.asu-feedback-cluetip').cluetip({
         local:true,
         dropShadow: false,
         cursor: 'pointer',
         sticky: true,
         mouseOutClose: 'both',
         closePosition: 'none',
         positionBy: 'fixed',
         topOffset:  -(cluetipHeight + 15),
         leftOffset: -127,
         snapToEdge: true,
         width: 127,
         showTitle: false,
	 cluetipClass: 'asu-feedback'
       });
     }
   }
})(jQuery);
