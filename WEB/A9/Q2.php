<?php
if($_SERVER["REQUEST_METHOD"]=="POST")
{
	$directoryName=trim($_POST["directory"]);
	$extension=trim($_POST["extension"]);
	
	$directoryPath=__DIR__.DIRECTORY_SEPARATOR.$directoryName;

	if(!is_dir($directoryPath))
	{
		die("<h3>Directory '$directoryName' does not exist in the current location!</h3>");
	}

	$extension=ltrim($extension,'.');

	$files=scandir($directoryPath);
	$matchedFiles=[];

	foreach($files as $file)
	{
		$filePath=$directoryPath.DIRECTORY_SEPARATOR.$file;
		if(is_file($filePath) && pathinfo($filePath,PATHINFO_EXTENSION)===$extension)
		{
			$matchedFiles[]=["name"=>$file,"size"=>filesize($filePath),"last_access"=>date("Y-m-d H:i:s",fileatime($filePath))];
		}
	}

	if(empty($matchedFiles))
	{
		echo "<h3>No Files found with .$extension extension in '$directoryName'</h3>";
	}
	else
	{
		echo "<h2>Files with .$extension extension in '$directoryName'</h2>";
		echo "<table border='1' cellpadding='5'>";
		echo "<tr><th>Filename</th><th>Size (Bytes)</th><th>Last Access Time</th></tr>";
		foreach($matchedFiles as $file)
		{
			echo "<tr>";
			echo "<td>{$file['name']}</td>";
			echo "<td>{$file['size']}</td>";
			echo "<td>{$file['last_access']}</td>";
			echo "</tr>";
		}
		echo "</table>";
	}
}
?>
