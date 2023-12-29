<?php
    $servername = 'localhost';
    $username  = 'root';
    $password = ''; 
    $dbname = 'pirdas4';
    
    $koneksi = mysqli_connect($servername, $username, $password, $dbname);

    if (!$koneksi) {
        die('Koneksi Gagal: ' . mysqli_connect_error());
    }

    if($_GET['ldr_value'])
        $ldr_value = $_GET['ldr_value'];

    $sql = "INSERT INTO data_cahaya (ldr_value) VALUES ('.$ldr_value.')";

    if ($koneksi->query($sql)===TRUE) {
        echo 'DATA LDR VALUE BERHASIL DITAMBAH';
    } else {
        echo 'ERROR: ' . $sql . '<br>' . $koneksi->error;
    }

    $koneksi->close();
    exit();
?>