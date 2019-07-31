
#include <driver.hpp>


namespace octetos
{
namespace toolkit
{
        bool Version::fromFile(std::string filestring)
        {
                std::cout << "Calling fromFile" << std::endl;
                Driver dr(*this);
                return dr.parse(filestring.c_str());
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
