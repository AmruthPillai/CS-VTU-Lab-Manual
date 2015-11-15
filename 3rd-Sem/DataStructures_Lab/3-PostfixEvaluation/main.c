/**
Design, develop, and execute a program in C to evaluate a valid postfix expression using stack.
Assume that the postfix expression is read as a single line consisting of non-negative single digit operands and binary arithmetic operators. The arithmetic operators are +(add), - (subtract), * (multiply) and / (divide).
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[50], top = -1;

void push (int num) {
    stack[++top] = num;
}

int pop () {
    return stack[top--];
}

int main()
{
    int i, op1, op2;
    char postfix[50];

    printf("Enter the postfix expression: ");
    gets(postfix);

    for (i = 0; i < strlen(postfix); i++) {
        if (isdigit(postfix[i]))
            push(postfix[i] - '0');
        else {
            op2 = pop();
            op1 = pop();
            switch (postfix[i]) {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            }
        }
    }

    printf("Result: %d", pop());

    return 0;
}
