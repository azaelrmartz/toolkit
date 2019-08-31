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
#define yyterminate() return( token::ENDFILE )

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}


%option debug
%option perf-report
/*%option verbose*/
%option warn
%option backup

%option nodefault
%option yyclass="octetos::toolkit::Scanner"
%option noyywrap
%option c++
%option pointer

DIGIT	[0-9]
NAME	[a-zA-Z0-9]+
SPACE [ \t\r]

%x sc_NUMBERS
%x sc_STAGE
%x sc_BUILD
%x sc_NAME

%%
%{          /** Code executed at the beginning of yylex **/
            yylval = lval;
            BEGIN(INITIAL);
%}

"valid"                 {
                                        //std::cout << yytext << std::endl;
                                       // yylval->build< std::string >( atoi(yytext) );
                                        return token::VALID;
                                }
                                
"numbers"                {
                                        //std::cout << yytext << std::endl;
                                        //yylval->build< std::string >( atoi(yytext) );
                                        return token::FIELDNAME_NUMBERS;

                                }
"stage"                {
                                        //std::cout << yytext << std::endl;
                                        //yylval->build< std::string >( atoi(yytext) );
                                        return token::FIELDNAME_STAGE;

                                }
"build"                 {
                                        //std::cout << yytext << std::endl;
                                        //yylval->build< std::string >( atoi(yytext) );
                                        return token::FIELDNAME_BUILD;

                                }
"name"                 {
                                        //std::cout << yytext << std::endl;
                                        //yylval->build< std::string >( atoi(yytext) );
                                        return token::FIELDNAME_NAME;

                                }
"="                 {
                                        ///std::cout << yytext << std::endl;
                                        //yylval->build< std::string >( atoi(yytext) );
                                        return token::EQUAL;

                                }                                


"."        	{
                        //std::cout << yytext << std::endl;
                        BEGIN(sc_NUMBERS);
                        return token::DOT;
                }
"-"        	{
                                //std::cout <<yytext << std::endl;
                                BEGIN(sc_STAGE);
                                return token::DASH;
                }

"snapshot"  {
                                        //std::cout << yytext << std::endl;
                                        BEGIN(sc_STAGE);
                                yylval->build< std::string >( yytext );return token::VALUE_SNAPSHOT;
                                }
"pre-alpha"		{
                                        //std::cout << yytext << std::endl;
                                        BEGIN(sc_STAGE);
                                yylval->build< std::string >( yytext );return token::VALUE_PREALPHA;
                                }
"alpha"		{
                                        //std::cout << yytext << std::endl;
                                        BEGIN(sc_STAGE);
                                yylval->build< std::string >( yytext );return token::VALUE_ALPHA;
                                }
"beta"     	{
                                        //std::cout << yytext << std::endl;
                                        BEGIN(sc_STAGE);
                                yylval->build< std::string >( yytext );return token::VALUE_BETA;
                                }
"betar"|"betarelease"    	{
			//std::cout << yytext << std::endl;
			BEGIN(sc_STAGE);
			yylval->build< std::string >( yytext );return token::VALUE_BETARELEASE;
		}
"rc"       	{
                                        //std::cout << yytext << std::endl;
                                        BEGIN(sc_STAGE);
                                        yylval->build< std::string >( yytext );return token::VALUE_RC;
                        }
"prerelease"  	{
                                        //std::cout << yytext << std::endl;
                                        BEGIN(sc_STAGE);
                                yylval->build< std::string >( yytext );return token::VALUE_PRERELEASE;
                                }
"release"  	{
                                        //std::cout << yytext << std::endl;
                                        BEGIN(sc_STAGE);
                                yylval->build< std::string >( yytext );return token::VALUE_RELEASE;
                                }
"RTM"  	{
                                        //std::cout << yytext << std::endl;
                                        BEGIN(sc_STAGE);
                                yylval->build< std::string >( yytext );return token::VALUE_RTM;
                                }                                
"GA"  	{
                                        //std::cout << yytext << std::endl;
                                        BEGIN(sc_STAGE);
                                yylval->build< std::string >( yytext );return token::VALUE_GA;
                                }
";"                     {
                                        //std::cout << yytext << std::endl;
                                        return token::SEMICOLON;
                                }

                                
{DIGIT}{1,11}  	{
                                        //std::cout << yytext << std::endl; 
                                        BEGIN(sc_NUMBERS);
                                        yylval->build< int >( atoi(yytext) );
                                        return token::VALUE_NUMBER;
                                }
			
{DIGIT}{12,16}                  {
                                                        //std::cout << "Build : " << yytext << std::endl;
                                                        BEGIN(sc_BUILD);
                                                        yylval->build< unsigned long >( std::stoul(yytext) );
                                                        return token::VALUE_BUILD;                                                                        
                                                }

{NAME}  	{
                                //std::cout << "Name: " << yytext << std::endl; 
                                BEGIN(sc_NAME);
                                yylval->build< std::string >( yytext ); 
                                return token::VALUE_NAME;
                        }


{SPACE}+	;

[\n\0]		{
                                        //std::cout << "En of line" << std::endl; 
                        return token::ENDLINE;
                        }
.          	            {
                                        std::string msg = "El carecter '";
                                        msg += yytext;
                                        msg += "' no se esperaba.";
                                        yylval->build< std::string >( yytext ); 
                                        return token::NOEXPECTED;
                                }
<<EOF>>    {
                                        //std::cout << "En of file" << std::endl; 
                                return token::ENDFILE;
                        }

%%


