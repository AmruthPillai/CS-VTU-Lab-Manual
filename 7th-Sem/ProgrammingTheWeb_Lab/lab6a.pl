#!/usr/bin/perl
use strict;
use CGI':standard';
#array of messages
my @greetings=("Welcome to dsce","welcome to cse","welcome to web lab","how are you");
#size of the array
my $range=@greetings;
#get any random number in that range
my $random_no=int(rand($range));
#if any parameter is passed
if(param)
{
  #print the basic html tags
  print header(),start_html(-title=>"greeting",-bgcolor=>"yellow",-text=>"lime");
  #get the parameter value
  my $name=param('uname');
  #print the name and message
  print b("Hello $name, $greetings[$random_no]"),br();
  #prints
  #<form method="post" action="" enctype="multipart/form-data">
  print start_form();
  #print a submit button to reload the page without sending any parameters
  print submit(-value=>"back");
  #prints </form>
  print end_form();
  #print the closing tag of html
  print end_html();
}
#print a form to get the name
else
{
  print header(), start_html(-title=>" ",-bgcolor=>"yellow",-text=>" ");
  print h5("Enter name :");
  print start_form();
  print textfield(-name => 'uname',-value=>' ');
  print submit(-value=>"submit");
  print reset();
}
