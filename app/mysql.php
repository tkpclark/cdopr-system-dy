<?php
	$mysqli = new mysqli('103.10.85.133', 'wraith', 'tengyewudi2012@)!@', 'cdopr');
	if($mysqli->connect_error)
	{
		die('Connect Error (' . $mysqli->connect_errno . ') '
				. $mysqli->connect_error);
	}	
?>
