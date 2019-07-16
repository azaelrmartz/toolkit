#ifndef TOOLKIT_CLIENTDB_POSTGRESQL_HPP
#define TOOLKIT_CLIENTDB_POSTGRESQL_HPP

#include <vector>

#include "clientdb.hpp"

namespace octetos
{
namespace toolkit
{
namespace clientdb
{
namespace postgresql
{                   
	octetos::toolkit::Version getPakageVersion();
	std::string getPakageName();	
        
        class Datconnect : public toolkit::clientdb::Datconnect
        {
        public:         
            Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            Datconnect(const Datconnect& obj);
            const Datconnect& operator=(const Datconnect&);
        };
        class Connector : public toolkit::clientdb::Connector
        {
        public:
            virtual ~Connector();
            Connector();
            virtual bool connect(const toolkit::clientdb::Datconnect* connector);
            virtual bool query(const std::string&);
            virtual bool query(const std::string&, std::vector<std::vector<const char*>>&);
            virtual Datresult* query(const char*);
            virtual unsigned long long insert(const std::string&);
            virtual bool commit();
            virtual bool begin();
            virtual bool rollback();
            const toolkit::clientdb::Datconnect& getDatconection() const;  
            virtual void close();
        };
}
}
}
}
#endif
