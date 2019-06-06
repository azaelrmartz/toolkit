%{
/* C++ string header, for string ops below */
#include <string>

/* Implementation of yyFlexScanner */ 
#include "scanner.hpp"
#include "common.hpp"
#undef  YY_DECL
#define YY_DECL int toolkit::Scanner::yylex( toolkit::Parser::semantic_type * const lval, toolkit::Parser::location_type *loc )

/* typedef to make the returns for the tokens shorter */
using token = toolkit::Parser::token;

/* define yyterminate as this instead of NULL */
#define yyterminate() return( token::END )

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option debug
%option nodefault
%option yyclass="toolkit::Scanner"
%option noyywrap
%option c++

DIGIT	[0-9]
CHAR	[a-zA-Z]
WORD	[a-zA-Z]+

%%
%{          /** Code executed at the beginning of yylex **/
            yylval = lval;
%}

{DIGIT}{1,11}  	{
		    printf("Number: %s\n", yytext);
		    return token::NUMBER;
		}
{DIGIT}{12,14}  {
		    printf("Build: %s\n", yytext);
		    return token::BUILD;
		}
{WORD} 		{
		    printf("WORD: %s\n", yytext);
		    return token::WORD;
		}	
\. 		{
		    printf("Dot: %s\n", yytext);
		    return token::DOT;
		}	
		
[\n\0]		{
		    printf("Fin %s\n", yytext);
		    return token::END;
		}

. 		 {
                        printf("Ignorando: '%s'\n", yytext);
                }


%%


