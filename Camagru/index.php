<?php
    session_start();
    require_once("utilities/db_config.php");
    require_once("utilities/cookie_check.php");
?>
<!DOCTYPE html>
<html>
	<head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width">
        <meta name="apple-mobile-web-app-title" content="Camagru">
        <meta name="apple-mobile-web-app-capable" content="yes">
        <meta name="apple-mobile-web-app-status-bar-style" content="black">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
        <!--        ICON-->
        <link rel="apple-touch-startup-image" href="apple-touch-icon.png">
        <link rel=”apple-touch-icon” href="apple-touch-icon.png">

<!--        STYLESHEETS-->
        <link rel="stylesheet" type="text/css" media="screen and (min-width: 768px)" href="styles/desktop/icon.css">
        <link rel="stylesheet" type="text/css" media="screen and (max-width: 768px)" href="styles/mobile/icon-mobile.css">
        <link rel="stylesheet" type="text/css" media="screen and (min-width: 768px)" href="styles/desktop/font.css">
        <link rel="stylesheet" type="text/css" media="screen and (max-width: 768px)" href="styles/mobile/font-mobile.css">
        <link rel="stylesheet" type="text/css" media="screen and (min-width: 768px)" href="styles/desktop/field.css">
        <link rel="stylesheet" type="text/css" media="screen and (max-width: 768px)" href="styles/mobile/field-mobile.css">
		<link rel="stylesheet" type="text/css" media="screen and (min-width: 768px)" href="styles/desktop/main.css">
        <link rel="stylesheet" type="text/css" media="screen and (max-width: 768px)" href="styles/mobile/main-mobile.css">
		<link href="https://fonts.googleapis.com/css?family=Pacifico" rel="stylesheet">
		<link href="https://fonts.googleapis.com/css?family=Open+Sans" rel="stylesheet">
		<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.0.10/css/all.css" integrity="sha384-+d0P83n9kaQMCwj8F4RJB66tzIwOKmrdb46+porD/OvrJ+37WqIM7UoBtwHO6Nlg" crossorigin="anonymous">
        <title>Camagru</title>
	</head>
<body>
    <header>
        <?php require_once("content/header.php"); ?>
    </header>
        <div id="mobile-menu-slider">
            <?php
            if (isset($_SESSION["auth_data"]["user"])) {require_once("user/content/user-panel-mobile.php");}
            else {require_once("user/content/login-mobile.php");}
            ?>
        </div>
        <div id="site-content">
            <div class="content" id="post-data" onclick="return unfade();">
                <?php
                    if ($_GET['page'] === "register") {require_once("register.php");}
                    else if ($_GET['page'] === "new") {require_once("upload.php");}
                    else if ($_GET['page'] === "live") {require_once("upload_live.php");}
                    else if ($_GET['page'] === "edit-profile") {require_once("edit_profile.php");}
                    else if ($_GET['page'] === "avatar") {require_once("add-avatar.php");}
                    else {require_once("content/content.php");}
                ?>
            </div>
            <div style="height:30px"></div>
            <div id="upanel">
                <?php
                    if (isset($_SESSION["auth_data"]["user"])) {require_once("user/content/user-panel.php");}
                    else {require_once("user/content/login.php");}
                ?>
            </div>
            <div class="more">
                <button onclick="loadMoreData()" id="load-more-btn">
                    Load More ...
                </button>
            </div>
        </div>
        <script src="js/like.js"></script>
        <script src="js/react.js"></script>
        <script src="js/panelitems.js"></script>
        <script src="js/mobilemenu.js"></script>
        <script src="js/submitreg.js"></script>
        <script src="js/delcom.js"></script>
        <script src="js/delphoto.js"></script>
        <script src="js/scroll.js"></script>
        <script src="js/preview.js"></script>
        <script src="js/logout.js"></script>
        <script src="js/login.js"></script>

