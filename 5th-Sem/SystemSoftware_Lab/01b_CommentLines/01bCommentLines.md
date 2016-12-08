## Aim
Program to count the numbers of comment lines in a given C program. Also eliminate them and copy the resulting program into separate file.

## Description
The central idea of the program is to develop a code which can count all the single line comments and the multiple line comments and give the total count. Also we should be able to generate a copy of the original C file without the comment lines.

## Code
```
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
```

## Execution
```
lex 01bCommentLines.l
gcc lex.yy.c
./a.out
```

## Output
```
Enter the input filename: lex.yy.c
Enter the output filename: lex.y.txt
Number of comments in the file: 106
```
