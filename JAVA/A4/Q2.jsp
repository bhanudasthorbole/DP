<%@page contentType="text/html;
charset=UTF-8"%>
<%@page import="java.util.*"%>
<%
int item_1=Integer.parseInt(request.getParameter("n1"));
int item_2=Integer.parseInt(request.getParameter("n2"));
int item_3=Integer.parseInt(request.getParameter("n3"));

double item_1_price=550.00;
double item_2_price=100.00;
double item_3_price=250.00;

double total = (item_1_price * item_1) + (item_2_price*item_2) + (item_3_price*item_3);
HttpSession Session = request.getSession();
session.setAttribute("total",total);
%>
<!DOCTYPE html>
<html>
	<head><title>total price</title></head>
	<body>
		<h1>TOTAL</h1>
		<p><%=total%>/-</p>
	</body>
</html>


