/**
Design, develop, and execute a program in C++ to create a class called STRING and implement the following operations.
Display the results after every operation by overloading the operator <<.
i. STRING s1 = "VTU"
ii. STRING s2 = "BELGAUM"
iii. STIRNG s3 = s1 + s2; (Use copy constructor)
**/

#include <iostream>
#include <string.h>

using namespace std;

class String {

private:
    char name[20];

public:
    String() {
        strcpy(name, "\0");
    }

    String(char str[]) {
        strcpy(name, str);
    }

    String(String &str) {
        strcpy(name, str.name);
    }

    friend String operator + (String, String);
    friend ostream & operator << (ostream &, String &);

};

String operator + (String s1, String s2) {
    String tempString(s1);
    strcat(tempString.name, s2.name);
    return tempString;
}

ostream & operator << (ostream &out, String &obj) {
    out << obj.name;
    return out;
}

int main()
{
    String  s1("VTU"),
            s2("Belgaum"), s3;

    s3 = s1 + s2;

    cout << "String 1: " << s1 << endl <<
            "String 2: " << s2 << endl <<
            "String 3: " << s3;

    return 0;
}
