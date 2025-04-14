<?php
$option=$_POST['radioo'];

$conn=pg_connect("host=192.168.16.1 port=5432 dbname=ty23 user=ty23");
if(!$conn)
{
	die("Connection Failed!");
}

if($option==1)
{	
	$disname=$_POST['disname'];
	
	$query1="SELECT stud_id,name,class FROM student where stud_id in(SELECT stud_id FROM student_comp WHERE student_comp.c_no in(SELECT c_no FROM competition WHERE c_name='$disname'))";
	$result1=pg_query($conn,$query1);
	
	while($row=pg_fetch_assoc($result1))
	{
		echo "Student ID--->".$row['stud_id']."<br>";
		echo "Student Name-->".$row['name']."<br>";
		echo "Student Class->".$row['class']."<br>";
		echo "<br>";
		
	}
	echo"<br>";
}


if($option==2)
{
	$delname=$_POST['delname'];
	$query2=" DELETE FROM  student where student.stud_id in(SELECT stud_id FROM student_comp WHERE student_comp.c_no in(SELECT c_no FROM competition WHERE c_name='$delname'))";
	$result2=pg_query($conn,$query2);
	if($result2)
	{
		echo "<br> Deleted Row From DB";
	}
}

?>
