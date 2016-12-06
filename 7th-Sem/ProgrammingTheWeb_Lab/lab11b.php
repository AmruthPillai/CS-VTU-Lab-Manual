<?php
//connect to mysql
mysql_connect("localhost","root","fedora") or die(mysql_error());
//select the database - student
mysql_select_db("student") or die(mysql_error());
//get the parameters value
$name=$_GET['name'];
//run the select query to get information about a particular student
$result=mysql_query("select * from studentInfo where name='$name'");
echo "<table border='1'>";
echo "<tr><th>Name</th><th>Address1</th><th>Address2</th><th>EmailID</th></tr>";
//fetch individual row values and store it in a array
while($row=mysql_fetch_row($result))
  echo "<tr><td>$row[0]</td><td>$row[1]</td><td>$row[2]</td><td>$row[3]</td>";
echo "</table>";
?>
