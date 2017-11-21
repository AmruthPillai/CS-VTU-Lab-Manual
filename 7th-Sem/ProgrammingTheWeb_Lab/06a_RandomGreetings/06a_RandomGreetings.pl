#!/usr/bin/perl
use strict;
use CGI':standard';

my @greetings = ("Hello, World!", "Hello there!", "Welcome to Program 06a!", "Namaskaara!");
my $range = 4;
my $randno = int(rand($range));

print header();
print start_html('Greetings');

if (param) {
  my $name = param('name');
  print "Hi $name! <br /> $greetings[$randno]";
} else {
  print start_form();

  print "Enter your name: ";
  print textfield(-name => 'name');

  print submit();
  print reset();

  print end_form();
}

print end_html();
