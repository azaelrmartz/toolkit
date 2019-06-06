%{

#include <stdio.h>
#include <stdlib.h>


#include "common.h"

typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern int yylex();
extern int yyparse(struct octetos_toolkit_common_Version* version);
extern YY_BUFFER_STATE yy_scan_string(char * str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

void yyerror(struct octetos_toolkit_common_Version* ver,const char* s);



%}

%union {
	short shortVal;
	unsigned long ulVal;
	const char* strVal;
}

%parse-param {struct octetos_toolkit_common_Version* ver}

%token<shortVal> NUMBER
%token<ulVal> BUILD
%token<strVal> WORD
%token END DOT


%start version

%%

version : numbers end | numbers build end | numbers build name end;

numbers : one_number | two_numbers | tree_numbers | four_numbers ;

        one_number : NUMBER
	{
	    ver->major = $1;
	}
	;

        two_numbers : NUMBER DOT NUMBER
	{
	    ver->major = $1;
	    ver->minor = $3;
	}
	;

        tree_numbers : NUMBER DOT NUMBER DOT NUMBER
	{
                ver->major = $1;
                ver->minor = $3;
                ver->patch = $5;
	}
	;

        four_numbers : NUMBER DOT NUMBER DOT NUMBER DOT NUMBER
	{
	    ver->major = $1;
	    ver->minor = $3;
	    ver->patch = $5;
	    ver->tweak = $7;
	}
	;

build : BUILD
	{
	    ver->build = $1;
	}
	;

name : WORD;

end : END;


%%

void  octetos_toolkit_common_Version_fromString(const char* string, struct octetos_toolkit_common_Version* ver)
{
	YY_BUFFER_STATE buffer = yy_scan_string(string);
        yyparse(ver);
	yy_delete_buffer(buffer);       
}

void yyerror(struct octetos_toolkit_common_Version* version,const char* s) 
{
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
