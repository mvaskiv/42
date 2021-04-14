<!--<div class="content">-->
    <div id="register_form" style="height: 640px;">
        <form name="desk" method="post" style="position:relative;top:20px;" action="user/register.php" onsubmit="return registerMeSubmit();">
            <span onclick="return backToPanel();" class="mobhide" id="back-to-panel"><i class="fas fa-arrow-left"></i></span>
            <span id="login_d">Register</span><br><br>
            <span id="blue_text">Choose your nikname</span><br>
            <input class="register_input desk" type="text" placeholder="Login" name="login" id="register-login" minlength="3" maxlength="32" pattern="[a-zA-Z0-9]+" required><br><br>
            <span id="blue_text">Type your password twice</span><br>
            <input class="register_input desk" type="password" placeholder="Password" name="password" id="register-pwd" minlength="3" maxlength="32" pattern="^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?!.*\s).*$" required><br>
            <input class="register_input desk" type="password" placeholder="Repeat it" name="repeat" id="register-pwd-conf" minlength="3" maxlength="32" pattern="^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?!.*\s).*$" required><br><br>
            <p class="footer" style="margin-top:-20px;"><br>*Use one of each: upper, lower case letter & digit</p>
            <span id="blue_text">Your full name here</span><br>
            <input class="register_small_input desk" type="text" placeholder="First name" name="first" id="register-first" minlength="3" maxlength="32" pattern="[a-ZA-Z]+" required>
            <input class="register_small_input desk" type="text" placeholder="Last name" name="last" id="register-last" minlength="3" maxlength="32" pattern="[a-ZA-Z]+" required><br><br>
            <span id="blue_text">And your email here</span><br>
            <input class="register_input desk" type="email" placeholder="Email" name="email" id="register-email" minlength="5" maxlength="32" required><br><br>
            <input id="bigassbutton" type="submit" value="Submit" name="send">
        </form>
    </div>
<!--</div>-->

