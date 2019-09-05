%{

#include <stdio.h>
#include <stdlib.h>

#include "../../common.h"
#include "../driver.h"

extern int yylex(struct Tray* ty);
extern int yyparse(struct Tray* ty);
extern int parse_string(struct Tray* ty, const char* in);
extern FILE* yyin;

void yyerror(struct Tray* ty, const char* s);
void set_input_string(const char* in);
void end_lexical_scan(void);
%}

%lex-param {struct Tray* ty}
%parse-param {struct Tray* ty}

%union {
	short sval;
	unsigned long ulval;
	const char* str;
}

%token
  DOT
  DASH
  ENDLINE
  SEMICOLON
  ENDFILE
;

%token VALUE_SNAPSHOT
%token VALUE_PREALPHA
%token VALUE_ALPHA
%token VALUE_BETA
%token VALUE_BETARELEASE
%token VALUE_RC 
%token VALUE_PRERELEASE 
%token VALUE_RELEASE 
%token VALUE_RTM
%token VALUE_GA
%token <const char*> VALUE_NAME
%token <short> VALUE_NUMBER
%token <unsigned long> VALUE_BUILD
%token <const char*> NOEXPECTED

%token VALID 
%token FIELDNAME_NUMBERS
%token FIELDNAME_STAGE
%token FIELDNAME_BUILD
%token FIELDNAME_NAME 
%token EQUAL    

%locations

%%
%start stmt;

	stmt : version end
	{
		YYACCEPT;
	}
	|
	version_list end
	{
		YYACCEPT;
	}
	| 
	valid end
	{
		YYACCEPT;
	};

	version : 
	numbers_value
	{
	}
	|
	numbers_value stage
	{
	}
	| 
	numbers_value stage build
	{
	}
	| 
	numbers_value stage build name
	{
	}

	version_list : | version SEMICOLON  version_list

	numbers_value : one_number | two_numbers | three_numbers;

	one_number : VALUE_NUMBER
	{
		//drv.getVersion().setNumbers($1);
	};
	two_numbers : VALUE_NUMBER DOT VALUE_NUMBER
	{
		//drv.getVersion().setNumbers($1,$3);
	};
	three_numbers : VALUE_NUMBER DOT VALUE_NUMBER DOT VALUE_NUMBER
	{
		ty->version.major = $1;
		ty->version.minor = $3;
		ty->version.patch = $5;
		printf("N1: %d\n",ty->version.major);
	};

	stage : DASH VALUE_SNAPSHOT
	{
			//drv.getVersion().setStage(octetos::toolkit::Version::snapshot);
	}
	| 
	DASH VALUE_PREALPHA
	{
			//drv.getVersion().setStage(octetos::toolkit::Version::prealpha);
	}
	| 
	DASH VALUE_ALPHA
	{
			//drv.getVersion().setStage(octetos::toolkit::Version::alpha);
	}
	| 
	DASH VALUE_BETA
	{
			//drv.getVersion().setStage(octetos::toolkit::Version::beta);
	} 
	|
	DASH VALUE_BETARELEASE
	{
			//drv.getVersion().setStage(octetos::toolkit::Version::betarelease);
	}
	| 
	DASH VALUE_RC
	{
			//drv.getVersion().setStage(octetos::toolkit::Version::rc);
	}
	| 
	DASH VALUE_PRERELEASE
	{
			//drv.getVersion().setStage(octetos::toolkit::Version::prerelease);
	}
	| 
	DASH VALUE_RELEASE
	{
			//drv.getVersion().setStage(octetos::toolkit::Version::release);
	}
	| 
	DASH VALUE_RTM
	{
			//drv.getVersion().setStage(octetos::toolkit::Version::rtm);
	}
	| 
	DASH VALUE_GA
	{
			//drv.getVersion().setStage(octetos::toolkit::Version::ga);
	}
	;

	build : VALUE_BUILD
	{
		//drv.getVersion().setBuild($1);      
			//std::cout << "Build = " << $1 << std::endl;
	};

	name : VALUE_NAME
	{
		//drv.getVersion().setName($1);
		//std::cout << "Name = " << $1 << std::endl;
	};

	end : ENDLINE | ENDFILE | SEMICOLON
	{
	};

	valid : VALID FIELDNAME_NUMBERS EQUAL numbers_value 
	{
	}
	|
	VALID FIELDNAME_STAGE EQUAL stage_values 
	{
	}
	|
	VALID FIELDNAME_BUILD EQUAL VALUE_BUILD 
	{
	}
	|
	VALID  FIELDNAME_NAME EQUAL VALUE_NAME
	{
	};
	
	stage_values : VALUE_SNAPSHOT | VALUE_PREALPHA | VALUE_ALPHA | VALUE_BETA  | VALUE_BETARELEASE | VALUE_RC | VALUE_PRERELEASE | VALUE_RTM | VALUE_GA
	{
		
	};

%%
void yyerror(struct Tray* ty,const char* s) {
	//if(ty.getAnnounceError())
	fprintf(stderr, "Parse error: %s\n", s);
}
int parse_string(struct Tray* ty,const char* in) {
  set_input_string(in);
  int rv = yyparse(ty);
  end_lexical_scan();
  return rv;
}

