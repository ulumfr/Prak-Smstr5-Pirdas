<?php
    include "koneksi.php";

    $sql = mysqli_query($koneksi, "SELECT * from tb_sensor ORDER BY id DESC");

    $data1 = mysqli_fetch_array($sql);
    $sensor = $data1['sensor'];

    if($sensor == "") $sensor = 0;

    echo $sensor;
?>