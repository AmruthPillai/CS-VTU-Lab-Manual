#!/usr/bin/perl
use strict;
use CGI':standard';
print header();
my $no_access;
print start_html(-title=>"Enter username", -bgcolor=>"pink");
print h1("<center>SERVER PAGE ACCESS INFORMATION</center>"),br();
my $countfile="count.txt";
if(open(FILE,"<".$countfile))
{
			$no_access=<FILE>;
			close(FILE);
			if(open(FILE,">".$countfile))
			{
      	$no_access++;
				print FILE $no_access;
				close(FILE);
			}
			else
			{
				print("can't write<br>");
			}
}
else
{
			print("Cannot open the file<br>");
}
 print "<center>WELCOME USER</center>";
 print "<center>This page has been accessed : $no_access</center>";
 print end_html();
