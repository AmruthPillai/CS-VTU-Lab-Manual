%{
	int a[4]={0,0,0,0};
	int valid=1,i;
	int nop=0;
%}

%x OPER

%%
[a-zA-Z0-9]+ {BEGIN OPER;nop++;}                                                             
"+" {if(valid) {valid=0;i=0;}else ext();}
"-" {if(valid) {valid=0;i=1;}else ext();}
"*" {if(valid) {valid=0;i=2;}else ext();}
"/" {if(valid) {valid=0;i=3;}else ext();}
[a-zA-Z0-9]+ {nop++;if(valid==0){valid=1;a[i]++;}else ext();}
. {if(valid){valid=0;ext();}else return 0;}
\n {if(valid==0){ext();}else return 0;}
%%

int ext()
{
    printf("Invalid expression\n");
    exit(0);
}

int main()
{
    printf("Enter expression\n");
    yylex();
    printf("Expression is valid\n");
    printf("No. of '+' is:%d\n",a[0]);
    printf("No. of '-' is:%d\n",a[1]);
    printf("No. of '*' is:%d\n",a[2]);
    printf("No. of '/' is:%d\n",a[3]);
    printf("No. of operands is:%d\n",nop);
    return 0;
}