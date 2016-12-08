## Aim
Shell script that accepts two file names as arguments, checks if the permissions for these files are identical and if the permissions are identical, outputs the common permissions, otherwise outputs each file name followed by its permissions.

## Description
`-ne`: Not equal to.  
`cut -c`: Command to cut the specified columns from the given input.  
`$#`: Contains the total number of input arguments.  

## Code
```
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
```

## Output
```
$ touch file1 file2

$ sh 08a.sh file1 file2
Permissions are same for both files.
Permissions are: -rw-r--r--

$ chmod 777 file2

$ sh 08a.sh file1 file2
Permissions are different.
File file1 has -rw-r--r-- permissions.
File file2 has -rwxrwxrwx permissions.

```
