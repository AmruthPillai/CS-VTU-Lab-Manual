%{
int line_count, word_count, space_count, char_count;
%}

%%
[^ \t\n]+ {word_count++;char_count+=yyleng;}
\n {line_count++;char_count++;}
" " {space_count++;char_count++;}
. {char_count++;}
%%

int main() {
	char filename[100];
	printf("Enter the filename: ");
	scanf("%s", &filename);
	yyin = fopen(filename, "r");
	yylex();
	fclose(yyin);
	printf("Line Count: %d\nWord Count: %d\nSpace Count: %d\nCharacter Count: %d\n", line_count, word_count, space_count, char_count);
	return 0;
}

int yywrap() {}
