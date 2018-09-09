<?php
if (file_exists("../utilities/db_config.php")) {require_once("../utilities/db_config.php");}
else {require_once("utilities/db_config.php");}
session_start();
while ($post = $result->fetch_assoc()) {
    $user = mysqli_fetch_row(send_db_request("SELECT login FROM users WHERE id = '" . $post['user'] . "';"));
    ?>
    <div class="id u_post" id="<?php echo $post['id']; ?>">
        <div id="u_post_owner">
            <i id="user_icon_l" class="fas fa-user-circle"></i>
            <span id="u_name_l"><?php echo $user[0]; ?></span>
            <span id="u_post_time"><i class="far fa-clock"></i>&nbsp;<?php echo $post['added']; ?>&nbsp;</span>
        </div>
        <div title="<?php echo $post['id']; ?>" id="u_content" ondblclick="return like();" style="background: url('user_posts/<?php echo $post["photo"]?>') center no-repeat;background-size:cover;">
        </div>
        <div id="likes-counter">
            <?php
            $user = $_SESSION["auth_data"]["user"];
            $dbq = $dbh->prepare("SELECT likes FROM img WHERE id = '" . $post['id'] . "'");
            $dbq->execute();
            $q = $dbq->fetchColumn();
            if ($q > 0) {echo '<i class="fa fa-heart" id="sml-like-icon"></i>';}
            ?>
            <p class="like-count"><?php

                if ($q == 0) {echo "<span style='color:#696969'>be the first to like</span>";}
                else if ($q == 1) {echo $q . " like";}
                else {echo $q . " likes";}
                ?></p>
        </div>
        <div id="u_comments">
            <?php
            $dbq = $dbh->prepare("SELECT id FROM users WHERE login = '" . $_SESSION['auth_data']['user'] . "'");
            $dbq->execute();
            $user_id = $dbq->fetchColumn();

            $dbq = $dbh->prepare("SELECT * FROM comments WHERE photo = '" . $post['id'] . "'");
            $dbq->execute();
            $com = $dbq->fetchAll();
            //                    $com = mysqli_fetch_all(send_db_request("SELECT * FROM comments WHERE photo = '" . $post['id'] . "'"));
            $i = 0;
            while($com[$i]) {
                $dbq = $dbh->prepare("SELECT login FROM users WHERE id = '" . $com[$i][2] . "'");
                $dbq->execute();
                $poster = $dbq->fetchColumn();
                echo '<div id="u_posted_comment">';
                echo '<i id="user_icon" class="fas fa-user-circle"></i>';
                echo '<span id="u_name">' . $poster . '</span>';
                echo '<span id="u_comment_text">' . $com[$i][3] . '</span>';
                if (isset($_SESSION['auth_data']["user"]) && !(empty(mysqli_fetch_row(send_db_request("SELECT id FROM comments WHERE user = '$user_id' AND id = '" . $com[$i][0] . "' AND photo = '" . $post['id'] . "'"))))) {
                    echo '<form name="' . $post['id'] . '" id="' . $com[$i][0] . '" action="user/comment.php" method="post" onsubmit="return delcom();"><input style="display: none;" name="photo-id" type="text" value="' . $post['id'] . '"><input class="comid ' . $com[$i][0] . '" style="display: none;" name="commentid" type="text" value="' . $com[$i][0] . '"><button name="delete_comment" id="delete_icon"><i class="fa fa-ban" aria-hidden="true"></i></button></form>';
                }
                echo '</div>';
                $i++;
            }
            ?>
        </div>
        <?php if (isset($_SESSION['auth_data'])) { ?>
            <div class="comment-like">
                <form name="<?php echo $post['id']?>" action="user/comment.php" method="post" id="comment-form" onsubmit="return react();">
                        <span onclick="return like();" class="comment-button" style="margin-left: 1px;" name="like" id="like-btn" title="<?php echo $post['id']?>"><?php
                            $user = $_SESSION['auth_data']["user"];
                            $photoid = $post['id'];
                            $user_id = mysqli_fetch_row(send_db_request("SELECT id FROM users WHERE login = '$user'"));
                            echo "<i title='" . $post['id'] . "' id='like_icon' ";
                            if (!(empty(mysqli_fetch_row(send_db_request("SELECT id FROM likes WHERE user = '" . $user_id[0] . "' AND photo = '$photoid'"))))) {
                                echo "class='fa fa-heart' style='color:red'>";
                            } else {echo "class='far fa-heart'>";}
                            echo "</i>";
                            ?></span>
                    <input type="text" class="u_new_comment <?php echo $post['id']?>" name="new_comment" placeholder="Express your disgust here" id="disgust">
                    <input style="display: none;" name="photoid" type="text" value="<?php echo $post['id']?>" id="photoid">
                    <button class="comment-button" type="submit" name="send" value="Enter"><i id='comment_submit_icon' class='fab fa-stack-exchange'></i></button>
                </form>
            </div>
        <?php } ?>
    </div>
    <?php
}
?>