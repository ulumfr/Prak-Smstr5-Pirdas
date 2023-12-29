<table class="my-3 table table-bordered table-danger border-dark text-center">
    <thead>
        <tr>
            <th scope="col" class="text-center">ID</th>
            <th scope="col" class="text-center">Angle X</th>
            <th scope="col" class="text-center">Angle Y</th>
            <th scope="col" class="text-center">Status Sensor</th>
        </tr>
    </thead>
    <?php
    include "koneksi.php";

    $cari = $_POST['cari'] ?? '';

    $sql = "SELECT * FROM dbsensor WHERE status_sensor LIKE '%$cari%'";
    $result = $koneksi->query($sql);

    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo "<tr><td>" . $row["id"] . "</td><td>" . $row["angleX"] . "</td><td>" . $row["angleY"] . "</td><td>" . $row["status_sensor"] . "</td></tr>";
        }
    } else {
        echo "<tr><td colspan='4'>No results found</td></tr>";
    }
    ?>
</table>