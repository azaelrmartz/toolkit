#include "clientdb.hpp"
#include "config.h"

namespace toolkit
{
namespace clientdb
{
	const char* getPakageName()
	{
		return PAKAGENAME;
	}
	Version getPakageVersion()
	{
		return Version(VERSION_MAJOR,VERSION_MINOR,VERSION_PATCH,VERSION_STAGE);		
	}
}	
}

