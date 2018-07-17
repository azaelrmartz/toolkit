#ifndef TOOLKIT_HPP
#define TOOLKIT_HPP

#include <exception>
#include <string>

namespace toolkit
{
	/**
	 * \brief Informacion de version
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
		void set(short major,short minor);
		void set(short major,short minor,short patch,Stage stage);
		
		short major;
		short minor;
		short patch;
		Stage stage;	
	};
	
	/**
	 * \brief returna la version actual de componente common
	 **/
	Version getPakageVersion();
	
	/**
	 * \brief Guarda la informacion de estatus.
	 * 
	 **/
    class Message
    {
    public:
		/**
		 * \brief Status code
		 **/
        enum Fails
        {
            FAIL_SRD_CONNECTION     =   -1001,
            FAIL_SERVER_DATABASE    =   -1000,
            FAIL					=	-1
        };
        enum Succeeds
        {
            SUCCEED =   1,
            SUCCEED_SERVER_DATABASE =   1000,
		};
		class Code
		{
		private:
			union
			{
				Message::Fails fail;
				Message::Succeeds succeeds;	
				int code;			
			};
		public:
			Code();
			Code(Message::Fails fail);
			Code(Message::Succeeds succeeds);
			operator int() const;
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
        virtual const char* what() const throw();
        Code getCode() const;
	protected:
		Message(Code code,const std::string &description);
    private:
        std::string description;               
        Code code;
    };
	
	/**
	 * \brief Es un mesaje con status pass
	 **/
    class Confirmation : public Message
    {
    public:
        Confirmation(Succeeds number,const std::string &description) throw();
        //Confirmation() throw();
    };
	
	/**
	 * \brief Es un mensaje con estatus fail.
	 */
    class Exception : public Message, public std::exception
    {
    public:
        //exception () throw();
        //exception (const exception&) throw();
        //exception& operator= (const exception&) throw();
        virtual ~Exception() throw();
        virtual const char* what() const throw();
        Exception(Fails code,const std::string &description) throw();
        //Exception()throw();
    };	
	
}

#endif
