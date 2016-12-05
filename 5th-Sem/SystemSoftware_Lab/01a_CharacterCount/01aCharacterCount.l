%{
int char_count = 0, word_count = 0, line_count = 0, space_count = 0;
char infile[30];
%}
%%
[^ \t\n]+ { word_count++; char_count+=yyleng; }
\n { line_count++; char_count++; }
\t { space_count+=8; char_count++; }
" " { space_count++; char_count++; }
%%
int main() {
        printf("Enter filename: ");
        scanf("%s", infile);

        yyin = fopen(infile, "r");
        yylex();

        fclose(yyin);
        printf("Line count is %d.\n", line_count);
        printf("Word count is %d.\n", word_count);
        printf("Space count is %d.\n", space_count);
        printf("Character count is %d.\n", char_count);

        return 0;
}

int yywrap() {
        return 1;
}