<!--    <footer>-->
<!--        <div class="footer">-->
<!--            <p class="footer">&copy; mvaskiv 2018</p>-->
<!--        </div>-->
<!--    </footer>-->
<!--    <script>-->
<!--        $(window).scroll(function() {-->
<!--            if ($(window).scrollTop() + $(window).height()  >= $(document).height()) {-->
<!--                var id = $(".u_post:last").attr("id");-->
<!--                loadMoreData(id);-->
<!--            }-->
<!--        });-->
<!--        function loadMoreData(id) {-->
<!--            if (!id) {var id = $(".u_post:last").attr("id");}-->
<!--            $.ajax(-->
<!--                {-->
<!--                    url: 'content/loader.php?id=' + id,-->
<!--                    type: "get"-->
<!--                })-->
<!--                .done(function(data) {-->
<!--                    $("#post-data").append(data);-->
<!--                    var newid = $(".u_post:last").attr("id");-->
<!--                    if (newid == id) {-->
<!--                        $('.more').hide();-->
<!--                    }-->
<!--                })-->
<!--                .fail(function(jqXHR, ajaxOptions, thrownError)-->
<!--                {-->
<!--                    alert("Something's gone wrong...");-->
<!--                });-->
<!--        }-->
<!--    </script>-->
<!--    <script>-->
<!--        var i = 0;-->
<!--        function revealMenu() {-->
<!--            if (i === 0) {-->
<!--                document.getElementById('mobile-menu-slider').style.left = "0";-->
<!--                i++;-->
<!--            } else if (i === 1) {-->
<!--                document.getElementById('mobile-menu-slider').style.left = "100%";-->
<!--                i--;-->
<!--            }-->
<!--        }-->
<!--    </script>-->
<!--    <script>-->
<!--        function logMeIn() {-->
<!--            var form = event.target.name;-->
<!--            var uname = $(".login.lgn." + form).val();-->
<!--            var pwd = $(".login.pwd." + form).val();-->
<!--            if ($('#cookie_desk').prop("checked")) {var cookie = "setme";} else {var cookie = ""}-->
<!--            if (uname !== "" && pwd !== "") {-->
<!--                $.ajax ({-->
<!--                    type: 'post',-->
<!--                    url: 'user/login.php',-->
<!--                    data: {-->
<!--                        send: "Enter",-->
<!--                        login: uname,-->
<!--                        password: pwd,-->
<!--                        cookie: cookie-->
<!--                    },-->
<!--                    success: function(response) {-->
<!--                        if (response === "success") {-->
<!--                            var id = $(".u_post:last").attr("id");-->
<!--                            var idf = $(".u_post:first").attr("id");-->
<!--                            while (id <= idf) {-->
<!--                                $(".u_post#" + id).load(location.href + "updater.php?id=" + id);-->
<!--                                id++;-->
<!--                            }-->
<!--                            $("#upanel").load("user/content/user-panel.php");-->
<!--                            $("#mobile-menu-slider").load("user/content/user-panel-mobile.php");-->
<!--                        } else if (response === "confirmation") {-->
<!--                            alert("Please, verify your email");-->
<!--                        } else {-->
<!--                            alert("Check Your login credentials");-->
<!--                        }-->
<!--                    }-->
<!--                });-->
<!--            } else {-->
<!--                alert("You can't login without your name or your password");-->
<!--            }-->
<!--            return false;-->
<!--        }-->
<!--    </script>-->
<!--    <script>-->
<!--        function logMeOut() {-->
<!--            $.ajax ({-->
<!--                url: 'user/logout.php',-->
<!--                success: function(response) {-->
<!--                    if (response === "success") {-->
<!--                        var id = $(".u_post:last").attr("id");-->
<!--                        var idf = $(".u_post:first").attr("id");-->
<!--                        $("#upanel").load("user/content/login.php");-->
<!--                        $("#mobile-menu-slider").load("user/content/login-mobile.php");-->
<!--                        if (id) {-->
<!--                            while (id <= idf) {-->
<!--                                $(".u_post#" + id).load(location.href + "updater.php?id=" + id);-->
<!--                                id++;-->
<!--                            }-->
<!--                        } else {-->
<!--                            $(location).attr('href', "/");-->
<!--                        }-->
<!--                    }-->
<!--                }-->
<!--            });-->
<!--            return false;-->
<!--        }-->
<!--    </script>-->
<!--    <script>-->
<!--        function react() {-->
<!--            var poid = event.target.name;-->
<!--            var comtext = $(".u_new_comment." + poid).val();-->
<!--            var like = $("#like-btn").val();-->
<!--            if (poid !== "") {-->
<!--                $.ajax ({-->
<!--                    type: 'post',-->
<!--                    url: 'user/comment.php',-->
<!--                    data: {-->
<!--                        send: "Enter",-->
<!--                        photoid: poid,-->
<!--                        like: like,-->
<!--                        new_comment: comtext-->
<!--                    },-->
<!--                    success: function(response) {-->
<!--                        if (response === "success") {-->
<!--                            $(".u_post#" + poid).load(location.href + "updater.php?id=" + poid);-->
<!--                            $("#upanel").load("user/content/user-panel.php");-->
<!--                            $("#mobile-menu-slider").load("user/content/user-panel-mobile.php");-->
<!--//                            $("#post-data").load("/content/content.php");-->
<!--                        } else if (response === "loggedout") {-->
<!--                            alert("You need to be logged in to like and comment");-->
<!--                        } else {-->
<!--                            alert("Ooops, something's gone wrong...");-->
<!--                        }-->
<!--                    }-->
<!--                });-->
<!--            } else {-->
<!--                alert("Ooops, something's gone wrong...");-->
<!--            }-->
<!--            return false;-->
<!--        }-->
<!--    </script>-->
<!--    <script>-->
<!--        function delcom() {-->
<!--            var poid = event.target.id;-->
<!--            var phtid = event.target.name;-->
<!--            var comid = $(".comid." + poid).val();-->
<!--            if (poid !== "") {-->
<!--                if (confirm("Dou you really want to delete this comment?")) {-->
<!--                    $.ajax({-->
<!--                        type: 'post',-->
<!--                        url: 'user/comment.php',-->
<!--                        data: {-->
<!--                            photoid: poid,-->
<!--                            delete_comment: "delete_comment",-->
<!--                            commentid: comid-->
<!--                        },-->
<!--                        success: function (response) {-->
<!--                            if (response === "success") {-->
<!--                                $(".u_post#" + phtid).load(location.href + "updater.php?id=" + phtid);-->
<!--                            } else {-->
<!--                                alert("Ooops, something's gone wrong...");-->
<!--                            }-->
<!--                        }-->
<!--                    });-->
<!--                }-->
<!--            } else {-->
<!--                alert("Ooops, something's gone wrong...");-->
<!--            }-->
<!--            return false;-->
<!--        }-->
<!--    </script>-->
<!--    <script>-->
<!--        function like() {-->
<!--            var poid = event.target.title;-->
<!--            if (poid !== "") {-->
<!--                $.ajax ({-->
<!--                    type: 'post',-->
<!--                    url: 'user/comment.php',-->
<!--                    data: {-->
<!--                        send: "Enter",-->
<!--                        photoid: poid,-->
<!--                        like: "like"-->
<!--                    },-->
<!--                    success: function(response) {-->
<!--                        if (response === "success") {-->
<!--                            $(".u_post#" + poid).load(location.href + "updater.php?id=" + poid);-->
<!--                            $("#upanel").load("user/content/user-panel.php");-->
<!--                            $("#mobile-menu-slider").load("user/content/user-panel-mobile.php");-->
<!--//                            $("#post-data").load("/content/content.php");-->
<!--                        } else if (response === "loggedout") {-->
<!--                            alert("You need to be logged in to like and comment");-->
<!--                        } else {-->
<!--                            alert("Ooops, something's gone wrong...");-->
<!--                        }-->
<!--                    }-->
<!--                });-->
<!--            } else {-->
<!--                alert("Ooops, something's gone wrong...");-->
<!--            }-->
<!--            return false;-->
<!--        }-->
<!--    </script>-->
<!--    <script>-->
<!--        function registerMe() {-->
<!--            $("#upanel").load("register.php");-->
<!--            $("#mobile-menu-slider").load("register-mobile.php");-->
<!--            $('#post-data').fadeTo(500, 0.3);-->
<!--        }-->
<!--        function backToPanel() {-->
<!--            $("#upanel").load("user/content/login.php");-->
<!--            $("#mobile-menu-slider").load("user/content/login-mobile.php");-->
<!--            $('#post-data').fadeTo(500, 1.0);-->
<!--        }-->
<!--        function unfade() {-->
<!--            $('#post-data').fadeTo(500, 1.0);-->
<!--        }-->
<!--        function newPostPanel() {-->
<!--            $("#upanel").load("user/content/login.php");-->
<!--            $("#mobile-menu-slider").load("user/content/login-mobile.php");-->
<!--            $('#post-data').fadeTo(500, 1.0);-->
<!--        }-->
<!--        function managePosts() {-->
<!--            $("#upanel").load("manage-posts.php");-->
<!--            $("#mobile-menu-slider").load("manage-posts-mobile.php");-->
<!--        }-->
<!--        function backToUserPanel() {-->
<!--            $("#upanel").load("user/content/user-panel.php");-->
<!--            $("#mobile-menu-slider").load("user/content/user-panel-mobile.php");-->
<!--        }-->
<!--        function gallery() {-->
<!--            $("#post-data").load("/content/content.php");-->
<!--        }-->
<!--    </script>-->
<!--    <script>-->
<!--        function registerMeSubmit() {-->
<!--            var form = event.target.name;-->
<!--            var login = $("#register-login." + form).val();-->
<!--            var pwd  = $("#register-pwd." + form).val();-->
<!--            var pwd2  = $("#register-pwd-conf." + form).val();-->
<!--            var name = $("#register-first." + form).val();-->
<!--            var surname = $("#register-last." + form).val();-->
<!--            var email = $("#register-email." + form).val();-->
<!--            alert(login + pwd + pwd2 + name + surname + email);-->
<!--            $.ajax ({-->
<!--                type: 'post',-->
<!--                url: 'user/register.php',-->
<!--                data: {-->
<!--                    send: "Submit",-->
<!--                    login: login,-->
<!--                    password: pwd,-->
<!--                    repeat: pwd2,-->
<!--                    first: name,-->
<!--                    last: surname,-->
<!--                    email: email-->
<!--                },-->
<!--                success: function(response) {-->
<!--                    if (response === "success") {-->
<!--                        $("#upanel").load("user/regsuccess.php");-->
<!--                        $("#mobile-menu-slider").load("user/regsuccess.php");-->
<!--                    } else if (response === "nomatch") {-->
<!--                        alert("Please check the information you provided");-->
<!--                    } else {-->
<!--                        alert("Ooops, something's gone wrong... Probably the login you chose is alredy taken");-->
<!--                    }-->
<!--                }-->
<!--            });-->
<!--            return false;-->
<!--        }-->
<!--    </script>-->
<!--    <script>-->
<!--        function previewAvFunc(image) {-->
<!--            if (image.files && image.files[0]) {-->
<!--                var view = new FileReader();-->
<!--                view.onload = function(e) {-->
<!--                    $('#previewAv').attr('src', e.target.result);-->
<!--                };-->
<!--                view.readAsDataURL(image.files[0]);-->
<!--            }-->
<!--        }-->
<!--        function previewPhFunc(image) {-->
<!--            if (image.files && image.files[0]) {-->
<!--                var view = new FileReader();-->
<!--                view.onload = function(e) {-->
<!--                    $('#previewPh').attr('src', e.target.result);-->
<!--                };-->
<!--                view.readAsDataURL(image.files[0]);-->
<!--            }-->
<!--        }-->
<!--    </script>-->
<!--    <script>-->
<!--        function delPhoto(item) {-->
<!--              if (confirm("Dou you really want to delete this picture?")) {-->
<!--                $.ajax({-->
<!--                    type: 'post',-->
<!--                    url: 'user/delphoto.php',-->
<!--                    data: {-->
<!--                        photoid: item.id,-->
<!--                        send: "Delete"-->
<!--                    },-->
<!--                    success: function (response) {-->
<!--                        if (response === "success") {-->
<!--                            $("#post-data").load("/content/content.php");-->
<!--                            $("#upanel").load("manage-posts.php");-->
<!--                            $("#mobile-menu-slider").load("manage-posts-mobile.php");-->
<!--                        }-->
<!--                        else {-->
<!--                            alert(response);-->
<!--                        }-->
<!--                    }-->
<!--                });-->
<!--            }-->
<!--            return false;-->
<!--        }-->
<!--    </script>-->
</body>
</html>
