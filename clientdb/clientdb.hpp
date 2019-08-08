#ifndef TOOLKIT_CLIENTDB_HPP
#define TOOLKIT_CLIENTDB_HPP

#include <toolkit/common/common.hpp>
#include <vector>

namespace octetos
{
namespace toolkit
{
namespace clientdb
{
        
        class SQLException : public std::exception
        {
        public:
                virtual ~SQLException() throw();
                virtual const char* what() const throw();
                SQLException(const std::string &description) throw();
	private:
                std::string description;
        };
        class SQLExceptionConnection : public SQLException
        {
        public:
                virtual ~SQLExceptionConnection() throw();
                SQLExceptionConnection(const std::string &description) throw();
        };
        class SQLExceptionQuery : public SQLException
        {
        public:
                virtual ~SQLExceptionQuery() throw();
                SQLExceptionQuery(const std::string &description) throw();
        };
        class NotSupportedExcetion  : public SQLException
        {
                virtual ~NotSupportedExcetion() throw();
                NotSupportedExcetion(const std::string &description) throw();		
	};
    
        class Datconnect : public toolkit::Object
	{
	public:
                enum ServerType
                {
                        Unknow,
                        MySQL,
                        PostgreSQL
                };            
                Datconnect(const Datconnect&);
                Datconnect();
                const Datconnect& operator=(const Datconnect& obj);
                void set(ServerType serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            
            virtual std::string toString()const;
            const std::string& getHost()const;
            const std::string& getUser()const;
            const std::string& getPassword()const;
            const std::string& getDatabase()const;
            ServerType getServerType()const;
            const char* getServerTypeString()const;
            unsigned int getPort()const;
            void setHost(const std::string&);
            void setUser(const std::string&);
            void setPassword(const std::string&);
            void setDatabase(const std::string&);
            void setPort(unsigned int);
            
	protected:
            Datconnect(ServerType serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& user,const std::string& password);
            
	private:
            ServerType serverType;
            std::string host;
            std::string user;
            std::string password;
            std::string database;
            unsigned int port;        
	};	
	
        
        class Row : public toolkit::Object
        {
        protected:
                void* row;
                
        public:
                virtual const char* operator[](unsigned long long index) = 0; 
                Row();
                virtual ~Row();
                Row(void* row);
                Row(Row& row);
        };
        
        class Datresult : public toolkit::Object
        {
        protected:
                void* result;
                unsigned long long currentRow;
                
        public:
                Datresult(void* result);
                virtual ~Datresult();
                virtual Row* operator[](unsigned long long index) = 0;             
                virtual toolkit::clientdb::Row* next()= 0;
                void* getResult() const;
        };
        
	class Connector : public toolkit::Object
	{
        protected:
            void* serverConnector;
            const Datconnect* datconection;
            
        public:
            //
            static bool is_ipv4_address(const std::string& str);
            static bool is_ipv6_address(const std::string& str);
            static bool is_valid_domain_name(const std::string& str);
            virtual ~Connector();
            Connector();
            Connector(const Connector&);
            virtual bool connect(const Datconnect* connector)  = 0;            
            //virtual bool query(const std::string&) = 0;
            //virtual bool query(const std::string&, std::vector<std::vector<const char*>>&) = 0;
            virtual Datresult* query(const char*) = 0;
            virtual unsigned long long insert(const std::string&) = 0;
            virtual bool commit() = 0;
            virtual bool begin() = 0;
            virtual bool rollback() = 0;
            virtual void close() = 0;
            void* getServerConnector();
            const Datconnect* getDatconection() const;  
            const Connector& operator=(const Connector& obj);
	};
}
}
}

#endif
