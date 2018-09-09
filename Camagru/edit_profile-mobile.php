<div class="register-mobile-bg" style="height: 830px;">
<div id="register_form" style="height: 740px;">
    <form name="mobi" method="post" style="position:relative;top:20px;" action="user/edit_profile.php" onsubmit="return editMeSubmit();">
        <span id="login_d">Edit your profile</span><br><br>
        <span id="blue_text">Choose a new nikname</span><br>
        <input class="register_input mobi" type="text" placeholder="Login" name="login" id="edit-login" minlength="3" maxlength="32" pattern="[a-zA-Z0-9]+"><br><br>
        <br><span id="blue_text">Type your new password twice</span><br>
        <input class="register_input mobi" type="password" placeholder="Password" name="password" id="edit-pwd" minlength="3" maxlength="32" pattern="^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?!.*\s).*$"><br>
        <input class="register_input mobi" type="password" placeholder="Repeat it" name="repeat" id="edit-pwd-conf" minlength="3" maxlength="32" pattern="^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?!.*\s).*$"><br><br>
        <br><span id="blue_text">Change your email here</span><br>
        <input class="register_input mobi" type="email" placeholder="Email" name="email" id="edit-email"><br><br>
        <input id="bigassbutton" style="background-color: #00cc44;" type="submit" value="Submit" name="send">
    </form><br>
        <input class="bigbutton" type="submit" value="Return" name="send" onclick="return backToUserPanel()">
</div>
</div>



