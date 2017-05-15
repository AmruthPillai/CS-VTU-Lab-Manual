## Aim
To Write a C/C++ POSIX compliant program to check the following limits:
* No. of clock ticks
* Max. no. of child processes
* Max. path length
* Max. no. of characters in a file name
* Max. no. of open files/ process

## Description
To check system configuration variables: `sysconf(int CONSTANT);`  
To check file system configuration variables: `pathconf(char* PATH_TO_ROOT, int CONSTANT);`

* No. of clock ticks - `_SC_CLK_TCK`
* Max. no. of child processes - `_SC_CHILD_MAX`
* Max. path length - `_PC_PATH_MAX`
* Max. no. of characters in a file name - `_PC_NAME_MAX`
* Max. no. of open files/ process - `_SC_OPEN_MAX`

## Code
```
#define POSIX_SOURCE
#define POSIX_C_SOURCE 199309L

#include "iostream"
#include <unistd.h>

using namespace std;

int main() {
	cout << "No. of Clock Ticks:\t\t" << sysconf(_SC_CLK_TCK) << endl;
	cout << "Max. no. of Child Processes:\t" << sysconf(_SC_CHILD_MAX) << endl;
	cout << "Max. Path Length:\t\t" << pathconf("/", _PC_PATH_MAX) << endl;
	cout << "Max. Characters in a Filename:\t" << pathconf("/", _PC_NAME_MAX) << endl;
	cout << "Max. no. of Open Files:\t\t" << sysconf(_SC_OPEN_MAX) << endl;

	return 0;
}
```

## Execution
```
g++ 01_GetLimits.cpp
./a.out
```

## Output
```
No. of Clock Ticks:             100
Max. no. of Child Processes:    709
Max. Path Length:               1024
Max. Characters in a Filename:  255
Max. no. of Open Files:         256
```
