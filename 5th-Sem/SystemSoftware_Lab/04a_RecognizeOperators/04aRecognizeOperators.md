## AIM:
Program to recognize a valid arithmetic expression that uses operators +, -, * and /.

##Description:
This program checks if the given arithmetic expression is valid or not.An arithmetic expression contains operators like +,-,* and /. For example : 12+23-8 or (a+b)*c etc are valid expressions.
Example for invalid expressions are a+* or (23*3)/(78 etc.

##Program : 4a.y (Yacc Specification)
##Code:
	%{
		#include <stdio.h>
		#include <stdlib.h>
	%}
	
	%token NUMBER ID
	%left '+''-'
	%left '*''/'
	
	%%
	exp:exp'+'exp
	|exp'-'exp
	|exp'*'exp
	|exp'/'exp
	|NUMBER
	|ID;
	%%
	
	int main() {
		printf("Enter the expression\n");
		yyparse();
		printf("Valid expression\n");
		return 0;
	}
	
	yyerror() {
		printf("Invalid expression\n");
		exit(0);
	}

##Program :4a.l (Lex Specification)
##Code:
	%{
		#include "y.tab.h"
	%}
	
	%option noyywrap
	
	%%
	[0-9]+                  return NUMBER;
	[a-zA-Z][a-zA-Z0-9]*    return ID;
	.                       return yytext[0];
	\n                      return 0;
	%%

## How to Run:  
    yacc -d 04a_RecognizeOperators.y  
    lex 04a_RecognizeOperators.l  
    cc lex.yy.c y.tab.c y.tab.h  

##Output:  
    1.Enter the expression
    a+b
    Valid expression

    2.Enter the expression
    a+
    Invalid expression

















































































		
