<?php
mysql_connect("localhost","root","fedora") or die(mysql_error());
mysql_select_db("student") or die(mysql_error());
$name=$_GET['name'];
$res=mysql_query("select * from i where n='$name'");
echo "<table border='1'>";
echo "<tr><th>Name</th><th>Address1</th><th>Address2</th><th>EmailID</th></tr>";
while($arr=mysql_fetch_row($res))
  echo "<tr><td>$arr[0]</td><td>$arr[1]</td><td>$arr[2]</td><td>$arr[3]</td>";
echo "</table>";
?>
