%option noyywrap

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "common.h"
#include "driver.h"

#define YY_DECL int yylex(struct Tray* ty)
extern int parse_string(struct Tray* ty,const char* in);

#include "parser.tab.h"
//extern YYSTYPE yylval;
%}


DIGIT	[0-9]
NAME	[a-zA-Z0-9]+
SPACE [ \t\r]


%%
%{          /** Code executed at the beginning of yylex **/
            BEGIN(INITIAL);
%}

"valid"     {
				//std::cout << yytext << std::endl;
				// yylval->build< std::string >( atoi(yytext) );
				return VALID;
	}
                                
"numbers"		{
					//std::cout << yytext << std::endl;
					//yylval->build< std::string >( atoi(yytext) );
					return FIELDNAME_NUMBERS;
			}

"stage"                {
                                        //std::cout << yytext << std::endl;
                                        //yylval->build< std::string >( atoi(yytext) );
                                        return FIELDNAME_STAGE;

                                }
"build"                 {
                                        //std::cout << yytext << std::endl;
                                        //yylval->build< std::string >( atoi(yytext) );
                                        return FIELDNAME_BUILD;

                                }
"name"                 {
                                        //std::cout << yytext << std::endl;
                                        //yylval->build< std::string >( atoi(yytext) );
                                        return FIELDNAME_NAME;

                                }
"="                 {
                                        ///std::cout << yytext << std::endl;
                                        //yylval->build< std::string >( atoi(yytext) );
                                        return EQUAL;

                                }                                


"."     {
		//std::cout << yytext << std::endl;
		return DOT;
	}
	
"-"        	{
                                //std::cout <<yytext << std::endl;
                                return DASH;
                }

"snapshot"|"SNAPSHOT"  {
                                        //std::cout << yytext << std::endl;
                                yylval.stage=snapshot;
                                return VALUE_SNAPSHOT;
                                }
"prealpha"|"PREALPHA" {
                                        //std::cout << yytext << std::endl;
                                yylval.stage=prealpha;
                                return VALUE_PREALPHA;
                                }
"alpha"|"ALPHA"		{
                                        //std::cout << yytext << std::endl;
                                yylval.stage=alpha;
                                return VALUE_ALPHA;
                                }
"beta"|"BETA"     	{
                                        //std::cout << yytext << std::endl;
                                yylval.stage=beta;return VALUE_BETA;
                                }
"betar"|"betarelease"|"BETAR"|"BETARELEASE"    	{
			//std::cout << yytext << std::endl;
			yylval.stage=betarelease;return VALUE_BETARELEASE;
		}
"rc"|"RC"       	{
                                        //std::cout << yytext << std::endl;
                                        yylval.stage=rc;
                                        return VALUE_RC;
                        }
"prerelease"|"PRERELEASE"  	{
                                        //std::cout << yytext << std::endl;
                                yylval.stage=prerelease;
                                return VALUE_PRERELEASE;
                                }
"release"|"RELEASE"  	{
                                        //std::cout << yytext << std::endl;
                                yylval.stage=release;
                                return VALUE_RELEASE;
                        }
"RTM"  	{
                                        //std::cout << yytext << std::endl;
                                yylval.stage=rtm;
                                return VALUE_RTM;
                                }                                
"GA"  	{
                                        //std::cout << yytext << std::endl;
                                yylval.stage=ga;return VALUE_GA;
                                }
";"                     {
                                        //std::cout << yytext << std::endl;
                                        return SEMICOLON;
                                }

                                
{DIGIT}{1,11}  	{
                                        //printf("%s\n",yytext); 
                                        yylval.sval=(short)atoi(yytext);
                                        return VALUE_NUMBER;
                                }
			
{DIGIT}{14}                  {
                                                        //std::cout << "Build : " << yytext << std::endl;
                                                        yylval.ulval=strtoul(yytext, NULL, 0);
                                                        return VALUE_BUILD;                                                                        
                                                }

{NAME}  	{
                                //std::cout << "Name: " << yytext << std::endl; 
                                yylval.str=yytext; 
                                return VALUE_NAME;
                        }


{SPACE}+	;

[\n\0]		{
                                        //std::cout << "En of line" << std::endl; 
                        return ENDLINE;
                        }
.          	            {
                                        yylval.str=yytext; 
                                        return NOEXPECTED;
                                }
<<EOF>>    {
                                        //std::cout << "En of file" << std::endl; 
                                return ENDFILE;
                        }

%%
void set_input_string(const char* in) {
  yy_scan_string(in);
}

void end_lexical_scan(void) {
  yy_delete_buffer(YY_CURRENT_BUFFER);
}

