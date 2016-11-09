#!/usr/bin/perl
use strict;
use CGI':standard';
use DBI;
print header();
print start_html(-title=>"database",-bgcolor=>"#135ab",-text=>"green");
my $name=param('name');
my $age=param('age');
my $db=DBI->connect('DBI:mysql:student','root','fedora') or die"cannot connect:".DBI->errstr();
my $query=$db->prepare("insert into stud values('$name','$age')");
$query->execute();
my $query=$db->prepare("select * from stud where age>0");
$query->execute();
print "<table border=2>";
print "<tr><th>Name</th><th>Age</th></tr>";
while(($name,$age)=$query->fetchrow())
{
  print "<tr><td>$name</td><td>$age</td></tr>";
}
$query->finish();
$db->disconnect();
print end_html;
exit(0);
