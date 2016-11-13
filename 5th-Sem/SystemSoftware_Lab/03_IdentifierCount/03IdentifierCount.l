%{
	int int_count = 0, float_count = 0, char_count = 0, double_count = 0;
%}
ID [a-zA-Z][a-zA-Z0-9]*
I "int"
F "float"
C "char"
D "double"
%s DEFN1
%s DEFN2
%s DEFN3
%s DEFN4
%%
\t ;
{I} { BEGIN DEFN1; }
<DEFN1>{ID}"," { int_count++; printf("%s\n", yytext); }
<DEFN1>{ID}";" { int_count++; BEGIN 0; printf("%s\n", yytext); }
{F} { BEGIN DEFN2; }
<DEFN2>{ID}"," { float_count++; printf("%s\n", yytext); }
<DEFN2>{ID}";" { float_count++; BEGIN 0; printf("%s\n", yytext); }
{C} { BEGIN DEFN3; }
<DEFN3>{ID}"," { char_count++; printf("%s\n", yytext); }
<DEFN3>{ID}";" { char_count++; BEGIN 0; printf("%s\n", yytext); }
{D} { BEGIN DEFN4; }
<DEFN4>{ID}"," { double_count++; printf("%s\n", yytext); }
<DEFN4>{ID}";" { double_count++; BEGIN 0; printf("%s\n", yytext); }
\n ;
. ;
%%

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Error.\n");
		return 0;
	}
	yyin = fopen(argv[1], "r");
	printf("The identifiers are:\n");
	yylex();
	
	printf("The no. of int identifiers are: %d\n", int_count);
	printf("The no. of float identifiers are: %d\n", float_count);
	printf("The no. of char identifiers are: %d\n", char_count);
	printf("The no. of double identifiers are: %d\n", double_count);
	
	return 0;
}

int yywrap() {
	return 1;
}