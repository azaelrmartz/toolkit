
#include "common.hpp"
#include "config.h"

namespace toolkit
{	
        
#ifdef COLLETION_ASSISTANT
        unsigned int Object::getCountChils()
        {
                return countChilds;
        }
        Object::Object()
        {
                countChilds = 0;
        }
        void Object::addChild(const Object*)
        {
                countChilds++;
        }
        void Object::removeChild(const Object*)
        {
                countChilds--;
        }
        void Object::addChild(const Object&)
        {
                countChilds++;
        }
        void Object::removeChild(const Object&)
        {
                countChilds--;
        }
#endif







	int Version::getBuild() const
	{
                return build;
        }
        Version::Stage Version::getStage() const
        {
                return stage;
        }                
        void Version::set(short major,short minor,short patch)
        {
                this->major = major;
                this->minor = minor;
                this->patch = patch;
        }
        void Version::set(short major,short minor)
        {
                this->major = major;
                this->minor = minor;
        }
        void Version::set(short major)
        {
                this->major = major;
        }
        void Version::set(Stage stage)
        {
                this->stage = stage;
        }
        void Version::set(unsigned long build)
        {
                this->build = build;
        }
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

	/*Version::Version(short major,short minor,short patch,Stage stage)
	{
		this->major = major;
		this->minor = minor;
		this->patch = patch;
		this->stage = stage;
	}*/
	void Version::set(short major,short minor,short patch,Stage stage)
	{
		this->major = major;
		this->minor = minor;
		this->patch = patch;
		this->stage = stage;
	}

	std::string Version::toString() const
	{		
		std::string ver = "";
                if(major >= 0)
                {
                        ver += std::to_string(major);
                }
                if(minor >= 0)
                {
                        ver += ".";
                        ver += std::to_string(minor);
                }
                if(patch >= 0)
                {
                        ver += ".";
                        ver += std::to_string(patch);		
                }
                
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

		if(build >= 0)
                {
                        ver += " ";
                         ver += std::to_string(build);	
                }
		return ver;
	}
		
		
	Version getPakageVersion()
	{
                Version v;
                v.set(MAJOR,MINOR,PATCH,STAGE);
                v.set(std::stoul(BUILD));
		return v;		
	}
	
	
}
