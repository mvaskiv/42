<?php
    session_start();
    require_once("utilities/db_config.php");
?>
<div class="content" style="margin-top: 30px;margin-left:0px">
    <div id="register_form" style="height: auto;">
        <a href="/?page=live" class="mobhide"><span id="liveMode"><i class="fas fa-camera"></i> Live</span></a>
        <h1 class="blue_text" style="position: relative;top:20px;margin-left:-105px;">Choose a picture for your post</h1>
        <form method="POST" action="user/upload.php" enctype="multipart/form-data" id="upload-form">
            <img alt="" id="previewPh" src="img/img-placeholder.svg"><br>
            <input type="file" id="file-selection" class="custom-file-input2" name="photo" onchange="previewPhFunc(this);" required><br><br>
            <input type="submit" id="bigassbutton" name="submit" value="Upload" style="margin-top:-10px;margin-bottom: 60px;">
        </form>
    </div>
</div>
