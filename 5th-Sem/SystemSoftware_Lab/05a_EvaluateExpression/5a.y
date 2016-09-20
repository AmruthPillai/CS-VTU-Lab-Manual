%{
	#include<stdio.h>
	#include<stdlib.h>
%}

%token NUMBER
%left '+''-''*''/'

%%
exp:expr {printf("Result is %d\n",$1); return 0;}
expr:expr'+'expr {$$=$1+$3;}
    |expr'-'expr {$$=$1-$3;}
    |expr'*'expr {$$=$1*$3;}
    |expr'/'expr {$$=$1/$3;}
    |'('expr')' {$$=$2;}
    |NUMBER
    ;
%%

yyerror() {
	printf("Invalid expression\n");
	exit(0);
}

int main() {
	printf("Enter the expression\n");
	yyparse();
	printf("Valid expression\n");
	return 0;
}		
