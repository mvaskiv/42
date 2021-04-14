function logMeOut() {
    $.ajax ({
        url: 'user/logout.php',
        success: function(response) {
            if (response === "success") {
                var id = $(".u_post:last").attr("id");
                var idf = $(".u_post:first").attr("id");
                $("#upanel").load("user/content/login.php");
                $("#mobile-menu-slider").load("user/content/login-mobile.php");
                if (id) {
                    $(".u_post").each (function() {
                        $(this).load(location.href + "updater.php?id=" + this.id);
                    });
                } else {
                    $(location).attr('href', "/");
                }
            }
        }
    });
    return false;
}