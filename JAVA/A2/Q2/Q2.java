import java.sql.*;
import java.io.*;

class Q2
{
	public static void main(String[] args)throws IOException , ClassNotFoundException , SQLException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		Connection con=null;
		 
		ResultSet rs=null;
		PreparedStatement ps=null;
		try
		{
			Class.forName("org.postgresql.Driver");
			con=DriverManager.getConnection("jdbc:postgresql://192.168.16.1/ty23","ty23","");
			if(con==null)
			{
				System.out.println("\nConnection Failed\n");
				return;
			}
			
		
				System.out.println("\nConnection Successful\n");
				int choice;
				
				do
				{
					System.out.println("\n1. Add Record\n2. Display date-wise lecture details for a specific teacher\n3. Display class-wise timetable\n4. Modify Record for specific teacher\n5. Exit");
					System.out.println("\nEnter your choice:");
					choice=Integer.parseInt(br.readLine());
					
					switch(choice)
					{
						case 1:
							System.out.println("\nEnter the ID of the Teacher:");
							int teacherId=Integer.parseInt(br.readLine());
						
							System.out.println("\nEnter the name of the Teacher:");
							String teacherName=br.readLine();

							System.out.println("Enter Subject Code:");
							int subjectCode=Integer.parseInt(br.readLine());

							System.out.println("\nEnter Subject Name:");
                                                        String subjectName=br.readLine();

							System.out.println("\nEnter the date(YYYY-MM-DD):");
							String date=br.readLine();
							
							System.out.println("\nEnter the time(HH:MM):");
							String time=br.readLine();

							System.out.println("\nEnter class division:");
							String className=br.readLine();

							ps=con.prepareStatement("INSERT INTO Teacher2 VALUES(?,?)");
							ps.setInt(1,teacherId);
							ps.setString(2,teacherName);
							ps.executeUpdate();

						        ps=con.prepareStatement("INSERT INTO Workload2 VALUES(?,?,?,?,?,?)");
							ps.setInt(1,subjectCode);
							ps.setString(2,subjectName);
							ps.setDate(3,Date.valueOf(date));
							ps.setTime(4,Time.valueOf(time+":00"));
							ps.setString(5,className);
							ps.setInt(6,teacherId);
							ps.executeUpdate();
							System.out.println("\nWorkload record inserted successfully\n");
							break;


						case 2:
							System.out.println("Enter the Teacher Name:");
							String teacher=br.readLine();
							ps=con.prepareStatement("SELECT Teacher_Name,Subject_Name,Date,Time,Class FROM Teacher2 INNER JOIN Workload2 ON Teacher2.Teacher_Id=Workload2.Teacher_Id WHERE Teacher_Name=?");

							ps.setString(1,teacher);
							rs=ps.executeQuery();

							System.out.println("\nDate-wise Lecture Details:");
							while(rs.next())
							{
								System.out.println("Teacher : " +rs.getString("Teacher_Name"));
								System.out.println("Subject : " +rs.getString("Subject_Name"));
								System.out.println("Date:	" +rs.getDate("Date"));
								System.out.println("Time : " +rs.getTime("Time"));
								System.out.println("Class : " +rs.getString("Class"));
								System.out.println();
							}
							
							break;

						case 3:
							System.out.println("Enter the class division:");
							String classInput=br.readLine();
							
							ps=con.prepareStatement("SELECT Date,Subject_Name,Time from Workload2 WHERE Class=?");
							ps.setString(1,classInput);
							rs=ps.executeQuery();
							System.out.println("\nClass-wise Timetable:");

							while(rs.next())
							{
								System.out.println("Date:       " +rs.getDate("Date"));
								System.out.println("Subject : " +rs.getString("Subject_Name"));
								System.out.println("Time : " +rs.getTime("Time"));
								System.out.println();
							}
							
							break;

						case 4:

						        System.out.println("\nEnter the ID of the Teacher to Update:");
                                                        int updateteacherId=Integer.parseInt(br.readLine());

							System.out.println("Enter New Date(YYYY-MM-DD):");
                                                        String newDate=br.readLine();

							System.out.println("\nEnter New time(HH:MM):");
                                                        String newTime=br.readLine();

							System.out.println("\nEnter new class division:");
                                                        String newClass=br.readLine();

							ps=con.prepareStatement("UPDATE Workload2 SET Date = ?,Time = ? , Class = ? WHERE Teacher_Id = ?");
							ps.setDate(1,Date.valueOf(newDate));
							ps.setTime(2,Time.valueOf(newTime +":00"));
							ps.setString(3,newClass);
							ps.setInt(4,updateteacherId);

							int rowsUpdated=ps.executeUpdate();

							if(rowsUpdated > 0){
								System.out.println("\nRecord Updated Successfully\n");
							}else{
								System.out.println("\nNo records found for the given Teacher ID.");
					
							}break;

                                                        case 5:
							System.out.println("Exiting...");
							break;


						default:
							System.out.println("Wrong choice , please enter the correct choice.");
							
					}
				}
				while(choice!=5);
			}
		
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			if(rs != null)
				rs.close();
			if(ps != null)
				ps.close();
			if(con != null)
				con.close();

		}
	}
}


