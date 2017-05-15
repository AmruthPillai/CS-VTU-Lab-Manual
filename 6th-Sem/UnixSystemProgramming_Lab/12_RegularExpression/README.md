## Aim
Write a YACC program that accepts a regular expression as input and produce its parse tree as output.

## Description
`YACC` - `Yet Another Compiler Compiler` defines what it is all by itself. Computer program input generally has some structure; in fact, every computer program that does input can be thought of as defining an `input language` which it accepts.  

An input language may be as complex as a programming language, or as simple as a sequence of numbers. Unfortunately, usual input facilities are limited, difficult to use, and often are lax about checking their inputs for validity.

`YACC` provides a general tool for describing the input to a computer program. The Yacc user specifies the structures of his input, together with code to be invoked as each such structure is recognized. `YACC` turns such a specification into a subroutine that handles the input process; frequently, it is convenient and appropriate to have most of the flow of control in the user's application handled by this subroutine.

Every `YACC` specification file consists of three sections: the declarations, (grammar) rules, and programs. The sections are separated by double percent `%%` marks. (The percent % is generally used in `YACC` specifications as an escape character).  

In other words, a full specification file looks like:
```
declarations
%%
rules
%%
programs
```

The declaration section may be empty. Moreover, if the programs section is omitted, the second %% mark may be omitted also; thus, the smallest legal `YACC` specification is:
```
%%
rules
```

The following command `yacc grammar.y` draws YACC rules from the `grammar.y` file, and places the output in `y.tab.c`.

The following command `yacc -d grammar.y` functions the same as Example 1, but it also produces the `y.tab.h` file which would contain C-style `#define` statements for each of the tokens defined in the `grammar.y` file.

## Algorithm
1. Start
2. Accept an expression from the user.
3. Check for the structure that satisfies the conditions of a regular expression.
4. Print the parsed tree as output as when the conditions are satisfied.
5. End

## Code
```
%{
/* Declaration Part */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* To Store Productions*/
#define MAX 100

int getREindex(const char*);
signed char productions[MAX][MAX];
int count, i, j;
char temp[200], temp2[200];
%}

%token ALPHABET
%left '|'
%left '.'
%nonassoc '*' '+'

%%

/* Rules Section */
S : re '\n' {
  printf("\nThis is the rightmost derivation:\n");
  for(i = count - 1; i >= 0; --i) {
    if (i == count - 1) {
      printf("\nre => ");
      strcpy(temp, productions[i]);
      printf("%s", productions[i]);
    } else {
      printf("\n => ");
      j = getREindex(temp);
      temp[j] = '\0';
      sprintf(temp2, "%s%s%s", temp, productions[i], (temp + j + 2));
      printf("%s", temp2);
      strcpy(temp, temp2);
    }
  }
  printf("\n");
  exit(0);
}

re : ALPHABET {
  temp[0] = yylval;
  temp[1] = '\0';
  /* Copy the input to the Prodcution Array */
  strcpy(productions[count++], temp);
} /* Only conditions defined here will be valid, this is the structure. */
| '(' re ')' /* Adds the (expression) to the Production Array */
{ strcpy(productions[count++], "( re )"); }
| re '*'
{ strcpy(productions[count++], "re *"); }
| re '+' /* Adds expression+ type to the Production Array */
{ strcpy(productions[count++], "re +"); }
| re '|' re /* Adds the expression|expression to the Production Array */
{ strcpy(productions[count++], "re | re"); }
| re '.' re /* Adds the expression.expression to the Production Array */
{ strcpy(productions[count++], "re . re"); }
;

%%

int main(int argc, char *argv[]) {
  /* Parse and output the rightmost derivation,
  from which we can get the parse tree */

  printf("Enter an expression:\n");

  /* Calls the Parser */
  yyparse();

  return 0;
}

/* Calls lex and takes each character as input and feeds ALPHABET to check for the structure */
int yylex() {
  signed char ch = getchar();
  yylval = ch;

  if (isalpha(ch))
    return ALPHABET;

  return ch;
}

/* Function to alert user of invalid regular expressions */
int yyerror() {
  fprintf(stderr, "Invalid Regular Expression.\n");
  exit(1);
}

int getREindex(const char *str) {
  int i = strlen(str) - 1;
  for (; i >= 0; --i) {
    if (str[i] == 'e' && str[i - 1] == 'r')
    return i - 1;
  }
}
```

## Execution
```
yacc -d 12_RegularExpression.y
cc y.tab.c y.tab.h -w
./a.out
```

## Output
```
Enter an expression:
a+|b*|(b.c*)

This is the rightmost derivation:

re => re | re
 => re | ( re )
 => re | ( re . re )
 => re | ( re . re * )
 => re | ( re . c * )
 => re | ( b . c * )
 => re | re | ( b . c * )
 => re | re * | ( b . c * )
 => re | b * | ( b . c * )
 => re + | b * | ( b . c * )
 => a + | b * | ( b . c * )
```
