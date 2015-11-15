#include <iostream>
#include <cmath>

using namespace std;

class Octal {

private:
    int octalNumber;

public:
    // Converting Decimal to Octal
    // Octal h = int x;
    Octal(int);

    // Converting Octal to Decimal and performing Addition
    // int y = Octal h + int k;
    int operator + (int);

    // Overloading << operator to display Octal Number
    friend ostream & operator << (ostream &, Octal &);

};

// Converting Decimal to Octal
// Octal h = int x;
Octal :: Octal(int numToConvert) {
	octalNumber = 0;
    int dec, i = 0;

    while (numToConvert != 0) {
        dec = numToConvert % 8;
        octalNumber += dec * pow(10, i++);
        numToConvert /= 8;
    }
}

// Converting Octal to Decimal and performing Addition
// int y = Octal h + int k;
int Octal :: operator + (int numToAdd) {
    int decimal = 0, oct, i = 0;
    int octal = octalNumber;

    while (octal != 0) {
        oct = octal % 10;
        decimal += oct * pow(8, i++);
        octal /= 10;
    }

    return decimal + numToAdd;;
}

// Overloading << operator to display Octal Number
ostream & operator << (ostream &out, Octal &obj) {
    out << "Octal Number is: " << obj.octalNumber << endl;
    return out;
}

int main() {
    int decimalNum, numToAdd;

    cout << "Enter decimal number to convert: ";
    cin >> decimalNum;

    Octal obj(decimalNum);
    cout << obj;

    cout << "Enter number to add: ";
    cin >> numToAdd;

    cout << obj + numToAdd;;

    return 0;
}
