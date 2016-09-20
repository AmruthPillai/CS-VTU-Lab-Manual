%{
	#include"y.tab.h"
%}

%option noyywrap

%%
a return A;
b return B;
. return yytext[0];
\n return 0;
%%
