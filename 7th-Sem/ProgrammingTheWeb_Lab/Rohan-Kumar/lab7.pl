#!/usr/bin/perl
use strict;
use CGI':standard';
print header();
print start_html(-bgcolor=>"pink",-title=>"digital clock");
#get the current time in hours,mins,seconds and store it in the variables
my($sec,$min,$hr)=localtime();
#refresh the page every second
print"<meta http-equiv=\"refresh\"content=1>";
# formatted string based on the list values is stored in $time
my $time=sprintf("%5d:%5d:%5d",$hr,$min,$sec);
print("<center>Server time</center>");
print("<center>$time</center>");
print end_html();
