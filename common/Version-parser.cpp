

#include <driver.h>

#include "Version.hpp"
//#include "parser.tab.h"

extern "C" int parse_string(struct Tray* ty,const char* in);

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
        if(ret == 0) return true;
        return false;
    } 
}
}
