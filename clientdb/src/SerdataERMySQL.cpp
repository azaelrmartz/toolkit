#include <mysql/my_global.h>
#include <mysql/mysql.h>

#include <iostream>

#include "SerdataER.hpp"


namespace business
{
namespace serdata
{
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
                this->n1 = row[0];
                this->n2 = row[1];
                this->n2 = row[2];
                this->ap = row[3];
                this->am = row[4];
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
