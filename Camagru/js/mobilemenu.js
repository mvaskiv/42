var i = 0;
function revealMenu() {
    if (i === 0) {
        document.getElementById('mobile-menu-slider').style.left = "0";
        i++;
    } else if (i === 1) {
        document.getElementById('mobile-menu-slider').style.left = "100%";
        i--;
    }
}