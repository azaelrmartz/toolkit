#include <mysql/mysql.h>
#include <iostream>

#include "clientdb-mysql.hpp"

namespace toolkit
{
namespace clientdb
{
namespace mysql
{        
        Row::~Row()
        {
#ifdef COLLETION_ASSISTANT
                if(getCountChilds() > 0)
                {
                        std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
                }                
#endif
        }
        Row::Row(Row& row)
        {
                this->row = row.row;
#ifdef COLLETION_ASSISTANT
                this->parent = row.parent;
#endif
        }
         const char* Row::operator[](unsigned long long index)
         {
                 if(row != NULL) return ((MYSQL_ROW)row)[index];
                 return NULL;
        }
        Row::Row()
        {
#ifdef COLLETION_ASSISTANT
                
#endif
        }
        Row::Row(void* row):toolkit::clientdb::Row(row)
        {
#ifdef COLLETION_ASSISTANT
                
#endif
        }
        
        
        
        
        
       
        
        toolkit::clientdb::Row* Datresult::operator[](unsigned long long index)
        {
                Row* r = NULL;
                if(mysql_num_rows((MYSQL_RES*)result)  < index)
                {
                        mysql_data_seek((MYSQL_RES*)result,index); 
                        if(index >= 0) 
                        {
                                MYSQL_ROW row  = mysql_fetch_row((MYSQL_RES*)result);
                                 r = new Row(row);
#ifdef COLLETION_ASSISTANT
                                addChild(r);
#endif                                 
                                return r;
                        }
                        else
                        {
                                 r = new Row(NULL);
                                  return r;
                        }
                        
                }                
                return r;
        }
        
        Datresult::Datresult(void* result) : toolkit::clientdb::Datresult(result)
        {
        }
        
        toolkit::clientdb::Row* Datresult::next()
        {
                MYSQL_ROW row  = mysql_fetch_row((MYSQL_RES*)result);
                Row* r = new Row(row);
#ifdef COLLETION_ASSISTANT
                        addChild(r);
#endif                                 
                        return r;
        }
        Datresult::~Datresult()
        {
                if(result != NULL)
                {
                        mysql_free_result((MYSQL_RES*)result);
                        result = NULL;
                }
#ifdef COLLETION_ASSISTANT
                if(getCountChilds() > 0)
                {
                        std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
                }
#endif
        }
        
        
        
        Datconnect::~Datconnect() 
        {                
#ifdef COLLETION_ASSISTANT
                if(getCountChilds() > 0)
                {
                        std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
                }
#endif
        }
        Datconnect::Datconnect(const Datconnect& obj) : toolkit::clientdb::Datconnect(obj)
        {
        }
        
        const Datconnect& Datconnect::operator=(const Datconnect& obj)
        {		
             ((clientdb::Datconnect&)*this)=obj;//llamar el construc de la clase base
             return *this;
        }
        
        Datconnect::Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& user,const std::string& password) : clientdb::Datconnect(ServerType::MySQL,host,port,database,user,password)
        {
        }
        
        

        
        Connector::Connector()
        {
        }
        Connector::~Connector()
        {
            close();
#ifdef COLLETION_ASSISTANT
                if(getCountChilds() > 0)
                {
                        std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
                }
#endif
        }
        toolkit::clientdb::Datresult* Connector::query(const char* str)
        {
                if (mysql_query((MYSQL*)serverConnector, str)  != 0) 
                {
                        std::string msg = "";
                        msg = msg + " MySQL Server Error No. : '";
                        msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
                        msg = msg + "' ";
                        msg = msg + mysql_error((MYSQL*)serverConnector);
                        throw SQLException(msg);   
                }
                MYSQL_RES *result = mysql_store_result((MYSQL*)serverConnector);
                if (result == NULL && mysql_errno((MYSQL*)serverConnector) != 0) 
                {
                        std::string msg = "";
                        msg = msg + " MySQL Server Error No. : '";
                        msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
                        msg = msg + "' ";
                        msg = msg + mysql_error((MYSQL*)serverConnector);
                        throw SQLException(msg);   
                }
                Datresult* dtrs = new Datresult(result);
#ifdef COLLETION_ASSISTANT
                addChild(dtrs);
#endif    
                return dtrs;
        }
        bool Connector::begin()
        {
            return false; 
        }
        void Connector::close()
        {
                if (serverConnector != NULL) mysql_close((MYSQL*)serverConnector);
                serverConnector = NULL;
        }       
        bool Connector::rollback()
        {
                if (serverConnector != NULL)
                {
                        if(mysql_rollback((MYSQL*)serverConnector) == 0)
                        {
                        return true;
                        }
                }
            
                return false; 
        }        
        bool Connector::commit()
        {
            if (serverConnector != NULL)
            {
                if(mysql_commit((MYSQL*)serverConnector) == 0)
                {
                    return true;
                }
            }
            
            return false; 
        }
        ID Connector::insert(const std::string& str)
        {
            if (mysql_query((MYSQL*)serverConnector, str.c_str()) == 0) 
            {
                return mysql_insert_id((MYSQL*)serverConnector);
            }
            else
            {   
                return 0; 
            }		
        }        
        const char* Connector::serverDescription()
        {
            return mysql_get_client_info();
        }
        bool Connector::connect(const toolkit::clientdb::Datconnect* conection)
        {
            serverConnector = (void*)mysql_init(NULL);
            if (serverConnector == NULL)
            {
                std::string msg = "";
                msg = msg + " MySQL Server Error No. : '";
                msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
                msg = msg + "' ";
                msg = msg + mysql_error((MYSQL*)serverConnector);
                throw SQLException(msg);           
            }
            if (mysql_real_connect((MYSQL*)serverConnector, conection->getHost().c_str(), conection->getUser().c_str(), conection->getPassword().c_str(),conection->getDatabase().c_str(),conection->getPort(), NULL, 0) == NULL)
            {
                std::string msg = "";
                msg = msg + " MySQL Server Error No. : '";
                msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
                msg = msg + "' ";
                msg = msg + mysql_error((MYSQL*)serverConnector);
                throw SQLException(msg);
            }        
            if(mysql_autocommit((MYSQL*)serverConnector,0) != 0)
            {
                std::string msg = "";
                msg = msg + " MySQL Server Error No. : '";
                msg = msg + std::to_string(mysql_errno((MYSQL*)serverConnector));
                msg = msg + "' ";
                msg = msg + mysql_error((MYSQL*)serverConnector);
                throw SQLException(msg);
            }        
            datconection = conection;
            return true;
        }
}    
}
}
