%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {octetos::toolkit}
%define parser_class_name {Parser}

%code requires{
namespace octetos 
{
	namespace toolkit
	{
		class Driver;
		class Scanner;
	}
}

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%param {Scanner& scanner}
%param {Driver& drv}

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
   #include "driver.hpp"

#undef yylex
#define yylex scanner.yylex
}

%define api.value.type variant
//%define parse.assert
%verbose

%token
  //DOT
  //DASH
  //PLUS
  ENDLINE
  SEMICOLON
  ENDFILE
;

%token VALUE_DEVELOPING
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
%token <std::string> VALUE_NAME
%token <short> VALUE_NUMBER
%token <std::string> VALUE_BUILD
%token <std::string> NOEXPECTED

%token VALID 
%token FIELDNAME_NUMBERS
%token FIELDNAME_STAGE
%token FIELDNAME_BUILD
%token FIELDNAME_NAME 
%token EQUAL    

%locations

%%
%start stmt;

	stmt : version ENDFILE
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
	;

	numbers_value : one_number | two_numbers | three_numbers;

	one_number : VALUE_NUMBER
	{
			drv.getVersion().setNumbers($1);
	};
	two_numbers : VALUE_NUMBER '.' VALUE_NUMBER
	{
		drv.getVersion().setNumbers($1,$3);
	};
	three_numbers : VALUE_NUMBER '.' VALUE_NUMBER '.' VALUE_NUMBER
	{
		drv.getVersion().setNumbers($1,$3,$5);
	};

	stage : 
	'-' VALUE_DEVELOPING
	{
			drv.getVersion().setStage(octetos::toolkit::Version::developing);
	}
	| 
	'-' VALUE_SNAPSHOT
	{
			drv.getVersion().setStage(octetos::toolkit::Version::snapshot);
	}
	| 
	'-' VALUE_PREALPHA
	{
			drv.getVersion().setStage(octetos::toolkit::Version::prealpha);
	}
	| 
	'-' VALUE_ALPHA
	{
			drv.getVersion().setStage(octetos::toolkit::Version::alpha);
	}
	| 
	'-' VALUE_BETA
	{
			drv.getVersion().setStage(octetos::toolkit::Version::beta);
	} 
	|
	'-' VALUE_BETARELEASE
	{
			drv.getVersion().setStage(octetos::toolkit::Version::betar);
	}
	| 
	'-' VALUE_RC
	{
			drv.getVersion().setStage(octetos::toolkit::Version::rc);
	}
	| 
	'-' VALUE_PRERELEASE
	{
			drv.getVersion().setStage(octetos::toolkit::Version::prerelease);
	}
	| 
	'-' VALUE_RELEASE
	{
			drv.getVersion().setStage(octetos::toolkit::Version::release);
	}
	| 
	'-' VALUE_RTM
	{
			drv.getVersion().setStage(octetos::toolkit::Version::rtm);
	}
	| 
	'-' VALUE_GA
	{
			drv.getVersion().setStage(octetos::toolkit::Version::ga);
	}
	;

	build : 
	'+' VALUE_BUILD
	{
		//drv.getVersion().setBuild($2);      
			//std::cout << "Build = " << $1 << std::endl;
	};


%%


void 
octetos::toolkit::Parser::error( const location_type &l, const std::string &err_message )
{
   if(drv.getAnnounceError())std::cerr << "Error: " << err_message << " at " << l << "\n";
}
