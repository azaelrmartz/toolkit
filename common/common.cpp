
#include "common.hpp"
#include "config.h"

namespace toolkit
{
	

	Version::Version()
	{
#if FIELDS_NUMBER > 0
		major = -1;
#endif
#if FIELDS_NUMBER > 1
		minor = -1;
#endif
#if FIELDS_NUMBER > 2
		patch = -1;
#endif
#if FIELD_STAGE
		stage = unknown;
#endif
	}

#if FIELDS_NUMBER > 0
	Version::Version(short major)
	{
		this->major = major;
#if FIELD_STAGE
		this->stage = unknown;
#endif		
	}		
#endif
#if FIELDS_NUMBER > 1
	Version::Version(short major,short minor)
	{
		this->major = major;
		this->minor = minor;
#if FIELD_STAGE
		this->stage = unknown;
#endif
	}		
#endif
#if FIELDS_NUMBER > 2
	Version::Version(short major,short minor,short patch)
	{
		this->major = major;
		this->minor = minor;
		this->patch = patch;
#if FIELD_STAGE
		this->stage = unknown;
#endif
	}		
#endif
#if FIELDS_NUMBER > 1 && FIELD_STAGE
	Version::Version(short major,short minor,Stage stage)
	{
               	this->major = major;
               	this->minor = minor;
		this->stage = stage;
       	}
#endif
#if FIELDS_NUMBER > 2 && FIELD_STAGE
       	Version::Version(short major,short minor,short patch,Stage stage)
       	{
               	this->major = major;
               	this->minor = minor;
               	this->patch = patch;
		this->stage = stage;
       	}
#endif
	std::string Version::toString() const
	{
#if FIELDS_NUMBER == 1
		if(major < 0)
		{//falla devido a que no esta inicializado
			return "";
		}
#elif FIELDS_NUMBER == 2
		if((major < 0) | (minor < 0) )
		{//falla devido a que no esta inicializado
			return "";
		}
#elif FIELDS_NUMBER == 3
		if((major < 0) | (minor < 0) | (patch < 0) )
		{//falla devido a que no esta inicializado
			return "";
		}
#endif
#if FIELD_STAGE	
		if(stage == unknown)
		{//falla devido a que no esta inicializado
			return "";
		}
#endif

		std::string ver = "";
#if FIELDS_NUMBER == 1
		ver += std::to_string(major);
#elif FIELDS_NUMBER == 2		
		ver += std::to_string(major);
		ver += ".";
		ver += std::to_string(minor);
#elif FIELDS_NUMBER == 3
		ver += std::to_string(major);
		ver += ".";
		ver += std::to_string(minor);
		ver += ".";
		ver += std::to_string(patch);
#endif
		
#if FIELD_STAGE
		if(stage == alpha)
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
#endif
		return ver;
	}
		
		
	Version getVersionComponetCommon()
	{
		return Version(MAJOR,MINOR,PATCH,STAGE);		
	}
	
	
}
