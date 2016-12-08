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
