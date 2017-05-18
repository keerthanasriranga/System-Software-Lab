%{
#include<stdio.h>
int words,letters,spaces,lines,specialchar,numbers;
%}
%%
[a-zA-Z] {letters++;}
['\n'] {words++;lines++;}
[' '] {words++;spaces++;}
[0-9] {numbers++;}
. {specialchar++;}
%%
int yywrap(){return 1;}

void main()
{
yyin = fopen("input.dat","r");
yylex();
printf("Number of words are %d",words);
printf("Number of are letters %d",letters);
printf("Number of spaces are %d",spaces);
printf("Number of lines are %d",lines);
printf("Number of special characters are %d",specialchar);
printf("Number of numbers are %d",numbers);
}
