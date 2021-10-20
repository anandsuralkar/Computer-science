  
%{
    /* Definition section */
    #include<stdio.h>
    #include<math.h>
    int num, decimal,i;
    char a[20];
%}
/* Rule Section */
%%

[0-7]+ { num=atoi(yytext);
	i=0;
        while(num!=0)
        {
		decimal =  decimal +(num % 10)* pow(8, i++);
        	num= num/ 10;
    	}
}
 

.|\n    ECHO;
         
%%
  
// driver code

int main()
{
    yylex();
    printf("\n octal %d  to Decimal  %d",num,decimal);

    return 0;
}      
int yywrap(){return(1);}
