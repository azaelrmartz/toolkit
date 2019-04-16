#ifndef TOOLKIT_CLIENTDB_MYSQL_HPP
#define TOOLKIT_CLIENTDB_MYSQL_HPP

#include <vector>

#include "toolkit-clientdb.hpp"

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
        };      

        class Row : public toolkit::clientdb::Row
        {
#ifdef COLLETION_ASSISTANT
        private:
                Datresult* parent;
        public:
                Row(Datresult* rs,void* row);
#endif
        public:
                virtual const char* operator[](unsigned long long index); 
                Row();
                Row(void* row);
                Row(Row& row);
        };
        
        class Datresult : public toolkit::clientdb::Datresult
        {
        public:
                ~Datresult();
                Datresult(void* result);
                virtual toolkit::clientdb::Row& operator[](unsigned long long index);                
                virtual toolkit::clientdb::Row& next();
        };
        
        class Connector : public toolkit::clientdb::Connector
        {
        public:
            virtual ~Connector();
            Connector();
            virtual bool connect(const Datconnect& connector);
            const char* serverDescription();
            virtual bool query(const std::string&);
            virtual bool query(const std::string&, std::vector<std::vector<const char*>>&);
            virtual toolkit::clientdb::Datresult& query(const char*);
            virtual ID insert(const std::string&);
            virtual bool commit();
            virtual bool begin();
            virtual bool rollback();
            //const Datconnect& getDatconection() const;  
            virtual void close();
        };        
}
}
}

#endif
