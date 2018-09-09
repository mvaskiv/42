function logMeIn() {
    var form = event.target.name;
    var uname = $(".login.lgn." + form).val();
    var pwd = $(".login.pwd." + form).val();
    if ($('#cookie_desk').prop("checked")) {var cookie = "setme";} else {var cookie = ""}
    if (uname !== "" && pwd !== "") {
        $.ajax ({
            type: 'post',
            url: 'user/login.php',
            data: {
                send: "Enter",
                login: uname,
                password: pwd,
                cookie: cookie
            },
            success: function(response) {
                if (response === "success") {
                    $("#upanel").load("user/content/user-panel.php");
                    $("#mobile-menu-slider").load("user/content/user-panel-mobile.php");
                    $(".u_post").each (function() {
                        $(this).load(location.href + "updater.php?id=" + this.id);
                    });
                } else if (response === "confirmation") {
                    alert("Please, verify your email");
                } else {
                    alert("Please, check Your login credentials");
                }
            }
        });
    } else {
        alert("You can't login without your name or your password");
    }
    return false;
}