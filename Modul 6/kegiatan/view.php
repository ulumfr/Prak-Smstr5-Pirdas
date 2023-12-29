<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>IOT Praktikum</title>
</head>
<body>
    <script type="text/javascript">
        function ubahstatus(value) {
            var status = value ? "ON" : "OFF";
            document.getElementById('status').innerHTML = status;

            var xmlhttp = new XMLHttpRequest();

            xmlhttp.onreadystatechange = function() {
                if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
                    document.getElementById('status').innerHTML = xmlhttp.responseText;
                }
            }

            xmlhttp.open("GET", "fetch.php" + status, true);
            xmlhttp.send();
        }
    </script>
</body>
</html>