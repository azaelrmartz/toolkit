#include <mysql/my_global.h>
#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "clientdb-er.hpp"


namespace toolkit
{
namespace clientdb
{
    bool Persons::selectRamdom(Connector& connector)
    {
        std::string str = "";
        str = str + "SELECT id FROM ";
        //str = str + (((DatconectionMySQL*)connector.getDatconection())->database);
        //str = str + "`.";
        str = str + TABLE_NAME;
        str = str + " ORDER BY RAND() LIMIT 1";
        //std::cout<<"Consulting : "<<str<<std::endl;
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
                id = std::atoi(row[0]);
                //std::cout<<"Cargando datos :id = "<< id <<std::endl;
                download(connector);                
                //mysql_free_result(result);
                return true;
            }
            else
            {
                mysql_free_result(result);
                return false;
            }
            //std::cout<<"Operacion completa."<<std::endl;
            
            return true;
        }
        else
        {
            //std::cout<<"Consulta no aceptada:" << str<<std::endl;
            return false;
        }
    }
    
    bool Persons::download(Connector& connector)
    {
        std::string str = "";
        str = str + "SELECT n1,n2,ns,ap,am FROM " + TABLE_NAME + " WHERE id = " + std::to_string(this->id) + " LIMIT 1";
        //std::cout<<"downloading:" << str <<std::endl;
        if(connector.query(str.c_str()))
        {
            //std::cout<<"Consulta aceptada"<<std::endl;
            MYSQL_RES *result = mysql_store_result((MYSQL*)connector.getServerConnector());
            //std::cout<<"Download acpetada: id ="<<id <<std::endl;
            if (result == NULL)
            {
                return false;
            }
            MYSQL_ROW row;
            if((row = mysql_fetch_row(result)))
            {
                //std::cout<<"Reading row : id ="<<id<<std::endl;
                if(row[0] != NULL)
                {
                    //std::cout<<"Reading row : \t row[0] = "<<row[0]<<std::endl;
                    n1 = row[0];
                }
                if(row[1] != NULL)
                {
                    //std::cout<<"Reading row : \t row[1] = "<<row[1]<<std::endl;
                    n2 = row[1];
                }
                if(row[2] != NULL)
                {
                    //std::cout<<"Reading row : \t row[2] = "<<row[2]<<std::endl;
                    ns = row[2];
                }
                if(row[3] != NULL)
                {
                    //std::cout<<"Reading row : \t row[3] = "<<row[3]<<std::endl;
                    ap = row[3];
                }
                if(row[4] != NULL)
                {
                    //std::cout<<"Reading row : \t row[4] = "<<row[4]<<std::endl;
                    am = row[4];
                }
                //std::cout<<"Copied datas : id ="<<id<<std::endl;
                //mysql_free_result(result);
                //std::cout<<"mysql_free_result : id ="<<id<<std::endl;
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
            //std::cout<<"Download rechazada: id ="<<id <<std::endl;
            return false;
        }
    }
}
}
