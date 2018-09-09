<?php
session_start();
require_once("utilities/db_config.php");
if (isset($_SESSION['auth_data'])) {
    ?>
    <div id="register_form" style="height: 715px;margin-top:30px;">
        <a href="/?page=new"><span id="liveMode" style="color:#c23;"><i class="fas fa-camera"></i> Live</span></a>
        <h1 class="blue_text" style="position: relative;top:20px;margin-left:-105px;z-index:9">Choose a picture for your
            post</h1>
        <div id="previewVidCnt" style="margin-top: -20px;">
            <div class="vidprevabs">
                <form method="POST" action="user/upload64.php" enctype="multipart/form-data" id="upload-form">
                    <video class="previewVid" id="previewVid"></video>
                    <br><br>
                    <img alt="" class="ph vidprevabs cropprev" style="position: absolute;top: -40px;left:0;right:0"
                         src="">
                    <img alt="" class="pr vidprevabs cropprev" style="position: absolute;top: -40px;left:0;right:0"
                         src="">
                    <input id="snapupload" type="text" name="photo" style="display: none;" required>

                    <input type="submit" id="bigassbutton" name="submit" value="Upload"
                           style="margin-top:60px;margin-bottom: 60px;">
                    <br>
                    <input type="radio" name="gender" class="gender" id="fr1"
                        <?php if (isset($gender) && $gender=="female") echo "checked";?>
                           value="female">Female
                    <input type="radio" name="gender" class="gender" id="fr2"
                        <?php if (isset($gender) && $gender=="male") echo "checked";?>
                           value="male">Male
                    <input type="radio" name="gender" class="gender" id="fr3"
                        <?php if (isset($gender) && $gender=="other") echo "checked";?>
                           value="other">Other
                    <input type="radio" name="gender" class="gender" id="fr4"
                        <?php if (isset($gender) && $gender=="other") echo "checked";?>
                           value="other">Off
                </form>
            </div>
            <canvas style="display: none;" class='vidprevabs'></canvas>
            <button value="Snap" class="snap-btn" onclick="snapQ();">Snap</button>
            <button value="Snap" class="snap-del-btn" onclick="delsnapQ();"><i
                        style="font-size: 15px;margin-top:5px;margin-left:2px;" class="fas fa-trash trash"></i></button>
        </div>
    </div>
    <script>
      $("input.gender").on("click", function () {
         if (this.id === "fr4") {$("img.pr").attr("src", "");}
         else {$("img.pr").attr("src", "/img/overlays/" + this.id + ".png");}
      })
    </script>
    <script src="js/liveview.js"></script>
    <script src="js/snap.js"></script>
    <?php
}
?>