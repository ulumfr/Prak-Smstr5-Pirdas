<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>MPU6050 Sensor</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous">
</head>

<body style="background-color: #F8E8EE;">
    <nav class="navbar navbar-expand-lg" style="background-color: #F2BED1;">
        <div class="container-fluid">
            <a class="navbar-brand mx-auto text-black fw-medium" href="#">DATA MPU6050 SENSOR</a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavAltMarkup" aria-controls="navbarNavAltMarkup" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
        </div>
    </nav>

    <div class="container my-5">
        <div class="row">
            <div class="col-auto">
                <form class="d-flex" role="search" method="post" action="">
                    <input class="form-control " name="cari" type="search" placeholder="Search" aria-label="Search">
                </form>
            </div>
        </div>
        <div class="row">
            <div class="col-6">
                <div id="link"></div>
            </div>

            <div class="col-6">
                <div id="last">
                </div>
            </div>
        </div>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-C6RzsynM9kWDrMNeT87bh95OGNyZPhcTNXj1NW7RuBCsyN/o0jlpcV8Qyq46cDfL" crossorigin="anonymous"></script>
    <script>
        function loadWeb() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("link").innerHTML = xhttp.responseText;
                }
            };
            var formData = new FormData();
            formData.append('cari', document.querySelector('input[name="cari"]').value); // Get the search input value
            xhttp.open("POST", "table.php", true);
            xhttp.send(formData);

        }

        function loadAngleX() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("last").innerHTML = xhttp.responseText;
                }
            };
            xhttp.open("GET", "last.php", true);
            xhttp.send();
        }
        setInterval(function() {
            loadAngleX();
            loadWeb();
        }, 1000);
    </script>
</body>

</html>