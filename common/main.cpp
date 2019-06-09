#include <iostream>

#include "common.hpp"


int main(int argc, char *argv[])
{
        std::cout << toolkit::getPakageName() << " v" << toolkit::getPakageVersion().toString()<<std::endl;
#ifdef COLLETION_ASSISTANT
        std::cout<< "El asistente de recoleccion esta activo."<<std::endl;
#endif
        
}
