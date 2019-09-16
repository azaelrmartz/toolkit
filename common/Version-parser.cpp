
#include <sstream>
#include <driver.hpp>


namespace octetos
{
namespace toolkit
{
		bool Version::fromString(const std::string& str)
		{
                //std::cout << "Calling fromFile" << std::endl;
                Driver dr(*this,false);
                std::istringstream istr(str);
                return dr.parse(istr);
        } 
        bool Version::fromFile(const std::string& filestring)
        {
                //std::cout << "Calling fromFile" << std::endl;
                Driver dr(*this,false);
                return dr.parse(filestring.c_str());
        } 
        /*bool Version::valid(const std::string& str)
        {
                Version ver;
                Driver dr(ver,false);
                std::istringstream istr(str);
                return dr.parse(istr);
        } */
}
}
