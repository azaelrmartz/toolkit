#ifndef TOOLKIT_COMMON_HPP
#define TOOLKIT_COMMON_HPP

#ifndef FIELDS_NUMBER
	#define FIELDS_NUMBER 3
#endif
#ifndef FIELD_STAGE
	#define FIELD_STAGE true
#endif

#include <string>

namespace toolkit
{
	/**
	 * \brief Informacion de version
	 * 
	 **/
	class Version
	{
	public:
#if FIELD_STAGE
		enum Stage
		{
			unknown,
			alpha,
			beta,
			release
		};	
#endif

#if FIELDS_NUMBER == 1
		short major;
#elif FIELDS_NUMBER == 2		
		short major;
		short minor;
#elif FIELDS_NUMBER == 3
		short major;
		short minor;
		short patch;
#endif
#if FIELD_STAGE
		Stage stage;
#endif
		Version();
#if FIELDS_NUMBER == 1
		Version(short major);
#elif FIELDS_NUMBER == 2 	
		Version(short major);
		Version(short major,short minor);
#elif FIELDS_NUMBER == 3 
		Version(short major);
		Version(short major,short minor);
		Version(short major,short minor,short patch);
#endif
#if FIELDS_NUMBER == 1 && FIELD_STAGE
		Version(short major,Stage stage);
#elif FIELDS_NUMBER == 2 && FIELD_STAGE		
		Version(short major,Stage stage);
		Version(short major,short minor,Stage stage);
#elif FIELDS_NUMBER == 3 && FIELD_STAGE		
		Version(short major,Stage stage);
		Version(short major,short minor,Stage stage);
		Version(short major,short minor,short patch,Stage stage);
#endif
		std::string toString() const;
	};


	
	/**
	 * \brief returna la version actual de componente common
	 **/
	Version getVersionCommon();	
}
#endif
