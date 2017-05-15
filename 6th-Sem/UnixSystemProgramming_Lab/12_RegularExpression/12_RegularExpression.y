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
  
  for (; i >= 0; --i)
    if (str[i] == 'e' && str[i - 1] == 'r')
      return i - 1;
}
