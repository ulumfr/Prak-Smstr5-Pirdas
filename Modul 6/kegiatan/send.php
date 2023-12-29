<?php
    include "koneksi.php";

    $sensor = $_GET['sensor'];

    mysqli_query($koneksi, "ALTER TABLE tb_sensor AUTO_INCREMENT=1");
    $simpan = mysqli_query($koneksi, "INSERT INTO tb_sensor (sensor) values ('$sensor')");

    if($simpan) {
        echo "Berhasil dikirim";
    }else {
        echo "Gagal dikirim";
    }
?>