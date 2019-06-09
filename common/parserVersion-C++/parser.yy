%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.3.2"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  #include <string>
  #include "../common.hpp"
  
  class driver;
}

// The parsing context.
%param { driver& drv }

%locations

%define parse.trace
%define parse.error verbose

%code {
# include "driver.hh"
}

%define api.token.prefix {TOK_}
%token
  END  0  "end of file"
  DOT  "."
  DASH   "-"
  SNAPSHOT    "snapshot"
  ALPHA    "alpha"
  BETA   "beta"
  RC  "rc"
  RELEASE  "release"
  SPACE
;

%token <std::string> NAME "string"
%token <int> NUMBER "number"
%token <unsigned long> BUILD "unsigned long"


//%printer { yyo << $$; } <*>;

%%
%start version;

version : 
        numbers end
        |
        numbers stage end 
        | 
        numbers stage build end 
        | 
        numbers stage build name end
	{
		//printf("$1 = %s\n",$1);
	};

numbers : firts_number | second_numbers | third_numbers ;

firts_number : NUMBER
{
        //printf("$1 = %s\n",$1);
        //version.setNumbers($1);
};

second_numbers : NUMBER DOT NUMBER
{
       //version.setNumbers($1,$3);
};

third_numbers : NUMBER DOT NUMBER DOT NUMBER
{        
        std::cout << "$1 = " << $1 << std::endl;
        std::cout << "$3 = " << $3 << std::endl;
        std::cout << "$5 = " << $5 << std::endl;
        //drv.getVersion().setNumbers($1,$3,$5);
};

stage : DASH SNAPSHOT
{
         //version.setStage(Version::snapshot);
}
| 
DASH ALPHA
{
         //version.setStage(Version::alpha);
}
| 
DASH BETA
{
         //version.setStage(Version::beta);
}
| 
DASH RC
{
         //version.setStage(Version::rc);
}
| 
DASH RELEASE
{
         //version.setStage(Version::release);
}
;

build : BUILD
{
        //printf("$1 = %s\n",$1);
        //version.setBuild($1);
};

name : NAME
{
        //printf("$1 = %s\n",((std::string)$1)).c_str();
        //version.setName($1);
};

end : END
{
        YYACCEPT;
};
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
