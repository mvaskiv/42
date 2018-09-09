function registerMeSubmit() {
    var form = event.target.name;
    var login = $("#register-login." + form).val();
    var pwd  = $("#register-pwd." + form).val();
    var pwd2  = $("#register-pwd-conf." + form).val();
    var name = $("#register-first." + form).val();
    var surname = $("#register-last." + form).val();
    var email = $("#register-email." + form).val();
    $.ajax ({
        type: 'post',
        url: 'user/register.php',
        data: {
            send: "Submit",
            login: login,
            password: pwd,
            repeat: pwd2,
            first: name,
            last: surname,
            email: email
        },
        success: function(response) {
            if (response === "success") {
                $("#upanel").load("user/regsuccess.php");
                $("#mobile-menu-slider").load("user/regsuccess.php");
            } else if (response === "nomatch") {
                alert("Please check the information you provided");
            } else {
                alert("Ooops, something's gone wrong... Probably the login you chose is alredy taken");
            }
        }
    });
    return false;
}

function editMeSubmit() {
    var form = event.target.name;
    var login = $("#edit-login." + form).val();
    var pwd  = $("#edit-pwd." + form).val();
    var pwd2  = $("#edit-pwd-conf." + form).val();
    var email = $("#edit-email." + form).val();
    $.ajax ({
        type: 'post',
        url: 'user/edit_profile.php',
        data: {
            send: "Submit",
            login: login,
            password: pwd,
            repeat: pwd2,
            email: email
        },
        success: function(response) {
            if (response === "success") {
                $("#upanel").load("user/editsuccess.php");
                $("#mobile-menu-slider").load("user/editsuccess.php");
            } else if (response === "ops") {
                alert("Please check the information you provided");
            } else {
                alert("Ooops, something's gone wrong... Probably the login you chose is alredy taken");
            }
        }
    });
    return false;
}