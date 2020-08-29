<?php
//
$db_host = "localhost"; //db 호스트
$db_user = "id"; //db id
$db_passwd = "pass"; //db 비밀번호
$db_name = "dbname"; //db 이름
//
$conn = mysqli_connect($db_host,$db_user,$db_passwd,$db_name); //db연결
$db= mysqli_select_db($conn,"superthinks"); //db선택
$query = "select * from beat"; // 검색 위치
$result = mysqli_query( $conn, $query ); // 테이블 선택
$delete="truncate `beat`";
if (mysqli_connect_errno()){ // 에러 나면
    echo "MySQL Err: " . mysqli_connect_error(); // 에러 출력
exit;
}
else {
//echo "DB : \"$db_name\"Succes <br/>"; //연결 완료
}
?>