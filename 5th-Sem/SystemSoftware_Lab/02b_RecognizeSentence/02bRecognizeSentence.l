%{
	int valid = 1;
%}
id [a-zA-Z0-9]*
%%
{id}" and "{id} { valid = 0; }
{id}" or "{id} { valid = 0; }
{id}" but "{id} { valid = 0; }
{id}" between "{id} { valid = 0; }
\n { return 0; }
. ;
%%

int main(int argc, char *argv[]) {
	printf("Enter a sentence: ");
	yylex();
	if (valid)
		printf("It's a simple sentence!\n");
	else
		printf("It's a compound sentence!\n");
}

int yywrap() {
	return 1;
}