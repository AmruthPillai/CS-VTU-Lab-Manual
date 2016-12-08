%{
#include <stdio.h>
#include <stdlib.h>
int count;
%}

%token A B

%%

S : X B
X : X A { count++; }
| ;

%%

int main(int argc, char*argv[]) {
	printf("Enter a string of a's & b's: ");

	yyparse();

	if (count >= 10)
		printf("Valid Grammar!\n");
	else
		printf("Invalid Grammar!\n");

	return 0;
}

int yyerror() {
	printf("Invalid Grammar!\n");
	exit(1);
}

int yywrap() {
	return 1;
}
