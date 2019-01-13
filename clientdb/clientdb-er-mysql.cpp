#include <mysql/my_global.h>
#include <mysql/mysql.h>

#include <iostream>

#include "clientdb-er.hpp"


namespace toolkit
{
namespace clientdb
{
    bool Persons::selectRandom(Connector& connector)
    {
        std::string sql = "SELECT id FROM ";
        sql += TABLE_NAME ;
        sql += " ORDER BY RAND() LIMIT 1";
        
        if(connector.query(sql.c_str()))
        {
            MYSQL_RES *result = mysql_store_result((MYSQL*)connector.getServerConnector());
            if (result == NULL)
            {
                return false;
            }
            MYSQL_ROW row;
            if((row = mysql_fetch_row(result)))
            {
                //std::cout<<"Cargando datos."<<std::endl;
                if(row[0] != NULL) id = std::atoi(row[0]);
                download(connector);
                return true;
            }
        }
        return false;
    }
    
    bool Persons::download(Connector& connector)
    {
        std::string str = "";
        str = str + "SELECT n1,n2,ns,ap,am FROM " + TABLE_NAME + " WHERE id = " + std::to_string(this->id) + " LIMIT 1";
        if(connector.query(str.c_str()))
        {
            //std::cout<<"Consulta aceptada"<<std::endl;
            MYSQL_RES *result = mysql_store_result((MYSQL*)connector.getServerConnector());
            //std::cout<<"Consulta Resultado cargado"<<std::endl;
            if (result == NULL)
            {
                return false;
            }
            MYSQL_ROW row;
            if((row = mysql_fetch_row(result)))
            {
                //std::cout<<"Cargando datos."<<std::endl;
                if(row[0] != NULL) n1 = row[0];
                if(row[1] != NULL) n2 = row[1];
                if(row[2] != NULL) n2 = row[2];
                if(row[3] != NULL) ap = row[3];
                if(row[4] != NULL) am = row[4];
            }
            else
            {
                mysql_free_result(result);
                return false;
            }
            //std::cout<<"Operacion completa."<<std::endl;
            mysql_free_result(result);
            return true;
        }
        else
        {
            //std::cout<<"Consulta no aceptada"<<std::endl;
            return false;
        }
    }
}
}
