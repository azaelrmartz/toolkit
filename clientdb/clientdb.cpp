#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "clientdb.hpp"

namespace toolkit
{
namespace clientdb
{
	
	SQLException::SQLException(const std::string &description) throw()
	{
		this->description = description;
	}
	
	SQLException::~SQLException() throw()
	{
		
	}
	
    const char* SQLException::what() const throw()
    {
        return this->description.c_str();
    }

	
	std::string getPakageName()
	{
		return std::string(PAKAGENAME);
	}
	toolkit::Version getPakageVersion()
	{
		return toolkit::Version(VERSION_MAJOR,VERSION_MINOR,VERSION_PATCH,VERSION_STAGE);		
	}	
	namespace datasourcies
	{
        Datasource::ServerType Datasource::getServerType() const
        {
            return serverType;
        }
	
        void Datasource::set(ServerType serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password)
        {
            this->host = host;
            this->user = usuario;
            this->password = password;
            this->database = database;
            this->port = port;
            this->serverType = serverType;        
        }
        const Datasource& Datasource::operator=(const Datasource& obj)
        {
            this->host = obj.host;
            this->user = obj.user;
            this->password = obj.password;
            this->database = obj.database;
            this->port = obj.port;		
            this->serverType = obj.serverType;
            
            return obj;
        }
        
        std::string Datasource::toString() const
        {
            std::string constr = "";
            if(!host.empty())
            {
                constr = host;
            }
            if(port > 0)
            {
                constr =  constr + ":";
                constr =  constr + std::to_string(port);
            }		
            if(!database.empty())
            {
                constr += "/" + database;
            }					
            if(!password.empty())
            {
                constr += " - with password.";
            }
            
            return constr;
        }
        
        Datasource::Datasource(const Datasource& obj)
        {
            this->host = obj.host;
            this->user = obj.user;
            this->password = obj.password;
            this->database = obj.database;
            this->port = obj.port;		
        }
        
        Datasource::Datasource(ServerType serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password)
        {
            this->host = host;
            this->user = usuario;
            this->password = password;
            this->database = database;
            this->port = port;
            this->serverType = serverType;
        }
        
        const std::string& Datasource::getHost()const
        {
            return host;
        }
        const std::string& Datasource::getUser()const
        {
            return user;
        }
        const std::string& Datasource::getPassword()const
        {
            return password;
        }
        const std::string& Datasource::getDatabase()const
        {
            return database;
        }
        unsigned int Datasource::getPort()const
        {
            return port;
        }
        
        std::string MySQL::toString() const
        {		
            return Datasource::toString();
        }
        
        

        MySQL::MySQL(const MySQL& obj) : Datasource(obj)
        {
            
        }
        const MySQL& MySQL::operator=(const MySQL& obj)
        {		
            ((Datasource&)*this)=obj;
            return *this;
        }
        MySQL::MySQL(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password) : Datasource(ServerType::MySQL,host,port,database,usuario,password)
        {
        }
        
    }
	namespace connectors
    {
        Connector::Connector()
        {
        }
        Connector::~Connector()
        {
        }
        void* Connector::getServerConnector()
        {
            return this->serverConnector;
        }
        const datasourcies::Datasource& Connector::getDatconection() const
        {
            return *datconection;
        }
        
    
        
        MySQL::MySQL()
        {
        }
        MySQL::~MySQL()
        {
        }
        void* MySQL::getServerConnector()
        {
            return Connector::getServerConnector();
        }
        const datasourcies::MySQL& MySQL::getDatconection() const
        {
            return (const datasourcies::MySQL&)Connector::getDatconection();
        } 
    }
}	
}

