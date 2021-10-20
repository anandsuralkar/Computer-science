%{
#include<stdio.h>
int counter = 0;
%}
%%
[a-z A-Z]+ {
if (yyleng > counter){
counter = yyleng;
}
}
%%
int main()
{
yylex();
printf("largest: %d", counter);
return 0;
}

