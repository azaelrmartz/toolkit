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
	private:
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
		short getMajor();
#elif FIELDS_NUMBER == 2		
		short getMajor();
		short getMinor();
#elif FIELDS_NUMBER == 3
		short getMajor();
		short getMinor();
		short getPatch();
#endif
#if FIELD_STAGE
		Stage stage;
#endif
		Version();
#if FIELDS_NUMBER == 1 && !FIELD_STAGE
		Version(short major);
		void set();
#elif FIELDS_NUMBER == 2  && !FIELD_STAGE	
		Version(short major,short minor);
		void set(short major,short minor);
#elif FIELDS_NUMBER == 3  && !FIELD_STAGE
		Version(short major,short minor,short patch);
		void set(short major,short minor,short patch);
#endif
#if FIELDS_NUMBER == 1 && FIELD_STAGE
		Version(short major,Stage stage);
		void set(short major,Stage stage);
#elif FIELDS_NUMBER == 2 && FIELD_STAGE		
		Version(short major,short minor,Stage stage);
		void set(short major,short minor,Stage stage);
#elif FIELDS_NUMBER == 3 && FIELD_STAGE		
		Version(short major,short minor,short patch,Stage stage);
		void set(short major,short minor,short patch,Stage stage);
#endif
		std::string toString() const;
	};


	
	/**
	 * \brief returna la version actual de componente common
	 **/
	Version getVersion();	
}
#endif
