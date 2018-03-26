#include <mysql/my_global.h>
#include <mysql/mysql.h>

#include <string>

#include "SerdataER.hpp"


namespace business
{
namespace serdata
{
    const char* Persons::TABLE_NAME = "Persons";
    bool Persons::insert(Connector& connector,const char* n1)
    {
        std::string str = "";
        str = str + "INSERT INTO " + TABLE_NAME + "(n1) VALUES('" + n1 + "')";
        return connector.query(str.c_str());
    }
    const char* Persons::toString()
    {
        std::string str = "";
        if(this->n1 != NULL) str = str + n1;
        if(this->n2 != NULL) str = str + " " + n2;
        if(this->ns != NULL) str = str + " " + ns;
        if(this->ap != NULL) str = str + " " + ap;
        if(this->am != NULL) str = str + " " + am;
        return str.c_str();
    }
    void Persons::clean()
    {
        this->n1 = NULL;
        this->n2 = NULL;
        this->ns = NULL;
        this->ap = NULL;
        this->am = NULL;
    }


}
}
