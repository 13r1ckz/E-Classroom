

<?php
   include "inc.php";
   ?> 
<article>
   <h1>Change room</h1>
   <p>Here you can change the display</p>
   <form method="post">
      <select name="RoomsA">
         <?php
          /**
          * @brief Get list of rooms whit board
          * This part wil get the rooms witch have a board connected to them
          * and turns the int of the database to a mac addres
          */
            $sql = "SELECT * FROM Rooms AS R JOIN Boards AS B ON R.RID = B.RID";
            $result = $conn->query($sql);
            
            if ($result->num_rows > 0) {
                // output data of each row
                while($row = $result->fetch_assoc()) {
                $hexmac = my_base_convert($row["MAC"], 10, 16);
                $hexmacup = strtoupper($hexmac);
                $fullhex = $hexmacup[0].$hexmacup[1].":".$hexmacup[2].$hexmacup[3]. ":" . $hexmacup[4].$hexmacup[5].":".$hexmacup[6].$hexmacup[7].":".$hexmacup[8].$hexmacup[9].":".$hexmacup[10].$hexmacup[11];
            		?>
                   <option value=<?php echo $row["MAC"];?>><?php echo $row["Rname"] . " (" . $fullhex . ")";?></option>
                 <?php
                }
            } 
            else {
              echo "0 results";
            }
            ?>
      </select>
      TO: 
      <select name="RoomsB">
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
      * @brief move board from room to room
      *  connects the selected board to the new selected room
      *  $sql = "UPDATE `Boards` SET `RID` = '$RIDB' WHERE `Boards`.`MAC` = '$RIDA';";
      */
      if ($_SERVER["REQUEST_METHOD"] == "POST") {
      	$RIDA = $_POST['RoomsA'];
      	$RIDB = $_POST['RoomsB'];
      	
      
      $sql = "UPDATE `Boards` SET `RID` = '$RIDB' WHERE `Boards`.`MAC` = '$RIDA';";
      $result = $conn->query($sql);
      
      if ($result) {
        echo "The display has been changed";
      } 
      else {
        echo "error";
        echo $sql;
      }
      	
      }
      ?>
</article>
</section>
</body>
</html>

