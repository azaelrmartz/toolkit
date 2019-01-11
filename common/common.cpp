
#include "common.hpp"
#include "config.h"

namespace toolkit
{
	
       	Version::Version(short major,short minor,short patch,Stage stage)
       	{
               	this->major = major;
               	this->minor = minor;
               	this->patch = patch;
               	this->stage = stage;
       	}
	std::string Version::toString() const
	{
		std::string ver = "";
		if(major > -1)
		{
			ver += std::to_string(major);
		}	
		else
		{//falla devido a que no esta inicializado
			return "?";
		}	
		if(minor > -1)
		{
			if(major > -1)
			{
				ver += ".";
			}
			ver += std::to_string(minor);
		}
		else
		{//falla devido a que no esta inicializado
			return "?";
		}
	
		if(patch > -1)
		{
			if(major > -1 || minor > -1)
			{
				ver += ".";
			}
			ver += std::to_string(patch);
		}
		else
		{//falla devido a que no esta inicializado
			return "?";
		}
		
		if(stage == unknown)
		{//falla devido a que no esta inicializado
			return "?";
		}
		else if(stage == alpha)
		{
			ver += "-alpha";
		}
		else if(stage == beta)
		{
			ver += "-beta";
		}
		else if(stage == release)
		{
			ver += "-release";
		}
		
		return ver;
	}
		
		
	Version getPakageVersion()
	{
		return Version(MAJOR,MINOR,PATCH,STAGE);		
	}
	
	
}
