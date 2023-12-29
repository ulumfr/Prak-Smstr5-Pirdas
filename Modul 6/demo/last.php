<div class="card my-3 border border-dark" style="background-color: #F8D7DA;">
    <div class="card-body text-center">
        <?php
        include "koneksi.php";

        $sql = "SELECT * FROM dbsensor ORDER BY id DESC LIMIT 1";
        $result = $koneksi->query($sql);

        if ($result->num_rows > 0) {
            $row = $result->fetch_assoc();
            echo "<div style='display: flex; justify-content: space-between;'>";
            echo "<h5>AngleX: " . $row["angleX"] . "</h5>";
            echo "<h5>AngleY: " . $row["angleY"] . "</h5>";
            echo "<h5>Status: " . $row["status_sensor"] . "</h5>";
            echo "</div>";
        } else {
            echo "<p>No data available</p>";
        }
        $koneksi->close();
        ?>
    </div>
</div>