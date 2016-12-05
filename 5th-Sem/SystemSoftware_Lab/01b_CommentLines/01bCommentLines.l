%{
int c;
char infile[30], outfile[30];
%}
%x COMMENT
%%
"//".* { c++; }
"/*".* { BEGIN COMMENT; }
<COMMENT>. ;
<COMMENT>\n ;
<COMMENT>"*/" { BEGIN 0; c++; }
%%
int main() {
	printf("Enter the input file: ");
	scanf("%s", infile);
	printf("Enter the output file: ");
	scanf("%s", outfile);
	
	yyin = fopen(infile, "r");
	yyout = fopen(outfile, "w");
	
	yylex();
	
	printf("Number of comments in the file is %d.\n", c);
	return 0;
}

int yywrap() {
	return 1;
}
