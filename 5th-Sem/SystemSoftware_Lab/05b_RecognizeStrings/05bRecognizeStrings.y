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
