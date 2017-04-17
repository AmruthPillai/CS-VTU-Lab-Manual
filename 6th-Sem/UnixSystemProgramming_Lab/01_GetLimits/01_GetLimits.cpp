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
