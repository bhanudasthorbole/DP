<html>
	<head>
	<style>
		body{
			background-color: <%= request.getParameter("color")%>
			}
	</style>
	</head>
	<body>
		<font color="white"> Session working <br/>
			Selected color is : <%= request.getParameter("color")%><br>
			<a href="Q3.html"> Back </a>
	</body>
</html>

