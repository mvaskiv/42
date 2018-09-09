function react() {
    var poid = event.target.name;
    var comtext = $(".u_new_comment." + poid).val();
    var like = $("#like-btn").val();
    if (poid !== "") {
        $.ajax ({
            type: 'post',
            url: 'user/comment.php',
            data: {
                send: "Enter",
                photoid: poid,
                like: like,
                new_comment: comtext
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
                    alert("Seems like you're doing it the wrong way...");
                }
            }
        });
    } else {
        alert("Ooops, something's gone wrong...");
    }
    return false;
}