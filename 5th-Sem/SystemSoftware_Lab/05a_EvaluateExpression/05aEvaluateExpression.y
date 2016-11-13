%{
#include <stdlib.h>
%}

%name parse

%token NUMBER
%left '+''-''*''/'
%%
exp:expr {printf("Result is %d.\n", $1); return 0;}
expr:expr'+'expr {$$=$1+$3;}
|expr'-'expr {$$=$1-$3;}
|expr'*'expr {$$=$1*$3;}
|expr'/'expr {$$=$1/$3;}
|NUMBER
;
%%

int yyerror() {
	printf("Invalid Expression.\n");
	exit(0);
}

int main(int argc, char *argv[]) {
	printf("Enter the expression: ");
	yyparse();
	printf("Valid Expression.\n");
	return 0;
}
