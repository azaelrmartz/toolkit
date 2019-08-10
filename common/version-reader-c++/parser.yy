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

%param {Scanner &scanner}
%param {Driver& drv }

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

%token
  DOT
  DASH
  END
;

%token SNAPSHOT
%token ALPHA
%token BETA
%token  RC 
%token RELEASE 
%token <std::string> VALUE_NAME
%token <int> VALUE_NUMBER
%token <unsigned long> VALUE_BUILD
%token <std::string> NOEXPECTED

%token VALID 
%token FIELD_NUMBERS
%token FIELD_STAGE
%token FIELD_BUILD
%token FIELD_NAME 
%token EQUAL    

%locations

%%
%start stmt;

stmt : version | valid ;

version : 
        numbers end
	{
		YYACCEPT;
	};
        |
        numbers stage  end 
	{
		YYACCEPT;
	};
        | 
        numbers stage build end
	{
		YYACCEPT;
	}; 
        | 
        numbers stage build name end
	{
		YYACCEPT;
	};

numbers : 
        firts_number | second_numbers | third_numbers
;

firts_number : VALUE_NUMBER
{
        drv.getVersion().setNumbers($1);
};

second_numbers : VALUE_NUMBER DOT VALUE_NUMBER
{
       drv.getVersion().setNumbers($1,$3);
};

third_numbers : VALUE_NUMBER DOT VALUE_NUMBER DOT VALUE_NUMBER
{        
        //std::cout << "$1 = " << $1 << std::endl;
        //std::cout << "$3 = " << $3 << std::endl;
        //std::cout << "$5 = " << $5 << std::endl;
        drv.getVersion().setNumbers($1,$3,$5);
};

stage : DASH SNAPSHOT
{
        drv.getVersion().setStage(octetos::toolkit::Version::snapshot);         
        //std::cout << "Stage = " << $2 << std::endl;
}
| 
DASH ALPHA
{
         drv.getVersion().setStage(octetos::toolkit::Version::alpha);
}
| 
DASH BETA
{
         drv.getVersion().setStage(octetos::toolkit::Version::beta);
}
| 
DASH RC
{
         drv.getVersion().setStage(octetos::toolkit::Version::rc);
}
| 
DASH RELEASE
{
         drv.getVersion().setStage(octetos::toolkit::Version::release);
}
;

build : VALUE_BUILD
{
        drv.getVersion().setBuild($1);      
        //std::cout << "Build = " << $1 << std::endl;
};

name : VALUE_NAME
{
        drv.getVersion().setName($1);
        //std::cout << "Name = " << $1 << std::endl;
};

end : END
{
        
};

valid : VALID FIELD_NUMBERS EQUAL numbers end
	{
		YYACCEPT;
	};
	
valid : VALID FIELD_STAGE EQUAL stages end
	{
		YYACCEPT;
	};
	
valid : VALID FIELD_BUILD EQUAL VALUE_BUILD end
	{
		YYACCEPT;
	};	
valid : VALID  FIELD_NAME FIELD_BUILD EQUAL VALUE_NAME end
	{
		YYACCEPT;
	};
	
stages : SNAPSHOT | ALPHA | BETA | RC | RELEASE
	{
		YYACCEPT;
	};

%%


void 
octetos::toolkit::Parser::error( const location_type &l, const std::string &err_message )
{
   if(drv.getAnnounceError())std::cerr << "Error: " << err_message << " at " << l << "\n";
}
