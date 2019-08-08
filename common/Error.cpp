#include <string.h>
#include <iostream> //test


#include "Error.hpp"


namespace octetos
{
namespace toolkit
{	
        const Error* Error::error = NULL;
        Error Error::get()
        {
                Error e(*error);
                if(error != NULL)
                {
                        delete error;
                        error = NULL;
                }
                
                return e;
        }
        bool Error::check()
        {
                if(error != NULL)return true;
                return false;
        }
        bool Error::write(const Error& e)
        {                
                if(error != NULL)
                {
                        return false;
                }
                error = new Error(e);
                return true;
        }
        
        Error::Error(const std::string& brief, int code,std::string filename,int lineNumber) throw()
	{
                full = filename + " : " + std::to_string(lineNumber) + ", codigo (" + std::to_string(code) + "):" + "\n" + brief;
	}	
        Error::Error(const std::string& brief, int code) throw()
	{
                full="";
                full = full + "Codigo (" + std::to_string(code) + "):" + "\n" + brief;
	}
	Error::~Error() throw()
	{
		
	}	
	const std::string& Error::describe() const throw()
        {
                return full;               
        }
        const char* Error::what() const throw()
        {
                return this->full.c_str();
        }
        
}
}
