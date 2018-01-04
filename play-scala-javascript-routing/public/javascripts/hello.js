$(document).ready(function() {
    $('#get_name').click(function() {
        jsRoutes.controllers.HomeController.getName().ajax({
            success: function(result) {
                alert("Hello: " + result)
                $("#name").text(result);
            },
            failure: function(err) {
                var errorText = 'There was an error';
                $("#name").text(errorText);
            }
        });
    });

    $('#set_name').click(function() {
        var inputName = $("#input_name").val()
        jsRoutes.controllers.HomeController.updateName(inputName).ajax({
            success: function(result) {
                $("#name").text(result);
            },
            failure: function(err) {
                var errorText = 'There was an error';
                $("#name").text(errorText);
            }
        });
    });

});