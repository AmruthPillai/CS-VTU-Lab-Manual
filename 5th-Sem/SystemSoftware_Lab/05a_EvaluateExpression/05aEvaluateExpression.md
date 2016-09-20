##Aim:
Program to evaluate an arithmetic expression involving operators +, -, * and /.
 
##Description:
This program is to solve or to evaluate the given arithmatic expression using the operators +,-,* and /.  
Example: 3+5=8

##Program: 5a.y (YACC specification)
##Code:
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

##Program: 5a.l (LEX specification)
##Code:
	%{
		#include "y.tab.h"
		extern int yylval;
	%}
	
	%option noyywrap
	
	%%
	[0-9]+		{yylval=atoi(yytext); return NUMBER;}
	.		return yytext[0];
	\n		return 0;
	%%

## How to Run:  
    yacc -d 5a.y  
    lex 5a.l  
    cc lex.yy.c y.tab.c y.tab.h  

##Output:
	1. Enter the expression
	2+6
	Result is 8
	Valid expression
	
	2. Enter the expression
	2*
	Invalid expression




