%{
int valid;
%}

w [a-zA-Z]+

%%

{w}" and "{w} |
{w}" AND "{w} |
{w}" or "{w} |
{w}" OR "{w} |
{w}" but "{w} |
{w}" BUT "{w} |
{w}" between "{w} |
{w}" BETWEEN "{w} { valid = 1; }
\n { return 0; }
. ;

%%

int main(int argc, char *argv[]) {
	printf("Enter a sentence: ");

	yylex();

	if (valid == 0)
		printf("It is a simple sentence!\n");
	else
		printf("It is a complex sentence!\n");

	return 0;
}

int yywrap() {
	return 1;
}
