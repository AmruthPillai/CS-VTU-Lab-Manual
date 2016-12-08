## Aim
Program to recognize a valid arithmetic expression and to recognize the identifiers and operators present. Print them separately.

## Description
Following the syntax for defining an identifier we generate arithmetic expressions using basic arithmetic operators such as +, -, * & /.

## Code
```
%{
int op_count, br_count, id_count, a[4] = {0, 0, 0, 0};
%}

%%

"+" { a[0]++; }
"-" { a[1]++; }
"*" { a[2]++; }
"/" { a[3]++; }
"(" { br_count++; }
")" { br_count--; }
[a-zA-Z0-9]+ { id_count++; printf("Identifier Found: %s\n", yytext); }
\n { return 0; }

%%

int main(int argc, char *argv[]) {
	printf("Enter the expression: ");

	yylex();

	printf("\nOperator Count:\n");
	printf("Addition:\t%d\nSubtraction:\t%d\nMultiplication:\t%d\nDivision:\t%d\n", a[0], a[1], a[2], a[3]);
	printf("Number of Identifiers:\t%d\n", id_count);

	op_count = a[0] + a[1] + a[2] + a[3];

	if (op_count >= id_count || br_count != 0 || id_count == 1)
		printf("\nIt is an invalid expression!\n");
	else
		printf("\nIt is a valid expression!\n");

	return 0;
}

int yywrap() {
	return 1;
}
```

## Execution
```
lex 02aRecognizeIdentifiers.l
gcc lex.yy.c
./a.out
```

## Output
#### Test Case 1: Valid
```
Enter the expression: a+b-c*(d/e)/f-g+h
Identifier Found: a
Identifier Found: b
Identifier Found: c
Identifier Found: d
Identifier Found: e
Identifier Found: f
Identifier Found: g
Identifier Found: h

Operator Count:
Addition:       2
Subtraction:    2
Multiplication: 2
Division:       2
Number of Identifiers:  8

It is a valid expression!
```

#### Test Case 2: Invalid
```
Enter the expression: a+b-c/
Identifier Found: a
Identifier Found: b
Identifier Found: c

Operator Count:
Addition:       1
Subtraction:    1
Multiplication: 0
Division:       1
Number of Identifiers:  3

It is an invalid expression!
```
