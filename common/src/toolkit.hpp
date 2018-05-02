#ifndef __toolkit_hpp__
#define __toolkit_hpp__

#include <exception>
#include <string>

namespace toolkit
{
	/**
	 * \brief Get version info
	 * 
	 **/
	class Version
	{
	public:
		enum Stage
		{
			unknown,
			alpha,
			beta,
			release
		};
		Version();
		Version(short major);
		Version(short major,short minor);
		Version(short major,short minor,short patch);
		Version(short major,short minor,short patch,Stage stage);
		Version(short major,Stage stage);
		Version(short major,short minor,Stage stage);
		Version(const Version &version);
		short getMajor();
		short getMinor();
		short getPatch();
		Stage getStage();
		std::string toString();	
		
	private:
		short major;
		short minor;
		short patch;
		Stage stage;	
	};
	
	/**
	 * \brief return tha actual version of common component
	 **/
	Version getVersionCommon();
	
	/**
	 * \brief Gets infor of status and description of operation
	 * 
	 **/
    class Message
    {
    public:
		/**
		 * \brief Status code
		 **/
        enum Code
        {
            FAIL_SRD_CONNECTION     =   -1001,
            FAIL_SERVER_DATABASE    =   -1000,
            FAIL    =   -1,
            NOTHINK =   0,
            SUCCEED =   1,
            SUCCEED_SERVER_DATABASE =   1000,
        };
        /**
         * \return true if code is greater than zero
         **/
        bool isPass();        
        /**
         * \return true if code is smaller than zero
         **/
        bool isFail();        
        //Message();
        Message(Code, const char* description);
        virtual const char* what() const throw();
        Code getCode() const;
    private:
        const char* description;
        Code code;
    };
	
	/**
	 * \brief A Message qith status corect.
	 **/
    class Confirmation : public Message
    {
    public:
        Confirmation(Code number, const char* description) throw();
        //Confirmation() throw();
    };
	
	/**
	 * \brief Implmetation of std::exception with support for Message,
	 *        it mean the process fail.
	 */
    class Exception : public Message, public std::exception
    {
    public:
        //exception () throw();
        //exception (const exception&) throw();
        //exception& operator= (const exception&) throw();
        //virtual ~exception() throw();
        virtual const char* what() const throw();
        Exception(Code number,const char* description) throw();
        //Exception()throw();
    };	
	
}

#endif
