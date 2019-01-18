#ifndef TOOLKIT_CLIENTDB_HPP
#define TOOLKIT_CLIENTDB_HPP

#include "common.hpp"
#include <vector>

namespace toolkit
{
namespace clientdb
{
	toolkit::Version getPakageVersion();
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
    namespace datasourcies
    {
        class Datasource
        {
        public:
            enum ServerType
            {
                MySQL,
                PostgreSQL
            };            
            Datasource(const Datasource&);
            Datasource(ServerType serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            const Datasource& operator=(const Datasource& obj);
            void set(ServerType serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            
            virtual std::string toString() const;
            const std::string& getHost()const;
            const std::string& getUser()const;
            const std::string& getPassword()const;
            const std::string& getDatabase()const;
            ServerType getServerType()const;		
            unsigned int getPort()const;
            
        private:
            ServerType serverType;
            std::string host;
            std::string user;
            std::string password;
            std::string database;
            unsigned int port;        
        };        
        class MySQL : public Datasource
        {
        public:         
            MySQL(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            MySQL(const MySQL& obj);

            const MySQL& operator=(const MySQL&);
            virtual std::string toString() const;
        };	
    }
    namespace connectors
    {
        class Connector
        {
        protected:
            void* serverConnector;
            datasourcies::Datasource* datconection;
        public:
            virtual ~Connector();
            Connector();
            //Connector(datasourcies::Datasource& connector);
            virtual bool connect(const datasourcies::Datasource& connector) = 0;
            virtual const char* serverDescription() = 0;
            virtual bool query(const std::string&) = 0;
            //bool query(const std::string&,Rows&);
            virtual ID insert(const std::string&) = 0;
            virtual bool commit() = 0;
            virtual bool rollback() = 0;
            void* getServerConnector();
            const datasourcies::Datasource& getDatconection() const;  
            virtual void close() = 0;
        };
        
        class MySQL : public Connector
        {
        public:
            virtual ~MySQL();
            MySQL();
            //MySQL(const datasourcies::MySQL& connector);
            virtual bool connect(const datasourcies::Datasource& connector);
            virtual const char* serverDescription();
            virtual bool query(const std::string&);
            //bool query(const std::string&,Rows&);
            virtual ID insert(const std::string&);
            virtual bool commit();
            virtual bool rollback();
            void* getServerConnector();
            const datasourcies::MySQL& getDatconection() const;  
            void close();
        };
    }
}
}

#endif
