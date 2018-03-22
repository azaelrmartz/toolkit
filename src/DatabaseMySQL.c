
#include <mysql/my_global.h>
#include <mysql/mysql.h>

const char* serverDescription()
{
    return mysql_get_client_info();
}
