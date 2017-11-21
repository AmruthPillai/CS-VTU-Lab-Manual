#!/usr/bin/perl
use strict;
use CGI':standard';

print header();
print start_html('Visitor Count');

my $count;

open(FILE,'<count.txt');
$count=<FILE>;
close(FILE);

$count++;

open(FILE,'>count.txt');
print FILE "$count";
print "This page has been viewed $count times";
close(FILE);

print end_html();
