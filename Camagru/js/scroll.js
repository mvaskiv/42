$(window).scroll(function() {
    if ($(window).scrollTop() + $(window).height()  >= $(document).height()) {
        var id = $(".u_post:last").attr("id");
        loadMoreData(id);
    }
});
function loadMoreData(id) {
    if (!id) {var id = $(".u_post:last").attr("id");}
    $.ajax(
        {
            url: 'content/loader.php?id=' + id,
            type: "get"
        })
        .done(function(data) {
            $("#post-data").append(data);
            var newid = $(".u_post:last").attr("id");
            if (newid == id) {
                $('.more').hide();
            }
        })
        .fail(function(jqXHR, ajaxOptions, thrownError)
        {
            alert("Something's gone wrong...");
        });
}