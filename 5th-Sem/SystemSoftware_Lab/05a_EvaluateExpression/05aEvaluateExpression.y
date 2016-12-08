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
