
#include "common.h"

int main()
{
	struct Version version;
	version = getPakageVersionTC();
	printf("%s\n", toString(&version));
}
