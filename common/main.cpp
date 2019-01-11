#include <iostream>


#include "common.hpp"

int main()
{
	toolkit::Version version(toolkit::getPakageVersion());
	std::cout<< version.toString()<<std::endl;
}
