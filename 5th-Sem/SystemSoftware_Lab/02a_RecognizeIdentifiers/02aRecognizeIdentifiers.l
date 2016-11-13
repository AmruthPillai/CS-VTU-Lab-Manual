%{
int a[4] = {0, 0, 0, 0};
int valid = 1, i;
int nop = 0;
%}
%x OPER
%%
[a-zA-Z0-9]+ { BEGIN OPER; nop++; }
"+" { if (valid) { valid = 0; i = 0; } else terminate(); }
"-" { if (valid) { valid = 0; i = 1; } else terminate(); }
"*" { if (valid) { valid = 0; i = 2; } else terminate(); }
"/" { if (valid) { valid = 0; i = 3; } else terminate(); }
[a-zA-Z0-9]+ { nop++; if (!valid) { valid = 1; a[i]++; } else terminate(); }
. { if (valid) { valid = 0; terminate(); } else return 0; }
\n { if (!valid) terminate(); else return 0; }
. terminate();
\n terminate();
%%

int terminate() {
	printf("Invalid Expression.");
	exit(0);
}

int main() {
	printf("Enter Expression: ");
	yylex();
	printf("Expression is Valid!");
	
	printf("No. of + is: %d\n", a[0]);
	printf("No. of - is: %d\n", a[1]);
	printf("No. of * is: %d\n", a[2]);
	printf("No. of / is: %d\n", a[3]);
	
	printf("No. of operands is: %d\n", nop);
	return 0;
}

int yywrap() {
	return 1;
}
