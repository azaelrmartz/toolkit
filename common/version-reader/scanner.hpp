#ifndef OCTETOS_TOOLKIT_SCANNER_HPP
#define OCTETOS_TOOLKIT_SCANNER_HPP

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "parser.tab.hh"
#include "location.hh"

namespace octetos
{
namespace toolkit
{

class Scanner : public yyFlexLexer{
public:
   
   Scanner(std::istream *in) : yyFlexLexer(in)
   {
   };
   virtual ~Scanner() {
   };

   //get rid of override virtual function warning
   using FlexLexer::yylex;

   virtual
   int yylex(Parser::semantic_type * const lval, Parser::location_type *location, Scanner &scanner, Driver&);

private:
   /* yyval ptr */
   Parser::semantic_type *yylval = nullptr;
};

}
}
#endif
