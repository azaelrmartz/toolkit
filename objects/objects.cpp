   /*
    * For generic data represetation library
    *Copyright (C) 2019  Azael Reyes

   * This program is free software: you can redistribute it and/or modify
   * it under the terms of the GNU General Public License as published by
    *the Free Software Foundation, either version 3 of the License, or
    *(at your option) any later version.

    *This program is distributed in the hope that it will be useful,
   * but WITHOUT ANY WARRANTY; without even the implied warranty of
    *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    *GNU General Public License for more details.

    *You should have received a copy of the GNU General Public License
    *along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */

#include "objects.hpp"

namespace toolkit
{
namespace objects
{
        License::License(const std::string& nameLic)
        {
                if(nameLic.compare("GPLv1")  == 0)
                {
                        
                }
                else if(nameLic.compare("GPLv2")  == 0)
                {
                        
                }
                else if(nameLic.compare("GPLv3")  == 0)
                {
                        
                }
        }

        Person::Person(int namesleng): names(namesleng)
        {
                
        }
}
}
