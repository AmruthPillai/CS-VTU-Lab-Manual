#!/usr/bin/perl
use strict;
use CGI':standard';

print header();
print start_html('Server Time');
print "<meta http-equiv='refresh' content='1'>";

my ($sec, $min, $hr) = localtime();
my $time = sprintf("%d : %d : %d", $hr, $min, $sec);

print "<center>Current Server Time</center>";
print "<center>$time</center>";

print end_html();
