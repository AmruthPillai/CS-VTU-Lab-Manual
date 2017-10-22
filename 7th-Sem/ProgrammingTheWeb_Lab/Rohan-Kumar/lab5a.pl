#!/usr/bin/perl
use strict;
use CGI':standard';

#prints "Content-Type" text/html; charset=ISO-8859-1"
print header();
#prints
#<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11-transitional.dtd">
#<html xmlns = "http://www.w3.org/1999/xhtml" lang="en-US" xml:lang="en-US">
#<head>
#<title>Command</title>
#<meta http-equiv="Content-Type" content="text/html"; charset=ISO-8859-1" />
#</head>
#<body>
print start_html("Server Information");
#print the table starting tag
print "<table border='2' bgcolor='lime' align='center'>";
#get the environment variables key in variable i
foreach my $i(sort(keys(%ENV)))
{
  #print the each row - key and value
 	print "<tr><td>$i</td><td>$ENV{$i}</td></tr>";
}
#print the table closing tag
print "</table>";
#prints
#</body>
#</html>
print end_html();
exit(0);
