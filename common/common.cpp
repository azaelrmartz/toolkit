


#include "versionInfo-c++.h"
#include "common.hpp"


namespace octetos
{
namespace toolkit
{	
        
	Version getPakageVersion()
	{
                Version v;
                v.setNumbers(VERSION_MAJOR,VERSION_MINOR,VERSION_PATCH);
                v.setStage(VERSION_STAGE);
                v.setBuild(std::stoul(VERSION_BUILD));
		return v;		
	}

	std::string getPakageName()
	{
		return std::string(PAKAGENAME);
	}	
}
}
