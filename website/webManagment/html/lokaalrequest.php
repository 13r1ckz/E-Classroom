<?php
include "db.php";
error_reporting(E_ALL);
ini_set('dispaly_errors', 1);

/*
* @brief curl request
* tis makes a post request to https://roostertest.windesheim.nl/WebUntis/Timetable.do
* does the command 'ajaxCommand' => 'getPageConfig',
* and says it wants type 4
* it has the cookie schoolname="_d2luZGVzaGVpbQ==***"
* @returns JSON
*/
$url = 'https://roostertest.windesheim.nl/WebUntis/Timetable.do';

$post_data = array(
  'request.preventCache' => '1543327601812',
  'ajaxCommand' => 'getPageConfig',
  'type' => '4'
  );

const COOKIES       = 'schoolname="_d2luZGVzaGVpbQ==***"';

$sh = curl_init();

curl_setopt($sh, CURLOPT_URL, $url);

curl_setopt($sh, CURLOPT_RETURNTRANSFER, 1);

curl_setopt($sh, CURLOPT_COOKIE, COOKIES);

curl_setopt($sh, CURLOPT_POST, 1);

curl_setopt($sh, CURLOPT_POSTFIELDS, $post_data);

$output =curl_exec($sh);

if($output == false){
  echo "cURL Error: " . curl_error($sh);
}

curl_close($sh);

$data = json_decode($output, true);
/*
* @brief curl request json to db
* gets form every room the id name and longname
* this wil be placed in to the data base
* fist it checks if the room id exist
* if this is fals it will add a new record.
* if the id exists it will chek if the data is the same.
* if it is the same it will do nothing.
* else it wil update the data
*/
foreach($data['elements'] as $room){
  $RID = $room['id'];
  $Rname = $room['name'];
  $FRname = $room['longName'];
  
  $sql = "SELECT * FROM Rooms Where RID = " . $RID . "";
  $result = $conn->query($sql);
  
  if ($result->num_rows > 0) {
      while($row = $result->fetch_assoc()) {
          if($row["Rname"] != $Rname || $row["FRname"] != $FRname){
            $sql = "UPDATE Rooms SET Rname='".$Rname."', FRname='".$FRname."' WHERE RID=" . $RID ."";
  
            if ($conn->query($sql) === TRUE) {
              echo $RID . "Record updated successfully</br>";
            } 
            else {
              echo $RID . "Error updating record: " . $conn->error . "</br>";
            }
  
          }
          else{
            echo "id: " . $row["RID"]. " - Name: " . $row["Rname"]. " Long name" . $row["FRname"]. "<br>";
          }
      }
  } 
  else {
      $sql = "INSERT INTO Rooms (RID, Rname, FRname) VALUES ('".$RID."', '".$Rname."', '".$FRname."')";
  
      if ($conn->multi_query($sql) === TRUE) {
          echo $RID . " - New records created successfully</br>";
      } 
      else {
          echo $RID . "INSERT Error: " . $sql . "<br>" . $conn->error . "</br>";
      }
    }
}

$_SESSION["Rupdate"] = 1;
?>
<script> location.replace("index.php"); </script>