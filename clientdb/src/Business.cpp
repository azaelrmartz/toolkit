
#include "Business.hpp"

namespace business
{
    Exception::Exception(int number,const char* description) throw()
    {
        this->description = description;
    }

    const char* Exception::what() const throw()
    {
        return this->description;
    }

    Confirmation::Confirmation(int number,const char* description) throw()
    {
        this->description = description;
    }
    const char* Confirmation::what() const throw()
    {
        return this->description;
    }
}
