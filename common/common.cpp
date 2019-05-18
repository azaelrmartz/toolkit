
#include "common.hpp"
#include "config.h"

namespace toolkit
{	
        
#ifdef COLLETION_ASSISTANT
        Object::Object()
        {
                countChilds = 0;
        }
        void Object::addChild(Object*)
        {
                countChilds++;
        }
        void Object::removeChild(Object*)
        {
                countChilds--;
        }
#endif

	short Version::getMajor() const
	{
		return this->major;		
	}

	short Version::getMinor() const
	{
		return this->minor;
	}

	short Version::getPatch() const
	{
		return this->patch;
	}

	Version::Version()
	{
		major = -1;
		minor = -1;
		patch = -1;
		stage = unknown;
	}

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

	std::string Version::toString() const
	{

		if((major < 0) | (minor < 0) | (patch < 0) | stage == unknown)
		{//falla devido a que no esta inicializado
			return "";
		}
		
		std::string ver = "";
		ver += std::to_string(major);
		ver += ".";
		ver += std::to_string(minor);
		ver += ".";
		ver += std::to_string(patch);		

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

		return ver;
	}
		
		
	Version getVersion()
	{
		return Version(MAJOR,MINOR,PATCH,STAGE);		
	}
	
	
}
