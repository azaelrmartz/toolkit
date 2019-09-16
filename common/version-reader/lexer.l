%option noyywrap

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include <common.h>
#include "driver.h"

#define YY_DECL int yylex(struct Tray* ty)
//int parse_string(struct Tray* ty,const char* in);

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
                     

{DIGIT}{1,5}  	{
                                        //printf("%s\n",yytext); 
                                        yylval.sval=(short)atoi(yytext);
                                        return VALUE_NUMBER;
                                }

"."     {
		//std::cout << yytext << std::endl;
		return yytext[0];
	}
	
"-"     {
                                //std::cout <<yytext << std::endl;
                                return yytext[0];
                }

"dev"|"devel"|"developing"|"DEV"|"DEVEL"|"DEVELOPING"   {
                                yylval.stage=developing;
                                return VALUE_SNAPSHOT;
                                        
                            }
"snapshot"|"SNAPSHOT"  {
                                        //std::cout << yytext << std::endl;
                                yylval.stage=snapshot;
                                return VALUE_SNAPSHOT;
                        }
"a"|"alpha"|"ALPHA"		{
                                        //std::cout << yytext << std::endl;
                                yylval.stage=alpha;
                                return VALUE_ALPHA;
                                }

"b"|"beta"|"BETA"     	{
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
"r"|"release"|"RELEASE"  	{
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

"+"        	{
                //std::cout <<yytext << std::endl;
                //yylval->build< std::string >( yytext );
                //BEGIN(scPlus);
                return yytext[0];
            }

{DIGIT}{14}                  {
                                                        printf("build : %s\n",yytext);
                                                        yylval.ulval=strtoul(yytext, NULL, 0);
                                                        return VALUE_BUILD_UL;                                                                        
                                                }
[a-zA-Z]+[a-zA-Z0-9\.]* {
                            yylval.str = yytext;
                            return VALUE_BUILD_STRING;
}

[\0\n]            {
                        return ENDOFINPUT;
}
.          	            {
                                                        printf("build : %s\n",yytext);
                                        printf("invalid : %s\n",yytext);
                                        return NOEXPECTED;
                                }
<<EOF>>    {
                                        //std::cout << "En of file" << std::endl; 
                                return ENDOFINPUT;
                        }

%%
void set_input_string(const char* in) {
  yy_scan_string(in);
}

void end_lexical_scan(void) {
  yy_delete_buffer(YY_CURRENT_BUFFER);
}

