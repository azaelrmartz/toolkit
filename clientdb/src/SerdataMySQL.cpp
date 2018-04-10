#include <mysql/my_global.h>
#include <mysql/mysql.h>

#include "Serdata.hpp"

namespace business
{
namespace serdata
{
    const char* Connector::serverDescription()
    {
        return mysql_get_client_info();
    }

    Connector::Connector(DatconectionMySQL& conection)
    {
        connect(conection);
    }

    void Connector::connect(DatconectionMySQL& conection) throw(Exception)
    {
        serverConnector = (void*)mysql_init(NULL);
        if (serverConnector == NULL)
        {
			std::string msg = "";
			msg = msg + " MySQL server return error number '";
			msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
			msg = msg + "' ";
			msg = msg + mysql_error((MYSQL*)serverConnector);
            throw Exception(Exception::Code::FAIL_SERVER_DATABASE,msg.c_str());
            //return false;
        }

        if (mysql_real_connect((MYSQL*)serverConnector, conection.host, conection.usuario, conection.password,conection.database,conection.port, NULL, 0) == NULL)
        {
			std::string msg = "";
			msg = msg + " MySQL server return error number '";
			msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
			msg = msg + "' ";
			msg = msg + mysql_error((MYSQL*)serverConnector);
            throw Exception(Exception::Code::FAIL_SERVER_DATABASE,msg.c_str());
            //mysql_close((MYSQL*)serverConnector);
            //return false;
        }
    }
    
    void* Connector::getServerConnector()
    {
		return this->serverConnector;
	}
	
	bool Connector::query(const char* str)
	{
		if (mysql_query((MYSQL*)serverConnector, str)) 
		{
			return true;
		}
		
		return false;
	}
}
}
