
#include <sstream>
#include <driver.h>

#include "Version.hpp"
extern int parse_string(struct Tray* ty,const char* in);


namespace octetos
{
namespace toolkit
{
        bool Version::from(const std::string& str)
		{
            Tray ty;
            int ret = parse_string(&ty,str.c_str());
            major = ty.version.major;
            minor = ty.version.minor;
            patch = ty.version.patch;
            //stage = ty.version.stage;
            //build = ty.version.build;
            return ret;
        } 
        /*bool Version::fromFile(const std::string& filestring)
        {
                //std::cout << "Calling fromFile" << std::endl;
                Driver dr(*this,false);
                return dr.parse(filestring.c_str());
        } */
        /*bool Version::valid(const std::string& str)
        {
                Version ver;
                Driver dr(ver,false);
                std::istringstream istr(str);
                return dr.parse(istr);
        } */
}
}
