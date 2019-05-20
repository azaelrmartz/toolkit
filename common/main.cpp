#include <iostream>


#include "common.hpp"

int main()
{
	toolkit::Version version(toolkit::getPakageVersion());
	std::cout<< version.toString()<<std::endl;
#ifdef COLLETION_ASSISTANT
        std::cout<< "El asistente de recoleccion esta activo."<<std::endl;
#endif
}
