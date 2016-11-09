%{
	#include<stdio.h>
	#include<stdlib.h>
	int count = 0;
%}

%token A B;

%%
S: X B
X: X A {count++;}
 |
 ;
%%

yyerror() {
	printf("Invalid Grammar\n");
	exit(0);
}

main()
{
	printf("Enter a string of a's and b's:\n");
	yyparse();
	if(count>=10)
	printf("Valid Grammar\n");
	else
	printf("Invalid Grammar\n");
}
