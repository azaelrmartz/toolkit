#include <cctype>
#include <fstream>
#include <cassert>

#include "driver.hpp"

namespace octetos
{
namespace toolkit
{

Driver::Driver()
{
}
Version& Driver::getVersion()
{
	return *version;
}

Driver::Driver(Version& v)
{
	version = &v;
}
Driver::~Driver()
{
   delete(scanner);
   scanner = nullptr;
   delete(parser);
   parser = nullptr;
}

bool 
Driver::parse( const char * const filename )
{
   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() )
   {
       return false;
   }
   return parse_helper( in_file );
}

bool
Driver::parse( std::istream &stream )
{
   if( ! stream.good()  && stream.eof() )
   {
       return false;
   }
   //else
   return parse_helper( stream ); 
}


bool 
Driver::parse_helper( std::istream &stream )
{
   
   delete(scanner);
   try
   {
      scanner = new Scanner( &stream );
   }
   catch( std::bad_alloc &ba )
   {
      std::cerr << "Failed to allocate scanner: (" <<
         ba.what() << "), exiting!!\n";
      return false;
   }
   
   delete(parser); 
   try
   {
      parser = new Parser(*scanner,(*this));
   }
   catch( std::bad_alloc &ba )
   {
      std::cerr << "Failed to allocate parser: (" << 
         ba.what() << "), exiting!!\n";
      return false;
   }
   const int accept( 0 );
   if( parser->parse() != accept )
   {
      return false;
   }
   return true;
}

void 
Driver::add_upper()
{ 
   uppercase++; 
   chars++; 
   words++; 
}

void 
Driver::add_lower()
{ 
   lowercase++; 
   chars++; 
   words++; 
}

void 
Driver::add_word( const std::string &word )
{
   words++; 
   chars += word.length();
   for(const char &c : word ){
      if( islower( c ) )
      { 
         lowercase++; 
      }
      else if ( isupper( c ) ) 
      { 
         uppercase++; 
      }
   }
}

void 
Driver::add_newline()
{ 
   lines++; 
   chars++; 
}

void 
Driver::add_char()
{ 
   chars++; 
}


std::ostream& 
Driver::print( std::ostream &stream )
{
   stream << red  << "Results: " << norm << "\n";
   stream << blue << "Uppercase: " << norm << uppercase << "\n";
   stream << blue << "Lowercase: " << norm << lowercase << "\n";
   stream << blue << "Lines: " << norm << lines << "\n";
   stream << blue << "Words: " << norm << words << "\n";
   stream << blue << "Characters: " << norm << chars << "\n";
   return(stream);
}

}
}
