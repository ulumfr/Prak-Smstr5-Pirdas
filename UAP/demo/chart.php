<?php
include 'koneksi.php';

$waktuArray = [];
$kelembabanArray = [];

$sql = "SELECT waktu, kelembaban FROM dbtanah ORDER BY id DESC LIMIT 10";
$result = $koneksi->query($sql);

if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $waktuArray[] = $row['waktu']; 
        $kelembabanArray[] = $row['kelembaban'];
    }
}

$waktuArray = array_reverse($waktuArray);
$kelembabanArray = array_reverse($kelembabanArray);

echo json_encode([$waktuArray, $kelembabanArray]);
?>
