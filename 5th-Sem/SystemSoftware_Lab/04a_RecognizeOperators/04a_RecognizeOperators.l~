%{
	#include "y.tab.h"
%}

%option noyywrap

%%
[0-9]+                  return NUMBER;
[a-zA-Z][a-zA-Z0-9]*    return ID;
.                       return yytext[0];
\n                      return 0;
%%
