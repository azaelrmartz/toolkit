#include <iostream>

#include "common.hpp"


int main(int argc, char *argv[])
{
	//std::cout << "Saludos ..." << std::endl;
	std::cout << octetos::toolkit::getPakageName() << " v" << octetos::toolkit::getPakageVersion().toString()<<std::endl;
#ifdef COLLETION_ASSISTANT
	std::cout<< "El asistente de recoleccion esta activo."<<std::endl;
#endif
	/*octetos::toolkit::Version ver;
	ver.fromString("1.2.65-snapshot");
	std::cout << "Ver: " << ver.toString() <<std::endl;*/
}
