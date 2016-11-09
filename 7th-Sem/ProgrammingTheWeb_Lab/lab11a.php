<?php
mysql_connect("localhost","root","fedora") or die(mysql_error());
mysql_select_db("student") or die(mysql_error());
$name=$_GET['name1'];
$add1=$_GET['addr1'];
$add2=$_GET['addr2'];
$email=$_GET['emails'];
echo "hello".$name;
$query="insert into i values('$name','$add1','$add2','$email')";
mysql_query($query) or die(mysql_error());
echo "INSERTED";
?>
