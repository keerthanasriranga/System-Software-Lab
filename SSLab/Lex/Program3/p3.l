%{
#include<stdio.h>
int valid=1,top=-1,coper=0,copnd=0,l=0,m=0;
char s[20],oper[10][10],opnd[10][10];
%}
%%
"{" {top++; s[top]='{';}
"(" {top++; s[top]='(';}
"]" {top++; s[top]=']';}
"}" {if(s[top]!='{') { valid=0;return;} else top--;}
")" {if(s[top]!='(') { valid=0;return;} else top--;}
"]" {if(s[top]!='[') { valid=0;return;} else top--;}
[0-9]+|[a-zA-Z][a-zA-Z0-9] { strcpy(opnd[l],yytext); copnd++;l++;}
[+|-|*|/] { strcpy(oper[m],yytext); coper++;m++;}
%%
int yywrap(){return 1;}
void main()
{
printf("Enter the expression\n");
yylex();
if(valid!=1){printf("Not a valid expression\n"); exit(0);}
else
{
printf("Valid expression");
for(int x=0;x<copnd;x++)printf("%s\t",opnd[x]);
for(int y=0;y<copnd;y++)printf("%s\t",oper[y]);
}
}
