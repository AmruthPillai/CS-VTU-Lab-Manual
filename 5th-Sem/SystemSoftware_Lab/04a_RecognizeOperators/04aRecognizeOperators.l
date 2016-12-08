%{
#include "y.tab.h"
%}

%%

[0-9]+ { return NUMBER; }
[_a-zA-Z][_a-zA-Z0-9]* { return ID; }
\n { return 0; }
. { return yytext[0]; }

%%
