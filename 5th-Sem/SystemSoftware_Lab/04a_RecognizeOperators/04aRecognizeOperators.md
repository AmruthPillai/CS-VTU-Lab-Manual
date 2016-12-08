## Aim
Program to recognize a valid arithmetic expression that uses operators +, -, * and /.

## Description
This program checks if the given arithmetic expression is valid or not. An arithmetic expression contains operators like +, -, * and /. For Example: 12+23-8 or a+b*c etc. are valid expressions. Example for invalid expressions are a+* or (23*3)/ etc.

## Code
### Lex
```
%{
#include "y.tab.h"
%}

%%

[0-9]+ { return NUMBER; }
[_a-zA-Z][_a-zA-Z0-9]* { return ID; }
\n { return 0; }
. { return yytext[0]; }

%%
```
### Yacc
```
%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER ID
%left '+''-''*''/'

%%

exp : exp'+'exp
| exp'-'exp
| exp'*'exp
| exp'/'exp
| '('exp')'
| NUMBER
| ID ;

%%

int main(int argc, char *argv[]) {
	printf("Enter the expression: ");

	yyparse();

	printf("Valid Expression!\n");
	return 0;
}

int yyerror() {
	printf("Invalid Expression!\n");
	exit(1);
}

int yywrap() {
	return 1;
}
```

## Execution
```
lex 04aRecognizeOperators.l
yacc -dy 04aRecognizeOperators.y
gcc lex.yy.c y.tab.c
```

## Output
#### Test Case #1: Valid Expression
```
Enter the expression: 12+23-8
Valid Expression!
```
#### Test Case #2: Invalid Expression
```
Enter the expression: a+*
Invalid Expression!
```
