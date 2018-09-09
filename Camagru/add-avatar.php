<?php
session_start();
if (isset($_SESSION['auth_data'])) { ?>
    <div class="content" style="margin-top: 30px;margin-left:0px">
        <div id="register_form">
            <br>
            <h1 class="blue_text">Choose your profile picture</h1>
            <form method="POST" action="user/add-avatar.php" enctype="multipart/form-data" id="add-avatar-form">
                <img alt="" id="previewAv" src="img/img-placeholder.svg"><br>
                <input type="file" accept="image/*" id="file-selection" name="avatar" class="custom-file-input"
                       onchange="previewAvFunc(this);" required><br>
                <input type="submit" id="bigassbutton mobu" class="mobu" name="submit" value="Upload">
            </form>
        </div>
    </div>
    <?php
}
?>