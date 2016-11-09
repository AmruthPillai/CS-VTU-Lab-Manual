##Aim:
Program to recognize strings 'aaab', 'abbb', 'ab' and 'a' using the grammar (a^nb^n, n >= 0).

##Description: 
The program has three parts defination section, rule section, subroutine section. The program accepts equal number of a's and b's as valid inputs.  
The grammar is S->A S B, A->a ,b->b.

##Program: 5b.y (Yacc Specification)
##Code:
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

##Program: 5b.l (Lex Specification)
##Code:
	%{
		#include"y.tab.h"
	%}
	
	%option noyywrap
	
	%%
	a return A;
	b return B;
	. return yytext[0];
	\n return 0;
	%%

## How to Run:
    yacc -d 5b.y
    lex 5b.l
    cc lex.yy.c y.tab.c y.tab.h

##Output:
	Enter a string of a's and b's:
	aaab
	Invalid Grammar

	Enter a string of a's and b's:
	abbb
	Invalid Grammar

	Enter a string of a's and b's:
	ab
	Valid Grammar

	Enter a string of a's and b's:
	a
	Invalid Grammar



