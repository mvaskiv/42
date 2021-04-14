function registerMe() {
    $("#upanel").load("register.php");
    $("#mobile-menu-slider").load("register-mobile.php");
    $('#post-data').fadeTo(500, 0.3);
}
function backToPanel() {
    $("#upanel").load("user/content/login.php");
    $("#mobile-menu-slider").load("user/content/login-mobile.php");
    $('#post-data').fadeTo(500, 1.0);
}
function unfade() {
    $('#post-data').fadeTo(500, 1.0);
}
function newPostPanel() {
    $("#upanel").load("user/content/login.php");
    $("#mobile-menu-slider").load("user/content/login-mobile.php");
    $('#post-data').fadeTo(500, 1.0);
}
function managePosts() {
    $("#upanel").load("manage-posts.php");
}
function managePostsMob() {
    $("#mobile-menu-slider").load("manage-posts-mobile.php");
}
function editProfile() {
    $("#upanel").load("edit_profile.php");
    $("#mobile-menu-slider").load("edit_profile-mobile.php");
}
function backToUserPanel() {
    $("#upanel").load("user/content/user-panel.php");
    $("#mobile-menu-slider").load("user/content/user-panel-mobile.php");
}
function gallery() {
    $("#post-data").load("/content/content.php");
    revealMenu();
}
function LiveOn() {
    $("#post-data").load("upload_live.php");
}