## Aim
Program to recognize the grammar (a^nb, n >= 10).

##Description:
The program has three parts: definition section, rule section, subroutine section. The program uses a variable count to keep track of the number of A's in the input string and B is accepted only once according to the rule described. So count must be more than 9.

## Code
### Lex
```
%{
#include "y.tab.h"
%}

%%

a { return A; }
b { return B; }
\n { return 0; }
. { return yytext[0]; }

%%
```
### Yacc
```
%{
#include <stdio.h>
#include <stdlib.h>
int count;
%}

%token A B

%%

S : X B
X : X A { count++; }
| ;

%%

int main(int argc, char*argv[]) {
	printf("Enter a string of a's & b's: ");

	yyparse();

	if (count >= 10)
		printf("Valid Grammar!\n");
	else
		printf("Invalid Grammar!\n");

	return 0;
}

int yyerror() {
	printf("Invalid Grammar!\n");
	exit(1);
}

int yywrap() {
	return 1;
}
```

## Execution
```
lex 06RecognizeGrammar.l
bison -dy 06RecognizeGrammar.y
gcc lex.yy.c y.tab.c
```

## Output
#### Test Case #1: Valid Grammar
```
Enter a string of a's & b's: aaaaaaaaaab
Valid Grammar!
```
#### Test Case #2: Invalid Grammar
```
Enter a string of a's & b's: aaaaabb
Invalid Grammar!
```
