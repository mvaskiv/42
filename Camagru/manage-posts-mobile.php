<div id="register_form" style="overflow-y: scroll;overflow-x: hidden;"><br>
    <span onclick="return backToUserPanel();" id="back-to-panel"><i class="fas fa-arrow-left"></i> Back to panel</span>
    <br><br>
    <?php
    session_start();
    if (file_exists("../utilities/db_config.php")) {require_once("../utilities/db_config.php");}
    else {require_once("utilities/db_config.php");}
    ?>
    <?php
    $user = $_SESSION["auth_data"]["user"];
    $user_id = mysqli_fetch_row(send_db_request("SELECT id FROM users WHERE login = '$user'"));
    $dbq = $dbh->prepare("SELECT * FROM img WHERE user = '" . $user_id[0] . "' ORDER BY id DESC");
    $dbq->execute();
    $i = $dbq->fetchAll();
    foreach ($i as $photo) {
        ?>
        <div class="img-manager">
            <img alt="" class="photo-thumbs" src="user_posts/<?php echo $photo[1]; ?>">
            <div class="img-del-over" id="toDel<?php echo $photo[0];?>" onclick="return delPhoto(this);"><i class="fas fa-trash trash"></i></div>
        </div>
        <?php
    }
    ?>
</div>
