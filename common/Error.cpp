#include <string.h>


#include "Error.hpp"


namespace octetos
{
namespace toolkit
{	
        const char * Error::getFilename()
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
                this->brief = new char(strlen(obj.brief));
		strcpy(this->brief,obj.brief);
                this->code = code;
                this->filename = obj.filename; 
                this->lineNumber = obj.lineNumber;
        }
        Error::Error(const char * brief, int code,const char * filename,int lineNumber) throw()
	{
                this->brief = new char(strlen(brief));
		strcpy(this->brief,brief);
                this->code = code;
                this->filename = filename; 
                this->lineNumber = lineNumber;
	}	
        Error::Error(const char * brief, int code) throw()
	{
                this->brief = new char(strlen(brief));
		strcpy(this->brief,brief);
                this->code = code;
	}	
	Error::~Error() throw()
	{
		delete brief;
	}	
        const char* Error::what() const throw()
        {
                return this->brief;
        }
        
}
}
