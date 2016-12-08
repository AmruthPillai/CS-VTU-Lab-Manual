%{
int char_count, word_count, line_count, space_count;
char infile[30];
%}

%%

[^ \t\n] { word_count++; char_count+=yyleng; }
" " { space_count++; char_count++; }
\t { space_count+=8; char_count++; }
\n { line_count++; char_count++; }

%%

int main(int argc, char *argv[]) {
    printf("Enter the filename: ");
    scanf("%s", infile);

    yyin = fopen(infile, "r");
    yylex();
    fclose(yyin);

    printf("Character Count:\t%d\n", char_count);
    printf("Word Count:\t\t%d\n", word_count);
    printf("Line Count:\t\t%d\n", line_count);
    printf("Space Count:\t\t%d\n", space_count);

    return 0;
}

int yywrap() {
    return 1;
}
