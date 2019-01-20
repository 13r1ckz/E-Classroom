

<?php
   include "inc.php";
   ?> 
<article>
   <h1>Add display</h1>
   <p>Here you can add a new display</p>
   <form method="post">
      <input id="macAddress" type="text" maxlength="17" name="mac"></input>
      <script>
         var macAddress = document.getElementById("macAddress");
         
         /**
         * @brief only MAC adress
         * 
         * this function makes sure the input is made to a mac adress
         * it add's the : automaticly
         * @retuns none
         * @note needs a var macAddress with a element id form a text input
         */
         function formatMAC(e) {
             var r = /([a-f0-9]{2})([a-f0-9]{2})/i,
                 str = e.target.value.replace(/[^a-f0-9]/ig, "");
         
             while (r.test(str)) {
                 str = str.replace(r, '$1' + ':' + '$2');
                 str = str.replace(/([A-Z])/g, "-$1").toLowerCase();
             }
         
             e.target.value = str.slice(0, 17);
         };
         
         macAddress.addEventListener("keyup", formatMAC, false);
      </script>
      <select name="Rooms">
         <?php
           /**
           * @brief get list of all rooms
           *  get list of existing rooms form the database
           *  $sql = "SELECT * FROM Rooms";
           */
         
            $sql = "SELECT * FROM Rooms";
            $result = $conn->query($sql);
            
            if ($result->num_rows > 0) {
                // output data of each row
                while($row = $result->fetch_assoc()) {
            		?>
                  <option value=<?php echo $row["RID"];?>><?php echo $row["Rname"];?></option>
                 <?php
                }
            } 
            else {
            echo "0 results";
            }
            
            ?>
      </select>
      <input type="submit" value="Submit">
   </form>
   <?php
      /**
      * @brief add new board
      *  add the new board to the data base will link a mac adress to a room id
      *  $sql = "INSERT INTO `Boards` (`MAC`, `RID`, `Bstats`) VALUES ('".$MACint."', '".$RID."', NULL);";
      */
      if ($_SERVER["REQUEST_METHOD"] == "POST") {
      	$MAC = $_POST['mac'];
      	$RID = $_POST['Rooms'];
      	if(isset($MAC)){
            $MACnodubble = str_replace(":","",$MAC);
            $MACint = hexdec($MACnodubble);
            $sql = "INSERT INTO `Boards` (`MAC`, `RID`, `Bstats`) VALUES ('".$MACint."', '".$RID."', NULL);";
            $result = $conn->query($sql);
            if($result){
              echo "Boart with the MAC addres: " . $MAC . " has been submitted to the databased and connected to room: " . $RID . "</br>";
              echo "Verder data over de MAC: " . $MACnodubble . " MAC int: " . $MACint;
            }
            else{
              echo("Error description: " . mysqli_error($conn));
            }
          }
          else{
            echo "ERROR: leeg MAC";
          }			
      }
      ?>
</article>
</section>
</body>
</html>

