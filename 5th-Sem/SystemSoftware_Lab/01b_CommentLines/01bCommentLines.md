## Aim
Program to count the numbers of comment lines in a given C program.
Also eliminate them and copy the resulting program into separate file.
## Description
The central idea of the program is to develop a code which can count all the single line comments and the multiple line comments and give the total count. Also we should be able to generate a copy of the original C file without the comment lines.

## Code
```
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
```

###OUTPUT:
```
./a.out lex.yy.c lex.yy.txt
Number of comments in the file is 108.
```
