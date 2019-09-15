
#include <stdio.h>


#include "driver.h"
#include "parser.tab.h"

//extern int parse_string(struct Driver* drv,const char* in);

int main()
{
	struct Tray ty;
		
	parse_string(&ty,"1.0.55-alpha");
    
    printf( "M: %d\n",ty.version.major);
    printf( "m: %d\n",ty.version.minor);
    printf( "p: %d\n",ty.version.patch);
    if(ty.version.stage == alpha) printf( "s: -alpha\n");
	
}
