<?php
include "db.php";
?>

<!doctype html>
<html lang="ko">
    <head>
        <meta charset="utf-8">
        <title>값 읽어오기</title>
        <link rel="stylesheet" type="text/css" href="styles/css/button_cool.css">
        <link rel="stylesheet" type="text/css" href="styles/css/index.css">
    </head>
    <body>
        <div id="cell">
            <iframe width="640" height="470" src="/scripts/cell.php" alig="center" frameborder=0 framespacing=0 marginheight=0 marginwidth=0 vspace=0>표 들어가는부분</iframe>
        </div>
        <div id="charc">
            <iframe width="1040" height="640" src="/scripts/chart.php" frameborder=0 framespacing=0 marginheight=0 marginwidth=0 vspace=0>차트 들어가는 부분     </iframe>
        </div>
        <div id="button_1">
            <button class="snip1535" onclick="location.href='scripts/delete.php'">초기화</button>
        </div>
        <div id="button_2">
            <button class="snip1535" onclick="location.href='scripts/setting.php'">설정</button>
        </div>
    </body>
</html>
