<?php
		$bs = $_POST["bs"];
		$da = $_POST["da"];
		$hra = $_POST["hra"];
		

		setcookie("bs" , $bs, time()+(300));
		setcookie("da" , $da ,time()+(300));
		setcookie("hra" , $hra ,time()+(300));

?>

<html>
        <head>
                <title>Employee Details</title>
         
                
        </head>
        <body style="text-align:center;color:#A38772;">
                <h2>EMPLOYEE DETAILS</h2>
                <h4>Employee Number : <?php echo $_COOKIE["no"] ; ?></h4>
                <h4>Employee Name : <?php echo $_COOKIE["name"] ; ?></h4>
                <h4>Employee Address : <?php echo $_COOKIE["add"] ; ?></h4>
                <h4>Basic Salary :<?php echo $_POST["bs"] ; ?></h4>
		<h4>DA :<?php echo $_POST["da"] ; ?></h4>
		<h4>HRA :<?php echo $_POST["hra"] ; ?></h4>
		<h4>TOTAL :<?php echo $_POST["bs"] + $_POST["da"] + $_POST["hra"]; ?></h4>
        </body>
</html>
