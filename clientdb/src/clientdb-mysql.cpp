#include <mysql/my_global.h>
#include <mysql/mysql.h>
#include <iostream>

#include "clientdb.hpp"

namespace toolkit
{
namespace clientdb
{
    const Datconection* Connector::getDatconection() const
    {
        return datconection;
    }
    bool Connector::commit() throw(Exception)
    {
        if (serverConnector != NULL)
        {
            if(mysql_commit((MYSQL*)serverConnector))
            {
                return true;
            }
        }
        
        return false; 
    }
    ID Connector::insert(const char* str)
    {
		if (mysql_query((MYSQL*)serverConnector, str) == 0) 
		{
			return mysql_insert_id((MYSQL*)serverConnector);
		}
		else
        {   
            return 0; 
        }		
    }
    
    const char* Connector::serverDescription()
    {
        return mysql_get_client_info();
    }

    Connector::Connector()
    {
    }

    Message Connector::connect(DatconectionMySQL& conection)
    {
        serverConnector = (void*)mysql_init(NULL);
        if (serverConnector == NULL)
        {
            //std::cerr<<"Fail init."<<std::endl;
            std::string msg = "";
            msg = msg + " MySQL server return error number '";
            msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
            msg = msg + "' ";
            msg = msg + mysql_error((MYSQL*)serverConnector);
            return Exception(Message::FAIL_SERVER_DATABASE,msg.c_str());
        }

        if (mysql_real_connect((MYSQL*)serverConnector, conection.host, conection.usuario, conection.password,conection.database,conection.port, NULL, 0) == NULL)
        {
            //std::cerr<<"Fail conect."<<std::endl;
            std::string msg = "";
            msg = msg + " MySQL server return error number '";
            msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
            msg = msg + "' ";
            msg = msg + mysql_error((MYSQL*)serverConnector);
            return Exception(Message::FAIL_SERVER_DATABASE,msg.c_str());
        }
        
        /*if(mysql_select_db((MYSQL*)serverConnector,conection.database) != 0)
        {
            if(conection.database == NULL)
            {
                return Exception(Message::FAIL_SERVER_DATABASE,"Should set database name.");
            }
            else
            {
                return Exception(Message::FAIL_SERVER_DATABASE,"Fail on selecting BD, mey be the database name is incorrect.");
            }
        }*/
        
        if(mysql_autocommit((MYSQL*)serverConnector,0) != 0)
        {
            return Exception(Message::FAIL_SERVER_DATABASE,"Fail on disable commit.");
        }
        
        datconection = &conection;
        
        return Confirmation(Message::SUCCEED,"Conexion completa");
    }
    
    void* Connector::getServerConnector()
    {
	return this->serverConnector;
    }
	
    bool Connector::query(const char* str)
    {
		if (mysql_query((MYSQL*)serverConnector, str) == 0) 
		{
			return true;
		}
		
		return false;
    }
}
}
