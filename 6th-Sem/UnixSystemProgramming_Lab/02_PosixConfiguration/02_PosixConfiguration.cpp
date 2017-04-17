#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

#include "iostream"
#include <unistd.h>

using namespace std;

int main() {
  #ifdef _POSIX_JOB_CONTROL
    cout << "System supports POSIX Job Control." << endl;
  #else
    cout << "System does not support POSIX Job Control." << endl;
  #endif

  #ifdef _POSIX_SAVED_IDS
    cout << "System supports Saved Set UID and GID." << endl;
  #else
    cout << "System does not support Saved Set GID and UID." << endl;
  #endif

  #ifdef _POSIX_CHOWN_RESTRICTED
    cout << "Chown Restricted is enabled." << endl;
  #else
    cout << "Chown Restricted is disabled." << endl;
  #endif

  #ifdef _POSIX_NO_TRUNC
    cout << "Truncation is enabled." << endl;
  #else
    cout << "Truncation is disabled." << endl;
  #endif

  #ifdef _POSIX_VDISABLE
    cout << "Special Characters for Terminal Device Files will be disabled." << endl;
  #else
    cout << "Special Characters for Terminal Device Files will not be diasbled."<<endl;
  #endif

  return 0;
}
