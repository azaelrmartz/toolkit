#ifndef OCTETOS_TOOLKIT_COMMON_H
#define OCTETOS_TOOLKIT_COMMON_H



enum octetos_toolkit_Stage {
    unknown,
    developing,
    snapshot,  
    prealpha,
    alpha,
    beta,
    betarelease,
    rc,
    prerelease,
    release,
    rtm,
    ga
};

/**
* \brief Informacion de version
* 
**/
struct octetos_toolkit_Version {	
	short major;
	short minor;
	short patch;
	short tweak;
	unsigned long build;
	enum octetos_toolkit_Stage stage;	
	const char* name;
};

const char* octetos_toolkit_Version_toString(const struct octetos_toolkit_Version* version);
struct octetos_toolkit_common_Version Version(short major,short minor,short patch,enum octetos_toolkit_Stage stage);
	
/**
* \brief returna la version actual de componente common
**/
struct octetos_toolkit_common_Version getPakageVersionTC();

void  octetos_toolkit_common_Version_fromString(const char* string, struct octetos_toolkit_common_Version* ver);

#endif
