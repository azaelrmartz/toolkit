#ifndef TOOLKIT_COMMON_HPP
#define TOOLKIT_COMMON_HPP

#include <string>
#ifndef DEBUG
        #define COLLETION_ASSISTANT
#endif

namespace toolkit
{
        class Object
        {
        public:        
                Object();
                ~Object();
                
#ifdef COLLETION_ASSISTANT
        protected:
                void addChild(Object*);
                void removeChild(Object*);
                unsigned int getCountChilds();                               
        private:
                unsigned int countChilds;
                Object* parent;
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
                        snapshot,
			alpha,
			beta,
                        rc,
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
		unsigned long getBuild() const;
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
        std::string getPakageName();
}
#endif
