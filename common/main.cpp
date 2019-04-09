#include <iostream>


#include "toolkit-common.hpp"

int main()
{
	toolkit::Version version(toolkit::getVersion());
	std::cout<< version.toString()<<std::endl;
}
