%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {toolkit}
%define api.parser.class {Parser} //parser_class_name

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
%parse-param { toolkit::Version  &version  }

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
//%define parse.assert


%token<short> NUMBER
%token<unsigned long> BUILD
%token<std::string> NAME
%token DOT
%token HYPHEN
%token SNAPSHOT
%token ALPHA
%token BETA
%token RC
%token RELEASE
%token END

%start version
%locations

%%
version : 
        numbers end
        |
        numbers stage end 
        | 
        numbers stage build end 
        | 
        numbers stage build name end;

numbers : one_number | two_numbers | tree_numbers ;

one_number : NUMBER
{
        version.setNumbers($1);
};

two_numbers : NUMBER DOT NUMBER
{
       version.setNumbers($1,$3);
};

tree_numbers : NUMBER DOT NUMBER DOT NUMBER
{
        version.setNumbers($1,$3,$5);
};

stage : HYPHEN SNAPSHOT
{
         version.setStage(Version::snapshot);
}
| 
HYPHEN ALPHA
{
         version.setStage(Version::alpha);
}
| 
HYPHEN BETA
{
         version.setStage(Version::beta);
}
| 
HYPHEN RC
{
         version.setStage(Version::rc);
}
| 
HYPHEN RELEASE
{
         version.setStage(Version::release);
}
;

build : BUILD
{
       version.setBuild($1);
};

name : NAME
{
        version.setName($1);
};

end : END
{
        YYACCEPT;
};

%%


void 
toolkit::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}
