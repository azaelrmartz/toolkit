#ifndef TOOLKIT_PARSER_SCANNER
#define TOOLKIT_PARSER_SCANNER 1

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "parser.tab.hh"
#include "location.hh"
#include "common.hpp"

namespace toolkit{

class Scanner : public yyFlexLexer{
public:
   
   Scanner(std::istream *in) : yyFlexLexer(in)
   {
   };
   virtual ~Scanner() 
   {
   };

   //get rid of override virtual function warning
   using FlexLexer::yylex;

   virtual
   int yylex( toolkit::Parser::semantic_type * const lval, toolkit::Parser::location_type *location );
   // YY_DECL defined in mc_lexer.l
   // Method body created by flex in mc_lexer.yy.cc


private:
   /* yyval ptr */
   toolkit::Parser::semantic_type *yylval = nullptr;
};

} /* end namespace MC */

#endif /* END TOOLKIT_PARSER_SCANNER */
