%{
       // take number in words as input and print its number
       #include<stdio.h>
%}
%%
ZERO|zero printf("0");
ONE|one printf("1");
TWO|two printf("2");
THREE|three printf("3");
FOUR|four printf("4");
FIVE|five printf("5");
SIX|six printf("6");
SEVEN|seven printf("7");
EIGHT|eight printf("8");
NINE|nine printf("9");
%%
int main()
{
    yylex();
    return 0;
}

