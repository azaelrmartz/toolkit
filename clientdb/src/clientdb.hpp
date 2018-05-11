#ifndef TOOLKIT_CLIENTDB_HPP
#define TOOLKIT_CLIENTDB_HPP

#include "toolkit.hpp"

namespace toolkit
{
namespace clientdb
{
	toolkit::Version getPakageVersion();
	std::string getPakageName();	
	typedef unsigned int ID;
    
    class Datconection    
    {
        
    };
    
    class DatconectionMySQL : public Datconection
    {
        std::string host;
        std::string usuario;
        std::string password;
        std::string database;
        unsigned int port;
        //const char *unix_socket;
        //unsigned long client_flag;
        //int last_errono;
        //const char * last_errmsg;
    public:
		DatconectionMySQL();
		DatconectionMySQL(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
		DatconectionMySQL(const DatconectionMySQL& obj);
		const std::string& getHost()const;
		const std::string& getUsuario()const;
		const std::string& getPassword()const;
		const std::string& getDatabase()const;
		unsigned int getPort()const;
    };
	
    class Connector
    {
    private:
        void* serverConnector;
        Datconection* datconection;
    public:
        Connector();
        Connector(DatconectionMySQL& connector);
        bool connect(DatconectionMySQL& connector);
        const char* serverDescription();
        bool query(const std::string&);
        //bool query(const std::string&,Rows&);
        ID insert(const std::string&);
        bool commit();
        bool rollback();
        void* getServerConnector();
        const Datconection& getDatconection() const;  
    };
}
}

#endif
