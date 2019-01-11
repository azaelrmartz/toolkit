#include <iostream>


#include "common.hpp"

int main()
{
	toolkit::Version version(toolkit::getVersionCommon());
	std::cout<< version.toString()<<std::endl;
}
