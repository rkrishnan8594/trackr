$(document).ready(function() {
  $('.js-role').on('change', function() {
    if($('.js-role').val() == 'Faculty') {
      $('.department').show();
    } else {
      $('.department').hide();
    }
  });
});
