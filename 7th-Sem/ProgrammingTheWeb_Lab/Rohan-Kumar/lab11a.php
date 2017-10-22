<?php
//connect to mysql
mysql_connect("localhost","root","fedora") or die(mysql_error());
//select the database - student
mysql_select_db("student") or die(mysql_error());
//get the parameters value
$name=$_GET['name'];
$add1=$_GET['addr1'];
$add2=$_GET['addr2'];
$email=$_GET['email'];

echo "Hello ".$name;

//prepare mysql statement to insert into table 'studentInfo'
$query="insert into studentInfo values('$name','$add1','$add2','$email')";
//execute the query
mysql_query($query) or die(mysql_error());
echo "INSERTED";
?>
