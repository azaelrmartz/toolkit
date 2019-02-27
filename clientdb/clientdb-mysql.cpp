#include <mysql/mysql.h>
#include <iostream>

#include "clientdb-mysql.hpp"

namespace toolkit
{
namespace clientdb
{
namespace mysql
{        
        Connector::Connector()
        {
        }
        Connector::~Connector()
        {
            close();
        }
        const toolkit::clientdb::Datasource& Connector::getDatconection() const
        {
            return (const toolkit::clientdb::Datasource&)Connector::getDatconection();
        } 
        
        /*std::string Datasource::toString() const
        {
            return tooDatasource::toString();
        } */
        Datasource::Datasource(const Datasource& obj) : toolkit::clientdb::Datasource(obj)
        {
            
        }
        const Datasource& Datasource::operator=(const Datasource& obj)
        {		
            ((clientdb::Datasource&)*this)=obj;
            return *this;
        }
        Datasource::Datasource(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password) : clientdb::Datasource(ServerType::MySQL,host,port,database,usuario,password)
        {
        }
        
        bool Connector::begin()
        {
            return false; 
        }
        void Connector::close()
        {
            if (serverConnector != NULL) mysql_close((MYSQL*)serverConnector);
            serverConnector = NULL;
        }       
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
        bool Connector::connect(const toolkit::clientdb::Datasource& conection)
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
            datconection = new toolkit::clientdb::Datasource((const toolkit::clientdb::Datasource&)conection);
            return true;
        }
        bool Connector::query(const std::string& str)
        {
            if (mysql_query((MYSQL*)serverConnector, str.c_str()) == 0) 
            {
                return true;
            }
            
            return false;
        }
        bool Connector::query(const std::string& str, std::vector<std::vector<const char*>>& rows)
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
