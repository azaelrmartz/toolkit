#ifndef TOOLKIT_COMMON_HPP
#define TOOLKIT_COMMON_HPP

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
		enum Stage
		{
			unknown,
			alpha,
			beta,
			release
		};
		Version(short major,short minor,short patch,Stage stage);
		std::string toString() const;	
		short major;
		short minor;
		short patch;
		Stage stage;
	};


	
	/**
	 * \brief returna la version actual de componente common
	 **/
	Version getPakageVersion();	
}
#endif
