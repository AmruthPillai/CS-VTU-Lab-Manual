%{
#include <stdio.h>
#include <stdlib.h>
%}

%token DIGIT ALPHA

%%
var:ALPHA
|var ALPHA
|var DIGIT ;
%%

int yyerror() {
	printf("Invalid Variable.\n");
	exit(0);
}

int main() {
	printf("Enter the variable: ");
	yyparse();
	printf("Valid Variable.\n");
	return 0;
}

int yywrap() {
	return 1;
}
