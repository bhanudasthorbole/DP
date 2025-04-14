<?php
		$no = $_POST["no"];
		$name = $_POST["name"];
		$add = $_POST["add"];
		

		setcookie("no" , $no, time()+(300));
		setcookie("name" , $name ,time()+(300));
		setcookie("add" , $add ,time()+(300));

?>

<html>
        <head>
                <title>Details</title>
         
                
        </head>
        <body>
		<h2>Details :</h2>
                <form action="Q2_1.php" method="POST">
			 <label for="bs">Basic Salary</label>
			 <input type="number" name="bs"><br><br>

			 <label for="da">DA</label>
			 <input type="number" name="da"><br><br>

			 <label for="hra">HRA</label>
			 <input type="number" name="hra"><br><br>


			 <input type="submit" value="Submit">

		</form>
        </body>
</html>
