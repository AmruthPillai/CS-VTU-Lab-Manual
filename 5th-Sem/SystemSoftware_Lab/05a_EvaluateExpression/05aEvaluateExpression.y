%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER
%left '+''-''*''/'

%%
exp:expr { printf("Result is %d.\n", $$); return 0; }
expr:expr'+'expr {$$=$1+$3;}
|expr'-'expr {$$=$1-$3;}
|expr'*'expr {$$=$1*$3;}
|expr'/'expr {$$=$1/$3;}
|'('expr')' {$$=$2;}
|NUMBER ;
%%

int yyerror() {
	printf("Invalid Expression.\n");
	exit(0);
}

int main() {
	printf("Enter the expression: ");
	yyparse();
	printf("Valid Expression.\n");
	return 0;
}

int yywrap() {
	return 1;
}
