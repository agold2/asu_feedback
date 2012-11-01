 (function ($) {
   Drupal.behaviors.cluetip = {
     attach: function(context, settings) {
       $('.asu-feedback-cluetip').cluetip({
         local:true, 
         positionBy: 'topBottom', 
         dropShadow: false, 
         mouseOutClose: 'link', 
         delayedClose:99000, 
         width: 124,
         showTitle: false
       });
     }
   }
})(jQuery);
