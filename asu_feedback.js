 (function ($) {
   Drupal.behaviors.cluetip = {
     attach: function(context, settings) {
       $('.asu-feedback-cluetip').cluetip({
         local:true, 
         dropShadow: false, 
         cursor: 'pointer',
         sticky: true,
         mouseOutClose: 'both', 
         positionBy: 'topBottom', 
         topOffset:  0,
         leftOffset: 0,
         snapToEdge: true,        
         width: 124,
         showTitle: false
       });
     }
   }
})(jQuery);
