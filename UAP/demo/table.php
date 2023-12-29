<table class="my-3 table table-bordered table-danger border-dark text-center">
    <thead>
        <tr>
            <th scope="col" class="text-center">ID</th>
            <th scope="col" class="text-center">Waktu</th>
            <th scope="col" class="text-center">Kelembaban </th>
            <th scope="col" class="text-center">Kondisi</th>
        </tr>
    </thead>
    <?php
    include "koneksi.php";

    $cari = $_POST['cari'] ?? '';

    $sql = "SELECT * FROM dbtanah WHERE kondisi LIKE '%$cari%'";
    $result = $koneksi->query($sql);

    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo "<tr><td>" . $row["id"] . "</td><td>" . $row["waktu"] . "</td><td>" . $row["kelembaban"] . "</td><td>" . $row["kondisi"] . "</td></tr>";
        }
    } else {
        echo "<tr><td colspan='4'>No results found</td></tr>";
    }
    ?>
</table>