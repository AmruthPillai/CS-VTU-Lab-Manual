/**
Design, develop, and execute a program in C++ to create a class called STACK using an array of integers and to implement the following operations by overloading the operators + and -:
i. s1=s1 + element; where s1 is an object of the class STACK and element is an integer to be pushed on to top of the stack.
ii. s1=s1- ; where s1 is an object of the class STACK and - operator pops off the top element.

Handle the STACK Empty and STACK Full conditions.
Also display the contents of the stack after each operation, by overloading the operator <<.
**/

#include <iostream>

using namespace std;

class Stack {

private:
    int stack[10], size, top;

public:
    Stack(int n) {
        size = n;
        top = -1;
    }

    void operator + (int);
    void operator -- ();
    friend ostream & operator << (ostream &, Stack &);

};

void Stack :: operator + (int numToPush) {
    if (top == size-1)
        cout << "Stack Overflow!" << endl;
    else
        stack[++top] = numToPush;
}

void Stack :: operator -- () {
    if (top == -1)
        cout << "Stack Underflow!" << endl;
    else
        cout << stack[top--] << " was deleted!" << endl;
}

ostream & operator << (ostream &out, Stack &obj) {
    cout << "Stack Elements:" << endl;
    for (int i = 0; i <= obj.top; i++)
        out << "\t" << obj.stack[i] << endl;
}

int main()
{
    int n, choice = 1;

    cout << "Enter the size of stack: ";
    cin >> n;

    Stack obj(n);

    while (choice) {
        cout << "Stack Operations\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Exit\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int numToPush;
            cout << "Enter number to push: ";
            cin >> numToPush;
            obj + numToPush;
            break;
        case 2:
            --obj;
            break;
        case 3:
            cout << obj;
            break;
        case 4:
            choice = 0;
            break;
        }
    }

    return 0;
}
