<?php
    session_start();
    if (file_exists("../../utilities/db_config.php")) {require_once("../../utilities/db_config.php");}
    else {require_once("utilities/db_config.php");}
?>
<div id="user-panel">
    <form name="dsk" method="post" class="side-login-form" action="/user/login.php" onsubmit="return logMeIn();">
        <span id="login_d">Log in</span>
        <input class="login lgn dsk" type="text" placeholder="Login" name="login" id="login_name">
        <input class="login pwd dsk" type="password" placeholder="Password" name="password" id="login_pwd"><br>
        <p class="footer"><input name="cookie" id="cookie_desk" type="checkbox" checked>Remember Me</p>
        <input id="side-login-button" type="submit" value="Enter" name="send">
    </form>
    <div class="side-login-form">
        <span id="login_d">- OR -</span><br><br>
        <input id="side-register-button" type="submit" onclick="return registerMe();" value="Register">
    </div>
</div>
