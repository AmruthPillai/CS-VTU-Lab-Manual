%{
#include <stdio.h>
#include <stdlib.h>
%}

%token DIGIT ALPHA

%%

var : ALPHA
| var ALPHA
| var DIGIT ;

%%

int main(int argc, char *argv[]) {
	printf("Enter a variable name: ");

	yyparse();

	printf("Valid Variable!\n");
	return 0;
}

int yyerror() {
	printf("Invalid Variable!\n");
	exit(1);
}

int yywrap() {
	return 1;
}
