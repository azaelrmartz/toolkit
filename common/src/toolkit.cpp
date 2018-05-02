
#include "toolkit.hpp"
#include "config.h"

namespace toolkit
{
	Version::Version()
	{
		this->major = -1;
		this->minor = -1;
		this->patch = -1;
	}
	Version::Version(short major)
	{
		this->major = major;
		this->minor = -1;
		this->patch = -1;
	}
	Version::Version(short major,short minor)
	{
		this->major = major;
		this->minor = minor;
		this->patch = -1;
	}
	Version::Version(short major,short minor,short patch)
	{
		this->major = major;
		this->minor = minor;
		this->patch = patch;
	}
	Version getVersionCommon()
	{
		return Version(MAJOR,MINOR,PATCH);		
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
	
    Exception::Exception(Code code,const char* description) throw() : Message(code,description)
    {
    }
    
    const char* Exception::what() const throw()
    {
        return Message::what();
    }

    Confirmation::Confirmation(Code code,const char* description) throw() : Message(code,description)
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
    /*Message::Message()
    {
        code = NOTHINK;
        description = NULL;
    }*/
    Message::Message(Code code,const char* description)
    {
        this->code = code;
        this->description = description;
    }
    const char* Message::what() const throw()
    {
        return this->description;
    }
    Message::Code Message::getCode()const
    {
        return code;
    }
}
