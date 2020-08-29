<?php
include "../db.php";
mysqli_query($conn,$delete );
$prevPage = $_SERVER['HTTP_REFERER'];
header('location:'.$prevPage);
?>
