%token NUMBER NL
%left '+' '-'
%left '*' '/'
%%
stmt : exp NL {printf("%d\n",$1);exit(0);}
;
exp : exp '+' exp {$$ =$1+$3;}
|
exp '-' exp {$$=$1-$3;}
|
exp '*' exp {$$=$1*$3;}
|
exp '/' exp {if($3!=0)$$=$1/$3;else printf("invalid input");exit(0);}
|
'(' exp ')' { $$ = $2;}
|
NUMBER {$$=$1;}
;
%%
int yyerror(char *msg){printf("Invalid expression");return 1;}
void main()
{
printf("Enter expression");
yyparse();
}	
