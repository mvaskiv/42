<?php
session_start();
if (isset($_SESSION['auth_data'])) { ?>
    <div id="register_form" style="height: 480px;">
        <form name="desk" method="post" class="mobhide" style="position:relative;top:20px;"
              action="user/edit_profile.php" onsubmit="return editMeSubmit();">
            <span onclick="return backToUserPanel();" id="back-to-panel"><i class="fas fa-arrow-left"></i></span>
            <span id="login_d">Edit your profile</span><br><br>
            <span id="blue_text">Choose a new nikname</span><br>
            <input class="register_input desk" type="text" placeholder="Login" name="login" id="edit-login"
                   minlength="3" maxlength="32" pattern="[a-zA-Z0-9]+"><br><br>
            <span id="blue_text">Type your new password twice</span><br>
            <input class="register_input desk" type="password" placeholder="Password" name="password" id="edit-pwd"
                   minlength="3" maxlength="32" pattern="^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?!.*\s).*$"><br>
            <input class="register_input desk" type="password" placeholder="Repeat it" name="repeat" id="edit-pwd-conf"
                   minlength="3" maxlength="32" pattern="^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?!.*\s).*$"><br><br>
            <span id="blue_text">Change your email here</span><br>
            <input class="register_input desk" type="email" placeholder="Email" name="email" id="edit-email"><br><br>
            <input id="bigassbutton" type="submit" value="Submit" name="send">
        </form>
    </div>
    <?php
}
?>