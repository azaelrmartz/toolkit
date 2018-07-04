
#include "config.h"

#include "clientdb.hpp"

namespace toolkit
{
namespace clientdb
{	

	Datconection::ServerType Datconection::getServerType()const
	{
		return type;
	}
	Datconection::Datconection(ServerType serverType)
	{
		this->type = serverType;
	}

    void* Connector::getServerConnector()
    {
        return this->serverConnector;
    }
    Connector::Connector()
    {
    }
    const Datconection& Connector::getDatconection() const
    {
        return *datconection;
    }
	const DatconectionMySQL& DatconectionMySQL::operator=(const DatconectionMySQL& obj)
	{
		this->host = obj.host;
		this->usuario = obj.usuario;
		this->password = obj.password;
		this->database = obj.database;
		this->port = obj.port;		
	}
    const char* SQLException::what() const throw()
    {
        return this->description.c_str();
    }
	SQLException::SQLException(const std::string &description) throw()
	{
		this->description = description;
	}
	SQLException::~SQLException() throw()
	{
		
	}
	/*DatconectionMySQL::DatconectionMySQL()
	{
	}*/
	DatconectionMySQL::DatconectionMySQL(const DatconectionMySQL& obj) : Datconection(Datconection::ServerType::MySQL)
	{
		this->host = obj.host;
		this->usuario = obj.usuario;
		this->password = obj.password;
		this->database = obj.database;
		this->port = obj.port;		
	}
	DatconectionMySQL::DatconectionMySQL(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password) : Datconection(Datconection::ServerType::MySQL)
	{
		this->host = host;
		this->usuario = usuario;
		this->password = password;
		this->database = database;
		this->port = port;
	}
	const std::string& DatconectionMySQL::getHost()const
	{
		return host;
	}
	const std::string& DatconectionMySQL::getUsuario()const
	{
		return usuario;
	}
	const std::string& DatconectionMySQL::getPassword()const
	{
		return password;
	}
	const std::string& DatconectionMySQL::getDatabase()const
	{
		return database;
	}
	unsigned int DatconectionMySQL::getPort()const
	{
		return port;
	}
	
	std::string getPakageName()
	{
		return std::string(PAKAGENAME);
	}
	/*toolkit::Version getPakageVersion()
	{
		return toolkit::Version(VERSION_MAJOR,VERSION_MINOR,VERSION_PATCH,VERSION_STAGE);		
	}*/	
	
}	
}

