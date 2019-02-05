#include <mysql/my_global.h>
#include <mysql/mysql.h>
#include <iostream>

#include "clientdb.hpp"

namespace toolkit
{
namespace clientdb
{
    namespace datasourcies
    {
        
    }    
    namespace connectors
    {      
        void MySQL::close()
        {
            mysql_close((MYSQL*)serverConnector);
        }       
        bool MySQL::rollback()
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
        bool MySQL::commit()
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
        ID MySQL::insert(const std::string& str)
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
        const char* MySQL::serverDescription()
        {
            return mysql_get_client_info();
        }
        bool MySQL::connect(const datasourcies::Datasource& conection)
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
            if (mysql_real_connect((MYSQL*)serverConnector, conection.getHost().c_str(), conection.getUser().c_str(), conection.getPassword().c_str(),conection.getDatabase().c_str(),conection.getPort(), NULL, 0) == NULL)
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
            datconection = new datasourcies::Datasource((const datasourcies::Datasource&)conection);
            return true;
        }        
        bool MySQL::query(const std::string& str)
        {
            if (mysql_query((MYSQL*)serverConnector, str.c_str()) == 0) 
            {
                return true;
            }
            
            return false;
        }        
        bool MySQL::query(const std::string& str, std::vector<std::vector<const char*>>& rows)
        {
            if (mysql_query((MYSQL*)serverConnector, str.c_str())) 
            {
                return false;
            }
            MYSQL_RES *result = mysql_store_result((MYSQL*)serverConnector);
            if (result == NULL) 
            {
                return false;
            }
            int num_fields = mysql_num_fields(result);
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) 
            { 
                std::vector<const char*> r;
                for(int i = 0; i < num_fields; i++) 
                { 
                    r.push_back(row[i] ? row[i] : "");//printf("%s ", ); 
                }       
                rows.push_back(r);
            }
            mysql_free_result(result);
            return true;
        }
    }
	

}
}
