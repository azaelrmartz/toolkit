
#include "Business.hpp"

namespace business
{
    Exception::Exception(Code code,const char* description) throw() : Message(Message::FAIL,description)
    {
    }
    /*Exception::Exception() throw() : Message(Message::FAIL,description)
    {

    }*/
    const char* Exception::what() const throw()
    {
        return Message::what();
    }

    Confirmation::Confirmation(Code code,const char* description) throw() : Message(Message::SUCCEED,description)
    {
    }
    /*Confirmation::Confirmation() throw() : Message(Message::SUCCEED,description)
    {
    }*/

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
