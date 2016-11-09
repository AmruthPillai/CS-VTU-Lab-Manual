%{
	#include<stdio.h>
	#include<stdlib.h>
%}

%token A B;

%%
S:A S B
 |
 ;
%% 

yyerror() {
	printf("Invalid Grammar\n");
	exit(0);
}

main() {
	printf("Enter a string of a's and b's:\n");
	yyparse();
	printf("Valid grammar\n");
}
