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

#include <iostream>

int main(int argc, char *argv[])
{
	std::string db = argv[1];
	codes::database::Conector conn(db);
	codes::database::Language lang;
	lang.selectByCode(conn,"es");
	//std::cout<< "Lenguaje : " << lang.getLanguage() << std::endl;
	
	codes::database::Country country;
	country.selectByCode(conn,"MEX");
	
	
	std::cout<< lang.getLanguage() << " de " << country.getCountry() << std::endl;
        
        std::vector<codes::database::Language*> langs;
        codes::database::Language::selectAll(conn,langs);
        std::cout << "Lenguajes conocidos:" << std::endl;
        for(auto l:langs)
        {
                std::cout << "\t" <<  l->getLanguage() << std::endl;
        }
	
	return 0;
}
