%{
#include<stdio.h>
int comm;
%}
%s COMMENT
%%
"/*"[.]"*/" {comm++;}
"/*" {BEGIN COMMENT;}
<COMMENT>"*/" {BEGIN 0;comm++;}
<COMMENT>\n {comm++;}
<COMMENT>. {;}
\/\/.* {comm++;} 
.|\n {;}
%%
int yywrap(){return 1;}

void main()
{
yyin = fopen("input.dat","r");
yylex();
printf("Number of comment lines are %d",comm);
}
