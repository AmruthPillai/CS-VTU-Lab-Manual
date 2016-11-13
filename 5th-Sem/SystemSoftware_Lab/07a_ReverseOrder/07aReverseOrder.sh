#! /bin/bash
if [ $# -eq 0 ]
then
	echo "No Arguments."
	exit
fi
echo "The total number of arguments are $#"
echo "The arguments are $*"
for i in $@
do 
	rev=$i" "$rev
done
echo "$rev"
