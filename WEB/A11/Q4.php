<?php

// Array with names
$a[] = "ajax";
$a[] = "Ajax example";
$a[] = "Bible of C";
$a[] = "Beginning with C";

// Get the parameter from the request
$q = $_REQUEST["q"];

// Initialize hint
$hint = "";

// If q is not empty
if ($q !== "") {
    $q = strtolower($q);
    $len = strlen($q);
    
    // Loop through each name in the array
    foreach ($a as $name) {
        // Check if the user input matches the beginning of the name
        if (stristr($q, substr($name, 0, $len))) {
            // If hint is empty, set it to the current name, otherwise append to it
            $hint = ($hint === "") ? $name : "$hint, $name";
        }
    }
}

// Output the hint
echo $hint === "" ? "no suggestions" : $hint;
?>
