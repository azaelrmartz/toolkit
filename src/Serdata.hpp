#ifndef __BusinessDatabase_H__
#define __BusinessDatabase_H__

#include "Business.hpp"


namespace serdata
{
namespace database
{
    struct DatconectionMySQL
    {
        const char *host;
        const char *usuario;
        const char *password;
        const char *database;
        unsigned int port;
        const char *unix_socket;
        unsigned long client_flag;
    };

    class Connector
    {
    private:
        void* serverConnector;
    public:
        Connector();
        Connector(DatconectionMySQL& connector);
        bool connect(DatconectionMySQL& connector) throw(Exception);
        const char* serverDescription();
    };
}
}
#endif
