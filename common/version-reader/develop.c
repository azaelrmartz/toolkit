
 #include <stdio.h>
 
 
#include "Driver.h"
#include "parser.tab.h"

//extern int parse_string(struct Driver* drv,const char* in);

int main()
{
	struct Tray ty;
	
	printf( "Parsre C!\n" );
	
	parse_string(&ty,"1.0.23-alpha");
	
}
