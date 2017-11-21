<?php
  mysql_connect("localhost", "root", "root");
  mysql_select_db("students");

  $name = $_GET['name'];
  $address = $_GET['address'];
  $email = $_GET['email'];

  echo "Hello, " . $name;

  $query = "INSERT INTO student VALUES('$name', '$address', '$email')";
  mysql_query($query);

  echo "Information Inserted!";
?>
