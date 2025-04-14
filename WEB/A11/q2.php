<html>
	<head>
		<title>Book</title>
	</head>
	<body>
		<h1>XML contents:</h1>
		<pre>
			<?php
				$book_xml=simplexml_load_file("q2.xml"); // or die("error:cannot create object");
	
				echo htmlspecialchars($book_xml->asXML());
			?>
		</pre>
	</body>
</html>
