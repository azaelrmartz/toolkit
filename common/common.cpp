


#include "packInfo.hpp"
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
		return std::string(PACKAGE_NAME);
	}
	
	Package getPackageInfo()
	{
		Package packinfo;
		
		packinfo.name = PACKAGE_NAME;
		packinfo.brief = PACKAGE_BRIEF;
		packinfo.url = PACKAGE_URL;
		
		packinfo.version.setNumbers(VERSION_MAJOR,VERSION_MINOR,VERSION_PATCH);
		packinfo.version.setStage(VERSION_STAGE);
		packinfo.version.setBuild(std::stoul(VERSION_BUILD));
		
		packinfo.licence.type = Licence::Type::GPL;		
		packinfo.licence.name_public = packinfo.name;
		packinfo.licence.owner = "Azael Reyes";
		packinfo.licence.year = 2018;
		
		return packinfo;	
	}
}
}
