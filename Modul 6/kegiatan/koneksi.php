<?php
    $host = 'localhost';
    $username  = 'root';
    $password = ''; 
    $db = 'pirdas6';

    $koneksi = mysqli_connect($host, $username, $password, $db);

    if (!$koneksi) {
        echo "Gagal melakukan koneksi ke MYSQL: " . mysqli_connect_error();
        exit();
    }
?>