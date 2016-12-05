%{
int valid = 1;
%}
id [a-zA-Z0-9]*
%%
{id}" and "{id} |
{id}" AND "{id} |
{id}" or "{id} |
{id}" OR "{id} |
{id}" but "{id} |
{id}" BUT "{id} { valid = 0; }
. ;
%%
int main() {
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
