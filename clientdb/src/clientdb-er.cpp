#include <mysql/my_global.h>
#include <mysql/mysql.h>

#include <string>

#include "clientdb-er.hpp"


namespace toolkit
{
namespace clientdb
{
    const char* Persons::TABLE_NAME = "Persons";
    
    bool Persons::insert(Connector& connector,const char* n1,const char* am,const char* ap)
    {
        std::string str = "";
        str = str + "INSERT INTO " + TABLE_NAME + "(n1,am,ap) VALUES('" ;
        str += n1 ;
        str += "','";
        str += am ; 
        str += "','";
        str += ap ; 
        str += "')";
        id = connector.insert(str.c_str());
        if(id > 0) return true;
        return false;
    }
    bool Persons::insert(Connector& connector,const char* n1,const char* am)
    {
        std::string str = "";
        str = str + "INSERT INTO " + TABLE_NAME + "(n1,am) VALUES('" ;
        str += n1 ;
        str += "','";
        str += am ; 
        str += "')";
        id = connector.insert(str.c_str());
        if(id > 0) return true;
        return false;
    }
    bool Persons::insert(Connector& connector,const char* n1)
    {
        std::string str = "";
        str = str + "INSERT INTO " + TABLE_NAME + "(n1) VALUES('" + n1 + "')";
        id = connector.insert(str.c_str());
        if(id > 0) return true;
        return false;
    }
    std::string Persons::toString()
    {
        std::string str = "";
        if(n1.length() > 0) str = n1;
        if(n2.length() > 0) str = str + " " + n2;
        if(ns.length() > 0) str = str + " " + ns;
        if(ap.length() > 0) str = str + " " + ap;
        if(am.length() > 0) str = str + " " + am;
        return str;
    }
    void Persons::clean()
    {
        id = 0;
        n1 = "";
        n2 = "";
        ns = "";
        ap = "";
        am = "";
    }


}
}
