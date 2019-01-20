<?php
   include "inc.php";
?>  
<article>
   <h1>Status</h1>
   <p>Here you can see the display status</p>
   <form method="post">
      <select name="Rooms">
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
                   <option value=<?php echo $row["RID"];?>><?php echo $row["Rname"] . " (" . $fullhex . ")";?></option>
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
   * @brief get status form database
   * this wil get all the info form a board that is connected to a room
   */
      if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $RID = $_POST['Rooms'];
 
        $sql = "SELECT * FROM Rooms AS R JOIN Boards AS B ON R.RID = B.RID WHERE R.RID = $RID";
        $result = $conn->query($sql);
        
        if ($result->num_rows > 0) {
          // output data of each row
          while($row = $result->fetch_assoc()) {
              echo "id: " . $row["RID"]. " - Name: " . $row["Rname"]. " -Full name: " . $row["FRname"]. "<br>";
              echo "MAC: " . $row["MAC"]. " - baterij: " . $row["Bstats"]. "</br></br>";
          }
        } 
        else {
           echo "0 results";
        }        	
      }
      ?>
</article>
</section>
</body>
</html>

