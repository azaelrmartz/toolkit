#ifndef __Business_HPP__
#define __Business_HPP__


#include <exception>

namespace business
{
    class Confirmation
    {
    private:
        const char* description;
    public:
        //exception () throw();
        //exception (const exception&) throw();
        //exception& operator= (const exception&) throw();
        //virtual ~exception() throw();
        virtual const char* what() const throw();
        Confirmation(int number,const char* description) throw();
        Confirmation() throw(){};
    };

    class Exception : public std::exception
    {
    private:
        const char* description;
    public:
        //exception () throw();
        //exception (const exception&) throw();
        //exception& operator= (const exception&) throw();
        //virtual ~exception() throw();
        virtual const char* what() const throw();
        Exception(int number,const char* description)throw();
        Exception() throw(){};
    };

    union Message
    {
        Confirmation* confirmation;
        Exception* exception;
    };

}

#endif
