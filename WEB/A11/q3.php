<?php

function validate($name){
	if($name == '')
		return "Please enter any username";
	if(strlen($name)<3)
		return "Username too short";
	if(strlen($name)>10)
		return "Username too long";
	return "Username Valid";
}

echo validate($_GET['name']);
?>
