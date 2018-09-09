function delPhoto(item) {
    if (confirm("Dou you really want to delete this picture?")) {
        $.ajax({
            type: 'post',
            url: 'user/delphoto.php',
            data: {
                photoid: item.id,
                send: "Delete"
            },
            success: function (response) {
                if (response === "success") {
                    $("#post-data").load("/content/content.php");
                    $("#upanel").load("manage-posts.php");
                    $("#mobile-menu-slider").load("manage-posts-mobile.php");
                }
                else {
                    alert(response);
                }
            }
        });
    }
    return false;
}