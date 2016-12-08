## Aim
Program to recognize strings 'aaab', 'abbb', 'ab' and 'a' using the grammar (a^nb^n, n >= 0).

## Description
The program has three parts definition section, rule section, subroutine section. The program accepts equal number of a's and b's as valid inputs.  
The grammar is S -> A S B, A -> a , B -> b.

## Code
### Lex
```
%{
#include "y.tab.h"
%}

%%

a { return A; }
b { return B; }
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

%token A B

%%

S : A S B
| ;

%%

int main(int argc, char *argv[]) {
	printf("Enter a string of a's and b's: ");

	yyparse();

	printf("Valid Grammar!\n");
	return 0;
}

int yyerror() {
	printf("Invalid Grammar!\n");
	exit(1);
}

int yywrap() {
	return 1;
}
```

## Execution
```
lex 05bRecognizeStrings.l
yacc -dy 05bRecognizeStrings.y
gcc lex.yy.c y.tab.c
```

## Output
#### Test Case #1: Valid Grammar
```
Enter a string of a's and b's: aabb
Valid Grammar!
```
#### Test Case #2: Invalid Grammar
```
Enter a string of a's and b's: aabbaabb
Invalid Grammar!
```
