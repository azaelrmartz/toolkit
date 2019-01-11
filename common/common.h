#ifndef TOOLKIT_COMMON_HPP
#define TOOLKIT_COMMON_HPP



enum Stage {
	unknown,
	alpha,
	beta,
	release
};

/**
* \brief Informacion de version
* 
**/
struct Version {	
	short major;
	short minor;
	short patch;
	enum Stage stage;	
};

const char* toString(const struct Version* version);
struct Version Version(short major,short minor,short patch,enum Stage stage);
	
/**
* \brief returna la version actual de componente common
**/
struct Version getPakageVersionTC();
	

#endif
