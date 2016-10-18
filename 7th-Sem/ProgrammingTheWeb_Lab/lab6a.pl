#!/usr/bin/perl
use strict;
use CGI':standard';
my @greetings=("Welcome to dsce","welcome to cse","welcome to web lab","how are you");
my $range=4;
my $random_no=int(rand($range));
if(param)
{	
 print header(),
 start_html(-title=>"greeting",-bgcolor=>"yellow",-text=>"lime");	
 my $name=param('uname');	
 print b("Hello $name, $greetings[$random_no]"),br();
 print start_form();	
 print submit(-value=>"back");	
 print end_form();	
 print end_html();
}
else  
{
 print header(), start_html(-title=>" ",-bgcolor=>"yellow",-text=>" ");	
 print h5("Enter name :");
 print start_form();
 print textfield(-name => 'uname',-value=>' ');
 print submit(-value=>"submit");	
 print reset();
}
