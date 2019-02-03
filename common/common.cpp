
#include "common.hpp"
#include "config.h"

namespace toolkit
{
	
#if FIELDS_NUMBER > 0
	short Version::getMajor() const
	{
		return this->major;		
	}
#endif
#if FIELDS_NUMBER > 1	
	short Version::getMinor() const
	{
		return this->minor;
	}
#endif
#if FIELDS_NUMBER > 2
	short Version::getPatch() const
	{
		return this->patch;
	}
#endif

	Version::Version()
	{
#if FIELDS_NUMBER == 1
		major = -1;
#elif FIELDS_NUMBER == 2		
		major = -1;
		minor = -1;
#elif FIELDS_NUMBER == 3
		major = -1;
		minor = -1;
		patch = -1;
#endif

#if FIELD_STAGE
		stage = unknown;
#endif
	}

#if FIELDS_NUMBER == 1 && FIELD_STAGE
	Version::Version(short major)
	{
		this->major = major;	
	}
	void Version::set(short major)
	{
		this->major = major;	
	}		
#endif
#if FIELDS_NUMBER == 2 && !FIELD_STAGE
	Version::Version(short major,short minor)
	{
		this->major = major;
		this->minor = minor;
	}	
	void Version::set(short major,short minor)
	{
		this->major = major;
		this->minor = minor;
	}	
#endif
#if FIELDS_NUMBER == 3 && !FIELD_STAGE
	Version::Version(short major,short minor,short patch)
	{
		this->major = major;
		this->minor = minor;
		this->patch = patch;
	}	
	void Version::set(short major,short minor,short patch)
	{
		this->major = major;
		this->minor = minor;
		this->patch = patch;
	}	
#endif
#if FIELDS_NUMBER == 1 && FIELD_STAGE
	Version::Version(short major, Stage stage)
	{
               	this->major = major;
       	}
	void Version::set(short major, Stage stage)
	{
               	this->major = major;
		this->stage = stage;
       	}
#endif
#if FIELDS_NUMBER == 2 && FIELD_STAGE
	Version::Version(short major,short minor,Stage stage)
	{
               	this->major = major;
               	this->minor = minor;
		this->stage = stage;
       	}
	void Version::set(short major,short minor,Stage stage)
	{
               	this->major = major;
               	this->minor = minor;
		this->stage = stage;
       	}
#endif
#if FIELDS_NUMBER == 3 && FIELD_STAGE
       	Version::Version(short major,short minor,short patch,Stage stage)
       	{
               	this->major = major;
               	this->minor = minor;
               	this->patch = patch;
		this->stage = stage;
       	}
       	void Version::set(short major,short minor,short patch,Stage stage)
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
		
		
	Version getVersion()
	{
#if FIELDS_NUMBER == 1 && !FIELD_STAGE
		return Version(MAJOR);
#elif FIELDS_NUMBER == 2 && !FIELD_STAGE		
		return Version(MAJOR,MINOR);
#elif FIELDS_NUMBER == 3 && !FIELD_STAGE
		return Version(MAJOR,MINOR,PATCH);
#endif
#if FIELDS_NUMBER == 1 && FIELD_STAGE
		return Version(MAJOR,STAGE);
#elif FIELDS_NUMBER == 2 && FIELD_STAGE		
		return Version(MAJOR,MINOR,STAGE);
#elif FIELDS_NUMBER == 3 && FIELD_STAGE
		return Version(MAJOR,MINOR,PATCH,STAGE);
#endif			
	}
	
	
}