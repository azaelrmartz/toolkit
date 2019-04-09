#ifndef TOOLKIT_COMMON_HPP
#define TOOLKIT_COMMON_HPP

#include <string>

namespace toolkit
{
        class Object
        {
                
        };
        
        
	/**
	 * \brief Informacion de Version
	 * 
	 **/
	class Version: public Object
	{
	public:		
		enum Stage
		{
			unknown,
			alpha,
			beta,
			release
		};
		
	private:	
		short major;
		short minor;
		short patch;
		Stage stage;
				
	public:
		short getMajor() const;
		short getMinor() const;
		short getPatch() const;
		Version();	
		Version(short major,short minor,short patch,Stage stage);
		void set(short major,short minor,short patch,Stage stage);
		std::string toString() const;
	};


	
	/**
	 * \brief retorna la version actual de componente
	 **/
	Version getVersion();	
}
#endif
