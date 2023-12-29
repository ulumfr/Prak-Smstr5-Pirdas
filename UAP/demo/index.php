<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>UAP Pirdas | Pertanian</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous">
</head>

<body>

    <body style="background-color: #F8E8EE;">
        <nav class="navbar navbar-expand-lg" style="background-color: #F2BED1;">
            <div class="container-fluid">
                <a class="navbar-brand mx-auto text-black fw-medium" href="#">SENSOR KELEMBABAN TANAH</a>
                <!-- <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavAltMarkup" aria-controls="navbarNavAltMarkup" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                </button> -->
            </div>
        </nav>

        <div class="container my-5">
            <div class="row">
                <div class="col-6">
                    <div>
                        <canvas id="myChart"></canvas>
                    </div>
                </div>

                <div class="col-6">
                    <div id="last"></div>
                    <div class="row">
                        <div class="col-md-6 mb-3 mb-md-0">
                            <div class="card text-center border border-dark" style="background-color: #F8D7DA;">
                                <h5 class="card-header text-center border-dark">Mode Pump</h5>
                                <div class="card-body d-flex justify-content-center align-items-center">
                                    <div class="form-check form-switch">
                                        <input class="form-check-input" type="checkbox" role="switch" id="flexSwitchCheckDefault">
                                        <label class="form-check-label" for="flexSwitchCheckDefault" id="switchLabel">Auto</label>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div class="col-md-6" id="additionalCard" style="display: none;">
                            <div class="card text-center border border-dark" style="background-color: #F8D7DA;">
                                <h5 class="card-header text-center border-dark">Mode Manual</h5>
                                <div class="card-body d-flex justify-content-center align-items-center">
                                    <div class="form-check form-switch">
                                        <input class="form-check-input" type="checkbox" role="switch" id="additionalSwitch">
                                        <label class="form-check-label" for="additionalSwitch" id="additionalSwitchLabel">Off</label>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>

                <div class="my-5">
                    <div class="row">
                        <div class="col-auto">
                            <form class="d-flex" role="search" method="post" action="">
                                <input class="form-control " name="cari" type="search" placeholder="Search" aria-label="Search">
                            </form>
                        </div>
                    </div>
                    <div id="link"></div>
                </div>
            </div>

            <footer class="text-center py-3 opacity-50">
                <p>&copy; 2023 UAP Piranti Cerdas Kelas G</p>
            </footer>

            <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
            <script src="https://code.jquery.com/jquery-3.6.4.min.js"></script>
            <script src="https://cdn.jsdelivr.net/npm/chart.js/dist/Chart.min.js"></script>
            <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-C6RzsynM9kWDrMNeT87bh95OGNyZPhcTNXj1NW7RuBCsyN/o0jlpcV8Qyq46cDfL" crossorigin="anonymous"></script>
            <script>
                const switchLabel = document.getElementById('switchLabel');
                const toggleSwitch = document.getElementById('flexSwitchCheckDefault');
                const additionalCard = document.getElementById('additionalCard');
                const additionalSwitchLabel = document.getElementById('additionalSwitchLabel');
                const additionalSwitch = document.getElementById('additionalSwitch');

                toggleSwitch.addEventListener('change', function() {
                    if (this.checked) {
                        switchLabel.innerText = 'Manual';
                        additionalCard.style.display = 'block';
                    } else {
                        switchLabel.innerText = 'Auto';
                        additionalCard.style.display = 'none';
                        additionalSwitchLabel.innerText = 'Off';
                        additionalSwitch.checked = false;
                    }
                });

                additionalSwitch.addEventListener('change', function() {
                    if (this.checked) {
                        additionalSwitchLabel.innerText = 'On';
                    } else {
                        additionalSwitchLabel.innerText = 'Off';
                    }
                });

                function loadWeb() {
                    var xhttp = new XMLHttpRequest();
                    xhttp.onreadystatechange = function() {
                        if (this.readyState == 4 && this.status == 200) {
                            document.getElementById("link").innerHTML = xhttp.responseText;
                        }
                    };
                    var formData = new FormData();
                    formData.append("cari", document.querySelector('input[name="cari"]').value);
                    xhttp.open("POST", "table.php", true);
                    xhttp.send(formData);
                }

                function loadKelembaban() {
                    var xhttp = new XMLHttpRequest();
                    xhttp.onreadystatechange = function() {
                        if (this.readyState == 4 && this.status == 200) {
                            document.getElementById("last").innerHTML = xhttp.responseText;
                        }
                    };
                    xhttp.open("GET", "last.php", true);
                    xhttp.send();
                }

                function updateChartWithData(waktuArray, kelembabanArray) {
                    const myChart = new Chart(document.getElementById('myChart'), {
                        type: 'line',
                        data: {
                            labels: waktuArray,
                            datasets: [{
                                label: 'Kelembaban Tanah',
                                data: kelembabanArray,
                                borderWidth: 1,
                                borderColor: '#F2BED1',
                            }]
                        },
                        options: {}
                    });
                }

                function updateChart() {
                    var xhttpChart = new XMLHttpRequest();
                    xhttpChart.onreadystatechange = function() {
                        if (this.readyState == 4 && this.status == 200) {
                            const data = JSON.parse(xhttpChart.responseText);
                            const waktuArray = data[0];
                            const kelembabanArray = data[1];
                            updateChartWithData(waktuArray, kelembabanArray);
                        }
                    };
                    xhttpChart.open("GET", "chart.php", true);
                    xhttpChart.send();
                }

                setInterval(function() {
                    loadKelembaban();
                    loadWeb();
                    updateChart();
                }, 3000);
            </script>
    </body>
</body>

</html>