<?php
include "../db.php";
?>

<!doctype html>
<html lang="ko">
    <head>
        <meta charset="utf-8">
        <title>값 읽어오기</title>
        <link rel="stylesheet" type="text/css" href="../styles/css/cell_css.css">
    </head>
    <body>
        <div id="cell">
            <table width=600px style="margin:auto">
                <thead>
                    <tr>
                    <th>번호</th>
                    <th>날짜</th>
                    <th>심박수</th>
                    </tr>
                </thead>
                <tbody>
                <?php
                while( $row = mysqli_fetch_array( $result ) ) {
                    echo '<tr><td>' . $row[ 'idx' ] . '</td><td>'. $row[ 'ar_date' ] .'</td><td>' . $row[ 'ar_heart' ] . '</td></tr>'; // 차트 그리는 부분
                }
                ?>
                </tbody>
            </table>
        </div>
    </body>
</html>

