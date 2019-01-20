<?php
include "inc.php";
?> 
  
  <article>
    <h1>Menu</h1>
    <p>Welcome to the E-Classroom managment pannel</p>
    <p>Here you can alter the displays and the rooms wich they belongs to</p>
  </article>

<?php
if(isset($_SESSION["Rupdate"])){//check if session exists
  if($_SESSION["Rupdate"] == 1){//check if set to 1 if true show if not proceed
    ?>
    <div>
    <h1>The rooms database has been updated</h1>
    </div>
    <?php
    $_SESSION["Rupdate"] = 0;
  }
}
?>
</section>
</body>
</html>
