%{
int id_count;
char infile[30];
%}

ID [_a-zA-Z][_a-zA-Z0-9]*
DECL "int "|"float "|"char "|"double "

%x DEFN

%%

{DECL} BEGIN DEFN;
<DEFN>{ID}, { id_count++; }
<DEFN>{ID}; { id_count++; BEGIN 0; }
. ;

%%

int main(int argc, char *argv[]) {
	printf("Enter filename: ");
	scanf("%s", infile);

	yyin = fopen(infile, "r");
	yylex();

	printf("\nThe total number of identifiers:\t%d", id_count);
	return 0;
}

int yywrap() {
	return 1;
}
