%{
#include <stdlib.h>
int count = 0;
%}

%name parse
%token A B

%%
S:X B
X:X A { count++; }
| ;
%%

int yyerror() {
	printf("Invalid Grammar.\n");
	exit(0);
}

int main(int argc, char *argv[]) {
	printf("Enter a string of a's & b's: ");
	yyparse();
	if (count >= 10) {
		printf("Valid Grammar.\n");
	} else {
		printf("Invalid Grammar.\n");
	}
}
