## Aim
Program to evaluate an arithmetic expression involving operators +, -, * and /.

## Description
This program is to solve or to evaluate the given arithmetic expression using the operators +, -, * and /. Example: 3 + 5 = 8

## Code
### Lex
```
%{
#include "y.tab.h"
extern int yylval;
%}

%%

[0-9]+ { yylval = atoi(yytext); return NUMBER; }
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

%token NUMBER
%left '+''-''*''/'

%%

exp : expr { printf("Result:\t%d\n", $$); return 0; }
expr : expr'+'expr { $$ = $1 + $3; }
| expr'-'expr { $$ = $1 - $3; }
| expr'*'expr { $$ = $1 * $3; }
| expr'/'expr { $$ = $1 / $3; }
| '('expr')' { $$ = $2; }
| NUMBER ;

%%

int main(int argc, char *argv[]) {
	printf("Enter the expression: ");

	yyparse();

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
lex 05aEvaluateExpression.l
yacc -dy 05aEvaluateExpression.y
gcc lex.yy.c y.tab.c
```

## Output
```
Enter the expression: 123+25
Result: 148
```
