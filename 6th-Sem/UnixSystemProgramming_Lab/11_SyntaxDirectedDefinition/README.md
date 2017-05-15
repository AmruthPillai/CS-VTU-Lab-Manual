## Aim
Write a C/C++ program for a syntax directed definition of a "if E then S1" and "if E then S1 else S2".

## Description
A Syntax Directed Definition is a context-free grammar in which each grammar symbol X is associated with two finite sets of values: the synthesized attributes of X and the inherited attributes of X, each production A -> alpha is associated with a finite set of expressions of the form:
```
b := f(c1, ..., ck)
```

The called semantic rules where f is a function and either b is a synthesized attribute of A and the values `c1, ..., ck` are attributes of the grammar symbols of alpha or A, or b is an inherited attribute of a grammar symbol of alpha and the values `c1, ..., ck` are attributes of the grammar symbols of alpha or A. Each terminal symbol has no inherited attributes.

It is usual to denote the attributes of a grammar symbol in the form `X.name` where name is an meaningful name for the attribute.

## Algorithm
1. Start.
2. Output the if, if-else statement to the user for reference.
3. Manipulate the input string such that the if and if-else conditions are stored separately.
4. Generate the format of the if, if-else statements and output the same.
5. End.

## Code
```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int len, cur, i, j;
char input[60], stmt[3][60];

void generator() {
  int l1 = 101, l2 = 102, l3 = 103;

  printf("if %s goto %d\n", stmt[0], l1);
  printf("goto %d\n", l2);
  printf("%d: %s\n", l1, stmt[1]);
  if (cur < 3)
    printf("%d: STOP\n", l2);
  else {
    printf("goto %d\n", l3);
    printf("%d: %s\n", l2, stmt[2]);
    printf("%d: STOP\n", l3);
  }
}

int main() {
  printf("Format of 'if' statement\nExample:\n");
  printf("if(a<b)then(s=a);\n\n");
  printf("Format of 'if-else' statement\nExample:\n");
  printf("if(a<b)then(s=a)else(s=b);\n\n");

  printf("Enter statement: ");
  gets(input);

  len = strlen(input);
  int index = 0;

  for (i = 0; i < len && input[i] != ';'; i++) {
    if (input[i] == '(') {
      index = 0;
      for (j = i; input[j - 1] != ')'; j++)
        stmt[cur][index++] = input[j];
      cur++;
      i = j;
    }
  }

  generator();

  return 0;
}
```

## Execution
```
g++ 11_SyntaxDirectedDefinition.cpp
./a.out
```

## Output
```
Format of 'if' statement
Example:
if(a<b)then(s=a);

Format of 'if-else' statement
Example:
if(a<b)then(s=a)else(s=b);

Enter statement: if(3<5)then(a=100);
if (3<5) goto 101
goto 102
101: (a=100)
102: STOP

Enter statement: if(3<5)then(a=100)else(a=200);
if (3<5) goto 101
goto 102
101: (a=100)
goto 103
102: (a=200)
103: STOP
```
