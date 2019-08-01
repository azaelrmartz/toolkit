#include <string.h>


#include "Error.hpp"


namespace octetos
{
namespace toolkit
{	
        std::string Error::getFilename()
        {
                return filename;        
        }
        int Error::getLineNumber()
        {
                return lineNumber;
        }
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
        
        Error::Error(const Error& obj)
        {                
                this->brief = obj.brief;
                this->code = obj.code;
                this->filename = obj.filename; 
                this->lineNumber = obj.lineNumber;
        }
        Error::Error(const std::string& brief, int code,const std::string& filename,int lineNumber) throw()
	{
                this->brief = brief;
                this->code = code;
                this->filename = filename; 
                this->lineNumber = lineNumber;
	}	
        Error::Error(const std::string& brief, int code) throw()
	{
                this->brief = brief;
                this->code = code;
	}
	Error::~Error() throw()
	{
		
	}	
        const char* Error::what() const throw()
        {
                return this->brief.c_str();
        }
        
}
}
