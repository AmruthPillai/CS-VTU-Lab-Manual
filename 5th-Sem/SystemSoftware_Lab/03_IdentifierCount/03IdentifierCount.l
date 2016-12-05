%{
int id_count;
char infile[30];
%}
ID [a-zA-Z][a-zA-Z0-9]+
DECL "int "|"float "|"char "|"double "
%x DEFN
%%
{DECL} BEGIN DEFN;
<DEFN>{ID}, { id_count++; }
<DEFN>{ID}; { id_count++; BEGIN 0; }
. ;
%%
int main() {
	printf("Enter filename: ");
	scanf("%s", infile);
	yyin = fopen(infile, "r");
	
	yylex();

	printf("\nThe total number of identifiers: %d\n", id_count);
	return 0;
}

int yywrap() {
	return 1;
}
