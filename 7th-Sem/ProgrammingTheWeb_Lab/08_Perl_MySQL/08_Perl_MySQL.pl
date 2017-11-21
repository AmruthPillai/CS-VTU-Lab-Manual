#!/usr/bin/perl
use strict;
use CGI':standard';
use DBI;

print header();
print start_html('MySQL & Perl');

my $name = param('name');
my $age = param('age');

my $db = DBI->connect('DBI:mysql:student', 'root', 'root');
my $query = $db->prepare('INSERT INTO students VALUES("$name", "age")');
$query->execute();

my $query = $db->prepare('SELECT * FROM students');
$query->execute();

print "<table border='1'>";
print "<tr><th>Name</th><th>Age</th></tr>";

while ( ($name, $age) = $query->fetchrow() ) {
  print "<tr><td>$name</td><td>$age</td></tr>";
}

$query->finish();
$db->disconnect();

print end_html();
