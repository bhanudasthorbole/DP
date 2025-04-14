<!DOCTYPE html>
<head>
	<title>Registeration</title>
</head>

<body>
	<h2>Registeration form</h2>
	<form action="Q1.jsp" method="post">
		Name: <input type="text" name="name" placeholder="Enter your name" required><br>
		Email: 
		 <input type="text" name="email" placeholder="Enter your email" required><br>
		Contact number : <input type="text" name="contact" placeholder="Enter conatact no" required><br>
		Present occupation: <input type="text" name="occupation" placeholder="Enter your present occupation" required><br>
		Year of passing: <input type="text" name="year" placeholder="Enter year of passing" required><br>
		Program name: <select name="select">
			<option value="undergraduate">Undergraduate</option>
			<option value="graduate">Graduate</option>
		</select><br>
		<input type="submit" value="Register"><br>
		<%@ page import="java.sql.*" %>
		<%@ page import="java.io.*" %>
		<%@ page import="java.util.*" %>
 
 
	
<% 
	String name=request.getParameter("name");
        String email=request.getParameter("email");
        String contact=request.getParameter("contact");
        String occupation=request.getParameter("occupation");
        String year=request.getParameter("year");
        String select=request.getParameter("select");
        

        Connection conn = null;
        Statement stat = null;
        ResultSet res = null;
        PreparedStatement insert = null;
	
	Scanner input = new Scanner(System.in);

	try
	{
		Class.forName("org.postgresql.Driver");
		conn = DriverManager.getConnection("jdbc:postgresql://192.168.16.1/ty23","ty23","");
         	insert = conn.prepareStatement("insert into alumni values(?,?,?,?,?,?)");
         	if(conn==null)
         	{
         	       out.println("Connection failed");
         	}
         	else
         	{
         	       out.println("Connetion succesful..");
         	}
         	stat = conn.createStatement();

	         insert.setString(1,name);
	         insert.setString(2,email);
	         insert.setString(3,contact);
	         insert.setString(4,occupation);
	         insert.setString(5,year);
	         insert.setString(6,select);

	        insert.executeUpdate();
%>
	<br><br>
	
	
	Year Of Passing : <input type="text" name="y" id="Yea" placeholder="Enter Year Of Passing" required><br><br>
	<input type="submit" value="Search"><br>
	<%
		       String y=request.getParameter("y");
		       res = stat.executeQuery("select * from alumni where pass_year= '"+y+"'");
		       while(res.next())
		       {
		    		
		    	%>
	<table>
	<tr><td><%out.println(res.getString("name"));%></td></tr>
	<tr><td><%out.println(res.getString("email"));%></td></tr>
	<tr><td><%out.println(res.getString("cno"));%></td></tr>
	<tr><td><%out.println(res.getString("occupation"));%></td></tr>
	<tr><td><%out.println(res.getString("pass_year"));%></td></tr>
	<tr><td><%out.println(res.getString("program_name"));%></td></tr>
	</table>
	<%
		     	}
	
	}
	catch(Exception e)
	{
		out.println(e);
	}

%>
</form>
</body>
</html>

