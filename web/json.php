<?php
include "../db.php";
$flag = true;
$table = array();
$table['cols'] = array(
array('label' => 'Number', 'type' => 'string'),
array('label' => 'Beat', 'type' => 'number')
);
$rows = array();
while($row = mysqli_fetch_assoc($result)) {
    $temp = array();
    $temp[] = array('v' => (string) $row['ar_date']);
    $temp[] = array('v' => (int) $row['ar_heart']);
    $rows[] = array('c' => $temp);
}
$table['rows'] = $rows;
$jsonTable = json_encode($table);
//echo $jsonTable;
?>
