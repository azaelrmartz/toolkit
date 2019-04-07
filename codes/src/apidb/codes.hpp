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

#ifndef CODES_HPP
#define CODES_HPP
#include <string>
#include <vector>


namespace codes
{
	namespace database
	{
		class Conector
		{
		private:
			void* serverConnector;
		public:
			Conector(const std::string&);
			~Conector();
			bool query(const std::string&,int (*callback)(void*,int,char**,char**),void* obj);
			void* getServerConnector();
		};
		
		/**Implemetata el Standar ISO 639-1 e ISO 639-2
		***
		***/
		class Language
		{
		private:
			int id;
			std::string standard;
			std::string iso6391;
			std::string iso6392;
			std::string language;
			std::string comment;
                        //
			static int callbackByCode(void *data, int argc, char **argv, char **azColName);
                        static int callbackAll(void *data, int argc, char **argv, char **azColName);
			
		public:
			bool selectByCode(Conector& conect, const std::string& code);
			static bool selectAll(Conector& conect, std::vector<Language*>& vec);
			const std::string& getStandard();
			const std::string& get6391();
			const std::string& get6392();
			const std::string& getLanguage();
			const std::string& getComment();
		};
		
		/**Implemetata el Standar ISO 3166-1 Alpa-2 y Alpha-3
		***
		***/
		class Country
		{
		private:
			int id;
			std::string standard;
			std::string alpha2;
			std::string alpha3;
			std::string country;
			std::string comment;
                        //
			static int callbackByCode(void *data, int argc, char **argv, char **azColName);
			static int callbackAll(void* obj, int argc, char** argv, char** azColName);
                        
		public:
			bool selectByCode(Conector& conect, const std::string& code);
                        static bool selectAll(Conector& conect, std::vector<Country*>& vec);
			const std::string& getStandard();
			const std::string& getAlpha2();
			const std::string& getAlpha3();
			const std::string& getCountry();
			const std::string& getComment();
		};
	}	
}
#endif
