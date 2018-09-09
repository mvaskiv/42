<?php
    session_start();
    if (file_exists("../../utilities/db_config.php")) {require_once("../../utilities/db_config.php");}
    else {require_once("utilities/db_config.php");}
?>
<div id="user-panel-mobile">
    <img id="user-avatar" src=<?php
        $user = $_SESSION["auth_data"]["user"];
        $user_id = mysqli_fetch_row(send_db_request("SELECT id FROM users WHERE login = '$user'"));
        if (empty(mysqli_fetch_row(send_db_request("SELECT image FROM avatars WHERE user = '" . $user_id[0] . "'")))) {
            $img = "empty.png";
            $path = '"user/avatars/' . $img . '"';
        } else {
            $img = mysqli_fetch_row(send_db_request("SELECT image FROM avatars WHERE user = '" . $user_id[0] . "'"));
            $path = '"user/avatars/' . $img[0] . '"';
        }
        echo $path;
    ?>>
    <p class="info likes">Likes</p>
    <p class="counter likes"><?php
        $user = $_SESSION["auth_data"]["user"];
        $user_id = mysqli_fetch_row(send_db_request("SELECT id FROM users WHERE login = '$user'"));
        $dbq = $dbh->prepare("SELECT likes FROM img WHERE user = '" . $user_id[0] . "'");
        $dbq->execute();
        $i = $dbq->fetchAll();
        //        $i = mysqli_fetch_all(send_db_request("SELECT likes FROM img WHERE user = '" . $user_id[0] . "'"));
        $q = 0;
        if (isset($i)) {
            foreach ($i as $like) {
                $q += $like[0];
            }
        }
        echo $q;
        ?></p>
    <p class="info posts">Posts</p>
    <p class="counter posts"><?php
        $user = $_SESSION["auth_data"]["user"];
        $user_id = mysqli_fetch_row(send_db_request("SELECT id FROM users WHERE login = '$user'"));
        $dbq = $dbh->prepare("SELECT id FROM img WHERE user = '" . $user_id[0] . "'");
        $dbq->execute();
        $p = $dbq->fetchAll();
        //        $p = mysqli_fetch_all(send_db_request("SELECT id FROM img WHERE user = '" . $user_id[0] . "'"));
        $q = 0;
        if (isset($p)) {
            foreach ($p as $post) {
                $q++;
            }
        }
        echo $q;
        ?></p>
    <div class="panel-menu">
        <a onclick="return gallery();"><p class="menu">Gallery</p></a>
        <hr class="panel">
        <a href="?page=new"><p class="menu">+ Create a New Post</p></a>
        <hr class="panel">
        <a onclick="return managePostsMob();"><p class="menu">Manage Your Posts</p></a>
        <hr class="panel">
        <a href="?page=avatar"><p class="menu">Change Your Profile Picture</p></a>
        <hr class="panel">
        <a onclick="return editProfile();"><p class="menu">Edit Your Profile</p></a>
        <hr class="panel">
    </div>
    <a onclick="return logMeOut();"><p class="logout" id="logout_d">Log out</p></a>
</div>