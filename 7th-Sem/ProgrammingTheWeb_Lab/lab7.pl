#!/usr/bin/perl
use strict;
use CGI':standard';
print header();
print start_html(-bgcolor=>"pink",-title=>"digital clock");
my($sec,$min,$hr)=localtime();
print"<meta http-equiv=\"refresh\"content=1>"; 
my $time=sprintf("%5d:%5d:%5d",$hr,$min,$sec);
print("<center>Server time</center>");
print("<center>$time</center>");
print end_html();
