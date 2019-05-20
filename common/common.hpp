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
                void addChild(const Object*);
                void removeChild(const Object*);
                void addChild(const Object&);
                void removeChild(const Object&);
                unsigned int getCountChils();
                
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
                unsigned long build;
		Stage stage;
				
	public:
		short getMajor() const;
		short getMinor() const;
		short getPatch() const;
		int getBuild() const;
		Stage getStage() const;
		Version();	
		//Version(short major,short minor,short patch,Stage stage);
		void set(short major,short minor,short patch,Stage stage);
                void set(short major,short minor,short patch);
                void set(short major,short minor);
                void set(short major);
                void set(Stage stage);
                void set(unsigned long build);
		std::string toString() const;
	};


	
	/**
	 * \brief retorna la version actual de componente
	 **/
	Version getPakageVersion();	
}
#endif
