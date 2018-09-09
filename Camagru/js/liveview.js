window.addEventListener("load", function() {
    var c = document.getElementById('previewVid');
    var s = {audio: false, video: true};

    function success(input) {
        c.src = URL.createObjectURL(input);
        c.play();
    }

    function fail() {
        alert("Ooops, something's gone wrong...");
    }

    if (navigator.getUserMedia) {
        navigator.getUserMedia(s, success, fail);
    }
}, false);