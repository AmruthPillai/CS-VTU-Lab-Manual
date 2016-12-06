#!/usr/bin/perl
use strict;
use CGI':standard';
use DBI;
print header();
print start_html(-title=>"Database",-bgcolor=>"#135ab",-text=>"green");
#get the name and age values
my $name=param('name');
my $age=param('age');
#connect to database 'student' with username 'root' and password 'fedora'
my $db=DBI->connect('DBI:mysql:student','root','fedora') or die"cannot connect:".DBI->errstr();
#prepare a mysql query to insert into 'students' table
my $query=$db->prepare("insert into students values('$name','$age')");
#execute the query
$query->execute();
#prepare a mysql query to retreive data from 'students' table
my $query=$db->prepare("select * from students");
#execute the query
$query->execute();
print "<table border=2>";
print "<tr><th>Name</th><th>Age</th></tr>";
#fetch individual row values
while(($name,$age)=$query->fetchrow())
{
  print "<tr><td>$name</td><td>$age</td></tr>";
}
#releasing stattement handle
$query->finish();
#disconnect from database
$db->disconnect();
print end_html;
exit(0);
