%{
#include "y.tab.c"
%}
%%
[0-9]+ {return NUMBER;}
[a-zA-Z]+ {return LETTER;}
[_] {return UND;}
\n {return NL;}
. {return yytext[0];}
%%
int yywrap(){return 1;}

