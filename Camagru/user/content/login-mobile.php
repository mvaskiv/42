<?php
    session_start();
    if (file_exists("../../utilities/db_config.php")) {require_once("../../utilities/db_config.php");}
    else {require_once("utilities/db_config.php");}
?>
<div id="user-login-mobile">
    <form name="mob" method="post" class="side-login-form" action="/user/login.php" onsubmit="return logMeIn();">
        <span id="login_d">Log in</span>
        <input class="login lgn mob" type="text" placeholder="Login" name="login" id="login_name">
        <input class="login pwd mob" type="password" placeholder="Password" name="password" id="login_pwd" style="margin-top:30px;">
        <input id="side-login-button" type="submit" value="Enter" name="send">
    </form>
    <div class="side-login-form">
        <span id="login_d">- OR -</span><br><br>
        <input id="side-register-button" type="submit" value="Register" onclick="return registerMe();">
    </div>
</div>