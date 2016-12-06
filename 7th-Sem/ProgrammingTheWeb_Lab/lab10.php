<?php
//start the session
session_start();
//check if session information is set
//if it is set then increment the page views value
if(isset($_SESSION['views']))
  $_SESSION['views'] = $_SESSION['views']+ 1;
//else set the session variable for page views to 1
else
  $_SESSION['views'] = 1;
//print the page view count
echo "Page views = ". $_SESSION['views'];
?>
