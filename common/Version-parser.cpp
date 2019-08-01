
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
