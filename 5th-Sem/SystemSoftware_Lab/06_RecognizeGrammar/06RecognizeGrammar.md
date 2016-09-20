##Aim:  
Program to recognize the grammar (a^nb, n >= 10).

##Description:
The program has three parts:definition section,rule section,subroutine section. The program uses a variable count to keep track of the number of A's in the input string and B is accepted only once according to the rule described.So count must be more than 9.

##Program: 6.y (Yacc Specification)
##Code:
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
		if (count >= 10)
			printf("Valid Grammar\n");
		else
			printf("Invalid Grammar\n");
	}

##Program: 6.l (Lex Specification)
##Code
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

##How to Run:  
    yacc -d 6.y
    lex 6.l
    cc lex.yy.c y.tab.c y.tab.h

##Output:
	1. Enter a string of a's and b's:
	aaaaaaaaaab
	Valid Grammar

	2. Enter a string of a's and b's:
	aaaaaab
	Invalid Grammar
