<?php
  mysql_connect("localhost", "root", "root");
  mysql_select_db("students");

  $name = $_GET['search_name'];

  $query = "SELECT * FROM student WHERE name='$name'";
  $res = mysql_query($query);

  echo "<table border='1'>";
  echo "<tr><th>Name</th><th>Address</th><th>Email</th></tr>";

  while ($arr = mysql_fetch_row($res))
    echo "<tr><td>$arr[0]</td><td>$arr[1]</td><td>$arr[2]</td></tr>";

  echo "</table>";
?>
