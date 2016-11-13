%token DIGIT ALPHA
%%
var:ALPHA
|var ALPHA
|var DIGIT
;
%%

int yyerror() {
	printf("Invalid Expression.\n");
	exit(0);
}

int main(int argc, char *argv[]) {
	printf("Enter the variable: ");
	yyparse();
	printf("Valid Variable.");
	return 0;
}

int yywrap() {
	return 1;
}