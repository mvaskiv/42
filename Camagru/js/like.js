function like() {
    var poid = event.target.title;
    if (poid !== "") {
        $.ajax ({
            type: 'post',
            url: 'user/like.php',
            data: {
                send: "Enter",
                photoid: poid,
                like: "like"
            },
            success: function(response) {
                if (response === "success") {
                    $(".u_post#" + poid).load(location.href + "updater.php?id=" + poid);
                    $("#upanel").load("user/content/user-panel.php");
                    $("#mobile-menu-slider").load("user/content/user-panel-mobile.php");
//                            $("#post-data").load("/content/content.php");
                } else if (response === "loggedout") {
                    alert("You need to be logged in to like and comment");
                } else {
                    alert("Ooops, something's gone wrong...");
                }
            }
        });
    } else {
        alert("Ooops, something's gone wrong...");
    }
    return false;
}