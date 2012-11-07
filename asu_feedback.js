 (function ($) {
   Drupal.behaviors.cluetip = {
     attach: function(context, settings) {
       $('.asu-feedback-cluetip').cluetip({
         local:true, 
         dropShadow: false, 
         cursor: 'pointer',
         sticky: true,
         mouseOutClose: 'both', 
         closePosition: 'none',
         positionBy: 'fixed', 
         topOffset:  -64,
         leftOffset: -125,
         snapToEdge: true,        
         width: 124,
         showTitle: false
	 
       });
     }
   }
})(jQuery);
