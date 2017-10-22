#!/usr/bin/perl
use strict;
use CGI':standard';
print header();
my $no_access;
print start_html(-title=>"Lab6", -bgcolor=>"pink");
print h1("<center>SERVER PAGE ACCESS INFORMATION</center>"),br();
my $countfile="count.txt";
#open the file in read only mode
if(open(FILE,"<".$countfile))
{
			#get the page access count from the file
			$no_access=<FILE>;
			close(FILE);
			#open the file in write only mode
			if(open(FILE,">".$countfile))
			{
				#increment the page access count
      	$no_access++;
				#print it to the file
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
 print "<center>This page has been accessed $no_access times</center>";
 print end_html();
