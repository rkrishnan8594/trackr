$(document).ready(function() {
  $('#user_role').on('change', function() {
    console.log('hey');
    if($('#user_role').val() == 'Faculty') {
      $('.department').show();
    } else {
      $('.department').hide();
    }
  });
});
