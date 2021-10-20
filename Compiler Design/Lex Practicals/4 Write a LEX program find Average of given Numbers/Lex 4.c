%{
#include<stdio.h>
#include<math.h>
int sum=0,n=0;
%}
%%
[0-9] { sum = sum +  atoi(yytext);
n++;}
\n return sum;
%%
int main()
{
printf("avarage is %d ",yylex()/n);
return 0;
}

