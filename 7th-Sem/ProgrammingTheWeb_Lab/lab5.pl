#!/usr/bin/perl
use strict;
use CGI':standard';
print header(), start_html("server information");
print "<table border='2' bgcolor='lime' align='center'>";
foreach my $i(sort(keys(%ENV)))
{
 	print "<tr><td>$i</td><td>$ENV{$i}</td></tr>";
}
print "</table>";
print end_html();
exit(0);
