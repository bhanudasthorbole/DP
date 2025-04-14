<?php

$a_name=$_POST['name'];
$m_name=$_POST['movie'];
$release_year=$_POST['year'];
$opt=$_POST['r'];




$db=pg_connect("host=192.168.16.1 dbname=ty23 user=ty23");
if($db)
	echo "'DB connected' <br><br>";
$query="select movie_name from movie where movie_no in(select movie_no from movie_actor where actor_no=(select actor_no from actor where name='$a_name'))";
$q="update movie set release_year='$release_year' where movie_name='$m_name'";




if($opt==1)
{
	$res=pg_query($db,$query);
	if($res)
        {
	echo " 1st query is executed <br>";
	}

	else
	{
        echo " Enter Valid Input <br>";
	}

	while($row=pg_fetch_row($res))
	{
		echo "Played Role in Movie-> ".$row[0]."<br>";
		echo"<br>";
	}
}


if($opt==2)
{
	$res2=pg_query($db,$q);
	if($res2)
        echo "2nd query is executed <br>";
	
	while($row1=pg_fetch_assoc($res2))
	{		
		echo"Updated details <br>";
		echo $row1['movie_no'];
		echo $row1['movie_name'];
		echo $row1['release_year'];
	}
}



pg_close();
?>
