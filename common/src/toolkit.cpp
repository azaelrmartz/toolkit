
#include "toolkit.hpp"
#include "config.h"

namespace toolkit
{
		
	void Version::set(short major,short minor,short patch,Stage stage)
	{
		this->major = major;
		this->minor = minor;
		this->patch = patch;
		this->stage = stage;
	}
	
	void Version::set(short major,short minor)
	{
		this->major = major;
		this->minor = minor;
	}
	
	Exception::~Exception() throw()
	{
	}
	Version::Stage Version::getStage()
	{
		return stage;
	}	
	Version::Version(const Version &version)
	{
		this->major = version.major;
		this->minor = version.minor;
		this->patch = version.patch;
		this->stage = version.stage;
	}
	std::string Version::toString() const
	{
		std::string ver = "";
		if(major > -1)
		{
			ver += std::to_string(major);
		}		
		if(minor > -1)
		{
			if(major > -1)
			{
				ver += ".";
			}
			ver += std::to_string(minor);
		}
		if(patch > -1)
		{
			if(major > -1 || minor > -1)
			{
				ver += ".";
			}
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
		
		return ver;
	}
	Version::Version()
	{
		this->major = -1;
		this->minor = -1;
		this->patch = -1;
		this->stage = unknown;
	}
	Version::Version(short major)
	{
		this->major = major;
		this->minor = -1;
		this->patch = -1;
		this->stage = unknown;
	}
	Version::Version(short major,short minor)
	{
		this->major = major;
		this->minor = minor;
		this->patch = -1;
		this->stage = unknown;
	}
	Version::Version(short major,short minor,short patch)
	{
		this->major = major;
		this->minor = minor;
		this->patch = patch;
		this->stage = unknown;
	}
	Version::Version(short major,short minor,short patch,Version::Stage stage)
	{
		this->major = major;
		this->minor = minor;
		this->patch = patch;
		this->stage = stage;
	}
	short Version::getMajor()
	{
		return major;
	}
	short Version::getMinor()
	{
		return minor;
	}
	short Version::getPatch()
	{
		return patch;
	}		
	Version::Version(short major,Version::Stage stage)
	{
		this->major = major;
		this->minor = -1;
		this->patch = -1;
		this->stage = stage;
	}
	Version::Version(short major,short minor,Version::Stage stage)
	{
		this->major = major;
		this->minor = minor;
		this->patch = -1;
		this->stage = stage;
	}
	
	
		
	Version getPakageVersion()
	{
		return Version(MAJOR,MINOR,PATCH,STAGE);		
	}
	
	
	
    Exception::Exception(const std::string &description) throw() : Message(toolkit::Message::Fails::FAIL,description)
    {
    }

    Exception::Exception(Message::Fails code,const std::string &description) throw() : Message(Message::Code(code),description)
    {
    }
    
    const char* Exception::what() const throw()
    {
        return Message::what();
    }

    Confirmation::Confirmation(Message::Succeeds code,const std::string &description) throw() : Message(Message::Code(code),description)
    {
    }
    
    

    bool Message::isPass()
    {
        if(code > 0) return true;
        return false;
    }
    bool Message::isFail()
    {
        if(code < 0) return true;
        return false;
    }
    Message::Message(Message::Code code,const std::string &description)
    {
        this->code = code;
        this->description = description;
    }
    const char* Message::what() const throw()
    {
        return this->description.c_str();
    }
    Message::Code Message::getCode()const
    {
        return code;
    }
	Message::Code::Code()
	{
		this->code = 0;
	}
	Message::Code::operator int() const
	{
		return code;
	}
	Message::Code::Code(Message::Succeeds succeeds)
	{
		this->succeeds = succeeds;
	}
	Message::Code::Code(Message::Fails fail)
	{
		this->fail = fail;
	}
}
