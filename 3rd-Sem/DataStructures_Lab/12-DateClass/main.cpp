/**
Design, develop, and execute a program in C++ to create a class called DATE with methods to accept two valid dates in the form dd/mm/yy and to implement the following operations by overloading the operators + and -.
After every operation the results are to be displayed by overloading the operator <<.
i. no_of_days = d1 - d2; where d1 and d2 are DATE objects, d1 >=d2 and no_of_days is an integer.
ii. d2 = d1 + no_of_days; where d1 is a DATE object and no_of_days is an integer.
**/

#include<iostream>

using namespace std;

class Date {
    int dd, mm, yy, a[13], dateNumber;

public:
    Date () {
         a[1] = a[3] = a[5] = a[7] = a[8] = a[10] = a[12] = 31;
         a[4] = a[6] = a[9] = a[11] = 30;
         a[2] = 28;
    }

    void getDate ();
    void getNumber ();
    int operator - (Date &);
    Date operator + (int);
    friend ostream & operator << (ostream &, Date &);
};

void Date :: getDate () {
     cout<<"Enter Date (dd mm yy): ";
     cin >> dd >> mm >> yy;
     getNumber();
}

void Date :: getNumber () {
    int month = 1;
    dateNumber = (yy * 365) + (yy / 4);
    if ((yy % 4) == 0)
        dateNumber++;
    while (month != mm) {
        dateNumber += a[month];
        if ((yy % 4 == 0) && (month == 2))
            dateNumber++;
        month++;
    }
    dateNumber += dd;
}

int Date :: operator - (Date &obj) {
    return dateNumber - obj.dateNumber;
}

ostream & operator << (ostream &out, Date &obj) {
    out << obj.dd << "/" << obj.mm << "/" <<obj.yy << endl;
    return out;
}

Date Date :: operator + (int n) {
    for (int i = 1; i <= n; i++) {
        dd++;
        if (dd > a[mm]) {
            mm++;
            dd = 1;
        }
        if (mm > 12) {
            yy++;
            mm = 1;
        }
        if (yy % 4 == 0)
            a[2] = 29;
    }
    return *this;
}

int main()
{
    Date d1, d2, d3;

    d1.getDate();
    cout << "Date 1: " << d1;

    d2.getDate();
    cout << "Date 2: " << d2;

    int difference, daysToAdd;
    difference = d1 - d2;

    cout << "Difference between the two dates: " << difference << endl;
    cout << "Enter the number of days to be added to the date: ";
    cin >> daysToAdd;

    d3 = d1 + daysToAdd;

    cout << "New Date: " << d3 << endl;

    return 0;
}
