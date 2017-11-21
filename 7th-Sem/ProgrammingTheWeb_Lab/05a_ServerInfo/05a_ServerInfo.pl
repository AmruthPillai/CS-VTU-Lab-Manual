#!/usr/bin/perl
use strict;
use CGI':standard';

print header();
print start_html('Server Information');

print "<table border='1' align='center'>";

foreach my $i (sort(keys(%ENV))) {
  print "<tr><td>$i</td><td>$ENV{$i}</td></tr>";
}

print "</table>";
print end_html();
