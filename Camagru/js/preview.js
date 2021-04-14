function previewAvFunc(image) {
    if (image.files && image.files[0]) {
        var view = new FileReader();
        view.onload = function(e) {
            $('#previewAv').attr('src', e.target.result);
        };
        view.readAsDataURL(image.files[0]);
    }
}
function previewPhFunc(image) {
    if (image.files && image.files[0]) {
        var view = new FileReader();
        view.onload = function(e) {
            $('#previewPh').attr('src', e.target.result);
        };
        view.readAsDataURL(image.files[0]);
    }
}