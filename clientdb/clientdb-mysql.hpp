#ifndef TOOLKIT_CLIENTDB_MYSQL_HPP
#define TOOLKIT_CLIENTDB_MYSQL_HPP

#include <vector>

#include "clientdb.hpp"

namespace octetos
{
namespace toolkit
{
namespace clientdb
{       
namespace mysql
{
        class Datconnect : public toolkit::clientdb::Datconnect
        {
        public:         
            Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            Datconnect(const Datconnect& obj);
            const Datconnect& operator=(const Datconnect&);
            ~Datconnect();
        };      

        class Row : public toolkit::clientdb::Row
        {
        public:
#ifdef COLLETION_ASSISTANT
                Row(Datresult* rs,void* row);
#endif
                virtual const char* operator[](unsigned long long index); 
                Row();
                virtual ~Row();
                Row(void* row);
                Row(Row& row);
        };
        
        class Datresult : public toolkit::clientdb::Datresult
        {
        public:
                virtual ~Datresult();
                Datresult(void* result);
                virtual toolkit::clientdb::Row* operator[](unsigned long long index);                
                virtual toolkit::clientdb::Row* next();
        };
        
        class Connector : public toolkit::clientdb::Connector
        {
        public:
            virtual ~Connector();
            Connector();
            virtual bool connect(const toolkit::clientdb::Datconnect* connector);
            const char* serverDescription();
            //virtual bool query(const std::string&);
            //virtual bool query(const std::string&, std::vector<std::vector<const char*>>&);
            virtual toolkit::clientdb::Datresult* query(const char*);
            virtual unsigned long long insert(const std::string&);
            virtual bool commit();
            virtual bool begin();
            virtual bool rollback();
            virtual void close();
        };      
}
}
}
}

#endif
