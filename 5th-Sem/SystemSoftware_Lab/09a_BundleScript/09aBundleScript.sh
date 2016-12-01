for x in $*
do
	echo "cat>$x<<end
	abc
	def
	end"
done > recreate
