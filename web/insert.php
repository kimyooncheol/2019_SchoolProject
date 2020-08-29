<?php
include "../db.php";
for($i=0; $i<5; $i++) {
    mysqli_query($conn,"INSERT INTO beat(ar_date, ar_heart) VALUES(now(),FLOOR(55+RAND()*(15)))");
}
$prevPage = $_SERVER['HTTP_REFERER'];
header('location:'.$prevPage);
//Debug용
?>