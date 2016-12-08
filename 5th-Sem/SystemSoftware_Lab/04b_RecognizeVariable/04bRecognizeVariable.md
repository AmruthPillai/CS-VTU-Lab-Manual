## Aim
Program to recognize a valid variable, which starts with a letter, followed by any number of letters or digits.

## Description
This program checks if the given variable is valid or invalid. A variable should start with a letter followed any no of letters or digits. For Example: a123 or aa23 or b3455 etc. are valid variables. Example for invalid expression 12aa or 1cc etc.

## Code
### Lex
```
%{
#include "y.tab.h"
%}

%%

[0-9] { return DIGIT; }
[a-zA-Z] { return ALPHA; }
\n { return 0; }
. { return yytext[0]; }

%%
```

### Yacc
```
%{
#include <stdio.h>
#include <stdlib.h>
%}

%token DIGIT ALPHA

%%

var : ALPHA
| var ALPHA
| var DIGIT ;

%%

int main(int argc, char *argv[]) {
	printf("Enter a variable name: ");

	yyparse();

	printf("Valid Variable!\n");
	return 0;
}

int yyerror() {
	printf("Invalid Variable!\n");
	exit(1);
}

int yywrap() {
	return 1;
}
```

## Execution
```
lex 04bRecognizeVariable.l
yacc -dy 04bRecognizeVariable.y
gcc lex.yy.c y.tab.c
```

## Output
#### Test Case #1: Valid Variable
```
Enter a variable name: a123
Valid Variable!
```
#### Test Case #2: Invalid Variable
```
Enter a variable name: 12aa
Invalid Variable!
```
