<?php
include "koneksi.php";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST["angleX"]) && isset($_POST["angleY"]) && isset($_POST["status_sensor"])) {
        $angleX = $_POST["angleX"];
        $angleY = $_POST["angleY"];
        $status_sensor = $_POST["status_sensor"];

        if ($angleX !== null && $angleY !== null && $status_sensor !== null) {
            $stmt = $koneksi->prepare("INSERT INTO dbsensor (angleX, angleY, status_sensor) VALUES (?, ?, ?)");
            $stmt->bind_param("dds", $angleX, $angleY, $status_sensor);

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
