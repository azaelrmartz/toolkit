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
