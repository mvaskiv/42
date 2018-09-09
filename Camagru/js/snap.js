function snapQ() {
    var draft = document.querySelector('canvas'),
        input = document.querySelector('video.previewVid'),
        img = document.querySelector('img.ph'),

        w = 640,
        h = 480,
        c = draft.getContext('2d');
    draft.width = 480;
    draft.height = h;
    c.drawImage(input, -80, 0, w, h);
    var idataURL = draft.toDataURL('image/png');
    img.setAttribute('src', idataURL);
    document.getElementById('snapupload').setAttribute('value', idataURL);
    input.style.opacity = '0';
    img.style.opacity = '0';
    setTimeout(function() {
        img.style.opacity = '1';
    }, 500);
}
function delsnapQ() {
    var img = document.querySelector('img.ph');
    img.setAttribute('src', "");
    document.querySelector('video.previewVid').style.opacity = '1';

}