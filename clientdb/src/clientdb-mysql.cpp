#include <mysql/my_global.h>
#include <mysql/mysql.h>
#include <iostream>

#include "clientdb.hpp"

namespace toolkit
{
namespace clientdb
{
    bool Connector::rollback()
    {
        if (serverConnector != NULL)
        {
            if(mysql_rollback((MYSQL*)serverConnector) == 0)
            {
                return true;
            }
        }
        
        return false; 
    }
	/*bool Connector::query(const std::string& sql,Rows& rows)
	{
		if(query(sql.c_str()))
		{
			MYSQL_RES *result = mysql_store_result((MYSQL*)serverConnector);
			MYSQL_ROW row;
			while((row = mysql_fetch_row(result)))
			{
				rows.import(&row);
			}
			mysql_free_result(result);
			return true;
		}
		
		return false;
	}*/
	
    bool Connector::commit()
    {
        if (serverConnector != NULL)
        {
            if(mysql_commit((MYSQL*)serverConnector) == 0)
            {
                return true;
            }
        }
        
        return false; 
    }
    ID Connector::insert(const std::string& str)
    {
		if (mysql_query((MYSQL*)serverConnector, str.c_str()) == 0) 
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


    bool Connector::connect(const Datconection& conection)
    {
		//for MySQL
		if(conection.getServerType() == Datconection::ServerType::MySQL)
		{
			serverConnector = (void*)mysql_init(NULL);
			if (serverConnector == NULL)
			{
				std::string msg = "";
				msg = msg + " MySQL Server Error No. : '";
				msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
				msg = msg + "' ";
				msg = msg + mysql_error((MYSQL*)serverConnector);
				throw SQLException(msg);           
			}
			if (mysql_real_connect((MYSQL*)serverConnector, ((const DatconectionMySQL&)conection).getHost().c_str(), ((const DatconectionMySQL&)conection).getUsuario().c_str(), ((const DatconectionMySQL&)conection).getPassword().c_str(),((const DatconectionMySQL&)conection).getDatabase().c_str(),((const DatconectionMySQL&)conection).getPort(), NULL, 0) == NULL)
			{
				std::string msg = "";
				msg = msg + " MySQL Server Error No. : '";
				msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
				msg = msg + "' ";
				msg = msg + mysql_error((MYSQL*)serverConnector);
				throw SQLException(msg);
			}        
			if(mysql_autocommit((MYSQL*)serverConnector,0) != 0)
			{
				return false;
			}        
			datconection = new DatconectionMySQL((const DatconectionMySQL&)conection);
			return true;
		}
		else
		{
			return false;
		}
    }
    
	
    bool Connector::query(const std::string& str)
    {
		if (mysql_query((MYSQL*)serverConnector, str.c_str()) == 0) 
		{
			return true;
		}
		
		return false;
    }

}
}
