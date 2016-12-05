%{
#include <stdio.h>
#include <stdlib.h>
%}
%token NUMBER ID
%left '+''-''*''/'
%%
exp:exp'+'exp
|exp'-'exp
|exp'*'exp
|exp'/'exp
|'('exp')'
|NUMBER
|ID ;
%%
int main() {
	printf("Enter the expression: ");
	yyparse();
	printf("Valid expression.\n");
	return 0;
}

int yyerror() {
	printf("Invalid expression.\n");
	exit(0);
}

int yywrap() {
	return 1;
}
