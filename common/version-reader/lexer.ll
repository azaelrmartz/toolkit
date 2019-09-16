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



%%
%{          /** Code executed at the beginning of yylex **/
            yylval = lval;
%}
                        


"."     {
            //std::cout << yytext << std::endl;
            //yylval->build< std::string >( yytext );
            return yytext[0];
        }
"-"        	{
                //std::cout <<yytext << std::endl;
                //yylval->build< std::string >( yytext );
                return yytext[0];
            }
"+"        	{
                //std::cout <<yytext << std::endl;
                //yylval->build< std::string >( yytext );
                return yytext[0];
            }
"dev"|"devel"|"developing"|"DEVELOPING"  {
                                        //std::cout << yytext << std::endl;
                                yylval->build< std::string >( yytext );return token::VALUE_DEVELOPING;
                                }
"snapshot"|"SNAPSHOT"  {
                                        //std::cout << yytext << std::endl;
                                yylval->build< std::string >( yytext );return token::VALUE_SNAPSHOT;
                                }
"prealpha"|"PREALPHA" {
                                        //std::cout << yytext << std::endl;
                                yylval->build< std::string >( yytext );return token::VALUE_PREALPHA;
                                }
"a"|"alpha"|"ALPHA"		{
                                        //std::cout << yytext << std::endl;
                                yylval->build< std::string >( yytext );return token::VALUE_ALPHA;
                                }
"b"|"beta"|"BETA"     	{
                                        //std::cout << yytext << std::endl;
                                yylval->build< std::string >( yytext );return token::VALUE_BETA;
                                }
"br"|"betar"|"betarelease"|"BETAR"|"BETARELEASE"    	{
			//std::cout << yytext << std::endl;
			yylval->build< std::string >( yytext );return token::VALUE_BETARELEASE;
		}
"rc"|"RC"       	{
                                        //std::cout << yytext << std::endl;
                                        yylval->build< std::string >( yytext );return token::VALUE_RC;
                        }
"prerelease"|"PRERELEASE"  	{
                                        //std::cout << yytext << std::endl;
                                yylval->build< std::string >( yytext );return token::VALUE_PRERELEASE;
                                }
"r"|"release"|"RELEASE"  	{
                                        //std::cout << yytext << std::endl;
                                yylval->build< std::string >( yytext );return token::VALUE_RELEASE;
                                }
"RTM"  	{
                                        //std::cout << yytext << std::endl;
                                yylval->build< std::string >( yytext );return token::VALUE_RTM;
                                }                                
"GA"  	{
                                        //std::cout << yytext << std::endl;
                                yylval->build< std::string >( yytext );return token::VALUE_GA;
                                }
                                
[0-9]{1,5}  	{
                    //std::cout << yytext << std::endl; 
                    yylval->build< short >( atoi(yytext) );
                    return token::VALUE_NUMBER;
                }
			
[0-9]{14}       {
                    //std::cout << "Build : " << yytext << std::endl;
                    yylval->build< std::string >( yytext );
                    return token::VALUE_BUILD;                                                                        
            }
[a-zA-Z]+[a-zA-Z0-9\.]*       {
                        //std::cout << "Build : " << yytext << std::endl;
                        yylval->build< std::string >( yytext );
                        return token::VALUE_BUILD;                                                                        
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


