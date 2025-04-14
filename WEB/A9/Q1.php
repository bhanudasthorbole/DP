<F12><?php
$fname=$_POST['filename'];
$fp=fopen($fname,"r");
if($fp==null)
{
	echo "Unable to open the file";
	exit(1);
}
echo "<table border=1>";
echo "<tr>";
echo "<th>Roll Number</th>";
echo "<th>Name</th>";
echo "<th>Maths</th>";
echo "<th>Electronics</th>";
echo "<th>Computer</th>";
echo "<th>Percentage</th>";
echo "</tr>";
while($line=fgets($fp))
{
	$data=explode(" ",trim($line));
	$per=($data[2]+$data[3]+$data[4])/3;
	echo "<tr>";
	echo "<td>$data[0]</td>";
	echo "<td>$data[1]</td>";
	echo "<td>$data[2]</td>";
	echo "<td>$data[3]</td>";
	echo "<td>$data[4]</td>";
	echo "<td>$per</td>";
	echo "</tr>";
}
fclose($fp);
echo "</table>";
?>