/*import java.io.*;
import java.sql.*;

public class q2
{
	public static void main(String[] args)throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		Connection con=null;
		PreparedStatement ps=null;
		ResultSet rs=null;
		try
		{
			//Loading the driver and establishing a connection
			Class.forName("org.postgresql.Driver");
			con = DriverManager.getConnection("jdbc:postgresql://192.168.16.1/ty4","ty4","");

			if(con!=null)
			{
				System.out.println("\nConnection established successfully");
			}
			else
			{
				System.out.println("\nConnection Failed");
				return;
			}

			int choice;
			do
			{
				System.out.println("\nMenu:");
				System.out.println("1. Add Record");
				System.out.println("2. Display Date-wise lecture details for a specifc teacher");
				System.out.println("3. Display class-wise timetable");
				System.out.println("4. Modify Record of a specific teacher");
				System.out.println("5. Exit");
				System.out.print("Enter your choice:");
				choice=Integer.parseInt(br.readLine());

				switch(choice)
				{
					case 1:
						System.out.print("Enter Teacher ID:");
						int teacherId=Integer.parseInt(br.readLine());
						System.out.print("Enter Teacher Name:");
						String teacherName=br.readLine();

						System.out.print("Enter Subject Code:");
						int subjectCode=Integer.parseInt(br.readLine());
						System.out.print("Enter Subject Name:");
						String subject=br.readLine();
						System.out.print("Enter Date (yyyy-mm-dd):");
						String date=br.readLine();
						System.out.print("Enter Time (hh:mm:ss):");
						String time=br.readLine();
						System.out.print("Enter Class:");
						String className=br.readLine();


						ps = con.prepareStatement("INSERT INTO teacher VALUES (?,?)");
						ps.setInt(1,teacherId);
						ps.setString(2,teacherName);
						ps.executeUpdate();

						ps = con.prepareStatement("INSERT INTO workload VALUES (?,?,?,?,?,?)");
						ps.setInt(1,subjectCode);
						ps.setString(2,subject);
						ps.setDate(3,Date.valueOf(date));
						ps.setTime(4,Time.valueOf(time));
						ps.setString(5,className);
						ps.setInt(6,teacherId);
						ps.executeUpdate();

						System.out.println("Record Added Successfully");
						break;

					case 2:
						System.out.print("Enter Teacher Name: ");
						String searchTeacher = br.readLine();

						ps=con.prepareStatement("SELECT subject,date,time,class FROM teacher t JOIN workload w ON t.teacher_id=w.teacher_id WHERE t.teacher_name=?");
						ps.setString(1,searchTeacher);
						ps.executeQuery();

						System.out.println("\nDate-wise Lecture Details:");
						while(rs.next())
						{
							System.out.println("Subject: " + rs.getString("subject") + ", Date: " + rs.getDate("date") + ", Time: " + rs.getTime("time") + ", Class: " + rs.getString("class"));
						}
						break;

					case 3:
						System.out.print("Enter Class: ");
						String searchClass=br.readLine();

						ps=con.prepareStatement("SELECT subject , date , time FROM workload WHERE class=?");
						ps.setString(1,searchClass);
						ps.executeQuery();

						System.out.println("\nClass-wise Timetable:");
						while(rs.next())
						{
							System.out.println("Subject: " + rs.getString("subject") + ", Date: " + rs.getDate("date") + ", Time: " + rs.getTime("time"));
						}
						break;

					case 4:
						System.out.print("Enter Teacher ID: ");
						int modifyTeacherId=Integer.parseInt(br.readLine());
						System.out.print("Enter New Date (yyyy-mm-dd): ");
						String newDate=br.readLine();
						System.out.print("Enter New Time (hh:mm:ss): ");
						String newTime=br.readLine();
						System.out.print("Enter New Class: ");
						String newClass=br.readLine();

						ps=con.prepareStatement("UPDATE workload SET date=? , time=? , class=? WHERE teacher_id=?");
						ps.setDate(1,Date.valueOf(newDate));
						ps.setTime(2,Time.valueOf(newTime));
						ps.setString(3,newClass);
						ps.setInt(4,modifyTeacherId);
						int rowsUpdated=ps.executeUpdate();

						if(rowsUpdated>0)
						{
							System.out.println("Record Updated Successfully!!");
						}
						else
						{
							System.out.println("No Record Found for the given Teacher ID!!");
						}
						break;

					case 5:
						System.out.println("Exiting....");
						break;

					default:
						System.out.println("Invalid Choice.Please try again.");

				}
			}while(choice!=5);
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			try
			{
				if(rs!=null)
					rs.close();
				if(ps!=null)
					ps.close();
				if(con!=null)
					con.close();
			}
			catch(SQLException e)
			{
				e.printStackTrace();
			}
		}
	}
}*/
