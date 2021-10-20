%{
        #include<stdio.h>
        int lines=0, spaces=0, words=1, c_char=0;
%}

%%
[\n] lines++;
[' '] spaces++, words++;
[^' '\n\t] c_char=c_char+yyleng;
%%

int main()
{
        yylex();
        printf("\n No. of total lines: %d", lines);
        printf("\n No of total words: %d", words);
        printf("\n No of total spaces: %d", spaces);
        printf("\n No of total characters: %d\n", c_char);
        return 0;

}

