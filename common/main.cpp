#include <iostream>

#include "common.hpp"
//#include "version.tab.h"

int main()
{
    

	std::cout << toolkit::getPakageName() << " v" << toolkit::getPakageVersion().toString()<<std::endl;
#ifdef COLLETION_ASSISTANT
        std::cout<< "El asistente de recoleccion esta activo."<<std::endl;
#endif
        
        toolkit::Version vFromStr;
        vFromStr.from("1.25.36");
        std::cout << " Parsed :" <<vFromStr.toString()<<std::endl;
}
