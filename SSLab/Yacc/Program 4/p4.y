%{
#include<stdio.h>
int valid=1;
%}
%token A B
%%
stmt :S'\n' {return 0;}
S : c S d
|
c: c A 
|
d : d B
|
;
%%
int yyerror(){printf("Invalid input");exit(0);}
void main()
{
printf("enter expression");
yyparse();
if(valid==1)printf("valid expression");
}
