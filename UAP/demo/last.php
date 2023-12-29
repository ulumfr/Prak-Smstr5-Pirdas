<div class="card my-3 border border-dark" style="background-color: #F8D7DA;">
    <h5 class="card-header text-center border-dark">Informasi Data Terakhir</h5>
    <div class="card-body text-center">
        <?php
        include "koneksi.php";

        $sql = "SELECT * FROM dbtanah ORDER BY id DESC LIMIT 1";
        $result = $koneksi->query($sql);

        if ($result->num_rows > 0) {
            $row = $result->fetch_assoc();
            echo "<div class='d-md-flex justify-content-md-between'>";
            echo "<div class='mb-3 mb-md-0'>";
            echo "<h5>Waktu: " . $row["waktu"] . "</h5>";
            echo "</div>";
            echo "<div class='mb-3 mb-md-0'>";
            echo "<h5>Kelembaban: " . $row["kelembaban"] . "</h5>";
            echo "</div>";
            echo "<div>";
            echo "<h5>Kondisi: " . $row["kondisi"] . "</h5>";
            echo "</div>";
            echo "</div>";
        } else {
            echo "<p>No data available</p>";
        }
        $koneksi->close();
        ?>
    </div>
</div>