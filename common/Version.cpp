
#include <string>
//#include <iostream> //for test


#include "Version.hpp"


// Reference https://semver.org/


namespace octetos
{
namespace toolkit
{
        Version::InvalidComparison::InvalidComparison(const std::string& msg):Error(msg,Error::ERROR_VERSION_INVALID_COMPARISON)
        {
                
        }
        Version::InvalidComparison::InvalidComparison(const std::string& msg ,std::string filename,int lineNumber):Error(msg,Error::ERROR_VERSION_INVALID_COMPARISON,filename,lineNumber)
        {
                
        }
        void Version::init()
        {
		major = -1;
		minor = -1;
		patch = -1;
		stage = unknown;
                build = 0;
                name = "";
        }
        bool Version::operator <(const Version& v)
        {                              
                //por numeros
                if(major > -1 and v.major > -1)
                {
                        if(major >= v.major)
                        {
                                //std::cout << "por major" << std::endl;
                                return false;
                        }                          
                }
                else // no se puede retornar false y escribir un erro ya que el programa tendria la false idea de que la comparacion fue correcta con valor de retorno falso.
                {
                        throw InvalidComparison("Operación invalidad, está comprando objetos Version sin antes asignarles valores.");
                }
                if(minor > -1 and v.minor > -1)
                {
                        if(minor >= v.minor)
                        {
                                //std::cout << "por minor" << std::endl;
                                return false;
                        }
                }
                else//El major se asigno pero el menor no, los retante nuero ya ya no cuentan
                {
                        return false;
                }
                if(patch > -1 and v.patch > -1)
                {
                        if(patch >= v.patch)
                        {
                                //std::cout << "por patch" << std::endl;
                                return false;
                        }
                }
                else//El menor se asigno pero el patch no.
                {
                        return false;
                }
                
                return true;
        }
        const Version& Version::operator =(const Version& v)
        {
                this->major = v.major;
                this->minor = v.minor;
                this->patch = v.patch;
                this->build = v.build;
                this->stage = v.stage;
                this->name = v.name;
                
                return *this;
        }
        bool Version::operator >=(const Version& v)
        {           
                //por numeros
                if(major > -1 and v.major > -1)
                {
                        if(major > v.major)
                        {
                                //std::cout << "por major" << std::endl;
                                return true;
                        }
                        else if(major < v.major) 
                        {
                                return false;
                        }                                
                }
                else // no se puede retornar false y escribir un erro ya que el programa tendria la false idea de que la comparacion fue correcta con valor de retorno falso.
                {
                        throw InvalidComparison("Operación invalidad, está comprando objetos Version sin antes asignarles valores.");
                }
                if(minor > -1 and v.minor > -1)
                {
                        if(minor > v.minor)
                        {
                                //std::cout << "por minor" << std::endl;
                                return true;
                        }
                        else if(minor < v.minor)
                        {
                                return false;
                        }
                }
                else//El menor se asigno pero el patch no.
                {
                        return false;
                }
                if(patch > -1 and v.patch > -1)
                {
                        if(patch >= v.patch)
                        {
                                //std::cout << "por patch" << std::endl;
                                return true;
                        }
                        else if(patch < v.patch)
                        {
                                return false;
                        }
                }
                else//El menor se asigno pero el patch no.
                {
                        return false;
                }
                
                //std::cout << "no cumple" << std::endl;
                return false;
        }
        const std::string& Version::getName() const
        {
                return name;
        }
        void Version::setName(const std::string& name)
        {
                this->name = name;
        }
        void Version::set(short major,short minor,short patch,Stage stage,unsigned long build, const std::string& name)
        {                
                this->major = major;
                this->minor = minor;
                this->patch = patch;
                this->stage = stage;
                this->build = build;
                this->name = name;
        }
	unsigned long Version::getBuild() const
	{
                return build;
        }
        Version::Stage Version::getStage() const
        {
                return stage;
        }                
        void Version::setNumbers(short major,short minor,short patch)
        {
                this->major = major;
                this->minor = minor;
                this->patch = patch;
        }
        void Version::setNumbers(short major,short minor)
        {
                this->major = major;
                this->minor = minor;
                patch = 0;
        }
        void Version::setNumbers(short major)
        {
                this->major = major;
                minor = 0;
                patch = 0;
        }
        void Version::setStage(Stage stage)
        {
                this->stage = stage;
        }
        void Version::setBuild(unsigned long build)
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

	Version::Version(short major,short minor,short patch)
        {
		this->major = major;
		this->minor = minor;
		this->patch = patch;
		stage = unknown;
                build = 0;
                name = "";
        }
	Version::Version(short major,short minor)
        {
		this->major = major;
		this->minor = minor;
		patch = 0;
		stage = unknown;
                build = 0;
                name = "";
        }
	Version::Version()
	{
                init();
	}

	std::string Version::toString(Version::Format formato) const
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
                if(formato == Version::Format::ONLY_NUMBER) return ver;
                
		switch(stage)
                {
                        case snapshot:
                                ver += "-snapshot";
                                break;
                        case alpha:
                                ver += "-alpha";
                                break;
                        case beta:
                                ver += "-beta";
                                break;
                        case rc:
                                ver += "-rc";
                                break;
                        case release:
                                ver += "-release";
                                break;
                        case unknown:
                                ;
                }

		if(build > 0)
                {
                        ver += " ";
                        ver += std::to_string(build);	
                }
                
                if(name.size() > 0)
                {
                        ver += " ";
                        ver += name;
                }
                
		return ver;
	}
	
}
}
