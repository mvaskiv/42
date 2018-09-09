function delcom() {
    var poid = event.target.id;
    var phtid = event.target.name;
    var comid = $(".comid." + poid).val();
    if (poid !== "") {
        if (confirm("Dou you really want to delete this comment?")) {
            $.ajax({
                type: 'post',
                url: 'user/comment.php',
                data: {
                    photoid: poid,
                    delete_comment: "delete_comment",
                    commentid: comid
                },
                success: function (response) {
                    if (response === "success") {
                        $(".u_post#" + phtid).load(location.href + "updater.php?id=" + phtid);
                    } else {
                        alert("Ooops, something's gone wrong...");
                    }
                }
            });
        }
    } else {
        alert("Ooops, something's gone wrong...");
    }
    return false;
}