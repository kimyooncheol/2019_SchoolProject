<?php
include "../db.php";
include 'json.php';
?>
<!doctype html>
<html lang="ko">
    <head>
        <meta charset="utf-8">
        <title>차트 그리기</title>
        <script type="text/javascript" src="https://www.google.com/jsapi"></script>
        <script type="text/javascript"
        src="https://www.gstatic.com/charts/loader.js"></script>
        <script type="text/javascript"
        src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
        <script type="text/javascript">
        google.charts.load('current', {'packages':['corechart']});
        google.setOnLoadCallback(drawChart);
        function drawChart() {
        var data = new google.visualization.DataTable(<?=$jsonTable?>);
        var options = {
        backgroundColor: 'transparent',
        title: ' ' 심박수 차트 ,
        is3D: 'true',
        width: 1000,
        height: 600,
        outlineColor: "transparent",
        colors: ['blue']
        };
        var chart = new
        google.visualization.AreaChart(document.getElementById('chart_div'));
        chart.draw(data, options);
        }
        </script>
    </head>
    <body>
        <div id="chart_div"></div>
    </body>
</html>