#ifndef DRIVER_H
#define DRIVER_H

#include "../common.h"

struct Tray
{
	struct octetos_toolkit_Version version;
    int dysplay_erro;
};

extern int parse_string(struct Tray* ty,const char* in);

#endif

 
