%token ID NUMBER NL
%left '+' '-'
%left '/' '*'
%%
stmt:exp NL {printf("Valid expression");exit(0);}
;
exp: exp '+' exp
|
exp '-' exp
|
exp '*' exp
| 
exp '/' exp
|
'(' exp ')'
|
ID
|
NUMBER
;
%%
int yyerror(char *msg){printf("Invalid expression");return 0;}
void main()
{
printf("Enter expression");
yyparse();
}
