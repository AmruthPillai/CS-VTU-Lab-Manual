#!/bin/bash
if [ $# -ne 2 ]
then
	echo "Please enter 2 filenames as arguments."
	exit
fi

perm1=`ls -l $1|cut -c 1-10`
perm2=`ls -l $2|cut -c 1-10`

if [ $perm1 = $perm2 ]
then
	echo "Permissions are same for both files."
	echo "Permissions are: $perm1"
else
	echo "Permissions are different."
	echo "File $1 has $perm1 permissions."
	echo "File $2 has $perm2 permissions."
fi
