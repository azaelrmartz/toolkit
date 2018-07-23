#ifndef TOOLKIT_CLIENTDB_HPP
#define TOOLKIT_CLIENTDB_HPP

#include "toolkit.hpp"
#include <vector>

namespace toolkit
{
namespace clientdb
{
	//toolkit::Version getPakageVersion();
	std::string getPakageName();	
	typedef unsigned int ID;
    
    
    class SQLException : public std::exception
    {
    public:
        //exception () throw();
        //exception (const exception&) throw();
        //exception& operator= (const exception&) throw();
        virtual ~SQLException() throw();
        virtual const char* what() const throw();
        SQLException(const std::string &description) throw();
        //Exception()throw();
	private:
        std::string description;
    };	
    
    class Datconection    
    {
	public:
		enum ServerType
		{
			MySQL,
			PostgresSSQL
		};
	public:
		Datconection(ServerType typeServer);
		ServerType getServerType()const;
	private:
		ServerType type;
    };
    
    class DatconectionMySQL : public Datconection
    {
    public: 
        std::string host;
        std::string usuario;
        std::string password;
        std::string database;
        unsigned int port;
        
        DatconectionMySQL();
		DatconectionMySQL(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
		DatconectionMySQL(const DatconectionMySQL& obj);
		const std::string& getHost()const;
		const std::string& getUsuario()const;
		const std::string& getPassword()const;
		const std::string& getDatabase()const;
		unsigned int getPort()const;
		const DatconectionMySQL& operator=(const DatconectionMySQL&);
    };
	
    class Connector
    {
    private:
        void* serverConnector;
        Datconection* datconection;
    public:
		~Connector();
        Connector();
        Connector(DatconectionMySQL& connector);
        bool connect(const Datconection& connector);
        const char* serverDescription();
        bool query(const std::string&);
        //bool query(const std::string&,Rows&);
        ID insert(const std::string&);
        bool commit();
        bool rollback();
        void* getServerConnector();
        const Datconection& getDatconection() const;  
        void close();
    };
}
}

#endif
