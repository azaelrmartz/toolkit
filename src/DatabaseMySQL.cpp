
#include <mysql/my_global.h>
#include <mysql/mysql.h>

const char* Connector::serverDescription()
{
    return mysql_get_client_info();
}

Connector::Connector(DataconectionMySQL& conection)
{
    connect(conection)
}
bool connect(DataconectionMySQL& conection);
{
    serverCennector = (void*)mysql_init(NULL);
}
