/**
Design, develop, and execute a program in C++ to create a class called BIN_TREE that represents a Binary Tree, with member functions to perform inorder, preorder and postorder traversals.
Create a BIN_TREE object and demonstrate the traversals.
**/

#include <iostream>

using namespace std;

class Node {
public:
    int info;
    Node *left, *right;
};

Node *root = NULL;

class BinaryTree {

private:
    Node *temp, *prev, *cur;

public:
    void insert();
    void display();

    void preOrder(Node *);
    void inOrder(Node *);
    void postOrder(Node *);

};

void BinaryTree :: insert() {
    int num;

    cout << "Enter number to insert in new node: ";
    cin >> num;

    temp = new Node;
    temp -> info = num;
    temp -> left = NULL;
    temp -> right = NULL;

    if (root == NULL)
        root = temp;
    else {
        cur = root;

        while (cur != NULL) {
            if (num > cur -> info) {
                prev = cur;
                cur = cur -> right;
            } else {
                prev = cur;
                cur = cur -> left;
            }
        }

        if (num > prev -> info)
            prev -> right = temp;
        else
            prev -> left = temp;
    }
}

void BinaryTree :: preOrder (Node *cur) {
    if (cur != NULL) {
        cout << "\t" << cur -> info;
        preOrder(cur -> left);
        preOrder(cur -> right);
    }
}

void BinaryTree :: inOrder (Node *cur) {
    if (cur != NULL) {
        inOrder(cur -> left);
        cout << "\t" << cur -> info;
        inOrder(cur -> right);
    }
}

void BinaryTree :: postOrder (Node *cur) {
    if (cur != NULL) {
        postOrder(cur -> left);
        postOrder(cur -> right);
        cout << "\t" << cur -> info;
    }
}

void BinaryTree :: display() {
    if (root == NULL)
        cout << "Empty Tree!" << endl;
    else {
        cout << endl << "PreOrder Display:" << endl;
        preOrder(root);
        cout << endl << "InOrder Display:" << endl;
        inOrder(root);
        cout << endl << "PostOrder Display:" << endl;
        postOrder(root);
    }
}

int main() {
    BinaryTree obj;
    int choice = 1;

    while (choice) {
        cout << endl << "Binary Tree Operations" <<
                "\n\t1. Insert\n\t2. Traverse\n\t3. Exit\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            choice = 0;
        }
    }

    return 0;
}
