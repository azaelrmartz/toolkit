#ifndef TOOLKIT_CLIENTDB_MYSQL_HPP
#define TOOLKIT_CLIENTDB_MYSQL_HPP

#include <common.hpp>
#include <vector>

#include "clientdb.hpp"

namespace toolkit
{
namespace clientdb
{       
namespace mysql
{
        class Datasource : public toolkit::clientdb::Datasource
        {
        public:         
            Datasource(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            Datasource(const Datasource& obj);
            const Datasource& operator=(const Datasource&);
        };         
        class Connector : public toolkit::clientdb::Connector
        {
        public:
            virtual ~Connector();
            Connector();
            virtual bool connect(const Datasource& connector);
            const char* serverDescription();
            virtual bool query(const std::string&);
            virtual bool query(const std::string&, std::vector<std::vector<const char*>>&);
            virtual ID insert(const std::string&);
            virtual bool commit();
            virtual bool begin();
            virtual bool rollback();
            //const Datasource& getDatconection() const;  
            virtual void close();
        };        
}
}
}

#endif
