/**
 * 
 *  This file is part of codes.
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *  author: Azael Reyes
 * */


#include "codes.hpp"

#include <stdio.h>
#include <sqlite3.h> 


namespace codes
{
	namespace database
	{	
		/**
		***
		**/
		const std::string& Country::getStandard()
		{
			return standard;
		}
		const std::string& Country::getAlpha2()
		{
			return alpha2;
		}
		const std::string& Country::getAlpha3()
		{
			return alpha3;
		}
		const std::string& Country::getCountry()
		{
			return country;
		}
		const std::string& Country::getComment()
		{
			return comment;
		}
			
		int Country::callback(void *obj, int argc, char **argv, char **azColName)
		{
			//fprintf(stderr, "%s: ", (const char*)data);
			Country* p = (Country*)obj;
			//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
			p->id = std::atoi(argv[0] ? argv[0] : "0");
			p->country = argv[1] ? argv[1] : "";
			p->alpha2 = argv[2] ? argv[2] : "";
			p->alpha3 = argv[3] ? argv[3] : "";		
			return 0;
		}
		bool Country::selectByCode(Conector& connect, const std::string& code)
		{
			std::string sql = "SELECT id,country,alpha2,alpha3 FROM Countries WHERE alpha2 = '";
			sql = sql + code + "' OR alpha3 = '" + code + "'";
			if(connect.query(sql,callback,this))
			{
				return true;
			}
			
			return false;
		}
		
		/**
		***
		**/
		bool Language::selectAll(Conector& conect,std::vector<Language*>& vec)
		{
			std::string sql = "SELECT id,language,iso6391,iso6392 FROM Languages";
			if(conect.query(sql,callback,&vec))
			{
				return true;
			}
			
			return false;
		}
		const std::string& Language::getStandard()
		{
			return standard;
		}
		const std::string& Language::get6391()
		{
			return iso6391;
		}		
		const std::string& Language::get6392()
		{
			return iso6392;
		}
		const std::string& Language::getLanguage()
		{
			return language;
		}
		const std::string& Language::getComment()
		{
			return comment;
		}
			
		int Language::callback(void *obj, int argc, char **argv, char **azColName)
		{
			//if(typeid(obj) == typeid(Language*))
			{
				Language* p = (Language*)obj;				
				//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
				p->id = std::atoi(argv[0] ? argv[0] : "0");
				p->language = argv[1] ? argv[1] : "";
				p->iso6391 = argv[2] ? argv[2] : "";	
				p->iso6392 = argv[3] ? argv[3] : "";
			}		
			/*else if(typeid(obj) == typeid(std::vector<Language*>*))
			{
				std::vector<Language*>* lst = (std::vector<Language*>*)obj;
				for(int i = 0; i < argc; i++)
				{
					Language* p = new Language();
					p->id = std::atoi(argv[0] ? argv[0] : "0");
					p->language = argv[1] ? argv[1] : "";
					p->iso6391 = argv[2] ? argv[2] : "";	
					p->iso6392 = argv[3] ? argv[3] : "";
					lst->push_back(p);
				}
			}*/
			
			return argc;
		}
		bool Language::selectByCode(Conector& connect, const std::string& code)
		{
			std::string sql = "SELECT id,language,iso6391,iso6392 FROM Languages WHERE iso6391 = '";
			sql = sql + code + "' OR iso6392 = '"  + code + "'" ;
			if(connect.query(sql,callback,this))
			{
				return true;
			}
			
			return false;
		}
		
		
		
		/**
		***
		**/
		bool Conector::query(const std::string& str, int (*callback)(void*,int,char**,char**),void* obj)
		{
			char *zErrMsg = 0;
			int rc = sqlite3_exec((sqlite3*)serverConnector, str.c_str(), callback, obj, &zErrMsg);
			if( rc == SQLITE_NOTADB ) 
			{
				fprintf(stderr, "SQL error(%i): La base de datso tiene mal formato: %s\n",rc, zErrMsg);
				sqlite3_free(zErrMsg);
				return false;				
			}
			else if( rc != SQLITE_OK ) 			
			{
				fprintf(stderr, "SQL error(%i): %s\n",rc, zErrMsg);
				sqlite3_free(zErrMsg);
				return false;			
			} 
			else 
			{
				//fprintf(stdout, "Operation done successfully\n");
				return false;			
			}
			return true;			
		}
		void* Conector::getServerConnector()
		{
			return serverConnector;
		}
		Conector::~Conector()
		{
			if(serverConnector != NULL) 
			{
				sqlite3_close((sqlite3*)serverConnector);
				serverConnector = NULL;
			}
		}		
		Conector::Conector(const std::string& dbname)
		{
			serverConnector = NULL;
			int rc = sqlite3_open(dbname.c_str(), (sqlite3**)&serverConnector);
			if( rc ) {
				fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg((sqlite3*)serverConnector));
				//return(0);
			} else {
				//fprintf(stderr, "Opened database(%s) successfully\n",dbname.c_str());
			}
		}
	}
}
