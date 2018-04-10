#ifndef __BusinessSerdata_hpp__
#define __BusinessSerdata_hpp__


#include "toolkit.hpp"


namespace business
{
namespace serdata
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

        int last_errono;
        const char * last_errmsg;
    };

    class Connector
    {
    private:
        void* serverConnector;
    public:
        Connector();
        Connector(DatconectionMySQL& connector);
        Message connect(DatconectionMySQL& connector);
        const char* serverDescription();
        bool query(const char*);
        void commit() throw(Exception);
        void rollback() throw(Exception);
        void* getServerConnector();
    };




}
}

#endif
