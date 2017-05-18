%token UND NUMBER LETTER NL
%%
stmt : variable NL {printf("Valid identifier"); exit(0);}
;
variable : LETTER alphanumeric
;
alphanumeric : LETTER alphanumeric
|
NUMBER alphanumeric
|
UND alphanumeric
|
UND
|
NUMBER
|
LETTER
;
%%
int yyerror(char *msg) {printf("Invalid Identifier"); return 0;}
void main()
{
printf("enter\n");
yyparse();
}
