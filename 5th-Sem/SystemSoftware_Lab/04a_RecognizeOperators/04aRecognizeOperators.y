%{
#include <stdlib.h>
%}

%name parse

%token NUMBER ID
%left '+''-'
%left '*''/'

%%
exp:exp'+'exp
|exp'-'exp
|exp'*'exp
|exp'/'exp
|NUMBER
|ID ;
%%

int main(int argc, char *argv[]) {
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
