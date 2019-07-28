#include <iostream>
#include <cstdlib>
#include <cstring>

#include "driver.hpp"

int 
main( const int argc, const char **argv )
{
  	octetos::toolkit::Driver driver;
  	driver.parse(argv[1]);
  	
   	return EXIT_SUCCESS;
}
