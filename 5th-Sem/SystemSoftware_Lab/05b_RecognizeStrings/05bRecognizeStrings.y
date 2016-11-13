%{
#include <stdlib.h>
%}

%name parse
%token A B

%%
S:A S B
| ;
%%

int yyerror() {
	printf("Invalid Grammar.\n");
	exit(0);
}

int main(int argc, char *argv[]) {
	printf("Enter a string of a's & b's: ");
	yyparse();
	printf("Valid Grammar.\n");
	return 0;
}

int yywrap() {
	return 1;
}
