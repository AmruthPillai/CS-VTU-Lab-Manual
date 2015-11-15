/**
Design, develop, and execute a program in C++ to create a class called LIST (linked list) with member functions to insert an element at the front of the list as well as to delete an element from the front of the list.
Demonstrate all the functions after creating a list object.
**/

#include <iostream>

using namespace std;

class Node {
public:
    int info;
    Node *link;
};

class LinkedList {

private:
    Node * first;

public:
    LinkedList() { first = NULL; }

    void insertFront();
    void deleteFront();
    void display();

};

void LinkedList :: insertFront() {
    int num;
    cout << "Enter the number to insert: ";
    cin >> num;

    Node *temp = new Node;
    temp -> info = num;
    temp -> link = NULL;

    if (first == NULL)
        first = temp;
    else {
        temp -> link = first;
        first = temp;
    }

}

void LinkedList :: deleteFront() {
    Node *temp = first;

    if (temp == NULL)
        cout << "List Empty";
    else {
        first = first -> link;
        cout << temp -> info << " was deleted!" << endl;
        delete temp;
    }
}

void LinkedList :: display() {
    Node *cur = first;

    if (cur == NULL)
        cout << "List Empty!";
    else {
        cout << "List Elements:" << endl;
        while (cur != NULL) {
            cout << "\t" << cur -> info;
            cur = cur -> link;
        }
    }
}

int main()
{
    int choice = 1;
    LinkedList obj;

    while (choice) {
        cout << endl << "Singly Linked List Operations:" <<
                "\n\t1. Insert\n\t2. Delete\n\t3. Display\n\t4. Exit" << endl <<
                "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj.insertFront();
            break;
        case 2:
            obj.deleteFront();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            choice = 0;
        }
    }

    return 0;
}
