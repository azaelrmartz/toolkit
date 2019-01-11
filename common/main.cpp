
#include "common.hpp"

int main()
{
	toolkit::Version version(toolkit::getPakageVersion());
	printf("%s\n", version.toString());
}
