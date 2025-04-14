<?php
		$ff = $_POST["ff"];
		$fs = $_POST["fs"];
		$fc = $_POST["fc"];
		$bgc = $_POST["bgc"];

		setcookie("fontfamily" , $ff, time()+(300));
		setcookie("fontsize" , $fs ,time()+(300));
		setcookie("fontcolor" , $fc ,time()+(300));
		setcookie("backgroundcolor" , $bgc , time()+(300));

?>

<html>
        <head>
                <title>PREFERENCES</title>
         
                
        </head>
        <body>
                <h2>Your Preference </h2>
                <h4>Font Family : <?php echo $_COOKIE["fontfamily"] ; ?></h4>
                <h4>Font size : <?php echo $_COOKIE["fontsize"] ; ?></h4>
                <h4>Font color : <?php echo $_COOKIE["fontcolor"] ; ?></h4>
                <h4>Background color :<?php echo $_COOKIE["backgroundcolor"] ; ?></h4>
		<a href="Q1_1.php">Apply Effects</a>
        </body>
</html>
