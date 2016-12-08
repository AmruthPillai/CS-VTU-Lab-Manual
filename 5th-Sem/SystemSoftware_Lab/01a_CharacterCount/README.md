## Aim
Program to count the number of characters, words, spaces and lines in a given input file.

## Description
We have the command 'wc' in UNIX which gives us all the number of characters, number of words, number of lines. We are expected to develop a similar utility which does the same using flex.

## Code
```
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

    printf("Character Count:\t%d\n", char_count);
    printf("Word Count:\t\t%d\n", word_count);
    printf("Line Count:\t\t%d\n", line_count);
    printf("Space Count:\t\t%d\n", space_count);

    return 0;
}

int yywrap() {
    return 1;
}
```

## Execution
```
lex 01aCharacterCount.l
gcc lex.yy.c
./a.out
```

## Output
```
Enter the filename: lex.yy.c
Character Count:        44595
Word Count:             34281
Line Count:             1763
Space Count:            19646
```
