#include <cctype>
#include <fstream>
#include <cassert>

#include "driver.hpp"

namespace octetos
{
namespace toolkit
{

bool Driver::getAnnounceError()
{
        return announce_error;
}
Driver::Driver()
{
}
Version& Driver::getVersion()
{
	return *version;
}
Driver::Driver(Version& v, bool announce_error)
{
	version = &v;
        this->announce_error = announce_error;
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
           std::cout << "Fallo la apertura del archivo " << filename << std::endl;
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

        int retP = parser->parse();
        if(  retP == 0 )
        {
           
        }
        else if(  retP == 1 )
        {
                //std::cout << "Error  " << std::endl;
                return false;
        }
        else if(  retP == 2 )
        {
                //std::cout << "Problema de memoria  " << std::endl;
                return false;
        }
   
        return true;
}

}
}
