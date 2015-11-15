#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[50];
int top = -1;

void push(char symbol) {
    stack[++top] = symbol;
}

char pop() {
    return stack[top--];
}

int priority(char symbol) {
    if (symbol == '#' || symbol == '(')
        return 1;
    else if (symbol == '+' || symbol == '-')
        return 2;
    else if (symbol == '*' || symbol == '/')
        return 3;
    else if (symbol == '^' || symbol == '$')
        return 4;
    else
        return 0;
}

int main()
{
    char infix[50], postfix[50];
    int i, j = 0;

    printf("Enter an infix expression: ");
    gets(infix);

    push('#');

    for (i = 0; i < strlen(infix); i++) {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        } else {
            while(priority(stack[top]) >= priority(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }

    while(stack[top] != '#')
        postfix[j++] = pop();
    postfix[j] = '\0';

    printf("Postfix Expression: ");
    puts(postfix);

    return 0;
}
