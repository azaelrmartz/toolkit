#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#include <iostream>

#include "clientdb.hpp"

namespace toolkit
{
namespace clientdb
{  
    namespace connectors
    {
        bool PostgreSQL::begin()
        {
            return false; 
        }
        void PostgreSQL::close()
        {
            if(serverConnector != NULL) PQfinish((PGconn*)serverConnector);
        }       
        bool PostgreSQL::rollback()
        {
            return false; 
        }        
        bool PostgreSQL::commit()
        {
            return false; 
        }
        ID PostgreSQL::insert(const std::string& str)
        {
            return 0;		
        }        
        
        bool PostgreSQL::connect(const datasourcies::Datasource& conection)
        {
            std::string strsql = "";
            if(conection.getHost().length() > 1)
            {
                if(is_ipv4_address(conection.getHost()))
                {
                    strsql = strsql + "hostaddr=" + conection.getHost();
                }
                else if(is_ipv6_address(conection.getHost()))
                {
                    strsql = strsql + "hostaddr=" + conection.getHost();
                }
                else if(is_valid_domain_name(conection.getHost()))
                {
                    strsql = strsql + "host=" + conection.getHost();
                }
            }
            if(conection.getUser().length() > 1)
            {
                strsql = strsql + " user=" + conection.getUser();
            }
            if(conection.getPort() > 0)
            {
                strsql = strsql + " port=" + std::to_string(conection.getPort());
            }
            if(conection.getDatabase().length() > 1)
            {
                strsql = strsql + " dbname=" + conection.getDatabase();
            }
            if(conection.getPassword().length() > 1)
            {
                strsql = strsql + " password=" + conection.getPassword();
            }
            PGconn *serverConnector = PQconnectdb(strsql.c_str());
            if (PQstatus(serverConnector) == CONNECTION_BAD) 
            {
                std::string msg = PQerrorMessage(serverConnector);                  
                PQfinish(serverConnector);
                throw SQLException(msg);  
            }
            
            this->serverConnector = serverConnector;
            datconection = &conection;
            return true;
        }        
        bool PostgreSQL::query(const std::string& str)
        {
            PGresult *res = PQexec((PGconn*)serverConnector, str.c_str()); 
            if (PQresultStatus(res) != PGRES_TUPLES_OK)
            {
                throw SQLExceptionQuery("No se retorno datos.");        
                PQclear(res);
            }
            return true;
        }
        bool PostgreSQL::query(const std::string& str, std::vector<std::vector<const char*>>& rows)
        {
            PGresult *res = PQexec((PGconn*)serverConnector, str.c_str()); 
            if (PQresultStatus(res) != PGRES_TUPLES_OK)
            {
                throw SQLExceptionQuery("No se retorno datos.");        
                PQclear(res);
            }
            int countR = PQntuples(res); 
            int countF = PQnfields(res);
            for(int i = 0; i < countR; i++) 
            {           
                std::vector<const char*> val;
                for(int j = 0; j < countF; j++)
                {
                    val.push_back(PQgetvalue(res, i, 0));
                }
                rows.push_back(val);
            }
            PQclear(res);
            return true;
        }
    }
	

}
}
