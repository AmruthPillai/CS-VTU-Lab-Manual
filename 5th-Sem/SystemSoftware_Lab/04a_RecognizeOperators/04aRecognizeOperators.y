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
