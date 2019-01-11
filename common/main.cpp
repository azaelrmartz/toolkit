#include <iostream>


#include "common.hpp"

int main()
{
	toolkit::Version version(toolkit::getVersionComponetCommon());
	std::cout<< version.toString()<<std::endl;
}
