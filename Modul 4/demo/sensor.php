<?php
    $servername = 'localhost';
    $username = 'root';
    $password = '';
    $dbname = 'pirdas4';

    $koneksi = mysqli_connect($servername, $username, $password, $dbname);

    if (!$koneksi) {
        die('Koneksi Gagal: ' . mysqli_connect_error());
    }

    if (isset($_GET['angka_sumbuX']) && isset($_GET['angka_sumbuY']) && isset($_GET['kemiringan'])) {
        $angka_sumbuX = $_GET['angka_sumbuX'];
        $angka_sumbuY = $_GET['angka_sumbuY'];
        $kemiringan = $_GET['kemiringan'];

        $sql = "INSERT INTO data_sensor (angka_sumbuX, angka_sumbuY, kemiringan) VALUES ('$angka_sumbuX', '$angka_sumbuY', '$kemiringan')";

        if ($koneksi->query($sql) === TRUE) {
            echo 'DATA BERHASIL DISIMPAN KE DATABASE';
        } else {
            echo 'ERROR: ' . $sql . '<br>' . $koneksi->error;
        }
    }

    $koneksi->close();
    exit();
?>
