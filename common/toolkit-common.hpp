#ifndef TOOLKIT_COMMON_HPP
#define TOOLKIT_COMMON_HPP

#include <string>
#ifndef DEBUG
        #define COLLETION_ASSISTANT
#endif
#ifdef COLLETION_ASSISTANT

#endif

namespace toolkit
{
        class Object
        {
#ifdef COLLETION_ASSISTANT
        protected:
                void addChild(Object*);
                void removeChild( Object*);
                Object();
        private:
                unsigned int countChilds;                
#endif
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
