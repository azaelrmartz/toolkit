
#include <driver.hpp>


namespace octetos
{
namespace toolkit
{

        void Version::fromFile(std::string filestring)
        {
                Driver dr(*this);
                dr.parse(filestring.c_str());
        } 
}
}

/*
#include <iostream>
#include <cstdlib>
#include <cstring>

#include "parserVersion-C++/driver.hh"

int 
main( const int argc, const char **argv )
{
        octetos::toolkit::Version version;
        driver dr(version);
        dr.parseFile("version");
        std::cout << version.toString() << std::endl;
        
        return EXIT_SUCCESS;
}*/
