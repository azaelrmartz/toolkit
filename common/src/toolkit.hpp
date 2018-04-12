#ifndef __toolkit_hpp__
#define __toolkit_hpp__

#include <exception>
#include <string>


namespace toolkit
{
    class Message
    {
    public:
        enum Code
        {
            FAIL_SRD_CONNECTION     =   -1001,
            FAIL_SERVER_DATABASE    =   -1000,
            FAIL    =   -1,
            NOTHINK =   0,
            SUCCEED =   1,
            SUCCEED_SERVER_DATABASE =   1000,
        };
        bool isPass();
        bool isFail();
        //Message();
        Message(Code, const char* description);
        virtual const char* what() const throw();
        Code getCode() const;
    private:
        const char* description;
        Code code;
    };

    class Confirmation : public Message
    {
    public:
        Confirmation(Code number, const char* description) throw();
        //Confirmation() throw();
    };

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
