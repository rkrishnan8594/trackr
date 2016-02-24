$(document).on('page:load', function() {
  $('#user_role').on('change', function() {
    if($('#user_role').val() == 'Faculty') {
      $('.department').show();
    } else {
      $('.department').hide();
    }
  });

  $('#example').DataTable({
    responsive: true
  });

  /*$('.table__row').on('click', function() {
    window.document.location = $(this).data("href");
  });*/
});
