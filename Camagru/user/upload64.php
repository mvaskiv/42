<?php
    session_start();
    require_once("../utilities/db_config.php");

    if (isset($_POST['submit'])) {
        $data = $_POST['photo'];
        $arr = explode(',', $data);
        $s1 = base64_decode($arr[1]);

        if ($_POST['gender'] === "male") {$over_name = "fr2.png";}
        else if ($_POST['gender'] === "female") {$over_name = "fr1.png";}
        else if ($_POST['gender'] === "other") {$over_name = "fr3.png";}
        else {$over_name = "empty.png";}

        $overlay = imagecreatefrompng('../img/overlays/' . $over_name);
        $rand = rand(0, 99999);
        while (file_exists("../user_posts/" . $rand . ".png")) {$rand = rand(0, 99999);}
        $fd = fopen("../user_posts/" . $rand . ".png", 'w+') or die("Unable to open file!");
        fwrite($fd, $s1);
        fclose($fd);
        $im = imagecreatefrompng("../user_posts/". $rand . ".png");
        $sx = imagesx($overlay);
        $sy = imagesy($overlay);
        $mright = 0;
        $mbottom = 0;
        imagecopy($im, $overlay, imagesx($im) - $sx - $mright, imagesy($im) - $sy - $mbottom, 0, 0, imagesx($overlay), imagesy($overlay));
        header('Content-type: image/png');
        imagepng($im, "../user_posts/" . $rand . ".png");
        imagedestroy($im);

        $image = $rand . '.png';
        $user = $_SESSION["auth_data"]["user"];
        $user_id = mysqli_fetch_row(send_db_request("SELECT id FROM users WHERE login = '$user'"));
        $sql = "INSERT INTO img (photo, user, added) VALUES ('$image', '" . $user_id[0] . "', NOW())";
        if (send_db_request($sql) && file_exists("../user_posts/" . $image)) {
            header("Location: /");
        } else {
            echo "Ooops, something's gone wrong... <a href='/'> Press to return to the homepage</a>";
    }
}
