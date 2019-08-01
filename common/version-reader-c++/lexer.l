%{
/* C++ string header, for string ops below */
#include <string>

/* Implementation of yyFlexScanner */ 
#include "scanner.hpp"
#undef  YY_DECL
#define YY_DECL int octetos::toolkit::Scanner::yylex(octetos::toolkit::Parser::semantic_type * const lval, octetos::toolkit::Parser::location_type *loc,octetos::toolkit::Scanner &scanner, octetos::toolkit::Driver& drv)

/* typedef to make the returns for the tokens shorter */
using token = octetos::toolkit::Parser::token;

/* define yyterminate as this instead of NULL */
#define yyterminate() return( token::END )

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option debug
%option nodefault
%option yyclass="octetos::toolkit::Scanner"
%option noyywrap
%option c++

DIGIT	[0-9]
NAME	[a-zA-Z][a-zA-Z0-9]*
SPACE [ \t\r]


%s sc_NUMBER
%s sc_DOT
%s sc_DASH
%s sc_STAGE
%s sc_BUILD
%s sc_NAME

%%
%{          /** Code executed at the beginning of yylex **/
            yylval = lval;
            BEGIN(INITIAL);
%}

{DIGIT}{1,11}  	{
                                        std::cout << "Number : " << yytext << std::endl; 
                                        yylval->build< int >( atoi(yytext) );
                                        return token::NUMBER;
                                }

"."        	{
                                                        std::cout << yytext << std::endl;
                                                        return token::DOT;
                                                }
"-"        	{
                                                                std::cout <<yytext << std::endl;
                                                                return token::DASH;
                                                        }

"snapshot"  {std::cout << "Stage : " << yytext << std::endl;yylval->build< std::string >( yytext );return token::SNAPSHOT;}
"alpha"		{std::cout << "Stage : " << yytext << std::endl;yylval->build< std::string >( yytext );return token::ALPHA;}
"beta"     	{std::cout << "Stage : " << yytext << std::endl;yylval->build< std::string >( yytext );return token::BETA;}
"rc"       	{std::cout << "Stage : " << yytext << std::endl;yylval->build< std::string >( yytext );return token::RC;}
"release"  	{std::cout << "Stage : " << yytext << std::endl;yylval->build< std::string >( yytext );return token::RELEASE;}
			
{DIGIT}{12,16}        {
                                                                        std::cout << "Build : " << yytext << std::endl;
                                                                        yylval->build< unsigned long >( std::stoul(yytext) );
                                                                        return token::BUILD;                                                                        
                                                                }

{NAME}  	{std::cout << "Nombre: " << yytext << std::endl; yylval->build< std::string >( yytext ); return token::NAME;}


{SPACE}+	;

[\n\0]		{return token::END;}
.          	            {
                                        ECHO;
                                }
<<EOF>>    	return token::END;

%%


