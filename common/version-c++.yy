%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {toolkit}
%define parser_class_name {Parser}

%code requires
{
   namespace toolkit 
   {
      class Driver;
      class Scanner;
      class Version;
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

%parse-param { toolkit::Scanner  &scanner  }
%parse-param { toolkit::Driver  &driver  }
%parse-param { toolkit::Version  &ver  }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
  #include "common.hpp"
   #include "driver.hpp"
  
#undef yylex
#define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert


%token NUMBER
%token BUILD
%token WORD
%token END DOT

%start version
%locations

%%
version : numbers end | numbers build end | numbers build name end;

numbers : one_number | two_numbers | tree_numbers | four_numbers ;

        one_number : NUMBER
	{
	    //ver->major = $1;
	}
	;

        two_numbers : NUMBER DOT NUMBER
	{
	   //ver->major = $1;
	    //ver->minor = $3;
	}
	;

        tree_numbers : NUMBER DOT NUMBER DOT NUMBER
	{
                //ver->major = $1;
               // ver->minor = $3;
                //ver->patch = $5;
	}
	;

        four_numbers : NUMBER DOT NUMBER DOT NUMBER DOT NUMBER
	{
	   /* ver->major = $1;
	    ver->minor = $3;
	    ver->patch = $5;
	    ver->tweak = $7;*/
	}
	;

build : BUILD
	{
	    //ver->build = $1;
	}
	;

name : WORD;

end : END;

%%


void 
toolkit::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}
