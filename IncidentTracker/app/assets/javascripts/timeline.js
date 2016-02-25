$(document).on('page:change', function() {
  $("#datatable").DataTable({
    responsive: true
  });

  $('.incident__new-btn').detach().prependTo('.dataTables_wrapper');
});
