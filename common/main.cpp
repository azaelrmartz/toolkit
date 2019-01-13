#include <iostream>


#include "common.hpp"

int main()
{
	toolkit::Version version(toolkit::getVersion());
	std::cout<< version.toString()<<std::endl;
}
