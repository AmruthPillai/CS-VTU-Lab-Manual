## Aim
Program to recognize whether a given sentence is simple or compound.

## Description
The user is expected to develop a code which recognizes a sentence as either simple or compound. The design considers that we use and, or, but & between. The user can specify more rules as per his/her choice.

## Code
```
%{
int valid;
%}

w [a-zA-Z]+

%%

{w}" and "{w} |
{w}" AND "{w} |
{w}" or "{w} |
{w}" OR "{w} |
{w}" but "{w} |
{w}" BUT "{w} |
{w}" between "{w} |
{w}" BETWEEN "{w} { valid = 1; }
\n { return 0; }
. ;

%%

int main(int argc, char *argv[]) {
	printf("Enter a sentence: ");

	yylex();

	if (valid == 0)
		printf("It is a simple sentence!\n");
	else
		printf("It is a complex sentence!\n");

	return 0;
}

int yywrap() {
	return 1;
}
```

## Execution
```
lex 02bRecognizeSentence.l
gcc lex.yy.c
./a.out
```

## Output
#### Test Case #1: Complex Sentence
```
Enter a sentence: Harry and Ron loved Hermione
It is a complex sentence!
```

#### Test Case #2: Simple Sentence
```
Enter a sentence: Bananas
It is a simple sentence!
```
