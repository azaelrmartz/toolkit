#include <mysql/my_global.h>
#include <mysql/mysql.h>

#include <string>

#include "clientdb-er.hpp"


namespace toolkit
{
namespace clientdb
{

    const char* Persons::TABLE_NAME = "Persons";
    bool Persons::insert(Connector& connector,const std::string& n1)
    {
        std::string str = "";
        str = str + "INSERT INTO " + TABLE_NAME + "(n1) VALUES('" + n1.c_str() + "')";
        return connector.query(str.c_str());
    }
    const char* Persons::toString()
    {
        std::string str = "";
        if(n1.length() >0) str = str + n1;
        if(n2.length() >0) str = str + " " + n2;
        if(ns.length() >0) str = str + " " + ns;
        if(ap.length() >0) str = str + " " + ap;
        if(am.length() >0) str = str + " " + am;
        return str.c_str();
    }
    void Persons::clean()
    {
        n1 = "";
        n2 = "";
        ns = "";
        ap = "";
        am = "";
    }


}
}
