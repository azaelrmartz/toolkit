#ifndef toolkit_clientdb_hpp
#define toolkit_clientdb_hpp

#include "toolkit.hpp"


namespace toolkit
{
namespace clientdb
{
	Version getPakageVersion();
	const char* getPakageName();	
	typedef unsigned int ID;
    
    struct Datconection    
    {        
        
    };
    struct DatconectionMySQL : public Datconection
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
        Datconection* datconection;
    public:
        Connector();
        Connector(DatconectionMySQL& connector);
        Message connect(DatconectionMySQL& connector);
        const char* serverDescription();
        bool query(const char*);
        ID insert(const char*);
        bool commit() throw(Exception);
        void rollback() throw(Exception);
        void* getServerConnector();
        const Datconection* getDatconection() const;
    };

}
}

#endif
