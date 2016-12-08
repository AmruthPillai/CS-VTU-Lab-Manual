## Aim
Non-recursive shell script that accepts any number of arguments and prints them in the reverse order.  
For Example: If the script is named `args.sh`, then executing `sh args A B C` should produce C B A on the standard output.

## Description
`$#`: Contains the total number of input arguments.  
`$*`: Contains all the input arguments.  

## Code
```
#!/bin/bash
echo "The total number of arguments are: $#"
echo "The arguments are: $*"

for i in $*
do
	rev=$i" "$rev
done

echo $rev
```

## Output
```
The total number of arguments are: 4
The arguments are: a b c d
d c b a
```
