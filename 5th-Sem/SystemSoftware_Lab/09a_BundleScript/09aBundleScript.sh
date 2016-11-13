if [ $# -eq 0 ]
then
	echo "Error, please enter arguments."
	exit
fi

for i in $*
do
	echo "Extracting $i File" >> f.sh
	cat $i >> f.sh
	echo "EOF" >> f.sh
done

cat f.sh
