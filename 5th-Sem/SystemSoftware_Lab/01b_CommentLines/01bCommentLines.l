%{
int comment_count;
char infile[30], outfile[30];
%}

%x COMMENT

%%

"//".* { comment_count++; }
"/*".* { BEGIN COMMENT; }
<COMMENT>. ;
<COMMENT>"*/" { comment_count++; BEGIN 0; }

%%

int main(int argc, char *argv[]) {
	printf("Enter the input filename: ");
	scanf("%s", infile);
	printf("Enter the output filename: ");
	scanf("%s", outfile);

	yyin = fopen(infile, "r");
	yyout = fopen(outfile, "w");
	yylex();

	printf("Number of comments in the file:\t%d", comment_count);
	return 0;
}

int yywrap() {
	return 1;
}
