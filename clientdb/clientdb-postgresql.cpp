#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <iostream>

#include "clientdb-postgresql.hpp"
#include "versionInfo-pqc++.h"


namespace octetos
{
namespace toolkit
{
namespace clientdb
{
namespace postgresql
{
        
	std::string getPakageName()
	{
		return std::string(PAKAGENAME);
	}
	toolkit::Version getPakageVersion()
	{
                toolkit::Version v;
                v.setNumbers(VERSION_MAJOR,VERSION_MINOR,VERSION_PATCH);
                v.setStage(VERSION_STAGE);
                v.setBuild(std::stoul(VERSION_BUILD));
		return v;		
	}
	
        /*std::string Datasource::toString() const
        {		
            return toolkit::clientdb::Datasource::toString();
        } */
        Datconnect::Datconnect(const Datconnect& obj) : toolkit::clientdb::Datconnect(obj)
        {
            
        }
        const Datconnect& Datconnect::operator=(const Datconnect& obj)
        {		
            ((Datconnect&)*this)=obj;
            return *this;
        }
        Datconnect::Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password) : clientdb::Datconnect(ServerType::MySQL,host,port,database,usuario,password)
        {
        }
        
        
        Datresult* Connector::query(const char*)
        {
                return NULL;
        }
        Connector::Connector()
        {
        }
        Connector::~Connector()
        {
            close();
        }
        const toolkit::clientdb::Datconnect& Connector::getDatconection() const
        {
            return (const octetos::toolkit::clientdb::postgresql::Datconnect&)Connector::getDatconection();
        } 
        void Connector::close()
        {
            if(serverConnector != NULL) PQfinish((PGconn*)serverConnector);
            serverConnector  = NULL;
        }        
        bool Connector::begin()
        {
            return query("BEGIN"); 
        }
        bool Connector::rollback()
        {
            return query("ROLLBACK"); 
        }        
        bool Connector::commit()
        {
            return query("COMMIT"); 
        }
        unsigned long long Connector::insert(const std::string& str)
        { 		
            PGresult *res = PQexec((PGconn*)serverConnector, str.c_str()); 
            if (res == NULL)
            {
                throw SQLExceptionQuery("La consuta de insert fallo.");        
                PQclear(res);
            }        
			
			res = PQexec((PGconn*)serverConnector, "SELECT lastval()"); 
            if (res == NULL)
            {
                throw SQLExceptionQuery("No se retorno datos.");        
                PQclear(res);
            }
            int ID = 0;
            int countR = PQntuples(res);
            if(countR == 1)
            {
				ID = std::stoi(PQgetvalue(res, 0, 0));
			}
			else
			{
				throw SQLException("la funcion 'lastval()' no retorno resultdo.");
			}
			
            return ID;		
        }   
        bool Connector::connect(const toolkit::clientdb::Datconnect* conection)
        {
            std::string strsql = "";
            if(conection->getHost().length() > 1)
            {
                if(is_ipv4_address(conection->getHost()))
                {
                    strsql = strsql + "hostaddr=" + conection->getHost();
                }
                else if(is_ipv6_address(conection->getHost()))
                {
                    strsql = strsql + "hostaddr=" + conection->getHost();
                }
                else if(is_valid_domain_name(conection->getHost()))
                {
                    strsql = strsql + "host=" + conection->getHost();
                }
            }
            if(conection->getUser().length() > 1)
            {
                strsql = strsql + " user=" + conection->getUser();
            }
            if(conection->getPort() > 0)
            {
                strsql = strsql + " port=" + std::to_string(conection->getPort());
            }
            if(conection->getDatabase().length() > 1)
            {
                strsql = strsql + " dbname=" + conection->getDatabase();
            }
            if(conection->getPassword().length() > 1)
            {
                strsql = strsql + " password=" + conection->getPassword();
            }
            PGconn *serverConnector = PQconnectdb(strsql.c_str());
            if (PQstatus(serverConnector) == CONNECTION_BAD) 
            {
                std::string msg = PQerrorMessage(serverConnector);                  
                PQfinish(serverConnector);
                throw SQLException(msg);  
            }
            
            this->serverConnector = serverConnector;
            datconection = conection;
            return true;
        }        
        bool Connector::query(const std::string& str)
        {
            PGresult *res = PQexec((PGconn*)serverConnector, str.c_str()); 
            if (PQresultStatus(res) != PGRES_TUPLES_OK)
            {
                throw SQLExceptionQuery("No se retorno datos.");        
                PQclear(res);
            }
            return true;
        }
        bool Connector::query(const std::string& str, std::vector<std::vector<const char*>>& rows)
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
}
