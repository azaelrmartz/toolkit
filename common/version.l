%option noyywrap

%{
#include <stdio.h>

#include "version.tab.h"

#define YY_DECL int yylex()


%}

DIGIT	[0-9]
CHAR	[a-zA-Z]
WORD	[a-zA-Z]+


%%

{DIGIT}{1,11}  	{
		    //printf("Saw an Number: %s\n", yytext);
		    return NUMBER;
		}
{DIGIT}{12,14}  {
		    //printf("Saw an Build: %s\n", yytext);
		    return BUILD;
		}
{WORD} 		{
		    //printf("Saw an WORD: %s\n", yytext);
		    return WORD;
		}	
\. 		{
		    //printf("Saw an Dot: %s\n", yytext);
		    return DOT;
		}	

[\n\0]		{
		    //printf("Saw an Fin de Linea %s\n", yytext);
		    return END;
		}

. 		{}
%%

/*int main(void)
{
    yylex();
    return 0;
}*/
