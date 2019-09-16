
#include <stdio.h>


#include "driver.h"
#include "parser.tab.h"

//extern int parse_string(struct Driver* drv,const char* in);

int main()
{
	struct Tray ty1,ty2,ty3;
		
	parse_string(&ty1,"1.0.55-alpha");    
    printf( "M: %d\n",ty1.version.major);
    printf( "m: %d\n",ty1.version.minor);
    printf( "p: %d\n",ty1.version.patch);
    if(ty1.version.stage == alpha) printf( "s: -alpha\n");
    printf( ">>>\n");
	parse_string(&ty2,"1.0.55-alpha+12124312345678");    
    printf( "M: %d\n",ty2.version.major);
    printf( "m: %d\n",ty2.version.minor);
    printf( "p: %d\n",ty2.version.patch);
    if(ty2.version.stage == alpha) printf( "s: -alpha\n");
    if(ty2.version.build.type == string_e) printf("b: %s\n",ty2.version.build.value.string);
    if(ty2.version.build.type == ul_e) printf("b: %uli\n",ty2.version.build.value.ul);
	
}
