<?php
include "koneksi.php";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST["kelembaban"]) && isset($_POST["kondisi"])) {
        $kelembaban = $_POST["kelembaban"];
        $kondisi = $_POST["kondisi"];

        if ($kelembaban !== null && $kondisi !== null) {
            $stmt = $koneksi->prepare("INSERT INTO dbtanah (kelembaban, kondisi) VALUES (?, ?)");
            $stmt->bind_param("is", $kelembaban, $kondisi);

            try {
                $stmt->execute();
                echo "Data inserted successfully";
            } catch (mysqli_sql_exception $e) {
                echo "Error: " . $e->getMessage();
            }

            $stmt->close();
        } else {
            echo "Invalid data received";
        }
    } else {
        echo "Invalid POST data";
    }
}

$koneksi->close();
