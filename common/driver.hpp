#ifndef TOOLKIT_PARSER_DRIVER
#define TOOLKIT_PARSER_DRIVER 1

#include <string>
#include <cstddef>
#include <istream>
#include <string>


#include "common.hpp"
#include "scanner.hpp"
#include "parser.tab.hh"

namespace toolkit{

class Driver{
public:
   Driver(Version& version);
   Driver();
   virtual ~Driver();
   
   /** 
    * parse - parse from a file
    * @param filename - valid string with input file
    */
   void parse( const char * const filename );
   /** 
    * parse - parse from a c++ input stream
    * @param is - std::istream&, valid input stream
    */
   void parse( std::istream &iss );
   void parse(const std::string& line);


   //std::ostream& print(std::ostream &stream);
private:

   void parse_helper( std::istream &stream );


   toolkit::Parser  *parser  = nullptr;
   toolkit::Scanner *scanner = nullptr;
   toolkit::Version *version = nullptr;
};

} 
#endif  
