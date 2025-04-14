import java.sql.*;
import java.io.*;
class Q1
{
	public static void main(String[] args) throws IOException,ClassNotFoundException,SQLException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		Connection conn=null;	
		Statement stmt=null;
		PreparedStatement ps=null;
		
		try
		{
			Class.forName("org.postgresql.Driver");
			conn=DriverManager.getConnection("jdbc:postgresql://192.168.16.1/ty23","ty23","2331ds");
			if(conn==null)
			{
				System.out.println("\nconnection failed\n");
			}
			else
			{
				int ch,id,sal;
				String name;
				System.out.println("\nconnection successful...\n");
				stmt=conn.createStatement();
				do
				{
					System.out.printf("\n++++++++++++ MENU+++++++++\n");
					System.out.println("\n1. Insert\n2. Modify\n3. Delete\n4. Search\n5.View All\n6. Exit");
					System.out.printf("\n++++++++++++++++++++++++++\n");
					System.out.println("\nEnter choice:");
					ch=Integer.parseInt(br.readLine());
					if(ch==6)
					break;
					switch(ch)
					{
						case 1:System.out.println("\nEnter the ID of employee you want to Insert: \t");
							id=Integer.parseInt(br.readLine());
							System.out.print("\nEnter the Name: \t");
							name=br.readLine();
							System.out.print("Enter the Salary: \t");
							sal=Integer.parseInt(br.readLine());
							insert(conn,ps,id,name,sal);
							break;
						case 2:System.out.println("\nEnter the ID of employee you want to Update: \t");
							id=Integer.parseInt(br.readLine());
							System.out.print("\nEnter the Updated Name: \t");
							name=br.readLine();
                                                        System.out.print("Enter the Updated Salary: \t");
                                                        sal=Integer.parseInt(br.readLine());
							update(conn,ps,id,name,sal);
                                                        break;
						case 3:System.out.println("Enter the ID of employee you want to Delete: \t");
							id=Integer.parseInt(br.readLine());
							delet(conn,ps,id);
							break;								
						case 4:System.out.println("Enter the ID of employee you want to Search: \t");
                                                        id=Integer.parseInt(br.readLine());
						       	search(conn,ps,id);
							break;
						case 5:
							display(stmt);
							break;
						default:System.out.println("Wrong choice please enter correct choice: \t");
							ch=Integer.parseInt(br.readLine());
							break;
					}
				}while(ch!=6);
			}
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		catch(Exception e)
		{
			System.out.println();	
		}
		finally
		{
			stmt.close();
			conn.close();
		}
	}





	public static void insert(Connection conn,PreparedStatement ps,int empid,String empname,int salary) throws SQLException
	{	
		try{

		String sql="Insert into employee values(?,?,?)";
                ps=conn.prepareStatement(sql);
                ps.setInt(1,empid);
                ps.setString(2,empname);
                ps.setInt(3,salary);
                int result=ps.executeUpdate();
                if(result==1)
                {
      	        	  System.out.println("\nData Insertion successfull");
		}
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
	}

	public static void update(Connection conn,PreparedStatement ps,int empid,String empname,int salary) throws SQLException
	{
		try{

		String sql="Update employee SET e_name= ?, salary= ? where emp_id= ?";
                ps=conn.prepareStatement(sql);
                ps.setString(1,empname);
		ps.setInt(2,salary);
		ps.setInt(3,empid);
		int result=ps.executeUpdate();
		if(result==1)
		{
			System.out.println("\nData Updated successfully\n");
		}
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}

	}

	public static void delet(Connection conn,PreparedStatement ps,int empid) throws SQLException
	{
		try
		{

		String sql="Delete from employee where emp_id =?";
		ps=conn.prepareStatement(sql);
		ps.setInt(1,empid);
		int result=ps.executeUpdate();
                if(result==1)
                {
			System.out.println("\nData Deleted successfully\n");
		}
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}

	}

	public static void search(Connection conn,PreparedStatement ps,int empid) throws SQLException
	{
		try
		{
		ResultSet rs=null;
		String sql="Select * from employee where emp_id =?";
		ps=conn.prepareStatement(sql);
		ps.setInt(1,empid);
		rs=ps.executeQuery();
		while(rs.next())
		{
			System.out.println("ID = "+rs.getInt(1)+"\t");
			System.out.println("Name = "+rs.getString(2)+"\t");
			System.out.println("Salary = "+rs.getInt(3)+"\n");
		}
		rs.close();
		}
		catch(SQLException e)
                {
                        e.printStackTrace();
                }

	}

	public static void display(Statement stmt) throws SQLException
	{
	
		try
		{
			ResultSet rs=null;
			rs=stmt.executeQuery("Select * from employee");

			if(rs==null)
			{
				System.out.printf("\n DataBase Is Empty");
			}
			else
			{
				System.out.printf("\n======= Employe DB=========\n");
				System.out.printf("\nEmp ID\tEmp Name\tSalary\n");
				while(rs.next())
				{
					System.out.printf("%d\t%s\t\t%d\n",rs.getInt(1),rs.getString(2),rs.getInt(3));
				}
				System.out.printf("\n===========================\n");
				rs.close();
			}
		}catch(SQLException e)
                {
                        e.printStackTrace();
                }

	}

}


